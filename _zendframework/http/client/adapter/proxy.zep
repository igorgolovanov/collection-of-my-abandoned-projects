/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Client\Adapter;

/**
 * HTTP Proxy-supporting Zend\Http\Client adapter class, based on the default
 * socket based adapter.
 *
 * Should be used if proxy HTTP access is required. If no proxy is set, will
 * fall back to Zend\Http\Client\Adapter\Socket behavior. Just like the
 * default Socket adapter, this adapter does not require any special extensions
 * installed.
 */
class Proxy extends Socket
{
    /**
     * Parameters array
     *
     * @var array
     */
    protected config = [
		"ssltransport": "ssl", 
		"sslcert": null, 
		"sslpassphrase": null, 
		"sslverifypeer": true, 
		"sslcapath": null, 
		"sslallowselfsigned": false, 
		"sslusecontext": false, 
		"proxy_host": "", 
		"proxy_port": 8080, 
		"proxy_user": "", 
		"proxy_pass": "", 
		"proxy_auth": "basic", 
		"persistent": false
	];

    /**
     * Whether HTTPS CONNECT was already negotiated with the proxy or not
     *
     * @var bool
     */
    protected negotiated = false;

    /**
     * Set the configuration array for the adapter
     *
     * @param array $options
     */
    public function setOptions(array options = [])
    {

    }

    /**
     * Connect to the remote server
     *
     * Will try to connect to the proxy server. If no proxy was set, will
     * fall back to the target server (behave like regular Socket adapter)
     *
     * @param string  $host
     * @param int     $port
     * @param  bool $secure
     * @throws AdapterException\RuntimeException
     */
    public function connect(string host, int port = 80, boolean secure = false)
    {

    }

    /**
     * Send request to the proxy server
     *
     * @param string        $method
     * @param \Zend\Uri\Uri $uri
     * @param string        $httpVer
     * @param array         $headers
     * @param string        $body
     * @throws AdapterException\RuntimeException
     * @return string Request as string
     */
    public function write(string method, <\Zend\Uri\Uri> uri, string httpVer = "1.1", array headers = [], string body = "") -> string
    {

    }

    /**
     * Preform handshaking with HTTPS proxy using CONNECT method
     *
     * @param string  $host
     * @param int $port
     * @param string  $httpVer
     * @param array   $headers
     * @throws AdapterException\RuntimeException
     */
    protected function connectHandshake(string host, int port = 443, string httpVer = "1.1", array! headers = [])
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
     * Destructor: make sure the socket is disconnected
     *
     */
    public function __destruct()
    {

    }

}
