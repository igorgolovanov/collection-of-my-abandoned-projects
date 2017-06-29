
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

/**
 * @author Igor Golovanov
 *
 */
abstract class Service implements OAuth\ServiceInterface
{
	/**
     * @var OAuth\CredentialsInterface
     */
    private credentials;

    /**
     * @var OAuth\ClientInterface
     */
    private client;

    /**
     * @var OAuth\TokenStorageInterface
     */
    private storage;

    /**
     * @var OAuth\UriInterface
     */
    private baseApiUri;

    /**
     * Service ID
     *
     * @var string
     */
    private serviceId;

    /**
     * Class constructor.
     *
     * @param OAuth\CredentialsInterface credentials
     * @param OAuth\ClientInterface client
     * @param OAuth\TokenStorageInterface storage
     * @param OAuth\UriInterface baseApiUri
     * @param string serviceId
     */
    public function __construct(
        <OAuth\CredentialsInterface> credentials, 
        <OAuth\ClientInterface> client, 
        <OAuth\TokenStorageInterface> storage, 
        <OAuth\UriInterface> baseApiUri = null,
        string serviceId = null)
    {
        var reflection;

        if empty serviceId {
            let reflection = new ReflectionObject(this);
            let serviceId = reflection->getShortName();
        }

    	let this->credentials = credentials;
    	let this->client = client;
    	let this->storage = storage;
        let this->baseApiUri = baseApiUri;
        let this->serviceId = serviceId;
    }

    /**
     * Gets the credentials
     *
     * @return OAuth\CredentialsInterface
     */
    protected function getCredentials() -> <OAuth\CredentialsInterface>
    {
        return this->credentials;
    }

    /**
     * Gets the client
     *
     * @return OAuth\ClientInterface
     */
    protected function getClient() -> <OAuth\ClientInterface>
    {
        return this->client;
    }

    /**
     * Gets the token storage
     *
     * @return OAuth\TokenStorageInterface
     */
    protected function getTokenStorage() -> <OAuth\TokenStorageInterface>
    {
        return this->storage;
    }

    /**
     * Gets the base api uri
     *
     * @return OAuth\UriInterface
     */
    protected function getBaseApiUri() -> <OAuth\UriInterface>
    {
        return this->baseApiUri;
    }

    /**
     * Gets the service ID.
     * Uses for separate services in storage.
     *
     * @return string
     */
    public function getServiceId() -> string
    {
        return this->serviceId;
    }

    /**
     * Gets the extra headers for API.
     *
     * @return array
     */
    protected function getExtraApiHeaders()
    {
        return [];
    }

    /**
     * Gets the extra headers for OAuth.
     *
     * @return array
     */
    protected function getExtraOAuthHeaders()
    {
        return [];
    }
}