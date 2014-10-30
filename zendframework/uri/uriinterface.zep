/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Uri;

/**
 * Interface defining a URI
 */
interface UriInterface
{
    /**
     * Create a new URI object
     *
     * @param  Uri|string|null $uri
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(var uri = null);

    /**
     * Check if the URI is valid
     *
     * Note that a relative URI may still be valid
     *
     * @return bool
     */
    public function isValid() -> boolean;

    /**
     * Check if the URI is a valid relative URI
     *
     * @return bool
     */
    public function isValidRelative() -> boolean;

    /**
     * Check if the URI is an absolute or relative URI
     *
     * @return bool
     */
    public function isAbsolute() -> boolean;

    /**
     * Parse a URI string
     *
     * @param  string $uri
     * @return UriInterface
     */
    public function parse(string uri) -> <UriInterface>;

    /**
     * Compose the URI into a string
     *
     * @return string
     * @throws Exception\InvalidUriException
     */
    public function toString() -> string;

    /**
     * Normalize the URI
     *
     * Normalizing a URI includes removing any redundant parent directory or
     * current directory references from the path (e.g. foo/bar/../baz becomes
     * foo/baz), normalizing the scheme case, decoding any over-encoded
     * characters etc.
     *
     * Eventually, two normalized URLs pointing to the same resource should be
     * equal even if they were originally represented by two different strings
     *
     * @return Uri
     */
    public function normalize() -> <Uri>;

    /**
     * Convert the link to a relative link by substracting a base URI
     *
     *  This is the opposite of resolving a relative link - i.e. creating a
     *  relative reference link from an original URI and a base URI.
     *
     *  If the two URIs do not intersect (e.g. the original URI is not in any
     *  way related to the base URI) the URI will not be modified.
     *
     * @param  UriInterface|string $baseUri
     * @return UriInterface
     */
    public function makeRelative(var baseUri) -> <UriInterface>;

    /**
     * Get the scheme part of the URI
     *
     * @return string|null
     */
    public function getScheme() -> string;

    /**
     * Get the User-info (usually user:password) part
     *
     * @return string|null
     */
    public function getUserInfo() -> string;

    /**
     * Get the URI host
     *
     * @return string|null
     */
    public function getHost() -> string;

    /**
     * Get the URI port
     *
     * @return int|null
     */
    public function getPort() -> int;

    /**
     * Get the URI path
     *
     * @return string|null
     */
    public function getPath() -> string;

    /**
     * Get the URI query
     *
     * @return string|null
     */
    public function getQuery() -> string;

    /**
     * Return the query string as an associative array of key => value pairs
     *
     * This is an extension to RFC-3986 but is quite useful when working with
     * most common URI types
     *
     * @return array
     */
    public function getQueryAsArray() -> array;

    /**
     * Get the URI fragment
     *
     * @return string|null
     */
    public function getFragment() -> string;

    /**
     * Set the URI scheme
     *
     * If the scheme is not valid according to the generic scheme syntax or
     * is not acceptable by the specific URI class (e.g. 'http' or 'https' are
     * the only acceptable schemes for the Zend\Uri\Http class) an exception
     * will be thrown.
     *
     * You can check if a scheme is valid before setting it using the
     * validateScheme() method.
     *
     * @param  string $scheme
     * @throws Exception\InvalidUriPartException
     * @return UriInterface
     */
    public function setScheme(string scheme) -> <UriInterface>;

    /**
     * Set the URI User-info part (usually user:password)
     *
     * @param  string $userInfo
     * @return UriInterface
     * @throws Exception\InvalidUriPartException If the schema definition
     * does not have this part
     */
    public function setUserInfo(string userInfo) -> <UriInterface>;

    /**
     * Set the URI host
     *
     * Note that the generic syntax for URIs allows using host names which
     * are not necessarily IPv4 addresses or valid DNS host names. For example,
     * IPv6 addresses are allowed as well, and also an abstract "registered name"
     * which may be any name composed of a valid set of characters, including,
     * for example, tilda (~) and underscore (_) which are not allowed in DNS
     * names.
     *
     * Subclasses of Uri may impose more strict validation of host names - for
     * example the HTTP RFC clearly states that only IPv4 and valid DNS names
     * are allowed in HTTP URIs.
     *
     * @param  string $host
     * @throws Exception\InvalidUriPartException
     * @return UriInterface
     */
    public function setHost(string host) -> <UriInterface>;

    /**
     * Set the port part of the URI
     *
     * @param  int $port
     * @return UriInterface
     */
    public function setPort(int port) -> <UriInterface>;

    /**
     * Set the path
     *
     * @param  string $path
     * @return UriInterface
     */
    public function setPath(string path) -> <UriInterface>;

    /**
     * Set the query string
     *
     * If an array is provided, will encode this array of parameters into a
     * query string. Array values will be represented in the query string using
     * PHP's common square bracket notation.
     *
     * @param  string|array $query
     * @return UriInterface
     */
    public function setQuery(var query) -> <UriInterface>;

    /**
     * Set the URI fragment part
     *
     * @param  string $fragment
     * @return UriInterface
     * @throws Exception\InvalidUriPartException If the schema definition
     * does not have this part
     */
    public function setFragment(string fragment) -> <UriInterface>;

    /**
     * Magic method to convert the URI to a string
     *
     * @return string
     */
    public function __toString() -> string;

}
