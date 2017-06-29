
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

interface CredentialsInterface
{
	/**
     * Gets the callback url
	 *
	 * @return string
	 */
    public function getCallbackUrl() -> string;

	/**
	 * Gets the consumer ID
	 *
	 * @return string
	 */
    public function getConsumerId() -> string;

    /**
	 * Gets the consumer secret
	 *
	 * @return string
	 */
    public function getConsumerSecret() -> string;
}