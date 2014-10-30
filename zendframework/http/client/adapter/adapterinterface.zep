/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Client\Adapter;

//use Zend\Uri\UriInterface;

/**
 * An interface description for Zend\Http\Client\Adapter classes.
 *
 * These classes are used as connectors for Zend\Http\Client, performing the
 * tasks of connecting, writing, reading and closing connection to the server.
 */
interface AdapterInterface
{
    /**
     * Set the configuration array for the adapter
     *
     * @param array $options
     */
    public function setOptions(array options = []);

    /**
     * Connect to the remote server
     *
     * @param string  $host
     * @param int     $port
     * @param  bool $secure
     */
    public function connect(string host, int port = 80, boolean secure = false);

    /**
     * Send request to the remote server
     *
     * @param string        $method
     * @param UriInterface  $url
     * @param string        $httpVer
     * @param array         $headers
     * @param string        $body
     * @return string Request as text
     */
    public function write(string method, var url, string httpVer = "1.1", array headers = [], string body = "") -> string;
    // todo: <UriInterface>

    /**
     * Read response from server
     *
     * @return string
     */
    public function read() -> string;

    /**
     * Close the connection to the server
     *
     */
    public function close();

}
