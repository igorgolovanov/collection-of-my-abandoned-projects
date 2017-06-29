
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Foursquare extends OAuth\V2\Service
{
    const API_VERSION = "20130829";

    /**
     * Class constructor.
     *
     * @param OAuth\CredentialsInterface credentials Credentials
     * @param OAuth\ClientInterface client Client
     * @param OAuth\TokenStorageInterface storage Token storage
     * @param array scopes Scopes
     * @param OAuth\UriInterface baseApiUri Base API Uri.
     * @param string serviceId Service ID
     */
    public function __construct(
        <OAuth\CredentialsInterface> credentials,
        <OAuth\ClientInterface> client,
        <OAuth\TokenStorageInterface> storage,
        scopes = null,
        <OAuth\UriInterface> baseApiUri = null,
        string serviceId = null
    ) {
        if  empty baseApiUri {
            let baseApiUri = new OAuth\Uri("https://api.foursquare.com/v2/");
        }
        parent::__construct(credentials, client, storage, scopes, baseApiUri);
    }
    
    /**
     * Gets the authorization API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAuthorizationEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://foursquare.com/oauth2/authenticate");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://foursquare.com/oauth2/access_token");
    }

    protected function parseAccessTokenResponse(string responseBody) -> <OAuth\V2\Token>
    {
    	var data, token, error, accessToken;

    	let data = json_decode(responseBody, true);

    	if typeof data == "null" || typeof data != "array" {
    		throw new OAuth\TokenResponseException("Unable to parse response");
    	}
    	if fetch error, data {
    		let error = "Error in retrieving token: \"" . error . "\"";
    		throw new OAuth\TokenResponseException(error);
    	}
    	let token = new OAuth\V2\Token();
    	let accessToken = data["access_token"];

    	token->setAccessToken(accessToken);
        token->setEndOfLife(OAuth\V2\Token::LIFETIME_NEVER_EXPIRES);

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }

    public function request(string path, string method = "GET", string! body = null, headers = null)
    {
    	var uri, baseApiUri, apiVersion;

    	let apiVersion = this->apiVersion;
    	let baseApiUri = <OAuth\UriInterface> this->getBaseApiUri();
    	let baseApiUri .= path;

    	let uri = new OAuth\Uri(baseApiUri);

    	uri->addToQuery("v", self::API_VERSION);

        return parent::request(uri, method, body, headers);
    }
}
