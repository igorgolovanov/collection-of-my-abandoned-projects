/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

use ArrayIterator;
use Traversable;
use Zend\Stdlib;
use Zend\Stdlib\ArrayUtils;
use Zend\Stdlib\ErrorHandler;
use Zend\Uri\Http;
/**
 * Http client
 */
class Client implements Stdlib\DispatchableInterface
{
    /**
     * @const string Supported HTTP Authentication methods
     */
    const AUTH_BASIC  = "basic";
    const AUTH_DIGEST = "digest"; // not implemented yet

    /**
     * @const string POST data encoding methods
     */
    const ENC_URLENCODED = "application/x-www-form-urlencoded";
    const ENC_FORMDATA   = "multipart/form-data";

    /**
     * @const string DIGEST Authentication
     */
    const DIGEST_REALM  = "realm";
    const DIGEST_QOP    = "qop";
    const DIGEST_NONCE  = "nonce";
    const DIGEST_OPAQUE = "opaque";
    const DIGEST_NC     = "nc";
    const DIGEST_CNONCE = "cnonce";

    /**
     * @var Response
     */
    protected response;

    /**
     * @var Request
     */
    protected request;

    /**
     * @var Client/Adapter
     */
    protected adapter;

    /**
     * @var array
     */
    protected auth = [];

    /**
     * @var string
     */
    protected streamName;

    /**
     * @var array of Header\SetCookie
     */
    protected cookies = [];

    /**
     * @var string
     */
    protected encType = "";

    /**
     * @var Request
     */
    protected lastRawRequest;

    /**
     * @var Response
     */
    protected lastRawResponse;

    /**
     * @var int
     */
    protected redirectCounter = 0;

    /**
     * Configuration array, set using the constructor or using ::setOptions()
     *
     * @var array
     */
    protected config = [
		"maxredirects": 5, 
		"strictredirects": false, 
		"useragent": "Zend\\Http\\Client",
		"timeout": 10, 
		"adapter": "Zend\\Http\\Client\\Adapter\\Socket",
		"httpversion": "1.1",
		"storeresponse": true, 
		"keepalive": false, 
		"outputstream": false, 
		"encodecookies": true, 
		"argseparator": null, 
		"rfc3986strict": false
	];

    /**
     * Fileinfo magic database resource
     *
     * This variable is populated the first time _detectFileMimeType is called
     * and is then reused on every call to this method
     *
     * @var resource
     */
    protected static fileInfoDb;

    /**
     * Constructor
     *
     * @param string $uri
     * @param array|Traversable $options
     */
    public function __construct(string uri = null, var options = null)
    {
        if uri !== null {
            this->setUri(uri);
        }
        if options !== null {
            this->setOptions(options);
        }
    }

    /**
     * Set configuration parameters for this HTTP client
     *
     * @param  array|Traversable $options
     * @return Client
     * @throws Client\Exception\InvalidArgumentException
     */
    public function setOptions(var options = []) -> <Client>
    {
        var k, v, key;
        array wildcards = ["-", "_", " ", "."];

        if options instanceof Traversable {
            let options = ArrayUtils::iteratorToArray(options);
        }
        if unlikely typeof options != "array" {
            throw new Client\Exception\InvalidArgumentException("Config parameter is not valid");
        }

        for k, v in options {
            let key = str_replace(wildcards, "", strtolower(k));
            let this->config[key] = v; // replace w/ normalized
        }

        // Pass configuration options to the adapter if it exists
        if this->adapter instanceof Client\Adapter\AdapterInterface {
            this->adapter->setOptions(options);
        }

        return this;
    }

    /**
     * Load the connection adapter
     *
     * While this method is not called more than one for a client, it is
     * separated from ->request() to preserve logic and readability
     *
     * @param  Client\Adapter\AdapterInterface|string $adapter
     * @return Client
     * @throws Client\Exception\InvalidArgumentException
     */
    public function setAdapter(var adapter) -> <Client>
    {
        string exceptionMsg;
        var config;

        if typeof adapter == "string" {
            if unlikely !class_exists(adapter) {
                let exceptionMsg = "Unable to locate adapter class \"" . adapter . "\"";
                throw new Client\Exception\InvalidArgumentException(exceptionMsg);
            }
            let adapter = new {adapter}();
        }

        if unlikely !(adapter instanceof Client\Adapter\AdapterInterface) {
            let exceptionMsg = "Passed adapter is not a HTTP connection adapter";
            throw new Client\Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->adapter = adapter;
        let config = this->config;

        unset config["adapter"];

        adapter->setOptions(config);

        return this;
    }

    /**
     * Load the connection adapter
     *
     * @return Client\Adapter\AdapterInterface $adapter
     */
    public function getAdapter() -> <Client\Adapter\AdapterInterface>
    {
        var config;

        if !this->adapter {
            let config = this->config["adapter"];
            this->setAdapter(config);
        }
        return this->adapter;
    }

    /**
     * Set request
     *
     * @param Request $request
     * @return Client
     */
    public function setRequest(<Request> request) -> <Client>
    {
        let this->request = request;
        return this;
    }

    /**
     * Get Request
     *
     * @return Request
     */
    public function getRequest() -> <Request>
    {
        var request;

        let request = this->request;
        if empty request {
            let request = new Request();
            let this->request = request;
        }
        return request;
    }

    /**
     * Set response
     *
     * @param Response $response
     * @return Client
     */
    public function setResponse(<Response> response) -> <Client>
    {
        let this->response = response;
        return this;
    }

    /**
     * Get Response
     *
     * @return Response
     */
    public function getResponse() -> <Response>
    {
        var response;

        let response = this->response;
        if empty response {
            let response = new Response();
            let this->response = response;
        }
        return response;
    }

    /**
     * Get the last request (as a string)
     *
     * @return string
     */
    public function getLastRawRequest() -> string
    {
        return this->lastRawRequest;
    }

    /**
     * Get the last response (as a string)
     *
     * @return string
     */
    public function getLastRawResponse() -> string
    {
        return this->lastRawResponse;
    }

    /**
     * Get the redirections count
     *
     * @return int
     */
    public function getRedirectionsCount() -> int
    {
        return this->redirectCounter;
    }

    /**
     * Set Uri (to the request)
     *
     * @param string|Http $uri
     * @return Client
     */
    public function setUri(string uri) -> <Client>
    {
        if !empty uri {

        }
        return this;
    }

    /**
     * Get uri (from the request)
     *
     * @return Http
     */
    public function getUri()
    {

    }

    /**
     * Set the HTTP method (to the request)
     *
     * @param string $method
     * @return Client
     */
    public function setMethod(string method) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Get the HTTP method
     *
     * @return string
     */
    public function getMethod() -> string
    {
        return ""; // todo:
    }

    /**
     * Set the query string argument separator
     *
     * @param string $argSeparator
     * @return Client
     */
    public function setArgSeparator(string argSeparator) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Get the query string argument separator
     *
     * @return string
     */
    public function getArgSeparator() -> string
    {

    }

    /**
     * Set the encoding type and the boundary (if any)
     *
     * @param string $encType
     * @param string $boundary
     * @return Client
     */
    public function setEncType(string encType, string boundary = null) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Get the encoding type
     *
     * @return string
     */
    public function getEncType() -> string
    {

    }

    /**
     * Set raw body (for advanced use cases)
     *
     * @param string $body
     * @return Client
     */
    public function setRawBody(string body) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Set the POST parameters
     *
     * @param array $post
     * @return Client
     */
    public function setParameterPost(array! post) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Set the GET parameters
     *
     * @param array $query
     * @return Client
     */
    public function setParameterGet(array! query) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Reset all the HTTP parameters (request, response, etc)
     *
     * @param  bool   $clearCookies  Also clear all valid cookies? (defaults to false)
     * @param  bool   $clearAuth     Also clear http authentication? (defaults to true)
     * @return Client
     */
    public function resetParameters(boolean clearCookies = false) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Return the current cookies
     *
     * @return array
     */
    public function getCookies() -> array
    {
        return []; // todo
    }

    /**
     * Get the cookie Id (name+domain+path)
     *
     * @param  Header\SetCookie|Header\Cookie $cookie
     * @return string|bool
     */
    protected function getCookieId(var cookie) -> string|boolean
    {
        return ""; // todo:
    }

    /**
     * Add a cookie
     *
     * @param array|ArrayIterator|Header\SetCookie|string $cookie
     * @param string  $value
     * @param string  $expire
     * @param string  $path
     * @param string  $domain
     * @param  bool $secure
     * @param  bool $httponly
     * @param string  $maxAge
     * @param string  $version
     * @throws Exception\InvalidArgumentException
     * @return Client
     */
    public function addCookie(var cookie, string value = null, string expire = null, string path = null, string domain = null, boolean secure = false, boolean httponly = true, string maxAge = null, string version = null) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Set an array of cookies
     *
     * @param  array $cookies
     * @throws Exception\InvalidArgumentException
     * @return Client
     */
    public function setCookies(array cookies) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Clear all the cookies
     */
    public function clearCookies()
    {

    }

    /**
     * Set the headers (for the request)
     *
     * @param  Headers|array $headers
     * @throws Exception\InvalidArgumentException
     * @return Client
     */
    public function setHeaders(var headers) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Check if exists the header type specified
     *
     * @param  string $name
     * @return bool
     */
    public function hasHeader(string name) -> boolean
    {
        return true; // todo
    }

    /**
     * Get the header value of the request
     *
     * @param  string $name
     * @return string|bool
     */
    public function getHeader(string name) -> string|boolean
    {
        return ""; // todo
    }

    /**
     * Set streaming for received data
     *
     * @param string|bool $streamfile Stream file, true for temp file, false/null for no streaming
     * @return \Zend\Http\Client
     */
    public function setStream(var streamfile = true) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Get status of streaming for received data
     * @return bool|string
     */
    public function getStream() -> boolean|string
    {
        return ""; //todo
    }

    /**
     * Create temporary stream
     *
     * @throws Exception\RuntimeException
     * @return resource
     */
    protected function openTempStream() //-> resource
    {
        // todo
    }

    /**
     * Create a HTTP authentication "Authorization:" header according to the
     * specified user, password and authentication method.
     *
     * @param string $user
     * @param string $password
     * @param string $type
     * @throws Exception\InvalidArgumentException
     * @return Client
     */
    public function setAuth(string user, string password, var type = self::AUTH_BASIC) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Clear http authentication
     */
    public function clearAuth()
    {

    }

    /**
     * Calculate the response value according to the HTTP authentication type
     *
     * @see http://www.faqs.org/rfcs/rfc2617.html
     * @param string $user
     * @param string $password
     * @param string $type
     * @param array $digest
     * @param null|string $entityBody
     * @throws Exception\InvalidArgumentException
     * @return string|bool
     */
    protected function calcAuthDigest(string user, string password, var type = self::AUTH_BASIC, array digest = [], string entityBody = null) -> string|boolean
    {
        return ""; //todo
    }

    /**
     * Dispatch
     *
     * @param Stdlib\RequestInterface $request
     * @param Stdlib\ResponseInterface $response
     * @return Stdlib\ResponseInterface
     */
    public function dispatch(request, response = null)
    {
        // todo
    }

    /**
     * Send HTTP request
     *
     * @param  Request $request
     * @return Response
     * @throws Exception\RuntimeException
     * @throws Client\Exception\RuntimeException
     */
    public function send(<Request> request = null) // -> <Response>
    {
        // todo
    }

    /**
     * Fully reset the HTTP client (auth, cookies, request, response, etc.)
     *
     * @return Client
     */
    public function reset() -> <Client>
    {
        return this;// todo:
    }

    /**
     * Set a file to upload (using a POST request)
     *
     * Can be used in two ways:
     *
     * 1. $data is null (default): $filename is treated as the name if a local file which
     * will be read and sent. Will try to guess the content type using mime_content_type().
     * 2. $data is set - $filename is sent as the file name, but $data is sent as the file
     * contents and no file is read from the file system. In this case, you need to
     * manually set the Content-Type ($ctype) or it will default to
     * application/octet-stream.
     *
     * @param  string $filename Name of file to upload, or name to save as
     * @param  string $formname Name of form element to send as
     * @param  string $data Data to send (if null, $filename is read and sent)
     * @param  string $ctype Content type to use (if $data is set and $ctype is
     *                null, will be application/octet-stream)
     * @return Client
     * @throws Exception\RuntimeException
     */
    public function setFileUpload(string filename, string formname, string data = null, string ctype = null) -> <Client>
    {
        return this;// todo:
    }

    /**
     * Remove a file to upload
     *
     * @param  string $filename
     * @return bool
     */
    public function removeFileUpload(string filename) -> boolean
    {
        return true; // todo
    }

    /**
     * Prepare Cookies
     *
     * @param   string $domain
     * @param   string $path
     * @param   bool $secure
     * @return  Header\Cookie|bool
     */
    protected function prepareCookies(string domain, string path, boolean secure) -> <Header\Cookie>|boolean
    {
        return true; // todo
    }

    /**
     * Prepare the request headers
     *
     * @param resource|string $body
     * @param Http $uri
     * @throws Exception\RuntimeException
     * @return array
     */
    protected function prepareHeaders(var body, uri) -> array
    {
        return []; // todo
    }

    /**
     * Prepare the request body (for PATCH, POST and PUT requests)
     *
     * @return string
     * @throws \Zend\Http\Client\Exception\RuntimeException
     */
    protected function prepareBody() -> string
    {
        return ""; // todo
    }

    /**
     * Attempt to detect the MIME type of a file using available extensions
     *
     * This method will try to detect the MIME type of a file. If the fileinfo
     * extension is available, it will be used. If not, the mime_magic
     * extension which is deprecated but is still available in many PHP setups
     * will be tried.
     *
     * If neither extension is available, the default application/octet-stream
     * MIME type will be returned
     *
     * @param string $file File path
     * @return string MIME type
     */
    protected function detectFileMimeType(string file) -> string
    {
        return ""; // todo
    }

    /**
     * Encode data to a multipart/form-data part suitable for a POST request.
     *
     * @param string $boundary
     * @param string $name
     * @param mixed $value
     * @param string $filename
     * @param array $headers Associative array of optional headers @example ("Content-Transfer-Encoding" => "binary")
     * @return string
     */
    public function encodeFormData(string boundary, string name, value, string filename = null, array headers = []) -> string
    {
        return ""; // todo
    }

    /**
     * Convert an array of parameters into a flat array of (key, value) pairs
     *
     * Will flatten a potentially multi-dimentional array of parameters (such
     * as POST parameters) into a flat array of (key, value) paris. In case
     * of multi-dimentional arrays, square brackets ([]) will be added to the
     * key to indicate an array.
     *
     * @since 1.9
     *
     * @param array $parray
     * @param string $prefix
     * @return array
     */
    protected function flattenParametersArray(array parray, string prefix = null) -> array
    {
        return []; // todo
    }

    /**
     * Separating this from send method allows subclasses to wrap
     * the interaction with the adapter
     *
     * @param Http $uri
     * @param string $method
     * @param  bool $secure
     * @param array $headers
     * @param string $body
     * @return string the raw response
     * @throws Exception\RuntimeException
     */
    protected function doRequest(uri, string method, boolean secure = false, array headers = [], string body = "") -> string
    {
        return ""; // todo
    }

    /**
     * Create a HTTP authentication "Authorization:" header according to the
     * specified user, password and authentication method.
     *
     * @see http://www.faqs.org/rfcs/rfc2617.html
     * @param string $user
     * @param string $password
     * @param string $type
     * @return string
     * @throws Client\Exception\InvalidArgumentException
     */
    public static function encodeAuthHeader(string user, string password, var type = self::AUTH_BASIC) -> string
    {
        return ""; // todo
    }

}
