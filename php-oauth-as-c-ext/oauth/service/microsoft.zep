
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Microsoft extends OAuth\V2\Service
{
	const SCOPE_BASIC 				= "wl.basic";
    const SCOPE_OFFLINE 			= "wl.offline_access";
    const SCOPE_SIGNIN 				= "wl.signin";
    const SCOPE_BIRTHDAY 			= "wl.birthday";
    const SCOPE_CALENDARS 			= "wl.calendars";
    const SCOPE_CALENDARS_UPDATE 	= "wl.calendars_update";
    const SCOPE_CONTACTS_BIRTHDAY 	= "wl.contacts_birthday";
    const SCOPE_CONTACTS_CREATE 	= "wl.contacts_create";
    const SCOPE_CONTACTS_CALENDARS 	= "wl.contacts_calendars";
    const SCOPE_CONTACTS_PHOTOS 	= "wl.contacts_photos";
    const SCOPE_CONTACTS_SKYDRIVE 	= "wl.contacts_skydrive";
    const SCOPE_EMAILS 				= "wl.emails";
    const SCOPE_EVENTS_CREATE 		= "wl.events_create";
    const SCOPE_MESSENGER 			= "wl.messenger";
    const SCOPE_PHONE_NUMBERS 		= "wl.phone_numbers";
    const SCOPE_PHOTOS 				= "wl.photos";
    const SCOPE_POSTAL_ADDRESSES 	= "wl.postal_addresses";
    const SCOPE_SHARE 				= "wl.share";
    const SCOPE_SKYDRIVE 			= "wl.skydrive";
    const SCOPE_SKYDRIVE_UPDATE 	= "wl.skydrive_update";
    const SCOPE_WORK_PROFILE 		= "wl.work_profile";
    const SCOPE_APPLICATIONS 		= "wl.applications";
    const SCOPE_APPLICATIONS_CREATE = "wl.applications_create";

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
            let baseApiUri = new OAuth\Uri("https://apis.live.net/v5.0/");
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
        return new OAuth\Uri("https://login.live.com/oauth20_authorize.srf");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://login.live.com/oauth20_token.srf");
    }

    public function getAuthorizationMethod()
    {
        
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