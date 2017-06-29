
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

/**
 * Interface provides common methods among all OAuth services.
 */
interface ServiceInterface
{
    /**
     * Sends an authenticated API request to the path provided.
     * If the path provided is not an absolute URI, the base API Uri (service-specific) will be used.
     *
     * @param string path
     * @param string method HTTP-Method
     * @param array body
     * @param array headers Extra headers if applicable
     * @return string
     */
    public function request(string! path, string! method = "GET", body = null, var headers = null) -> string;

    /**
     * Gets the url to redirect to for authorization purposes.
     *
     * @param array params
     * @return OAuth\UriInterface
     */
    public function getAuthorizationUri(params = null) -> <OAuth\UriInterface>;

    /**
     * Gets the authorization API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAuthorizationEndpoint() -> <OAuth\UriInterface>;

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>;

    /**
     * Gets the service ID.
     * Uses for separate services in storage.
     *
     * @return string
     */
    public function getServiceId() -> string;
}