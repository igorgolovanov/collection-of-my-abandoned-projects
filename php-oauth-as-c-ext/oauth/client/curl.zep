
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Client;

class Curl extends OAuth\Client
{
	
	/**
	 * Retrive 
	 *
	 * @param OAuth\UriInterface endpoint
	 * @param mixed requestBody
	 * @param array headers
	 * @param string method
	 *
	 * @return string
     *
     * @throws OAuth\TokenResponseException
	 */
	public function retrieve(<OAuth\UriInterface> endpoint, requestBody, headers = null, string! method = null) -> string
	{

	}

}