
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class LinkedIn extends OAuth\V2\Service
{
	/**
     * See: http://developer.linkedin.com/documents/authentication#granting
     */
    const SCOPE_R_BASICPROFILE      = "r_basicprofile";
    const SCOPE_R_FULLPROFILE       = "r_fullprofile";
    const SCOPE_R_EMAILADDRESS      = "r_emailaddress";
    const SCOPE_R_NETWORK           = "r_network";
    const SCOPE_R_CONTACTINFO       = "r_contactinfo";
    const SCOPE_RW_NUS              = "rw_nus";
    const SCOPE_RW_COMPANY_ADMIN    = "rw_company_admin";
    const SCOPE_RW_GROUPS           = "rw_groups";
    const SCOPE_W_MESSAGES          = "w_messages";

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
            let baseApiUri = new OAuth\Uri("https://api.linkedin.com/v1/");
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
        return new OAuth\Uri("https://www.linkedin.com/uas/oauth2/authorization");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://www.linkedin.com/uas/oauth2/accessToken");
    }

    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_QUERY_STRING_V2;
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
}