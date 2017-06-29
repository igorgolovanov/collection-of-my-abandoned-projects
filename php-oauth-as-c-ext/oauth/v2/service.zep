
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V2;

abstract class Service extends OAuth\Service //implements OAuth\V2\ServiceInterface
{
	private scopes;

	/**
     * @param OAuth\CredentialsInterface credentials
     * @param OAuth\ClientInterface client
     * @param OAuth\TokenStorageInterface storage
     * @param array scopes
     */
    public function __construct(
        <OAuth\CredentialsInterface> credentials, 
        <OAuth\ClientInterface> client, 
        <OAuth\TokenStorageInterface> storage, 
        <OAuth\UriInterface> baseApiUri = null, 
        scopes = null,
        string serviceId = null)
    {
    	parent::__construct(credentials, client, storage, baseApiUri, serviceId);

    	if typeof scopes != "array" && typeof scopes != "null" {
    		throw new InvalidArgumentException("The scopes must be an Array");
    	}

    	let this->scopes = scopes;
    }

    /**
     * Sends an authenticated API request to the path provided.
     * If the path provided is not an absolute URI, the base API Uri (service-specific) will be used.
     *
     * @param string path
     * @param string method HTTP-Method
     * @param array body
     * @param array headers Extra headers if applicable
     * @return string
     */
    public function request(string! path, string! method = "GET", body = null, var headers = null) -> string
    {
        var uri, token, serviceId, storage, baseApiUri, endOfLife, lifetimeNeverExpires, 
            lifetimeUnknown, currentTime, errorMsg, mergedHeaders, accessToken,
            authorizationMethod, extraApiHeaders, client;

        let baseApiUri = <OAuth\UriInterface> this->getBaseApiUri();
        let storage = <OAuth\TokenStorageInterface> this->getTokenStorage();
        let serviceId = this->getServiceId();

        let token = <OAuth\V2\TokenInterface> storage->retrieveAccessToken(serviceId);
        let endOfLife = token->getEndOfLife();
        let lifetimeNeverExpires = OAuth\V2\TokenInterface::LIFETIME_NEVER_EXPIRES;
        let lifetimeUnknown = OAuth\V2\TokenInterface::LIFETIME_UNKNOWN;
        let currentTime = time();

        if endOfLife !== lifetimeNeverExpires && endOfLife !== lifetimeUnknown && currentTime > endOfLife {
            let errorMsg = "Token expired on " . date("m/d/Y", endOfLife) . " at " . date('h:i:s A', endOfLife);
            throw new OAuth\TokenExpiredException(token, errorMsg);
        }

        let authorizationMethod = this->getAuthorizationMethod();
        let accessToken = token->getAccessToken();

        switch authorizationMethod {
            case self::AUTHORIZATION_METHOD_HEADER_OAUTH:
                let headers = array_merge(["Authorization" : "OAuth " . accessToken], headers);
                break;

            case self::AUTHORIZATION_METHOD_QUERY_STRING:
                uri->addToQuery("access_token", accessToken);
                break;

            case self::AUTHORIZATION_METHOD_QUERY_STRING_V2:
                uri->addToQuery("oauth2_access_token", accessToken);
                break;

            case self::AUTHORIZATION_METHOD_QUERY_STRING_V3:
                uri->addToQuery("apikey", accessToken);
                break;

            case self::AUTHORIZATION_METHOD_HEADER_BEARER:
                let headers = array_merge(["Authorization" : "Bearer " . accessToken], headers);
                break;
        }

        let extraApiHeaders = this->getExtraApiHeaders();
        let mergedHeaders = array_merge(extraApiHeaders, headers);

        let client = <OAuth\ClientInterface> this->getClient();

        return client->retrieve(uri, body, mergedHeaders, method);
    }

    /**
     * Check the scope is valid or not.
     *
     * @param string scope
     * @return boolean
     */
    public function isValidScope(string scope) -> boolean
    {
        var ref, className, constants;

        let className = get_class(this);
        let ref = new ReflectionClass(className);
        let constants = ref->getConstants();

        return in_array(scope, constants, true);
    }

    /**
     * Gets the authorization method used for the API. See constants.
     *
     * @return int
     */
    protected function getAuthorizationMethod()
    {
        return self::AUTHORIZATION_METHOD_HEADER_OAUTH;
    }


    public function getAuthorizationUri(params = null)
    {
    	var credentials, consumerId, callbackUrl, baseParams, mergedParams, uri, key, value;

        if typeof params != "array" && typeof params != "null" {
            throw new InvalidArgumentException("The params must be an Array");
        }

    	let credentials = <OAuth\CredentialsInterface> this->getCredentials();
    	let consumerId = credentials->getConsumerId();
    	let callbackUrl = credentials->getCallbackUrl();

    	let baseParams = [
    			"type" : "web_server",
    			"client_id" : consumerId,
    			"redirect_uri" : callbackUrl,
    			"response_type" : "code"
    	];
    	if typeof params == "array" {
    		let mergedParams = array_merge(params, baseParams);
    	} else {
    		let mergedParams = baseParams;
    	}
    	
    	let mergedParams["scope"] = implode(" ", this->scopes);


    	let uri = new OAuth\Uri(); // clone this->getAuthorizationEndpoint();

    	for key, value in mergedParams {
    		uri->addToQuery(key, value);
    	}
    	return uri;
    }

    public function requestAccessToken(string code) -> <OAuth\V2\TokenInterface>
    {
    	var params, credentials, consumerId, consumerSecret, callbackUrl, 
            client, responseBody, accessTokenEndpoint, extraOAuthHeaders, 
            token, storage, serviceId;

    	let credentials = <OAuth\CredentialsInterface> this->getCredentials();
    	let consumerId = credentials->getConsumerId();
    	let consumerSecret = credentials->getConsumerSecret();
    	let callbackUrl = credentials->getCallbackUrl();
    	let client = <OAuth\ClientInterface> this->getClient();
    	let accessTokenEndpoint = this->getAccessTokenEndpoint();
    	let extraOAuthHeaders = this->getExtraOAuthHeaders();


    	let params = [
    		"code" : code,
    		"client_id" : consumerId,
    		"client_secret" : consumerSecret,
    		"redirect_uri" : callbackUrl,
    		"grant_type" : "authorization_code"
    	];

    	let responseBody = client->retrieve(accessTokenEndpoint, params, extraOAuthHeaders);
        let token = this->parseAccessTokenResponse(responseBody);

        let storage = <OAuth\TokenStorageInterface> this->getTokenStorage();
        let serviceId = this->getServiceId();

       	storage->storeAccessToken(service, token);

        return token;
    }
}