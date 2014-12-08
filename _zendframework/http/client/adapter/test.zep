/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Client\Adapter;

/**
 * A testing-purposes adapter.
 *
 * Should be used to test all components that rely on Zend\Http\Client,
 * without actually performing an HTTP request. You should instantiate this
 * object manually, and then set it as the client's adapter. Then, you can
 * set the expected response using the setResponse() method.
 */
class Test implements AdapterInterface
{
    /**
     * Parameters array
     *
     * @var array
     */
    protected config = [];

    /**
     * Buffer of responses to be returned by the read() method.  Can be
     * set using setResponse() and addResponse().
     *
     * @var array
     */
    protected responses = [
		"HTTP/1.1 400 Bad Request

"
	];

    /**
     * Current position in the response buffer
     *
     * @var int
     */
    protected responseIndex = 0;

    /**
     * Whether or not the next request will fail with an exception
     *
     * @var bool
     */
    protected nextRequestWillFail = false;

    /**
     * Adapter constructor, currently empty. Config is set using setOptions()
     */
    public function __construct()
    {

    }

    /**
     * Set the nextRequestWillFail flag
     *
     * @param  bool $flag
     * @return \Zend\Http\Client\Adapter\Test
     */
    public function setNextRequestWillFail(boolean flag) -> <Test>
    {

    }

    /**
     * Set the configuration array for the adapter
     *
     * @param  array|Traversable $options
     * @throws Exception\InvalidArgumentException
     */
    public function setOptions(var options = [])
    {

    }

    /**
     * Connect to the remote server
     *
     * @param  string $host
     * @param  int    $port
     * @param  bool   $secure
     * @throws Exception\RuntimeException
     */
    public function connect(string host, int port = 80, boolean secure = false)
    {

    }

    /**
     * Send request to the remote server
     *
     * @param string        $method
     * @param \Zend\Uri\Uri $uri
     * @param string        $httpVer
     * @param array         $headers
     * @param string        $body
     * @return string Request as string
     */
    public function write(string method, <\Zend\Uri\Uri> uri, string httpVer = "1.1", array headers = [], string body = "") -> string
    {

    }

    /**
     * Return the response set in $this->setResponse()
     *
     * @return string
     */
    public function read() -> string
    {

    }

    /**
     * Close the connection (dummy)
     *
     */
    public function close()
    {

    }

    /**
     * Set the HTTP response(s) to be returned by this adapter
     *
     * @param \Zend\Http\Response|array|string $response
     */
    public function setResponse(var response)
    {

    }

    /**
     * Add another response to the response buffer.
     *
     * @param string|Response $response
     */
    public function addResponse(string response)
    {

    }

    /**
     * Sets the position of the response buffer.  Selects which
     * response will be returned on the next call to read().
     *
     * @param int $index
     * @throws Exception\OutOfRangeException
     */
    public function setResponseIndex(int index)
    {

    }

}
