
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\TokenStorage;

class Session implements OAuth\TokenStorageInterface
{
	private sessionNamespace;

	public function __construct(boolean sessionStart = true, string! sessionNamespace = "oauth")
	{
		let this->sessionNamespace = sessionNamespace;

		if sessionStart {
			session_start();
		}
	}

	/**
     * @param string service
     *
     * @return TokenInterface
     *
     * @throws OAuth\TokenNotFoundException
     */
    public function retrieveAccessToken(string service) -> <OAuth\Token>
    {

    }

    /**
     * @param string service
     * @param OAuth\TokenInterface token
     *
     * @return OAuth\TokenStorage\Session
     */
    public function storeAccessToken(string service, <OAuth\TokenInterface> token) -> <OAuth\TokenStorage\Session>
    {

    }

    /**
     * @param string service
     *
     * @return boolean
     */
    public function hasAccessToken(string! service) -> boolean
    {

    }

    /**
     * Delete the users token. Aka, log out.
     *
     * @param string service
     *
     * @return OAuth\TokenStorage\Session
     */
    public function clearToken(string! service) -> <OAuth\TokenStorage\Session>
    {

    }

    /**
     * Delete *ALL* user tokens. Use with care. Most of the time you will likely
     * want to use clearToken() instead.
     *
     * @return OAuth\TokenStorage\Session
     */
    public function clearAllTokens() -> <OAuth\TokenStorage\Session>
    {

    }
}