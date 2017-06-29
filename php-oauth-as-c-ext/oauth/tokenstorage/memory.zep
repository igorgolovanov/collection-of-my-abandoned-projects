
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\TokenStorage;

class Memory implements OAuth\TokenStorageInterface
{
	protected tokens;

    public function __construct()
    {
        let this->tokens = [];
    }

    /**
     * {@inheritDoc}
     */
    public function retrieveAccessToken(string service) -> <OAuth\TokenInterface>
    {
    	var hasAccess;

    	let hasAccess = this->hasAccessToken(service);

    	if hasAccess {
    		return this->tokens[service];
    	}

        throw new OAuth\TokenNotFoundException("Token not stored");
    }

    /**
     * {@inheritDoc}
     */
    public function storeAccessToken(string service, <OAuth\TokenInterface> token)
    {
        let this->tokens[service] = token;

        return this;
    }

    /**
     * {@inheritDoc}
     */
    public function hasAccessToken(string service) -> boolean
    {
    	var token;
    	if fetch token, this->tokens[service] {
    		if token instanceof OAuth\TokenInterface {
    			return true;
    		}
    	}
        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function clearToken(service)
    {
    	if isset this->tokens[service] {
            //@todo: unset
    		//unset(this->tokens[service]);
    	}
        return this;
    }

    /**
     * {@inheritDoc}
     */
    public function clearAllTokens()
    {
    	let this->tokens = [];

        return this;
    }
}