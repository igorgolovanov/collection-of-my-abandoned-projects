
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

interface UriInterface
{
	/**
     * Gets the schema
     *
     * @return string
     */
    public function getScheme() -> string;

    /**
     * Sets the schema
     *
     * @param string scheme
     * @return OAuth\UriInterface
     */
    public function setScheme(string! scheme) -> <OAuth\UriInterface>;

    /**
     * Gets the host
     *
     * @return string
     */
    public function getHost() -> string;

    /**
     * Sets the host
     *
     * @param string host
     * @return OAuth\UriInterface
     */
    public function setHost(string! host) -> <OAuth\UriInterface>;

    /**
     * Gets the port
     *
     * @return int
     */
    public function getPort() -> int;

    /**
     * Sets the port
     *
     * @param int port
     * @return OAuth\UriInterface
     */
    public function setPort(int port) -> <OAuth\UriInterface>;

    /**
     * Gets the path 
     *
     * @return string
     */
    public function getPath() -> string;

    /**
     * Sets the path
     *
     * @param string path
     * @return OAuth\UriInterface
     */
    public function setPath(string path) -> <OAuth\UriInterface>;

    /**
     * Gets the query
     *
     * @return string
     */
    public function getQuery() -> string;

    /**
     * Sets the query
     *
     * @param string query
     * @return OAuth\UriInterface
     */
    public function setQuery(string! query) -> <OAuth\UriInterface>;

    /**
     * Adds a param to the query string.
     *
     * @param string name
     * @param string value
     * @return OAuth\UriInterface
     */
    public function addToQuery(string! name, value) -> <OAuth\UriInterface>;

    /**
     * Gets the fragment.
     *
     * @return string
     */
    public function getFragment() -> string;

    /**
     * Should return URI user info, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string
     */
    public function getUserInfo() -> string;

    /**
     * Sets the user info.
     *
     * @param string userInfo
     * @return OAuth\UriInterface
     */
    public function setUserInfo(userInfo) -> <OAuth\UriInterface>;

    /**
     * Should return the URI Authority, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string
     */
    public function getAuthority() -> string;

    /**
     * Should return the URI string, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string the URI string with user protected info masked
     */
    public function __toString() -> string;

    /**
     * Should return the URI Authority without masking protected user info data
     *
     * @return string
     */
    public function getRawAuthority() -> string;

    /**
     * Should return the URI user info without masking protected user info data
     *
     * @return string
     */
    public function getRawUserInfo() -> string;

    /**
     * Build the full URI based on all the properties
     *
     * @return string The full URI without masking user info
     */
    public function getAbsoluteUri() -> string;

    /**
     * Build the relative URI based on all the properties
     *
     * @return string The relative URI
     */
    public function getRelativeUri() -> string;

    /**
     * @return bool
     */
    public function hasExplicitTrailingHostSlash() -> boolean;

    /**
     * @return bool
     */
    public function hasExplicitPortSpecified() -> boolean;
}