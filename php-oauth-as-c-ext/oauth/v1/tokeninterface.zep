
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

interface TokenInterface extends OAuth\TokenInterface
{
	/**
	 * Gets the secret for access token
	 *
	 * @return string
	 */
    public function getAccessTokenSecret() -> string;

    /**
	 * Sets the secret for access token
	 *
	 * @param string tokenSecret Secret for access token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setAccessTokenSecret(string tokenSecret) -> <OAuth\V1\TokenInterface>;

    /**
	 * Gets the secret for request token
	 *
	 * @return string
	 */
    public function getRequestTokenSecret() -> string;

    /**
	 * Sets the secret for request token
	 *
	 * @param string tokenSecret Secret for request token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setRequestTokenSecret(string tokenSecret) -> <OAuth\V1\TokenInterface>;

    /**
	 * Gets the request token.
	 *
	 * @return string
	 */
    public function getRequestToken() -> string;

    /**
	 * Sets the request token.
	 *
	 * @param string token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setRequestToken(string token) -> <OAuth\V1\TokenInterface>;
}