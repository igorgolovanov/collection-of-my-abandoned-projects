/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

use Zend\Stdlib\Parameters;
use Zend\Stdlib\ParametersInterface;
use Zend\Stdlib\RequestInterface;
use Zend\Uri\Exception as UriException;
use Zend\Uri\Http as HttpUri;

/**
 * HTTP Request
 *
 * @link      http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html#sec5
 */
class Request extends AbstractMessage implements RequestInterface
{
    /**#@+
     * @const string METHOD constant names
     */
    const METHOD_OPTIONS = "OPTIONS";
    const METHOD_GET = "GET";
    const METHOD_HEAD = "HEAD";
    const METHOD_POST = "POST";
    const METHOD_PUT = "PUT";
    const METHOD_DELETE = "DELETE";
    const METHOD_TRACE = "TRACE";
    const METHOD_CONNECT = "CONNECT";
    const METHOD_PATCH = "PATCH";
    const METHOD_PROPFIND = "PROPFIND";


    /**
     * @var string
     */
    protected method = "GET";

    /**
     * @var string|HttpUri
     */
    protected uri;

    /**
     * @var ParametersInterface
     */
    protected queryParams;

    /**
     * @var ParametersInterface
     */
    protected postParams;

    /**
     * @var ParametersInterface
     */
    protected fileParams;

    /**
     * A factory that produces a Request object from a well-formed Http Request string
     *
     * @param  string $string
     * @return Request
     * @throws Exception\InvalidArgumentException
     */
    public static function fromString(string $string) -> <Request>
    {
        var className, request, lines, matches = null, methods, firstLine,
            version, headers = [], rawBody = [], nextLine;
        string regex;
        boolean isHeader = true;

        let className = get_called_class();
        let request = new {className}();
        let lines = explode("\r\n", $string);

        let methods = implode("|", [
            self::METHOD_OPTIONS, self::METHOD_GET, self::METHOD_HEAD, self::METHOD_POST,
            self::METHOD_PUT, self::METHOD_DELETE, self::METHOD_TRACE, self::METHOD_CONNECT,
            self::METHOD_PATCH
        ]);

        let regex = "#^(?P<method>" . methods . ")\s(?P<uri>[^ ]*)(?:\sHTTP\/(?P<version>\d+\.\d+)){0,1}#";
        let firstLine = array_shift(lines);

        if unlikely !preg_match(regex, firstLine, matches) {
            throw new Exception\InvalidArgumentException("A valid request line was not found in the provided string");
        }

        request->setMethod(matches["method"]);
        request->setUri(matches["uri"]);

        if fetch version, matches["version"] {
            request->setVersion(version);
        }

        if count(lines) == 0 {
            return request;
        }

        while lines {
            let nextLine = array_shift(lines);
            if nextLine == "" {
                let isHeader =  false;
                continue;
            }
            if isHeader {
                let headers[] = nextLine;
            } else {
                let rawBody[] = nextLine;
            }
        }

        if headers {
            let request->headers = implode("\r\n", headers);
        }
        if rawBody {
            request->setContent(implode("\r\n", rawBody));
        }

        return request;
    }

    /**
     * Set the method for this request
     *
     * @param  string $method
     * @return Request
     * @throws Exception\InvalidArgumentException
     */
    public function setMethod(string method) -> <Request>
    {
        string constName;

        let method = method->upper();
        let constName = "static::METHOD_" . method;

        if !defined(constName) {
            throw new Exception\InvalidArgumentException("Invalid HTTP method passed");
        }
        let this->method = method;
        return this;
    }

    /**
     * Return the method for this request
     *
     * @return string
     */
    public function getMethod() -> string
    {
        return this->method;
    }

    /**
     * Set the URI/URL for this request, this can be a string or an instance of Zend\Uri\Http
     *
     * @throws Exception\InvalidArgumentException
     * @param string|HttpUri $uri
     * @return Request
     */
    public function setUri(var uri) -> <Request>
    {
        string exceptionMsg, uriStr;
        var e;

        if typeof uri == "string" {
            try {
                let uri = new HttpUri(uri);
            } catch UriException\InvalidUriPartException, e {
                let uriStr = (string) uri;
                let exceptionMsg = "Invalid URI passed as string (" . uriStr . ")";

                throw new Exception\InvalidArgumentException(exceptionMsg, e->getCode(), e);
            }

        } elseif unlikely !(uri instanceof HttpUri) {
            throw new Exception\InvalidArgumentException("URI must be an instance of Zend\\Uri\\Http or a string");
        }
        let this->uri = uri;

        return this;
    }

    /**
     * Return the URI for this request object
     *
     * @return HttpUri
     */
    public function getUri()
    {
        var uri;

        let uri = this->uri;
        if uri === null || typeof uri == "string" {
            let uri = new HttpUri(uri);
            let this->uri = uri;
        }
        return uri;
    }

    /**
     * Return the URI for this request object as a string
     *
     * @return string
     */
    public function getUriString() -> string
    {
        var uri;

        let uri = this->uri;
        if uri instanceof HttpUri {
            return uri->toString();
        }
        return uri;
    }

    /**
     * Provide an alternate Parameter Container implementation for query parameters in this object,
     * (this is NOT the primary API for value setting, for that see getQuery())
     *
     * @param \Zend\Stdlib\ParametersInterface $query
     * @return Request
     */
    public function setQuery(<ParametersInterface> query) -> <Request>
    {
        let this->queryParams = query;
        return this;
    }

    /**
     * Return the parameter container responsible for query parameters or a single query parameter
     *
     * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
     * @param mixed|null            $default         Default value to use when the parameter is missing.
     * @return \Zend\Stdlib\ParametersInterface|mixed
     */
    public function getQuery(string name = null, var defaultVal = null)
    {
        var queryParams;

        let queryParams = this->queryParams;
        if queryParams === null {
            let queryParams = new Parameters();
            let this->queryParams = queryParams;
        }

        if name === null { // todo: check is null
            return queryParams;
        }

        return queryParams->get(name, defaultVal);
    }

    /**
     * Provide an alternate Parameter Container implementation for post parameters in this object,
     * (this is NOT the primary API for value setting, for that see getPost())
     *
     * @param \Zend\Stdlib\ParametersInterface $post
     * @return Request
     */
    public function setPost(<ParametersInterface> post) -> <Request>
    {
        let this->postParams = post;
        return this;
    }

    /**
     * Return the parameter container responsible for post parameters or a single post parameter.
     *
     * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
     * @param mixed|null            $default         Default value to use when the parameter is missing.
     * @return \Zend\Stdlib\ParametersInterface|mixed
     */
    public function getPost(string name = null, var defaultVal = null)
    {
        var postParams;

        let postParams = this->postParams;
        if postParams === null {
            let postParams = new Parameters();
            let this->postParams = postParams;
        }

        if name === null { // todo: check is null
            return postParams;
        }

        return postParams->get(name, defaultVal);
    }

    /**
     * Return the Cookie header, this is the same as calling $request->getHeaders()->get('Cookie');
     *
     * @convenience $request->getHeaders()->get('Cookie');
     * @return Header\Cookie
     */
    public function getCookie() -> <Header\Cookie>
    {
        var headers;

        let headers = <Headers> this->getHeaders();

        return headers->get("Cookie");
    }

    /**
     * Provide an alternate Parameter Container implementation for file parameters in this object,
     * (this is NOT the primary API for value setting, for that see getFiles())
     *
     * @param  ParametersInterface $files
     * @return Request
     */
    public function setFiles(<ParametersInterface> files) -> <Request>
    {
        let this->fileParams = files;
        return this;
    }

    /**
     * Return the parameter container responsible for file parameters or a single file.
     *
     * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
     * @param mixed|null            $default         Default value to use when the parameter is missing.
     * @return ParametersInterface|mixed
     */
    public function getFiles(string name = null, var defaultVal = null)
    {
        var fileParams;

        let fileParams = this->fileParams;
        if fileParams === null {
            let fileParams = new Parameters();
            let this->fileParams = fileParams;
        }

        if name === null { // todo: check is null
            return fileParams;
        }

        return fileParams->get(name, defaultVal);
    }

    /**
     * Return the header container responsible for headers or all headers of a certain name/type
     *
     * @see \Zend\Http\Headers::get()
     * @param string|null           $name            Header name to retrieve, or null to get the whole container.
     * @param mixed|null            $default         Default value to use when the requested header is missing.
     * @return \Zend\Http\Headers|bool|\Zend\Http\Header\HeaderInterface|\ArrayIterator
     */
    public function getHeaders(string name = null, var defaultVal = false) -> <Headers>|boolean|<Header\HeaderInterface>|<\ArrayIterator>
    {
        var headers;

        let headers = this->headers;
        if headers === null {
            let headers = new Headers();
            let this->headers = headers;
        } elseif typeof headers == "string" {
            let headers = <Headers> Headers::fromString(headers);
            let this->headers = headers;
        }

        if empty name { // todo: check is_null()
            return headers;
        }

        if headers->has(name) {
            return headers->get(name);
        }
        return defaultVal;
    }

    /**
     * Get all headers of a certain name/type.
     *
     * @see Request::getHeaders()
     * @param string|null           $name            Header name to retrieve, or null to get the whole container.
     * @param mixed|null            $default         Default value to use when the requested header is missing.
     * @return \Zend\Http\Headers|bool|\Zend\Http\Header\HeaderInterface|\ArrayIterator
     */
    public function getHeader(string name, var defaultVal = false) -> <Headers>|boolean|<Header\HeaderInterface>|<\ArrayIterator>
    {
        return this->getHeaders(name, defaultVal);
    }

    /**
     * Is this an OPTIONS method request?
     *
     * @return bool
     */
    public function isOptions() -> boolean
    {
        return this->method === self::METHOD_OPTIONS;
    }

    /**
     * Is this a PROPFIND method request?
     *
     * @return bool
     */
    public function isPropFind() -> boolean
    {
        return this->method === self::METHOD_PROPFIND;
    }

    /**
     * Is this a GET method request?
     *
     * @return bool
     */
    public function isGet() -> boolean
    {
        return this->method === self::METHOD_GET;
    }

    /**
     * Is this a HEAD method request?
     *
     * @return bool
     */
    public function isHead() -> boolean
    {
        return this->method === self::METHOD_HEAD;
    }

    /**
     * Is this a POST method request?
     *
     * @return bool
     */
    public function isPost() -> boolean
    {
        return this->method === self::METHOD_POST;
    }

    /**
     * Is this a PUT method request?
     *
     * @return bool
     */
    public function isPut() -> boolean
    {
        return this->method === self::METHOD_PUT;
    }

    /**
     * Is this a DELETE method request?
     *
     * @return bool
     */
    public function isDelete() -> boolean
    {
        return this->method === self::METHOD_DELETE;
    }

    /**
     * Is this a TRACE method request?
     *
     * @return bool
     */
    public function isTrace() -> boolean
    {
        return this->method === self::METHOD_TRACE;
    }

    /**
     * Is this a CONNECT method request?
     *
     * @return bool
     */
    public function isConnect() -> boolean
    {
        return this->method === self::METHOD_CONNECT;
    }

    /**
     * Is this a PATCH method request?
     *
     * @return bool
     */
    public function isPatch() -> boolean
    {
        return this->method === self::METHOD_PATCH;
    }

    /**
     * Is the request a Javascript XMLHttpRequest?
     *
     * Should work with Prototype/Script.aculo.us, possibly others.
     *
     * @return bool
     */
    public function isXmlHttpRequest() -> boolean
    {
        var headers, header, fieldValue;

        let headers = <Headers> this->getHeaders();
        let header = <Header\HeaderInterface> headers->get("X_REQUESTED_WITH");


        if header !== false {
            let fieldValue = header->getFieldValue();

            return fieldValue == "XMLHttpRequest";
        }
        return false;
    }

    /**
     * Is this a Flash request?
     *
     * @return bool
     */
    public function isFlashRequest() -> boolean
    {
        var headers, header, fieldValue;

        let headers = <Headers> this->getHeaders();
        let header = <Header\HeaderInterface> headers->get("USER_AGENT");


        if header !== false {
            let fieldValue = header->getFieldValue();

            return (boolean) stristr(fieldValue, " flash");
        }
        return false;
    }

    /**
     * Return the formatted request line (first line) for this http request
     *
     * @return string
     */
    public function renderRequestLine() -> string
    {
        var method, uri, version;

        let method = this->method;
        let uri = this->uri;
        let version = this->version;

        if typeof uri == "object" {
            let uri = uri->__toString();
        }

        return method . " " . uri . "HTTP/" . version;
    }

    /**
     * @return string
     */
    public function toString() -> string
    {
        string str;
        var line, headers, headersStr, content;

        let line = this->renderRequestLine();
        let headers = <Headers> this->getHeaders();
        let headersStr = headers->toString();
        let content = this->getContent();

        let str = line . "\r\n" . headersStr . "\r\n" . content;

        return str;
    }

}
