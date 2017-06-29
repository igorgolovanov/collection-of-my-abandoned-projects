
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class RunKeeper extends OAuth\V2\Service
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
            let baseApiUri = new OAuth\Uri("https://api.runkeeper.com/");
        }
        parent::__construct(credentials, client, storage, scopes, baseApiUri);
    }

    public function getAuthorizationUri(params = null)
    {
        var mergedParams, builtInParams, credentials, consumerId, 
            callbackUrl, scopes, key, value, uri, scopesStr;
        // todo: check params is array

        let credentials = <OAuth\CredentialsInterface> this->getCredentials();
        let consumerId = credentials->getConsumerId();
        let callbackUrl = credentials->getCallbackUrl();

        let builtInParams = [
            "client_id" : consumerId,
            "redirect_uri" : callbackUrl,
            "response_type" : "code",
        ];

        if empty params {
            let mergedParams = builtInParams;
        } else {
            let mergedParams = array_merge(params, builtInParams);
        }
        let scopes = this->getScopes();
        let scopesStr = implode(" ", scopes);
        let mergedParams["scope"] = scopesStr;

        // todo: clone
        //let uri = clone this->getAuthorizationEndpoint();
        let uri = new OAuth\Uri();

        for key, value in mergedParams {
            uri->addToQuery(key, value);
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
        return new OAuth\Uri("https://runkeeper.com/apps/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://runkeeper.com/apps/token");
    }

    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_HEADER_BEARER;
    }

    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg, token, accessToken;

        let data = json_decode(responseBody, true);

        if typeof data != "array" {
            throw new OAuth\TokenResponseException("Unable to parse response");
        }
        if fetch error, data["error"] {
            let errorMsg = "Error in retrieving token: \"" . error . "\"";
            throw new OAuth\TokenResponseException(errorMsg);
        }

        let accessToken = data["access_token"];
        let token = new OAuth\V2\Token(accessToken);

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }
}