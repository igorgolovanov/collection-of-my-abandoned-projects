/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use Traversable;

class Message implements MessageInterface
{
    /**
     * @var array
     */
    protected metadata = [];

    /**
     * @var string
     */
    protected content = "";

    /**
     * Set message metadata
     *
     * Non-destructive setting of message metadata; always adds to the metadata, never overwrites
     * the entire metadata container.
     *
     * @param  string|int|array|Traversable $spec
     * @param  mixed $value
     * @throws Exception\InvalidArgumentException
     * @return Message
     */
    public function setMetadata(var spec, var value = null) -> <Message>
    {
        string type, exceptionMsg;
        var key, val;

        if is_scalar(spec) {
            let this->metadata[spec] = value;
            return this;
        }

        if unlikely typeof spec != "array" && !(spec instanceof Traversable) {
            let type = typeof spec;
            if type == "object" {
                let type = get_class(spec);
            }
            let exceptionMsg = "Expected a string, array, or Traversable argument in first position; received \"" . type . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if typeof spec == "object" {
            for key, val in iterator(spec) {
                let this->metadata[key] = val;
            }
        } else {
            for key, val in spec {
                let this->metadata[key] = val;
            }
        }


        return this;
    }

    /**
     * Retrieve all metadata or a single metadatum as specified by key
     *
     * @param  null|string|int $key
     * @param  null|mixed $default
     * @throws Exception\InvalidArgumentException
     * @return mixed
     */
    public function getMetadata(var key = null, var defaultVal = null)
    {
        var v;

        if key === null {
            return this->metadata;
        }

        if unlikely !is_scalar(key) {
            throw new Exception\InvalidArgumentException("Non-scalar argument provided for key");
        }

        if fetch v, this->metadata[key] {
            return v;
        }
        return defaultVal;
    }

    /**
     * Set message content
     *
     * @param  mixed $value
     * @return Message
     */
    public function setContent(var value) -> <Message>
    {
        let this->content = value;
        return this;
    }

    /**
     * Get message content
     *
     * @return mixed
     */
    public function getContent()
    {
        return this->content;
    }

    /**
     * @return string
     */
    public function toString() -> string
    {
        string request = "", content;
        var key, value, metadata;

        let metadata = this->getMetadata();

        for key, value in metadata {
            let request = request . sprintf("%s: %s\r\n", key, value);
        }
        let content = (string) this->getContent();
        let request = request . "\r\n" . content;

        return request;
    }

}
