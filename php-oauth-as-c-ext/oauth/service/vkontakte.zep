
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class VKontakte extends OAuth\V2\Service
{
	/**
     * See: http://vk.com/dev/permissions
     */
    const SCOPE_NOTIFY        = "notify";
    const SCOPE_FRIENDS       = "friends";
    const SCOPE_PHOTOS        = "photos";
    const SCOPE_AUDIO         = "audio";
    const SCOPE_VIDEO         = "video";
    const SCOPE_DOCS          = "docs";
    const SCOPE_NOTES         = "notes";
    const SCOPE_PAGES         = "pages";
    const SCOPE_APP_LINK      = "";
    const SCOPE_STATUS        = "status";
    const SCOPE_OFFERS        = "offers";
    const SCOPE_QUESTIONS     = "questions";
    const SCOPE_WALL          = "wall";
    const SCOPE_GROUPS        = "groups";
    const SCOPE_MESSAGES      = "messages";
    const SCOPE_NOTIFICATIONS = "notifications";
    const SCOPE_STATS         = "stats";
    const SCOPE_ADS           = "ads";
    const SCOPE_OFFLINE       = "offline";
    const SCOPE_NOHTTPS       = "nohttps";

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
            let baseApiUri = new OAuth\Uri("https://api.vk.com/method/");
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
        return new OAuth\Uri("https://oauth.vk.com/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://oauth.vk.com/access_token");
    }

    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg accessToken, refreshToken, token, lifetime;

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
        let lifetime = data["expires_in"];

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