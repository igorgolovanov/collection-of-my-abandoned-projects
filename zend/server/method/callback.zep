/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Method;

use Zend\Server;

/**
 * Method callback metadata
 */
class Callback
{
    /**
     * @var string Class name for class method callback
     */
    protected $class;

    /**
     * @var string Function name for function callback
     */
    protected $function;

    /**
     * @var string Method name for class method callback
     */
    protected method;

    /**
     * @var string Callback type
     */
    protected type;

    /**
     * @var array Valid callback types
     */
    protected types = ["function", "static", "instance"];

    /**
     * Constructor
     *
     * @param  null|array $options
     */
    public function __construct(var options = null)
    {
        if typeof options == "array" {
            this->setOptions(options);
        }
    }

    /**
     * Set object state from array of options
     *
     * @param  array $options
     * @return \Zend\Server\Method\Callback
     */
    public function setOptions(array! options) -> <Callback>
    {
        var key, value;
        string methodName;

        for key, value in options {
            let methodName = ucfirst(key);
            let methodName = "set" . methodName;

            if method_exists(this, methodName) {
                this->{methodName}(value);
            }
        }
        
        return this;
    }

    /**
     * Set callback class
     *
     * @param  string $class
     * @return \Zend\Server\Method\Callback
     */
    public function setClass(var $class) -> <Callback>
    {
        if typeof $class == "object" {
            let $class = get_class($class);
        }
        let this->$class = $class;

        retrun this;
    }

    /**
     * Get callback class
     *
     * @return string|null
     */
    public function getClass() -> string
    {
        return this->$class;
    }

    /**
     * Set callback function
     *
     * @param  string $function
     * @return \Zend\Server\Method\Callback
     */
    public function setFunction(string $function) -> <Callback>
    {
        let this->$function = $function;
        this->setType("function");

        return this;
    }

    /**
     * Get callback function
     *
     * @return null|string
     */
    public function getFunction() -> string
    {
        return this->$function;
    }

    /**
     * Set callback class method
     *
     * @param  string $method
     * @return \Zend\Server\Method\Callback
     */
    public function setMethod(string method) -> <Callback>
    {
        let this->method = method;

        return this;
    }

    /**
     * Get callback class  method
     *
     * @return null|string
     */
    public function getMethod() -> string
    {
        return this->method;
    }

    /**
     * Set callback type
     *
     * @param  string $type
     * @return Callback
     * @throws Server\Exception\InvalidArgumentException
     */
    public function setType(string type) -> <Callback>
    {
        string exceptionMsg;

        if unlikely !in_array(type, this->types) {
            let exceptionMsg = "Invalid method callback type \"" . type . "\" passed to " . __CLASS__ . "::" . __METHOD__;
        }

        let this->type = type;

        return this;
    }

    /**
     * Get callback type
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Cast callback to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        string type;
        array data = [];

        let type = this->getType();
        let data["type"] = type;

        if type == "function" {
            let data["function"] = this->getFunction();
        } else {
            let data["class"] = this->getClass();
            let data["method"] = this->getMethod();
        }

        return data;
    }

}
