
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

class Signature implements OAuth\V1\SignatureInterface
{/**
* @var Credentials
*/
    private credentials;

    /**
* @var string
*/
    private algorithm;

    /**
* @var string
*/
    private tokenSecret = null;

    /**
	 * @param OAuth\CredentialsInterface credentials
	 */
    public function __construct(<OAuth\CredentialsInterface> credentials)
    {
        let this->credentials = credentials;
    }

	/**
     * Sets the algorithm for hashing
	 * 
     * @param string algorithm
	 */
    public function setHashingAlgorithm(string algorithm) -> <OAuth\V1\Signature>
    {
    	let this->algorithm = algorithm;
    	
    	return this;
    }

    /**
     * Sets the secret for token
	 * 
	 * @param string tokenSecret
	 */
    public function setTokenSecret(string tokenSecret) -> <OAuth\V1\Signature>
    {
    	let this->tokenSecret = tokenSecret;

    	return this;
    }

    /**
     * Gets the secret for token
     *
     * @return string
     */
    protected function getTokenSecret() -> string
    {
    	return this->tokenSecret;
    }

    /**
     * Gets the signature
     *
	 * @param OAuth\UriInterface uri
	 * @param array params
	 * @param string method
	 *
	 * @return string
	 */
    public function getSignature(<OAuth\UriInterface> uri, params, string method = "POST") -> string
    {
		var signature, signatureData, signatureString, signatureStringEncoded, query, 
			queryStringData, queryStringKey, queryStringValue, queryStringKeyEncoded, 
			queryStringValueEncoded, scheme, authority, path, hasExplicitTrailingHostSlash, 
			baseUri, baseUriEncoded, dataString, dataHash;

		let query = uri->getQuery();
		let queryStringData = [];
		let signatureData = [];

		/**
         * Throw exceptions if bad parameters are passed
         */
        if typeof params != "array" {
        	throw new InvalidArgumentException("The params must be an Array");
        }

		let queryStringData = array_merge(queryStringData, params);

		parse_str(query, queryStringData);

		for queryStringKey, queryStringValue in queryStringData {
			let queryStringKeyEncoded = rawurlencode(queryStringKey);
			let queryStringValueEncoded = rawurlencode(queryStringValue);
			let signatureData[queryStringKeyEncoded] = queryStringValueEncoded;
		}

		ksort(signatureData);

		let scheme = uri->getScheme();
		let authority = uri->getRawAuthority();
		let path = uri->getPath();
		let hasExplicitTrailingHostSlash = uri->hasExplicitTrailingHostSlash();

		let baseUri = scheme . "://" . authority;

		if path === "/" {
			if hasExplicitTrailingHostSlash {
				let baseUri .= "/";
			}
		} else {
			let baseUri .= path;
		}

		let baseUriEncoded = rawurlencode(baseUri);
		let signatureString = this->buildSignatureString(signatureData);
		let signatureStringEncoded = rawurlencode(signatureString);

		let dataString = strtoupper(method);
		let dataString = dataString . "&" . baseUriEncoded . "&" . signatureStringEncoded;
		
		let dataHash = this->hash(dataString);
		let signature = base64_encode(dataHash);

		return signature;
    }

    /**
     * Build signature string from array.
     *
     * @param array signatureData
     * @return string
     */
    protected function buildSignatureString(signatureData) -> string
    {
    	var signatureString, delimiter, key, value;

    	/**
         * Throw exceptions if bad parameters are passed
         */
        if typeof signatureData != "array" {
        	throw new InvalidArgumentException("The signatureData must be an Array");
        }

    	let signatureString = "";
    	let delimiter = "";

    	for key, value in signatureData {
    		let signatureString = delimiter . key . "=" . value;
    		let delimiter = "&";
    	}

    	return signatureString;
    }

    /**
     * Get hashing algorithm
     *
     * @return string
     */
    protected function getHashingAlgorithm() -> string
    {
    	return this->algorithm;
    }

    /**
	 * @return OAuth\CredentialsInterface
	 */
    protected function getCredentials() -> <OAuth\CredentialsInterface>
    {
    	return this->credentials;
    }

    /**
   	 * Gets the signing key
	 *
   	 * @return string
	 */
    protected function getSigningKey() -> string
    {
    	var signingKey, credentials, consumerSecret, tokenSecret;

    	let credentials = <OAuth\CredentialsInterface> this->getCredentials();
    	let consumerSecret = credentials->getConsumerSecret();
    	let tokenSecret = this->getTokenSecret();
    	let signingKey = rawurlencode(consumerSecret) . "&";

    	if !empty tokenSecret {
    		let signingKey .= rawurlencode(tokenSecret);
    	}

    	return signingKey;
    }

    /**
     * Hash
     *
     * @param string data 
     * @return string
     */
    protected function hash(string data) -> string
    {
    	var algorithm, hash, signingKey;

    	let algorithm = this->getHashingAlgorithm();
    	let algorithm = strtoupper(algorithm);

    	switch algorithm {

    		case "HMAC-SHA1":
    			let signingKey = this->getSigningKey();
    			let hash = hash_hmac("sha1", data, signingKey, true);
    			break;

    		default:
    			throw new OAuth\V1\UnsupportedHashAlgorithmException(algorithm, "Unsupported hashing algorithm (" . algorithm . ") used.");
    	}
    	return hash;
    }
}