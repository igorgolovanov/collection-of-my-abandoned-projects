
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;


class UnsupportedHashAlgorithmException extends Exception implements OAuth\ExceptionInterface
{
/**
	 * Algorithm
	 *
	 * @var string
	 */
	private algorithm;

	/**
	 * @param string algorithm Hash algorithm
	 * @param string message
	 * @param int code
	 * @param Exception previous
	 */
	public function __construct (string algorithm, string message = "", int code = 0, <Exception> previous = null)
	{
		parent::__construct (message, code, previous);

		let this->algorithm = algorithm;
	}

	/**
	 * Gets the hash algorithm
	 *
	 * @return string
	 */
	public function getAlgorithm() -> string
	{
		return this->algorithm;
	}
}