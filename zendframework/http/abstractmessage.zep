/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

use Zend\Stdlib\Message;

/**
 * HTTP standard message (Request/Response)
 *
 * @link      http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4
 */
abstract class AbstractMessage extends Message
{
    /**#@+
     * @const string Version constant numbers
     */
    const VERSION_10 = "1.0";
    const VERSION_11 = "1.1";
    //**#@-*/

    /**
     * @var string
     */
    protected version = "1.1";

    /**
     * @var Headers|null
     */
    protected headers;

    /**
     * Set the HTTP version for this object, one of 1.0 or 1.1
     * (AbstractMessage::VERSION_10, AbstractMessage::VERSION_11)
     *
     * @param  string $version (Must be 1.0 or 1.1)
     * @return AbstractMessage
     * @throws Exception\InvalidArgumentException
     */
    public function setVersion(string version) -> <AbstractMessage>
    {
        string exceptionMsg;

        if unlikely version != self::VERSION_10 && version != self::VERSION_11 {
            let exceptionMsg = "Not valid or not supported HTTP version: " . version;
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->version = version;

        return this;
    }

    /**
     * Return the HTTP version for this request
     *
     * @return string
     */
    public function getVersion() -> string
    {
        return this->version;
    }

    /**
     * Provide an alternate Parameter Container implementation for headers in this object,
     * (this is NOT the primary API for value setting, for that see getHeaders())
     *
     * @see    getHeaders()
     * @param  Headers $headers
     * @return AbstractMessage
     */
    public function setHeaders(<Headers> headers) -> <AbstractMessage>
    {
        let this->headers = headers;
        return this;
    }

    /**
     * Return the header container responsible for headers
     *
     * @return Headers
     */
    public function getHeaders() -> <Headers>
    {
        var headers;

        let headers = this->headers;
        if headers === null || typeof headers == "string" {
            // this is only here for fromString lazy loading
            if typeof headers == "string" {
                let headers = Headers::fromString(headers);
            } else {
                let headers = new Headers();
            }
            let this->headers = headers;
        }

        return headers;
    }

    /**
     * Allow PHP casting of this object
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->toString();
    }

}
