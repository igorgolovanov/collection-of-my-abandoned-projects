
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

interface SignatureInterface
{
	/**
     * Sets the algorithm for hashing
	 * 
     * @param string algorithm
	 */
    public function setHashingAlgorithm(string algorithm) -> <OAuth\V1\SignatureInterface>;

    /**
     * Sets the secret for token
	 * 
	 * @param string tokenSecret
	 */
    public function setTokenSecret(string tokenSecret) -> <OAuth\V1\SignatureInterface>;

    /**
     * Gets the signature.
     *
	 * @param OAuth\UriInterface uri
	 * @param array params
	 * @param string method
	 * @return string
	 */
    public function getSignature(<OAuth\UriInterface> uri, params, string! method = "POST") -> string;
}