
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth;

class Uri implements OAuth\UriInterface
{
	/**
     * @var string
     */
    private scheme = "http";

    /**
     * @var string
     */
    private userInfo;

    /**
     * @var string
     */
    private rawUserInfo;

    /**
     * @var string
     */
    private host;

    /**
     * @var int
     */
    private port = 80;

    /**
     * @var string
     */
    private path = "/";

    /**
     * @var string
     */
    private query;

    /**
     * @var string
     */
    private fragment;

    /**
     * @var boolean
     */
    private explicitPortSpecified = false;

    /**
     * @var boolean
     */
    private explicitTrailingHostSlash = false;


	public function __construct(string! uri = null)
	{
		if !empty uri {
			this->parseUri(uri);
		}
	}

	/**
	 * Parse URI and setup object vars.
	 *
	 * @param string uri URI.
	 * @return OAuth\Uri
	 */
	protected function parseUri(string uri) -> <OAuth\Uri>
	{
		var parts, userInfo, scheme, port, path, query, fragment, user, pass;

		let parts = parse_url(uri);

		if parts === false {
			throw new InvalidArgumentException("Invalid URI: " . uri);
		}

		if fetch scheme, parts["scheme"] {
			let this->scheme = parts["scheme"];
			let this->host = parts["host"];
		} else {
			throw new InvalidArgumentException("Invalid URI: http|https scheme required");
		}

		if fetch port, parts["port"] {
			let this->port = port;
			let this->explicitPortSpecified = true;
		} else {
			if parts["scheme"] == "https" {
				let this->port = 443;
			} else {
				let this->port = 80;
			}
			let this->explicitPortSpecified = false;
		}

		if fetch path, parts["path"] {
			let this->path = path;
			if path === "/" {
				let this->explicitTrailingHostSlash = true;
			}
		} else {
			let this->path = "/";
		}

		if fetch query, parts["query"] {
			let this->query = query;
		} else {
			let this->query = "";
		}

		if fetch fragment, parts["fragment"] {
			let this->fragment = fragment;
		} else {
			let this->fragment = "";
		}

		let userInfo = "";

		if fetch user, parts["user"] {
			let userInfo .= user;
		}
		if userInfo && fetch pass, parts["pass"] {
			let userInfo .= ":" . pass;
		}
		this->setUserInfo(userInfo);

		return this;
	}

	/**
     * Gets the schema
     *
     * @return string
     */
    public function getScheme() -> string
    {
    	return this->scheme;
    }

    /**
     * Sets the schema
     *
     * @param string scheme
     * @return OAuth\UriInterface
     */
    public function setScheme(string! scheme) -> <OAuth\UriInterface>
    {
    	let this->scheme = scheme;

    	return this;
    }

    /**
     * Gets the host
     *
     * @return string
     */
    public function getHost() -> string
    {
    	return this->host;
    }

    /**
     * Sets the host
     *
     * @param string host
     * @return OAuth\UriInterface
     */
    public function setHost(string! host) -> <OAuth\UriInterface>
    {
    	let this->host = host;

    	return this;
    }

    /**
     * Gets the port
     *
     * @return int
     */
    public function getPort() -> int
    {
    	return this->port;
    }

    /**
     * Sets the port
     *
     * @param int port
     * @return OAuth\UriInterface
     */
    public function setPort(int port) -> <OAuth\UriInterface>
    {
    	var scheme;

    	let this->port = port;
    	let scheme = this->getScheme();

    	if (scheme === "https" && port === 443) || (scheme === "http" && port === 80) {
    		let this->explicitPortSpecified = false;
    	} else {
    		let this->explicitPortSpecified = true;
    	}

    	return this;
    }

    /**
     * Gets the path 
     *
     * @return string
     */
    public function getPath() -> string
    {
    	return this->path;
    }

    /**
     * Sets the path
     *
     * @param string path
     * @return OAuth\UriInterface
     */
    public function setPath(string path) -> <OAuth\UriInterface>
    {
    	if empty path {
    		let this->path = "/";
    		let this->explicitTrailingHostSlash = false;
    	} else {
    		let this->path = path;
    		if path === "/" {
    			let this->explicitTrailingHostSlash = true;
    		}
    	}
    	return this;
    }

    /**
     * Gets the query
     *
     * @return string
     */
    public function getQuery() -> string
    {
    	return this->query;
    }

    /**
     * Sets the query
     *
     * @param string query
     * @return OAuth\UriInterface
     */
    public function setQuery(string! query) -> <OAuth\UriInterface>
    {
    	let this->query = query;

    	return this;
    }

    /**
     * Adds a param to the query string.
     *
     * @param string name
     * @param string value
     * @return OAuth\UriInterface
     */
    public function addToQuery(string! name, value) -> <OAuth\UriInterface>
    {
    	var query, params, paramsPacked, prefix, separator; 

    	let separator = "&";
    	let prefix = "";
    	let query = this->getQuery();

    	if !empty query {
    		let query .= separator;
    	}

        let params = [];
        let params[name] = value;

        let paramsPacked = http_build_query(params, prefix, separator);

        let query .= paramsPacked;
        let this->query = query;

        return this;
    }

    /**
     * Gets the fragment.
     *
     * @return string
     */
    public function getFragment() -> string
    {
    	return this->fragment;
    }

    /**
     * Should return URI user info, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string
     */
    public function getUserInfo() -> string
    {
    	return this->userInfo;
    }

    /**
     * Sets the user info.
     *
     * @param string userInfo
     * @return OAuth\UriInterface
     */
    public function setUserInfo(string userInfo) -> <OAuth\UriInterface>
    {
    	// var protectedUserInfo;

    	// let protectUserInfo = 

    	let this->userInfo = userInfo;
    	let this->rawUserInfo = userInfo;

    	return this;
    }

    /**
     * Should return the URI Authority, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string
     */
    public function getAuthority() -> string
    {
    	var authority, userInfo, host, postSpecified, port;

    	let userInfo = this->getUserInfo();
    	let host = this->getHost();
    	let postSpecified = this->hasExplicitPortSpecified();

    	if userInfo {
    		let authority = userInfo . "@";
    	} else {
    		let authority = "";
    	}
    	let authority .= host;

    	if postSpecified {
    		let port = this->getPort();
    		let authority .= ":" . port;
    	}
    	return authority;
    }

    /**
     * Should return the URI string, masking protected user info data according to rfc3986-3.2.1
     *
     * @return string the URI string with user protected info masked
     */
    public function __toString() -> string
    {
    	var uri, scheme, authority, path, explicitTrailingHostSlash, query, fragment;

    	let scheme = this->getScheme();
    	let authority = this->getAuthority();
    	let path = this->getPath();
    	let explicitTrailingHostSlash = this->hasExplicitTrailingHostSlash();
    	let query = this->getQuery();
    	let fragment = this->getFragment();

    	let uri = scheme . "://" . authority;

    	if path === "/" {
    		if explicitTrailingHostSlash {
    			let uri .= "/";
    		}
    	} else {
    		let uri .= path;
    	}

    	if !empty query {
    		let uri = uri . "?" . query;
    	}

    	if !empty fragment {
    		let uri = uri . "#" . fragment;
    	}
    	return uri;
    }

    /**
     * Should return the URI Authority without masking protected user info data
     *
     * @return string
     */
    public function getRawAuthority() -> string
    {
    	var authority, rawUserInfo, host, explicitPortSpecified, port;

    	let authority = "";
    	let rawUserInfo = this->getRawUserInfo();
    	let host = this->getHost();
    	let explicitPortSpecified = this->hasExplicitPortSpecified();

    	if rawUserInfo {
    		let authority = authority . rawUserInfo . "@";
    	}

    	if explicitPortSpecified {
    		let port = this->getPort();
    		let authority = authority . ":" . port;
    	}

    	return authority;
    }

    /**
     * Should return the URI user info without masking protected user info data
     *
     * @return string
     */
    public function getRawUserInfo() -> string
    {
    	return this->rawUserInfo;
    }

    /**
     * Build the full URI based on all the properties
     *
     * @return string The full URI without masking user info
     */
    public function getAbsoluteUri() -> string
    {
    	var uri, scheme, authority, path, query, fragment, explicitTrailingHostSlash;

    	let scheme = this->getScheme();
    	let authority = this->getRawAuthority();
    	let path = this->getPath();
    	let query = this->getQuery();
    	let fragment = this->getFragment();

    	let uri = scheme . "://" . authority;

    	if path === "/" {
    		let explicitTrailingHostSlash = this->hasExplicitTrailingHostSlash();
    		if explicitTrailingHostSlash {
    			let uri .= "/";
    		}
    	} else {
    		let uri .= path;
    	}

    	if !empty query {
    		let uri = uri . "?" . query;
    	}

    	if !empty fragment {
    		let uri = uri . "#" . fragment;
    	}

    	return uri;
    }

    /**
     * Build the relative URI based on all the properties
     *
     * @return string The relative URI
     */
    public function getRelativeUri() -> string
    {
    	var uri, path, explicitTrailingHostSlash;

    	let path = this->getPath();
    	let explicitTrailingHostSlash = this->hasExplicitTrailingHostSlash();
        let uri = "";

    	if path === "/" {
    		if explicitTrailingHostSlash {
    			let uri = "/";
    		}
    	} else {
    		let uri = path;
    	}

        return uri;
    }

    /**
     * @return bool
     */
    public function hasExplicitTrailingHostSlash() -> boolean
    {
    	return this->explicitTrailingHostSlash;
    }

    /**
     * @return bool
     */
    public function hasExplicitPortSpecified() -> boolean
    {
    	return this->explicitPortSpecified;
    }

    
	public static function createFromSuperGlobals(params = null)
	{
		var uri;

		let uri = new self();

		if !empty params {
			

			let params = _SERVER;
		}
		
	}
}