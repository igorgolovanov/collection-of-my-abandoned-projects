
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

abstract class Client implements OAuth\ClientInterface
{
	/**
	 * The maximum timeout
	 *
	 * @var int
	 */
	private timeout;

	/**
	 * The user agent
	 * 
	 * @var string
	 */
	private userAgent;

	/**
	 * The maximum number of redirects
	 *
     * @var int 
     */
    private maxRedirects = 5;

	public function __construct(string userAgent = "PHP")
	{
		let this->userAgent = userAgent;
	}


	/**
	 * Sets the timeout
	 * 
	 * @param int timeout
	 * @return OAuth\Client
	 */
	public function setTimeout(int timeout) -> <OAuth\Client>
	{
		let this->timeout = timeout;

		return this;
	}

	/**
	 * Gets the timeout
	 *
	 * @return int
	 */
	public function getTimeout() -> int
	{
		return this->timeout;
	}

	/**
	 * Gets the maximum number of redirects
	 *
	 * @return int
	 */
	public function getMaxRedirects() -> int
	{
		return this->maxRedirects;
	}

	/**
	 * Sets the maximum number of redirects
	 * 
	 * @param int redirects
	 * @return OAuth\Client
	 */
	public function setMaxRedirects(int redirects) -> <OAuth\Client>
	{
		let this->maxRedirects = redirects;

		return this;
	} 

	/**
	 * Gets the user agent
	 *
	 * @return string
	 */
	public function getUserAgent() -> string
	{
		return this->userAgent;
	}
}