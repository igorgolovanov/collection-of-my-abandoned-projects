/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Client\Adapter;

/**
 * An adapter class for Zend\Http\Client based on the curl extension.
 * Curl requires libcurl. See for full requirements the PHP manual: http://php.net/curl
 */
class Curl implements AdapterInterface, StreamInterface
{
    /**
     * Parameters array
     *
     * @var array
     */
    protected config = [];

    /**
     * What host/port are we connected to?
     *
     * @var array
     */
    protected connectedTo = [
		null, 
		null
	];

    /**
     * The curl session handle
     *
     * @var resource|null
     */
    protected curl;

    /**
     * List of cURL options that should never be overwritten
     *
     * @var array
     */
    protected invalidOverwritableCurlOptions;

    /**
     * Response gotten from server
     *
     * @var string
     */
    protected response;

    /**
     * Stream for storing output
     *
     * @var resource
     */
    protected outputStream;

    /**
     * Adapter constructor
     *
     * Config is set using setOptions()
     *
     * @throws AdapterException\InitializationException
     */
    public function __construct()
    {

    }

    /**
     * Set the configuration array for the adapter
     *
     * @param  array|Traversable $options
     * @return Curl
     * @throws AdapterException\InvalidArgumentException
     */
    public function setOptions(var options = []) -> <Curl>
    {

    }

    /**
      * Retrieve the array of all configuration options
      *
      * @return array
      */
    public function getConfig() -> array
    {

    }

    /**
     * Direct setter for cURL adapter related options.
     *
     * @param  string|int $option
     * @param  mixed $value
     * @return Curl
     */
    public function setCurlOption(var option, value) -> <Curl>
    {

    }

    /**
     * Initialize curl
     *
     * @param  string  $host
     * @param  int     $port
     * @param  bool $secure
     * @return void
     * @throws AdapterException\RuntimeException if unable to connect
     */
    public function connect(string host, int port = 80, boolean secure = false) -> void
    {

    }

    /**
     * Send request to the remote server
     *
     * @param  string        $method
     * @param  \Zend\Uri\Uri $uri
     * @param  float         $httpVersion
     * @param  array         $headers
     * @param  string        $body
     * @return string        $request
     * @throws AdapterException\RuntimeException If connection fails, connected to wrong host, no PUT file defined, unsupported method, or unsupported cURL option
     * @throws AdapterException\InvalidArgumentException if $method is currently not supported
     */
    public function write(string method, <\Zend\Uri\Uri> uri, float httpVersion = 1.1, array headers = [], string body = "") -> string
    {

    }

    /**
     * Return read response from server
     *
     * @return string
     */
    public function read() -> string
    {

    }

    /**
     * Close the connection to the server
     *
     */
    public function close()
    {

    }

    /**
     * Get cUrl Handle
     *
     * @return resource
     */
    public function getHandle() -> resource
    {

    }

    /**
     * Set output stream for the response
     *
     * @param resource $stream
     * @return Curl
     */
    public function setOutputStream(resource stream) -> <Curl>
    {

    }

    /**
     * Header reader function for CURL
     *
     * @param resource $curl
     * @param string $header
     * @return int
     */
    public function readHeader(resource curl, string header) -> int
    {

    }

}
