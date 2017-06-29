
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

interface ServiceInterface extends OAuth\ServiceInterface
{
	/**
     * Retrieves and stores/returns the OAuth1 request token obtained from the service.
     *
     * @return OAuth\V1\TokenInterface token
     * @throws OAuth\TokenResponseException
     */
    public function requestRequestToken() -> <OAuth\V1\TokenInterface>;

    /**
     * Retrieves and stores/returns the OAuth1 access token after a successful authorization.
     *
     * @param string token The request token from the callback.
     * @param string verifier
     * @param string tokenSecret
     * @return OAuth\V1\TokenInterface
     * @throws OAuth\TokenResponseException
     */
    public function requestAccessToken(string token, string verifier, string tokenSecret) -> <OAuth\V1\TokenInterface>;

    /**
     * @return OAuth\UriInterface
     */
    public function getRequestTokenEndpoint() -> <OAuth\UriInterface>;
}