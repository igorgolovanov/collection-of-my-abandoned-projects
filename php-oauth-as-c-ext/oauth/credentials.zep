
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

class Credentials implements OAuth\CredentialsInterface
{
	private consumerId;
	private consumerSecret;
	private callbackUrl;

	/**
	 * @param string consumerId
	 * @param string consumerSecret
	 * @param string callbackUrl
	 */	
	public function __construct(string consumerId, string consumerSecret, string! callbackUrl)
	{
		let this->consumerId = consumerId;
		let this->consumerSecret = consumerSecret;
		let this->callbackUrl = callbackUrl;
	}

	/**
     * Gets the callback url
	 *
	 * @return string
	 */
	public function getCallbackUrl() -> string
	{
		return this->callbackUrl;
	}

	/**
	 * Gets the consumer ID
	 *
	 * @return string
	 */
    public function getConsumerId() -> string
	{
		return this->consumerId;
	}

    /**
	 * Gets the consumer secret
	 *
	 * @return string
	 */
    public function getConsumerSecret() -> string
	{
		return this->consumerSecret;
	}
}