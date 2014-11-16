/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

use ArrayIterator;
use Zend\Http\Header\SetCookie;
use Zend\Uri;

/**
 * A Zend\Http\Cookies object is designed to contain and maintain HTTP cookies, and should
 * be used along with Zend\Http\Client in order to manage cookies across HTTP requests and
 * responses.
 *
 * The class contains an array of Zend\Http\Header\Cookie objects. Cookies can be added
 * automatically from a request or manually. Then, the Cookies class can find and return the
 * cookies needed for a specific HTTP request.
 *
 * A special parameter can be passed to all methods of this class that return cookies: Cookies
 * can be returned either in their native form (as Zend\Http\Header\Cookie objects) or as strings -
 * the later is suitable for sending as the value of the "Cookie" header in an HTTP request.
 * You can also choose, when returning more than one cookie, whether to get an array of strings
 * (by passing Zend\Http\Client\Cookies::COOKIE_STRING_ARRAY) or one unified string for all cookies
 * (by passing Zend\Http\Client\Cookies::COOKIE_STRING_CONCAT).
 *
 * @link       http://wp.netscape.com/newsref/std/cookie_spec.html for some specs.
 */
class Cookies extends Headers
{
    /**
     * Return cookie(s) as a Zend\Http\Cookie object
     *
     */
    const COOKIE_OBJECT = 0;

    /**
     * Return cookie(s) as a string (suitable for sending in an HTTP request)
     *
     */
    const COOKIE_STRING_ARRAY = 1;

    /**
     * Return all cookies as one long string (suitable for sending in an HTTP request)
     *
     */
    const COOKIE_STRING_CONCAT = 2;

    /**
     * Return all cookies as one long string (strict mode)
     *  - Single space after the semi-colon separating each cookie
     *  - Remove trailing semi-colon, if any
     */
    const COOKIE_STRING_CONCAT_STRICT = 3;

    /**
     * @var \Zend\Http\Cookies
     */
    protected cookies = [];

    /**
     * @var \Zend\Http\Headers
     */
    protected headers;

    /**
     * @var array
     */
    protected rawCookies;

    /**
     * @static
     * @throws Exception\RuntimeException
     * @param $string
     * @return void
     */
    public static function fromString(string $string) -> void
    {
        string exceptionMsg;

        let exceptionMsg = __CLASS__ . "::" . __FUNCTION__
                        . " should not be used as a factory, use "
                        . __NAMESPACE__ . "\\Headers::fromtString() instead.";

        throw new Exception\RuntimeException(exceptionMsg);
    }

    /**
     * Add a cookie to the class. Cookie should be passed either as a Zend\Http\Header\Cookie object
     * or as a string - in which case an object is created from the string.
     *
     * @param SetCookie|string $cookie
     * @param Uri\Uri|string $refUri Optional reference URI (for domain, path, secure)
     * @throws Exception\InvalidArgumentException
     */
    public function addCookie(var cookie, string refUri = null) -> void
    {
        var domain, path, name;

        if typeof cookie == "string" {
//            let cookie = SetCookie::fromString(cookie, refUri);
        }

// todo:
//        if unlikely !(cookie instanceof SetCookie) {
//            throw new Exception\InvalidArgumentException("Supplient argument is not a valid cookie string or object");
//        }

        let domain = cookie->getDomain();
        let path = cookie->getPath();
        let name = cookie->getName();

        if !isset this->cookies[domain] {
            let this->cookies[domain] = [];
        }
        if !isset this->cookies[domain][path] {
            let this->cookies[domain][path] = [];
        }

        let this->cookies[domain][path][name] = cookie;
        let this->rawCookies[] = cookie;
    }

    /**
     * Parse an HTTP response, adding all the cookies set in that response
     *
     * @param Response $response
     * @param Uri\Uri|string $refUri Requested URI
     */
    public function addCookiesFromResponse(<Response> response, string refUri) -> void
    {
        var headers, cookieHdrs, cookie;

        let headers = <Headers> response->getHeaders();
        let cookieHdrs = headers->get("Set-Cookie");

        if typeof cookieHdrs == "array" || cookieHdrs instanceof ArrayIterator {
            if cookieHdrs instanceof ArrayIterator {
                let cookieHdrs = iterator_to_array(cookieHdrs);
            }
            for cookie in cookieHdrs {
                this->addCookie(cookie, refUri);
            }
        } elseif typeof cookieHdrs == "string" {
            this->addCookie(cookieHdrs, refUri);
        }
    }

    /**
     * Get all cookies in the cookie jar as an array
     *
     * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\SetCookie or as strings
     * @return array|string
     */
    public function getAllCookies(int retAs = 0) -> array|string
    {
        var cookies;

        let cookies = this->cookies;
        let cookies = this->_flattenCookiesArray(cookies, retAs);

        return cookies;
    }

    /**
     * Return an array of all cookies matching a specific request according to the request URI,
     * whether session cookies should be sent or not, and the time to consider as "now" when
     * checking cookie expiry time.
     *
     * @param string|Uri\Uri $uri URI to check against (secure, domain, path)
     * @param bool $matchSessionCookies Whether to send session cookies
     * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\Cookie or as strings
     * @param int $now Override the current time when checking for expiry time
     * @throws Exception\InvalidArgumentException if invalid URI specified
     * @return array|string
     */
    public function getMatchingCookies(var uri, boolean matchSessionCookies = true, int retAs = 0, int now = null) -> array|string
    {
        var host, path, cookies, result = [], cookie;

        // todo:
        if typeof uri == "string" {
           // let uri = Uri\UriFactory::factory(uri, "http");
//        } elseif unlikely !(uri instanceof Uri\UriInterface) {
//            throw new Exception\InvalidArgumentException("Invalid URI string or object passed");
        }

        let host = uri->getHost();
        let path = uri->getPath();

        if empty host {
            throw new Exception\InvalidArgumentException("Invalid URI specified; does not contain a host");
        }

        // First, reduce the array of cookies to only those matching domain and path
        let cookies = this->_matchDomain(host);
        let cookies = this->_matchPath(cookies, path);
        let cookies = this->_flattenCookiesArray(cookies, self::COOKIE_OBJECT);

        // Next, run Cookie->match on all cookies to check secure, time and session matching
        for cookie in cookies {
            if cookie->match(uri, matchSessionCookies, now) {
                let result[] = cookie;
            }
        }
        // Now, use self::_flattenCookiesArray again - only to convert to the return format ;)
        return this->_flattenCookiesArray(result, retAs);
    }

    /**
     * Get a specific cookie according to a URI and name
     *
     * @param Uri\Uri|string $uri The uri (domain and path) to match
     * @param string $cookieName The cookie's name
     * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\SetCookie or as strings
     * @throws Exception\InvalidArgumentException if invalid URI specified or invalid $retAs value
     * @return SetCookie|string
     */
    public function getCookie(var uri, string cookieName, int retAs = 0) -> string|<SetCookie>|boolean
    {
        var host, path, result, cookie;
        string exceptionMsg;

// todo:
        if typeof uri == "string" {
           // let uri = Uri\UriFactory::factory(uri, "http");
    //    } elseif unlikely !(uri instanceof Uri\UriInterface) {
       //     throw new Exception\InvalidArgumentException("Invalid URI specified");
        }

        let host = uri->getHost();
        let path = uri->getPath();

        if empty host {
            throw new Exception\InvalidArgumentException("Invalid URI specified; host missing");
        }

        // Get correct cookie path
        let path = substr(path, 0, strrpos(path, "/"));
        if !path {
            let path = "/";
        }

        if fetch cookie, this->cookies[host][path][cookieName] {
            switch retAs {
                case self::COOKIE_OBJECT:
                    let result = cookie;
                    break;

                case self::COOKIE_STRING_CONCAT:
                case self::COOKIE_STRING_ARRAY:
                    let result = cookie->__toString();
                    break;

                default:
                    let exceptionMsg = "Invalid value passed for $retAs: " . retAs;
                    throw new Exception\InvalidArgumentException(exceptionMsg);
                    break;
            }
            return result;
        }
        return false;
    }

    /**
     * Helper function to recursively flatten an array. Should be used when exporting the
     * cookies array (or parts of it)
     *
     * @param \Zend\Http\Header\SetCookie|array $ptr
     * @param int $retAs What value to return
     * @return array|string
     */
    protected function _flattenCookiesArray(var ptr, int retAs = 0) -> array|string|null
    {
        var result, item, cookies;

        if typeof ptr == "array" {
            let result = retAs == self::COOKIE_STRING_CONCAT ? "" : [];
            for item in ptr {
                let cookies = this->_flattenCookiesArray(item, retAs);
                if retAs == self::COOKIE_STRING_CONCAT {
                    let result .= cookies;
                } else {
                    let result = array_merge(result, cookies);
                }
            }
            return result;
        }

        if ptr instanceof SetCookie {
            switch retAs {
                case self::COOKIE_STRING_ARRAY:
                    let result = [ptr->__toString()];
                    break;
                case self::COOKIE_STRING_CONCAT:
                    let result = ptr->__toString();
                    break;
                case self::COOKIE_OBJECT:
                    let result = [ptr];
                    break;
            }
            return result;
        }

        return null;
    }

    /**
     * Return a subset of the cookies array matching a specific domain
     *
     * @param string $domain
     * @return array
     */
    protected function _matchDomain(string domain) -> array
    {
        var result = [], cookiesKeys, cdom;

        let cookiesKeys = array_keys(this->cookies);
        for cdom in cookiesKeys {
        // todo:
         //   if SetCookie::matchCookieDomain(cdom, domain) {
         //       let result[cdom] = this->cookies[cdom];
         //   }
        }

        return result;
    }

    /**
     * Return a subset of a domain-matching cookies that also match a specified path
     *
     * @param array $domains
     * @param string $path
     * @return array
     */
    protected function _matchPath(array domains, string path) -> array
    {
        var result = [], dom, pathsArray, pathsArrayKeys, cpath;

        for dom, pathsArray in domains {
            let pathsArrayKeys = array_keys(pathsArray);
            for cpath in pathsArrayKeys {
             //   if SetCookie::matchCookiePath(cpath, path) { // todo:
                    if !isset result[dom] {
                        let result[dom] = [];
                    }
                    let result[dom][cpath] = pathsArray[cpath];
             //   }
            }
        }

        return result;
    }

    /**
     * Create a new Cookies object and automatically load into it all the
     * cookies set in a Response object. If $uri is set, it will be
     * considered as the requested URI for setting default domain and path
     * of the cookie.
     *
     * @param Response $response HTTP Response object
     * @param Uri\Uri|string $refUri The requested URI
     * @return Cookies
     * @todo Add the $uri functionality.
     */
    public static function fromResponse(<Response> response, string refUri) -> <Cookies>
    {
        var className, jar;

        let className = get_called_class();
        let jar = new {className}();

        jar->addCookiesFromResponse(response, refUri);

        return jar;
    }

    /**
     * Tells if the array of cookies is empty
     *
     * @return bool
     */
    public function isEmpty() -> boolean
    {
        var count;
        let count = this->count();

        return count == 0;
    }

    /**
     * Empties the cookieJar of any cookie
     *
     * @return Cookies
     */
    public function reset() -> <Cookies>
    {
        let this->cookies = [];
        let this->rawCookies = [];

        return this;
    }

}
