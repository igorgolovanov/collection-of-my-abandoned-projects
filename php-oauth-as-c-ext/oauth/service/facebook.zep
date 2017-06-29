
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class Facebook extends OAuth\V2\Service
{
	/**
     * See https://developers.facebook.com/docs/reference/login/
     */
    // email scopes
    const SCOPE_EMAIL                         = "email";
    // extended permissions
    const SCOPE_READ_FRIENDLIST               = "read_friendlists";
    const SCOPE_READ_INSIGHTS                 = "read_insights";
    const SCOPE_READ_MAILBOX                  = "read_mailbox";
    const SCOPE_READ_REQUESTS                 = "read_requests";
    const SCOPE_READ_STREAM                   = "read_stream";
    const SCOPE_XMPP_LOGIN                    = "xmpp_login";
    const SCOPE_USER_ONLINE_PRESENCE          = "user_online_presence";
    const SCOPE_FRIENDS_ONLINE_PRESENCE       = "friends_online_presence";
    const SCOPE_ADS_MANAGEMENT                = "ads_management";
    const SCOPE_CREATE_EVENT                  = "create_event";
    const SCOPE_MANAGE_FRIENDLIST             = "manage_friendlists";
    const SCOPE_MANAGE_NOTIFICATIONS          = "manage_notifications";
    const SCOPE_PUBLISH_ACTIONS               = "publish_actions";
    const SCOPE_PUBLISH_STREAM                = "publish_stream";
    const SCOPE_RSVP_EVENT                    = "rsvp_event";
    // Extended Profile Properties
    const SCOPE_USER_ABOUT_ME                 = "user_about_me";
    const SCOPE_USER_ACTIVITIES               = "user_activities";
    const SCOPE_USER_BIRTHDAY                 = "user_birthday";
    const SCOPE_USER_CHECKINS                 = "user_checkins";
    const SCOPE_USER_EDUCATION_HISTORY        = "user_education_history";
    const SCOPE_USER_EVENTS                   = "user_events";
    const SCOPE_USER_GROUPS                   = "user_groups";
    const SCOPE_USER_HOMETOWN                 = "user_hometown";
    const SCOPE_USER_INTERESTS                = "user_interests";
    const SCOPE_USER_LIKES                    = "user_likes";
    const SCOPE_USER_LOCATION                 = "user_location";
    const SCOPE_USER_NOTES                    = "user_notes";
    const SCOPE_USER_PHOTOS                   = "user_photos";
    const SCOPE_USER_QUESTIONS                = "user_questions";
    const SCOPE_USER_RELATIONSHIPS            = "user_relationships";
    const SCOPE_USER_RELATIONSHIPS_DETAILS    = "user_relationship_details";
    const SCOPE_USER_RELIGION                 = "user_religion_politics";
    const SCOPE_USER_STATUS                   = "user_status";
    const SCOPE_USER_SUBSCRIPTIONS            = "user_subscriptions";
    const SCOPE_USER_VIDEOS                   = "user_videos";
    const SCOPE_USER_WEBSITE                  = "user_website";
    const SCOPE_USER_WORK                     = "user_work_history";

    const SCOPE_FRIENDS_ABOUT_ME              = "friends_about_me";
    const SCOPE_FRIENDS_ACTIVITIES            = "friends_activities";
    const SCOPE_FRIENDS_BIRTHDAY              = "friends_birthday";
    const SCOPE_FRIENDS_CHECKINS              = "friends_checkins";
    const SCOPE_FRIENDS_EDUCATION_HISTORY     = "friends_education_history";
    const SCOPE_FRIENDS_EVENTS                = "friends_events";
    const SCOPE_FRIENDS_GROUPS                = "friends_groups";
    const SCOPE_FRIENDS_HOMETOWN              = "friends_hometown";
    const SCOPE_FRIENDS_INTERESTS             = "friends_interests";
    const SCOPE_FRIENDS_LIKES                 = "friends_likes";
    const SCOPE_FRIENDS_LOCATION              = "friends_location";
    const SCOPE_FRIENDS_NOTES                 = "friends_notes";
    const SCOPE_FRIENDS_PHOTOS                = "friends_photos";
    const SCOPE_FRIENDS_QUESTIONS             = "friends_questions";
    const SCOPE_FRIENDS_RELATIONSHIPS         = "friends_relationships";
    const SCOPE_FRIENDS_RELATIONSHIPS_DETAILS = "friends_relationship_details";
    const SCOPE_FRIENDS_RELIGION              = "friends_religion_politics";
    const SCOPE_FRIENDS_STATUS                = "friends_status";
    const SCOPE_FRIENDS_SUBSCRIPTIONS         = "friends_subscriptions";
    const SCOPE_FRIENDS_VIDEOS                = "friends_videos";
    const SCOPE_FRIENDS_WEBSITE               = "friends_website";
    const SCOPE_FRIENDS_WORK                  = "friends_work_history";
    // Open Graph Permissions
    const SCOPE_USER_ACTIONS_MUSIC            = "user_actions.music";
    const SCOPE_USER_ACTIONS_NEWS             = "user_actions.news";
    const SCOPE_USER_ACTIONS_VIDEO            = "user_actions.video";
    const SCOPE_USER_ACTIONS_APP              = "user_actions:APP_NAMESPACE";
    const SCOPE_USER_GAMES_ACTIVITY           = "user_games_activity";

    const SCOPE_FRIENDS_ACTIONS_MUSIC         = "friends_actions.music";
    const SCOPE_FRIENDS_ACTIONS_NEWS          = "friends_actions.news";
    const SCOPE_FRIENDS_ACTIONS_VIDEO         = "friends_actions.video";
    const SCOPE_FRIENDS_ACTIONS_APP           = "friends_actions:APP_NAMESPACE";
    const SCOPE_FRIENDS_GAMES_ACTIVITY        = "friends_games_activity";
    //Page Permissions
    const SCOPE_MANAGE_PAGES                  = "manage_pages";

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
            let baseApiUri = new OAuth\Uri("https://graph.facebook.com/");
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
        return new OAuth\Uri("https://www.facebook.com/dialog/oauth");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://graph.facebook.com/oauth/access_token");
    }


    protected function parseAccessTokenResponse(responseBody)
    {
        var data, error, errorMsg, token, refreshToken, accessToken, lifetime;

        let data = [];
        parse_str(responseBody, data);

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

    public function getDialogUri(string dialogPath, parameters)
    {
        let credentials, consumerId, baseUrl, query;

        // todo: check parameters as array

        if !isset parameters["redirect_uri"] {
            throw new InvalidArgumentException("Redirect uri (redirect_uri) is mandatory for this request");
        }

        let credentials = this->getCredentials();
        let consumerId = credentials->getConsumerId();
        let parameters["app_id"] = consumerId;

        let baseUrl = self::WWW_URL . "dialog/" . dialogPath;
        let query = http_build_query(parameters);

        return new OAuth\Uri(baseUrl . "?" . query);
    }
}