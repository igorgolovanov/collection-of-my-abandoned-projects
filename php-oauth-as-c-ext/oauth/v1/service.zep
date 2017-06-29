
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V1;

abstract class Service extends OAuth\Service // implements OAuth\V1\ServiceInterface
{
    /**
     * Signature
     *
     * @var OAuth\V1\SignatureInterface
     */
    private signature;

    /**
     * Class constructor.
     *
     * @param OAuth\CredentialsInterface credentials Credentials
     * @param OAuth\ClientInterface client Client
     * @param OAuth\TokenStorageInterface storage Token storage
     * @param OAuth\SignatureInterface signature Signature
     * @param OAuth\UriInterface baseApiUri Base API Uri.
     * @param string serviceId Service ID
     */
    public function __construct(
        <OAuth\CredentialsInterface> credentials,
        <OAuth\ClientInterface> client,
        <OAuth\TokenStorageInterface> storage,
        <OAuth\SignatureInterface> signature,
        <OAuth\UriInterface> baseApiUri = null,
        string serviceId = null
    ) {
        var signatureMethod;

        parent::__construct(credentials, client, storage, baseApiUri, serviceId);

        let this->signature = signature;
        let signatureMethod = this->getSignatureMethod();

        signature->setHashingAlgorithm(signatureMethod);
    }

    /**
     * Retrieves and stores/returns the OAuth1 request token obtained from the service.
     *
     * @return OAuth\TokenInterface token
     * @throws TokenResponseException
     */
    public function requestRequestToken() -> <OAuth\TokenInterface>
    {
        var header, headerValue, headers, extraHeaders, storage, token, responseBody, 
            requestTokenEndpoint, client, serviceId;

        let headerValue = this->buildAuthorizationHeaderForTokenRequest();
        let header = ["Authorization" : headerValue];

        let extraHeaders = this->getExtraOAuthHeaders();
        let headers = array_merge(header, extraHeaders);

        let client = <OAuth\ClientInterface> this->getClient();
        let responseBody = client->retrieve(requestTokenEndpoint, [], headers);
        let token = <OAuth\V1\TokenInterface> this->parseRequestTokenResponse(responseBody);

        let storage = <OAuth\TokenStorageInterface> this->getTokenStorage();
        let serviceId = this->getServiceId();

        storage->storeAccessToken(serviceId, token);

        return token;
    }

    /**
     * Gets the url to redirect to for authorization purposes.
     *
     * @param array params
     * @return OAuth\UriInterface
     */
    public function getAuthorizationUri(params = null) -> <OAuth\UriInterface>
    {
        var uri, key, value;

        if typeof params != "array" && typeof params != "null" {
            throw new InvalidArgumentException("The params must be an Array");
        }
        // todo: clone object
        //let uri = clone this->getAuthorizationEndpoint();
        let uri = new OAuth\Uri();

        if typeof params == "array" {
            for key, value in params {
                uri->addToQuery(key, value);
            }
        }

        return uri;
    }

    /**
     * Retrieves and stores/returns the OAuth1 access token after a successful authorization.
     *
     * @param string token The request token from the callback.
     * @param string verifier
     * @param string tokenSecret
     * @return OAuth\V1\TokenInterface
     * @throws OAuth\TokenResponseException
     */
    public function requestAccessToken(string token, string verifier, string tokenSecret) -> <OAuth\V1\TokenInterface>
    {
        var storage, signature, storedRequestToken, serviceId, client, tokenObj, 
            accessTokenEndpoint, bodyParams, headers, extraAuthHeaders, extraOAuthHeaders, 
            authHeaders, authHeaderForApi, accessToken;

        let storage = <OAuth\TokenStorageInterface> this->getTokenStorage();
        let serviceId = this->getServiceId();
        let signature = <OAuth\V1\SignatureInterface> this->getSignature();
        let accessTokenEndpoint = this->getAccessTokenEndpoint();

        if typeof tokenSecret == "null" {
            let storedRequestToken = <OAuth\V1\TokenInterface> storage->retrieveAccessToken(serviceId);
            let tokenSecret = storedRequestToken->>getRequestTokenSecret();
        }

        signature->setTokenSecret(tokenSecret);

        let extraAuthHeaders = ["oauth_token" : token];
        let bodyParams = ["oauth_verifier" : verifier];
        let accessToken = storage->retrieveAccessToken(serviceId);
        let authHeaderForApi = this->buildAuthorizationHeaderForAPIRequest("POST", accessTokenEndpoint, accessToken, bodyParams);

        let authHeaders = [
            "Authorization" : authHeaderForApi
        ];

        let headers = array_merge(authHeaders, extraOAuthHeaders);
        let tokenObj = client->retrieve(accessTokenEndpoint, bodyParams, headers);

        storage->storeAccessToken(serviceId, tokenObj);

        return tokenObj;
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
    public function request(string! path, string! method = "GET", body = null, headers = null) -> string
    {
        var uri, token, storage, extraApiHeaders, mergedHeaders, baseApiUri, 
            serviceId, authHeaders, authHeaderForApi, response;

        let storage = <OAuth\TokenStorageInterface> this->getTokenStorage();
        let serviceId = this->getServiceId();
        let baseApiUri = <OAuth\UriInterface> this->getBaseApiUri();
        let uri = <OAuth\UriInterface> this->determineRequestUriFromPath(path, baseApiUri);

        let token = <OAuth\V1\TokenInterface> storage->retrieveAccessToken(serviceId);

        let extraApiHeaders = this->getExtraApiHeaders();
        if typeof headers == "array" {
            let mergedHeaders = array_merge(extraApiHeaders, headers);
        } else {
            let mergedHeaders = extraApiHeaders;
        }
        let authHeaderForApi = this->buildAuthorizationHeaderForAPIRequest(method, uri, token, body);
        let authHeaders = ["Authorization" : authHeaderForApi];
        let headers = array_merge(authHeaders, mergedHeaders);

        let response = client->retrieve(uri, body, headers, method);

        return response;
    }


    /**
     * Builds the authorization header for getting an access or request token.
     *
     * @param array params Additional parameters
     * @return string
     */
    protected function buildAuthorizationHeaderForTokenRequest(params = null) -> string
    {
        var info, signature, signatureStr, requestTokenEndpoint,
            key, value, delimiter, authHeader, keyEncoded, valueEncoded;

        let info = this->getBasicAuthorizationHeaderInfo();
        let info = array_merge(info, params);

        let requestTokenEndpoint = this->getRequestTokenEndpoint();
        let signature = <OAuth\V1\SignatureInterface> this->getSignature();
        let signatureStr = signature->getSignature(requestTokenEndpoint, info, "POST");

        let info["oauth_signature"] = signatureStr;
        let authHeader = "OAuth ";

        for key, value in info {
            let keyEncoded = rawurlencode(key);
            let valueEncoded = rawurlencode(value);

            let authHeader = authHeader . delimiter . keyEncoded . "=\"" . valueEncoded . "\"";
            let delimiter = ", ";
        }

        return authHeader;
    }

    /**
     * Builds the authorization header for an authenticated API request
     *
     * @param string method
     * @param OAuth\UriInterface uri The uri the request is headed
     * @param OAuth\V1\TokenInterface token
     * @param array bodyParams Request body if applicable (key/value pairs)
     *
     * @return string
     */
    protected function buildAuthorizationHeaderForAPIRequest(string! method, <OAuth\UriInterface> uri, <OAuth\V1\TokenInterface> token, bodyParams = null) -> string
    {
        var signature, signatureStr, accessTokenSecret, params, accessToken, mergedParams,
            key, value, delimiter, authHeader, keyEncoded, valueEncoded;

        let signature = <OAuth\V1\SignatureInterface> this->getSignature();
        let accessTokenSecret = token->getAccessTokenSecret();

        signature->setTokenSecret(accessTokenSecret);

        let params = this->getBasicAuthorizationHeaderInfo();

        if isset params["oauth_callback"] {
            unset params["oauth_callback"];
        }

        let accessToken = token->getAccessToken();
        let params = array_merge(params, ["oauth_token" : accessToken];

        if typeof bodyParams == "array" {
            let mergedParams = array_merge(params, bodyParams);
        } else {
            let mergedParams = params;
        }

        let signatureStr = signature->getSignature(uri, mergedParams, method);
        let params["oauth_signature"] = signatureStr;

        let authHeader = "OAuth ";
        for key, value in params {
            let keyEncoded = rawurlencode(key);
            let valueEncoded = rawurlencode(value);

            let authHeader = authHeader . delimiter . keyEncoded . "=\"" . valueEncoded . "\"";
            let delimiter = ", ";
        }

        return authHeader;
    }

    /**
     * Builds the authorization header array.
     *
     * @return array
     */
    protected function getBasicAuthorizationHeaderInfo() // -> array
    {
        var dateTime, credentials, callbackUrl, consumerId, 
            nonce, signatureMethod, version, timestamp;

        let dateTime = new DateTime();
        let credentials = <OAuth\CredentialsInterface> this->getCredentials();

        let callbackUrl = credentials->getCallbackUrl();
        let consumerId = credentials->getConsumerId();
        let nonce = this->generateNonce();
        let timestamp = dateTime->format("U");
        let signatureMethod = this->getSignatureMethod();
        let version = this->getVersionForHeaders();

        return [
            "oauth_callback" : callbackUrl,
            "oauth_consumer_key" : consumerId,
            "oauth_nonce" => nonce,
            "oauth_signature_method" => signatureMethod,
            "oauth_timestamp" => timestamp,
            "oauth_version" : version
        ];
    }

    /**
     * Pseudo random string generator used to build a unique string to sign each request
     *
     * @param int length
     * @return string
     */
    protected function generateNonce(int length = 32) -> string
    {
        var characters, nonce, max, index;
        char symbol;

        let characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        let nonce = "";
        let max = strlen(characters) - 1;

        while length > 0 {
            length--;
            let index = rand(0, max);
            symbol = characters[index];
            let nonce .= symbol; 
        }
        return nonce;
    }


    /**
     * Gets the hashing method for signature
     *
     * @return string
     */
    protected function getSignatureMethod() -> string
    {
        return "HMAC-SHA1";
    }

    /**
     * Gets the version used in the authorization header of the requests
     *
     * @return string
     */
    protected function getVersionForHeaders() -> string
    {
        return '1.0';
    }

    /**
    * Parses the request token response and returns a OAuth\V1\TokenInterface.
    * This is only needed to verify the `oauth_callback_confirmed` parameter. The actual
    * parsing logic is contained in the access token parser.
    *
    * @param string responseBody
    * @return OAuth\V1\TokenInterface
    * @throws OAuth\TokenResponseException
    */
    abstract protected function parseRequestTokenResponse(string responseBody) -> <OAuth\V1\TokenInterface>;

    /**
    * Parses the access token response and returns a OAuth\V1\TokenInterface.
    *
    * @param string responseBody
    * @return OAuth\V1\TokenInterface
    * @throws OAuth\TokenResponseException
    */
    abstract protected function parseAccessTokenResponse(string responseBody) -> <OAuth\V1\TokenInterface>;
}