
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class GitHub extends OAuth\V2\Service
{
	/**
     * See http://developer.github.com/v3/oauth/ for definitions.
     */
    const SCOPE_READONLY = "";
    const SCOPE_USER = "user";
    const SCOPE_USER_EMAIL = "user:email";
    const SCOPE_USER_FOLLOW = "user:follow";
    const SCOPE_PUBLIC_REPO = "public_repo";
    const SCOPE_REPO = "repo";
    const SCOPE_REPO_STATUS = "repo:status";
    const SCOPE_DELETE_REPO = "delete_repo";
    const SCOPE_NOTIFICATIONS = "notifications";
    const SCOPE_GIST = "gist";

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
            let baseApiUri = new OAuth\Uri("https://api.github.com/");
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
        return new OAuth\Uri("https://github.com/login/oauth/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://github.com/login/oauth/access_token");
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
        token->setEndOfLife(OAuth\V2\Token::LIFETIME_NEVER_EXPIRES);

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }

    protected function getExtraOAuthHeaders()
    {
        return ["Accept" : "application/json"];
    }

    protected function getExtraApiHeaders()
    {
        return ["Accept" : "application/vnd.github.beta+json"];
    }
}