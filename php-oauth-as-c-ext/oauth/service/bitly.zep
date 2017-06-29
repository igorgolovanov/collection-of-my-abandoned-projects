
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Bitly extends OAuth\V2\Service
{
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
            let baseApiUri = new OAuth\Uri("https://api-ssl.bitly.com/v3/");
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
        return new OAuth\Uri("https://bitly.com/oauth/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://api-ssl.bitly.com/oauth/access_token");
    }

    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_QUERY_STRING;
    }

    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg, token, accessToken;

        if typeof data != "array" {
            throw new OAuth\TokenResponseException("Unable to parse response");
        }
        if fetch error, data["error"] {
            let errorMsg = "Error in retrieving token: \"" . error . "\"";
            throw new OAuth\TokenResponseException(errorMsg);
        }

        let token = new OAuth\V2\Token();
        let accessToken = data["access_token"];

        token->setAccessToken(accessToken);
        token->setEndOfLife(OAuth\V2\Token::LIFETIME_NEVER_EXPIRES);

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }

    public function requestAccessToken(code) -> <OAuth\V1\TokenInterface>
    {
        var params, credentials, consumerId, consumerSecret, callbackUrl, 
            client, responseBody, accessTokenEndpoint, extraOAuthHeaders,
            result, serviceId, resultEncoded, token, storage;

        let credentials = this->getCredentials();
        let consumerId = credentials->getConsumerId();
        let consumerSecret = credentials->getConsumerSecret();
        let callbackUrl = credentials->getCallbackUrl();

        let params = [
            "code" : code,
            "client_id" : consumerId,
            "client_secret" : consumerSecret,
            "redirect_uri" => callbackUrl,
            "grant_type" => "authorization_code",
        ];

        let extraOAuthHeaders = this->getExtraOAuthHeaders();
        let accessTokenEndpoint = this->getAccessTokenEndpoint();

        let client = this->getClient();
        let responseBody = client->retrieve(accessTokenEndpoint, params, extraOAuthHeaders);
        let result = [];

        parse_str(responseBody, result);

        let resultEncoded = json_encode(result);
        let token = this->parseAccessTokenResponse(resultEncoded);
        let storage = this->getTokenStorage();
        let serviceId = this->getServiceId();

        storage->storeAccessToken(serviceId, token);

        return token;
    }
}