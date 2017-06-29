
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Reddit extends OAuth\V2\Service
{
	/**
     * See: http://www.reddit.com/dev/api/oauth
     */
    // User scopes
    const SCOPE_EDIT                         = "edit";
    const SCOPE_HISTORY                      = "history";
    const SCOPE_IDENTITY                     = "identity";
    const SCOPE_MYSUBREDDITS                 = "mysubreddits";
    const SCOPE_PRIVATEMESSAGES              = "privatemessages";
    const SCOPE_READ                         = "read";
    const SCOPE_SAVE                         = "save";
    const SCOPE_SUBMIT                       = "submit";
    const SCOPE_SUBSCRIBE                    = "subscribe";
    const SCOPE_VOTE                         = "vote";
    // Mod Scopes
    const SCOPE_MODCONFIG                    = "modconfig";
    const SCOPE_MODFLAIR                     = "modflair";
    const SCOPE_MODLOG                       = "modlog";
    const SCOPE_MODPOST                      = "modpost";

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
            let baseApiUri = new OAuth\Uri("https://oauth.reddit.com");
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
        return new OAuth\Uri('https://ssl.reddit.com/api/v1/authorize');
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri('https://ssl.reddit.com/api/v1/access_token');
    }

    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_HEADER_BEARER;
    }


    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg, token, refreshToken, accessToken, lifetime;

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
        let lifetime = data["expires_in"];

        token->setAccessToken(accessToken);
        token->setLifeTime(lifetime);

        if fetch refreshToken, data["refresh_token"] {
            token->setRefreshToken(refreshToken);
            unset data["refresh_token"];
        }

        unset data["access_token"];
        unset data["expires_in"];

        token->setExtraParams(data);

        return token;
    }

    protected function getExtraOAuthHeaders()
    {
        var credentials, consumerId, consumerSecret, 
            consumerStr, consumerStrEncoded;

        let credentials = <OAuth\CredentialsInterface> this->getCredentials();
        let consumerId = getConsumerId();
        let consumerSecret = getConsumerSecret();

        let consumerStr = consumerId . ":" . consumerSecret;
        let consumerStrEncoded = base64_encode(consumerStr)

        return [
            "Authorization" : "Basic " . consumerStrEncoded
        ];
    }
}