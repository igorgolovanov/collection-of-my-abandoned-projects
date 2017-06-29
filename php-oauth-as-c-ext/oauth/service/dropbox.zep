
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class DropBox extends OAuth\V2\Service
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
            let baseApiUri = new OAuth\Uri("https://api.dropbox.com/1/");
        }
        parent::__construct(credentials, client, storage, scopes, baseApiUri);
    }

    public function getAuthorizationUri(params = null)
    {
        let builtInParams, mergedParams, credentials, consumerId, 
            callbackUrl, scopes, uri, key, value;

        let credentials = <OAuth\CredentialsInterface> this->getCredentials();
        let consumerId = credentials->getConsumerId();
        let callbackUrl = credentials->getCallbackUrl();

        let builtInParams = [
            "client_id" : consumerId,
            "redirect_uri" : callbackUrl,
            "response_type" : "code"
        ];

        if !empty params {
            let mergedParams = array_merge(params, builtInParams);
        } else {
            let mergedParams = builtInParams;
        }

        let scopes = this->getScopes();
        let mergedParams["scope"] = implode(" ", scopes);
        
        // todo: clone
        //let uri = clone this->getAuthorizationEndpoint();
        let uri = new OAuth\Uri();
        
        for key, value in mergedParams {
            url->addToQuery(key, value);
        }

        return uri;
    }

    /**
     * Gets the authorization API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAuthorizationEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://www.dropbox.com/1/oauth2/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://api.dropbox.com/1/oauth2/token");
    }

    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_QUERY_STRING;
    }

    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg, token, refreshToken, accessToken;

        let data = json_decode(responseBody, true);

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

        if fetch refreshToken, data["refresh_token"] {
            token->setRefreshToken(refreshToken);
            unset data["refresh_token"];
        }

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }
}