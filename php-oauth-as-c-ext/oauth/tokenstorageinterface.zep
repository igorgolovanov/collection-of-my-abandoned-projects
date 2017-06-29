
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

interface TokenStorageInterface
{
	/**
     * Retrive access token.
     *
     * @param string serviceId Service ID
     * @return TokenInterface
     * @throws OAuth\TokenNotFoundException
     */
    public function retrieveAccessToken(string serviceId) -> <OAuth\TokenInterface>;

    /**
     * Store access token.
     *
     * @param string serviceId Service ID
     * @param OAuth\TokenInterface token
     * @return OAuth\TokenStorageInterface
     */
    public function storeAccessToken(string serviceId, <OAuth\TokenInterface> token) -> <OAuth\TokenStorageInterface>;

    /**
     * Check exists access token.
     *
     * @param string serviceId Service ID
     * @return boolean
     */
    public function hasAccessToken(string! serviceId) -> boolean;

    /**
     * Delete the users token. Aka, log out.
     *
     * @param string serviceId Service ID
     * @return OAuth\TokenStorageInterface
     */
    public function clearToken(string! serviceId) -> <OAuth\TokenStorageInterface>;

    /**
     * Delete *ALL* user tokens. Use with care. Most of the time you will likely
     * want to use clearToken() instead.
     *
     * @return OAuth\TokenStorageInterface
     */
    public function clearAllTokens() -> <OAuth\TokenStorageInterface>;
}