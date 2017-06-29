
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Yammer extends OAuth\V2\Service
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
            let baseApiUri = new OAuth\Uri("https://www.yammer.com/api/v1/");
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
        return new OAuth\Uri("https://www.yammer.com/dialog/oauth");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://www.yammer.com/oauth2/access_token.json");
    }

    public function getAuthorizationMethod()
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

        let token = new OAuth\V2\Token(accessToken);

        let accessToken = data["access_token"]["token"];
        let lifetime = data["access_token"]["expires_at"];

        token->setAccessToken(accessToken);
        token->setLifeTime(lifetime);

        if fetch refreshToken, data["refresh_token"] {
            token->setRefreshToken(refreshToken);
            unset data["refresh_token"];
        }

        unset data["access_token"];

        token->setExtraParams(data);

        return token;
    }
}