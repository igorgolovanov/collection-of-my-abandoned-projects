
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Heroku extends OAuth\V2\Service
{
	/**
     * See: https://devcenter.heroku.com/articles/oauth#scopes
     */
    const SCOPE_GLOBAL          = "global";
    const SCOPE_IDENTITY        = "identity";
    const SCOPE_READ            = "read";
    const SCOPE_WRITE           = "write";
    const SCOPE_READ_PROTECTED  = "read-protected";
    const SCOPE_WRITE_PROTECTED = "write-protected";

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
            let baseApiUri = new OAuth\Uri("https://api.heroku.com/");
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
        return new OAuth\Uri("https://id.heroku.com/oauth/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://id.heroku.com/oauth/token");
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
        if fetch error, data["error_description"] || fetch error, data["error"] {
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
        return ["Accept" : "application/vnd.heroku+json; version=3"];
    }

    protected function getExtraApiHeaders()
    {
        return [
            "Accept" : "application/vnd.heroku+json; version=3",
            "Content-Type" : "application/json"
        ];
    }
}