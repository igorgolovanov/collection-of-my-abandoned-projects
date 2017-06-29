
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

interface TokenInterface
{
	const LIFETIME_UNKNOWN = -9001;
	const LIFETIME_NEVER_EXPIRES = -9002;
	
	/**
	 * Gets the access token.
	 *
	 * @return string
	 */
	public function getAccessToken() -> string;

	/**
	 * Sets the access token
	 *
     * @param string token
     * @return OAuth\TokenInterface
	 */
    public function setAccessToken(string! token) -> <OAuth\TokenInterface>;

	/**
	 * Gets the refresh token
	 *
	 * @return string
	 */
	public function getRefreshToken() -> string;

	/**
	 * Sets the refresh token
	 *
     * @param string token
     * @return OAuth\TokenInterface
	 */
    public function setRefreshToken(string! token) -> <OAuth\TokenInterface>;

    /**
	 * Gets the end of token life
     *
	 * @return int
	 */
    public function getEndOfLife() -> int;

    /**
	 * Sets the end of token life
     *
	 * @param int endOfLife
     * @return OAuth\TokenInterface
	 */
    public function setEndOfLife(int endOfLife) -> <OAuth\TokenInterface>;

    /**
	 * Sets the token lifetime.
     *
	 * @param int lifetime
     * @return OAuth\TokenInterface
	 */
    public function setLifetime(int lifetime) -> <OAuth\TokenInterface>;
}