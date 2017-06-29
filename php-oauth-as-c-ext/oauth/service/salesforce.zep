
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

class SalesForce extends OAuth\V2\Service
{
	/**
     * Scopes
     *
     * @var string
     */
    const SCOPE_API           = "api";
    const SCOPE_REFRESH_TOKEN = "refresh_token";

    /**
     * Gets the authorization API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAuthorizationEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://login.salesforce.com/services/oauth2/authorize");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://na1.salesforce.com/services/oauth2/token");
    }

    protected function parseRequestTokenResponse(responseBody)
    {
    	var data, error;
    	let data = [];

        parse_str(responseBody, data);

        if typeof data != "array" {
            throw new OAuth\TokenResponseException("Unable to parse response");
        } 
        if !isset data["oauth_callback_confirmed"] || data["oauth_callback_confirmed"] !== "true") {
            throw new OAuth\TokenResponseException('Error in retrieving token');
        }

        return this->parseAccessTokenResponse(responseBody);
    }

    protected function parseAccessTokenResponse(responseBody)
    {
    	ar data, token, error, errorMsg, accessToken, refreshToken;

    	let data = json_decode(responseBody, true);

    	if typeof data == "null" || typeof data != "array" {
    		throw new OAuth\TokenResponseException("Unable to parse response");
    	}
    	if fetch error, data["error"] {
    		let errorMsg = "Error in retrieving token: \"" . error . "\"";
    		throw new OAuth\TokenResponseException(errorMsg);
    	}
    	let accessToken = data["access_token"];
    	let token = new OAuth\V2\Token(accessToken);

    	unset data["access_token"];
    	
        token->setEndOfLife(OAuth\V2\Token::LIFETIME_NEVER_EXPIRES);

        if fetch refreshToken, data["refresh_token"] {
            token->setRefreshToken(refreshToken);
            unset data["refresh_token"];
        }
        
        token->setExtraParams(data);

        return token;
    }

    protected function getExtraOAuthHeaders()
    {
        return ["Accept" : "application/json"];
    }
}