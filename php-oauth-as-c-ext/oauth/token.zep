
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

abstract class Token implements OAuth\TokenInterface
{
	private accessToken;
	private refreshToken;
	private endOfLife; 


	public function __construct(string! accessToken, string! refreshToken, int lifetime)
	{
		this->setAccessToken(accessToken);
		this->setRefreshToken(refreshToken);
		this->setLifetime(lifetime);
	}

	/**
	 * Gets the access token.
	 *
	 * @return string
	 */
	public function getAccessToken() -> string
	{
		return this->accessToken;
	}

	/**
	 * Sets the access token.
	 *
     * @param string token
     * @return OAuth\Token
	 */
    public function setAccessToken(string! token) -> <OAuth\Token>
    {
    	let this->accessToken = token;
    	
    	return this;
    }

	/**
	 * Gets the refresh token.
	 *
	 * @return string
	 */
	public function getRefreshToken() -> string
	{
		return this->refreshToken;
	}

	/**
	 * Sets the refresh token.
	 *
     * @param string token
     * @return OAuth\Token
	 */
    public function setRefreshToken(string! token) -> <OAuth\Token>
    {
    	let this->refreshToken = token;

    	return this;
    }

    /**
	 * Gets the end of token life
     *
	 * @return int
	 */
    public function getEndOfLife() -> int
    {
    	return this->endOfLife;
    }

    /**
	 * Sets the end of token life
     *
	 * @param int endOfLife
     * @return OAuth\Token
	 */
    public function setEndOfLife(int endOfLife) -> <OAuth\Token>
    {
    	let this->endOfLife = endOfLife;

    	return this;
    }

    /**
	 * Sets the token lifetime.
     *
	 * @param int lifetime
     * @return OAuth\Token
	 */
    public function setLifetime(int lifetime) -> <OAuth\Token>
    {
    	// var lifetimeUnknown, lifetimeNeverExpires, currentTime;

    	// let lifetimeNeverExpires = OAuth\TokenInterface::LIFETIME_NEVER_EXPIRES;
    	// let lifetimeUnknown = OAuth\TokenInterface::LIFETIME_UNKNOWN;

    	// if lifetime === 0 || lifetime == lifetimeNeverExpires || lifetime == lifetimeUnknown {
    	// 	this->setEndOfLife(lifetimeNeverExpires);
    	// } else {
    	// 	let currentTime = time();
    	// 	let lifetime += currentTime;
    	// 	this->setEndOfLife(lifetime);
    	// }
    	return this;
    }
}