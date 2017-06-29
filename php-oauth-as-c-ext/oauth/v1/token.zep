
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

class Token extends OAuth\Token implements OAuth\V1\TokenInterface
{
	private accessTokenSecret;
	private requestTokenSecret;
	private requestToken;

	/**
	 * Gets the secret for access token
	 *
	 * @return string
	 */
    public function getAccessTokenSecret() -> string
    {
    	return this->accessTokenSecret;
    }

    /**
	 * Sets the secret for access token
	 *
	 * @param string tokenSecret Secret for access token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setAccessTokenSecret(string tokenSecret) -> <OAuth\V1\TokenInterface>
    {
    	let this->accessTokenSecret = tokenSecret;

    	return this;
    }

    /**
	 * Gets the secret for request token
	 *
	 * @return string
	 */
    public function getRequestTokenSecret() -> string
    {
    	return this->requestTokenSecret;
    }

    /**
	 * Sets the secret for request token
	 *
	 * @param string tokenSecret Secret for request token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setRequestTokenSecret(string tokenSecret) -> <OAuth\V1\TokenInterface>
    {
    	let this->requestTokenSecret = tokenSecret;

    	return this;
    }

    /**
	 * Gets the request token.
	 *
	 * @return string
	 */
    public function getRequestToken() -> string
    {
    	return this->requestToken;
    }

    /**
	 * Sets the request token.
	 *
	 * @param string token
	 * @return OAuth\V1\TokenInterface
	 */
    public function setRequestToken(string token) -> <OAuth\V1\TokenInterface>
    {
    	let this->requestToken = token;

    	return this;
    }
}