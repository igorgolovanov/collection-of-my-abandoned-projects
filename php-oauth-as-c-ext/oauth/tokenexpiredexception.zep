
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

class TokenExpiredException extends Exception implements OAuth\ExceptionInterface
{
	/**
	 * Token
	 *
	 * @var string
	 */
	private token;

	/**
	 * @param string token Expired token
	 * @param string message
	 * @param int code
	 * @param Exception previous
	 */
	public function __construct (string token, string message = "", int code = 0, <Exception> previous = null)
	{
		parent::__construct (message, code, previous);

		let this->token = token;
	}

	/**
	 * Gets the expired token
	 *
	 * @return string
	 */
	public function getToken() -> string
	{
		return this->token;
	}
}