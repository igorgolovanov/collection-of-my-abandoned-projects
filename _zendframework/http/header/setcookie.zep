/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * @throws Exception\InvalidArgumentException
 * @see http://www.ietf.org/rfc/rfc2109.txt
 * @see http://www.w3.org/Protocols/rfc2109/rfc2109
 */
class SetCookie implements MultipleHeaderInterface
{
    /**
     * Cookie name
     *
     * @var string|null
     */
    protected name;

    /**
     * Cookie value
     *
     * @var string|null
     */
    protected value;

    /**
     * Version
     *
     * @var int|null
     */
    protected version;

    /**
     * Max Age
     *
     * @var int|null
     */
    protected maxAge;

    /**
     * Cookie expiry date
     *
     * @var int|null
     */
    protected expires;

    /**
     * Cookie domain
     *
     * @var string|null
     */
    protected domain;

    /**
     * Cookie path
     *
     * @var string|null
     */
    protected path;

    /**
     * Whether the cookie is secure or not
     *
     * @var bool|null
     */
    protected secure;

    /**
     * If the value need to be quoted or not
     *
     * @var bool
     */
    protected quoteFieldValue = false;

    /**
     * @var bool|null
     */
    protected httponly;

    /**
     * @static
     * @throws Exception\InvalidArgumentException
     * @param  $headerLine
     * @param  bool $bypassHeaderFieldName
     * @return array|SetCookie
     */
    public static function fromString(headerLine, boolean bypassHeaderFieldName = false) -> array|<SetCookie>
    {

    }

    /**
     * Cookie object constructor
     *
     * @todo Add validation of each one of the parameters (legal domain, etc.)
     *
     * @param   string      $name
     * @param   string      $value
     * @param   int|string  $expires
     * @param   string      $path
     * @param   string      $domain
     * @param   bool        $secure
     * @param   bool        $httponly
     * @param   string      $maxAge
     * @param   int         $version
     * @return  SetCookie
     */
    public function __construct(string name = null, string value = null, var expires = null, string path = null, string domain = null, boolean secure = false, boolean httponly = false, string maxAge = null, int version = null) -> <SetCookie>
    {

    }

    /**
     * @return string 'Set-Cookie'
     */
    public function getFieldName() -> string
    {

    }

    /**
     * @throws Exception\RuntimeException
     * @return string
     */
    public function getFieldValue() -> string
    {

    }

    /**
     * @param string $name
     * @throws Exception\InvalidArgumentException
     * @return SetCookie
     */
    public function setName(string name) -> <SetCookie>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @param string $value
     * @return SetCookie
     */
    public function setValue(string value) -> <SetCookie>
    {

    }

    /**
     * @return string
     */
    public function getValue() -> string
    {

    }

    /**
     * Set version
     *
     * @param int $version
     * @throws Exception\InvalidArgumentException
     * @return SetCookie
     */
    public function setVersion(int version) -> <SetCookie>
    {

    }

    /**
     * Get version
     *
     * @return int
     */
    public function getVersion() -> int
    {

    }

    /**
     * Set Max-Age
     *
     * @param int $maxAge
     * @throws Exception\InvalidArgumentException
     * @return SetCookie
     */
    public function setMaxAge(int maxAge) -> <SetCookie>
    {

    }

    /**
     * Get Max-Age
     *
     * @return int
     */
    public function getMaxAge() -> int
    {

    }

    /**
     * @param  int|string $expires
     * @throws Exception\InvalidArgumentException
     * @return SetCookie
     */
    public function setExpires(var expires) -> <SetCookie>
    {

    }

    /**
     * @param bool $inSeconds
     * @return int|string
     */
    public function getExpires(boolean inSeconds = false) -> int|string
    {

    }

    /**
     * @param string $domain
     * @return SetCookie
     */
    public function setDomain(string domain) -> <SetCookie>
    {

    }

    /**
     * @return string
     */
    public function getDomain() -> string
    {

    }

    /**
     * @param string $path
     * @return SetCookie
     */
    public function setPath(string path) -> <SetCookie>
    {

    }

    /**
     * @return string
     */
    public function getPath() -> string
    {

    }

    /**
     * @param  bool $secure
     * @return SetCookie
     */
    public function setSecure(boolean secure) -> <SetCookie>
    {

    }

    /**
     * Set whether the value for this cookie should be quoted
     *
     * @param  bool $quotedValue
     * @return SetCookie
     */
    public function setQuoteFieldValue(boolean quotedValue) -> <SetCookie>
    {

    }

    /**
     * @return bool
     */
    public function isSecure() -> boolean
    {

    }

    /**
     * @param  bool $httponly
     * @return SetCookie
     */
    public function setHttponly(boolean httponly) -> <SetCookie>
    {

    }

    /**
     * @return bool
     */
    public function isHttponly() -> boolean
    {

    }

    /**
     * Check whether the cookie has expired
     *
     * Always returns false if the cookie is a session cookie (has no expiry time)
     *
     * @param int $now Timestamp to consider as "now"
     * @return bool
     */
    public function isExpired(int now = null) -> boolean
    {

    }

    /**
     * Check whether the cookie is a session cookie (has no expiry time set)
     *
     * @return bool
     */
    public function isSessionCookie() -> boolean
    {

    }

    /**
     * Check whether the value for this cookie should be quoted
     *
     * @return bool
     */
    public function hasQuoteFieldValue() -> boolean
    {

    }

    public function isValidForRequest(requestDomain, path, boolean isSecure = false)
    {

    }

    /**
     * Checks whether the cookie should be sent or not in a specific scenario
     *
     * @param string|\Zend\Uri\Uri $uri URI to check against (secure, domain, path)
     * @param bool $matchSessionCookies Whether to send session cookies
     * @param int $now Override the current time when checking for expiry time
     * @return bool
     * @throws Exception\InvalidArgumentException If URI does not have HTTP or HTTPS scheme.
     */
    public function match(var uri, boolean matchSessionCookies = true, int now = null) -> boolean
    {

    }

    /**
     * Check if a cookie's domain matches a host name.
     *
     * Used by Zend\Http\Cookies for cookie matching
     *
     * @param  string $cookieDomain
     * @param  string $host
     *
     * @return bool
     */
    public static function matchCookieDomain(string cookieDomain, string host) -> boolean
    {

    }

    /**
     * Check if a cookie's path matches a URL path
     *
     * Used by Zend\Http\Cookies for cookie matching
     *
     * @param  string $cookiePath
     * @param  string $path
     * @return bool
     */
    public static function matchCookiePath(string cookiePath, string path) -> boolean
    {

    }

    public function toString()
    {

    }

    public function toStringMultipleHeaders(array! headers)
    {

    }

}
