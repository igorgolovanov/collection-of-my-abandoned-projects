
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Service;

abstract class Twitter extends OAuth\V1\Service
{
	const ENDPOINT_AUTHENTICATE = "https://api.twitter.com/oauth/authenticate";
    const ENDPOINT_AUTHORIZE    = "https://api.twitter.com/oauth/authorize";

    private authorizationEndpoint;

	public function __construct(
        <OAuth\CredentialsInterface> credentials,
        <OAuth\ClientInterface> client,
        <OAuth\TokenStorageInterface> storage,
        <OAuth\V1\SignatureInterface> signature,
        <OAuth\UriInterface> baseApiUri = null,
        string serviceId = null
    ) {
        parent::__construct(credentials, client, storage, signature, baseApiUri);

        if typeof baseApiUri === "null" {
        	let baseApiUri = new OAuth\Uri("https://api.twitter.com/1.1/");
            this->setBaseApiUri(baseApiUri);
        }

        let this->authorizationEndpoint = self::ENDPOINT_AUTHENTICATE;
    }

    public function getRequestTokenEndpoint() -> <OAuth\Uri>
    {
        return new OAuth\Uri("https://api.twitter.com/oauth/request_token");
    }

    /**
     * Gets the access token API endpoint.
     *
     * @return OAuth\UriInterface
     */
    public function getAccessTokenEndpoint() -> <OAuth\UriInterface>
    {
        return new OAuth\Uri("https://api.twitter.com/oauth/access_token");
    }
}