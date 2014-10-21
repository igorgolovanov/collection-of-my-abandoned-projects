/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Method;

use Zend\Server;

/**
 * Method definition metadata
 */
class Definition
{
    /**
     * @var \Zend\Server\Method\Callback
     */
    protected callback;

    /**
     * @var array
     */
    protected invokeArguments = [];

    /**
     * @var string
     */
    protected methodHelp = "";

    /**
     * @var string
     */
    protected name;

    /**
     * @var null|object
     */
    protected $object;

    /**
     * @var array Array of \Zend\Server\Method\Prototype objects
     */
    protected prototypes = [];

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
     * Set object state from options
     *
     * @param  array $options
     * @return \Zend\Server\Method\Definition
     */
    public function setOptions(array! options) -> self
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
     * Set method name
     *
     * @param  string $name
     * @return \Zend\Server\Method\Definition
     */
    public function setName(string name) -> self
    {
        let this->name = name;

        return this;
    }

    /**
     * Get method name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Set method callback
     *
     * @param  array|\Zend\Server\Method\Callback $callback
     * @throws Server\Exception\InvalidArgumentException
     * @return \Zend\Server\Method\Definition
     */
    public function setCallback(var callback) -> self
    {
        if typeof callback == "array" {
            let callback = new Callback(callback);
        } else {
            if unlikely !(callback instanceof Callback) {
                throw new Server\Exception\InvalidArgumentException("Invalid method callback provided");
            }
        }
        let this->callback = callback;

        return this;
    }

    /**
     * Get method callback
     *
     * @return \Zend\Server\Method\Callback
     */
    public function getCallback() -> <Callback>
    {
        return this->callback;
    }

    /**
     * Add prototype to method definition
     *
     * @param  array|\Zend\Server\Method\Prototype $prototype
     * @throws Server\Exception\InvalidArgumentException
     * @return \Zend\Server\Method\Definition
     */
    public function addPrototype(var prototype) -> self
    {
        if typeof prototype == "array" {
            let prototype = new Prototype(callback);
        } else {
            if unlikely !(prototype instanceof Prototype) {
                throw new Server\Exception\InvalidArgumentException("Invalid method prototype provided");
            }
        }
        let this->prototypes[] = prototype;

        return this;
    }

    /**
     * Add multiple prototypes at once
     *
     * @param  array $prototypes Array of \Zend\Server\Method\Prototype objects or arrays
     * @return \Zend\Server\Method\Definition
     */
    public function addPrototypes(array! prototypes) -> self
    {
        var prototype;
        for prototype in prototypes {
            this->addPrototype(prototype);
        }

        return this;
    }

    /**
     * Set all prototypes at once (overwrites)
     *
     * @param  array $prototypes Array of \Zend\Server\Method\Prototype objects or arrays
     * @return \Zend\Server\Method\Definition
     */
    public function setPrototypes(array! prototypes) -> self
    {
        let this->prototypes = [];
        this->addPrototypes(prototypes);

        return this;
    }

    /**
     * Get all prototypes
     *
     * @return array $prototypes Array of \Zend\Server\Method\Prototype objects or arrays
     */
    public function getPrototypes() -> array
    {
        return this->prototypes;
    }

    /**
     * Set method help
     *
     * @param  string $methodHelp
     * @return \Zend\Server\Method\Definition
     */
    public function setMethodHelp(string methodHelp) -> <Definition>
    {
        let this->methodHelp = methodHelp;

        return this;
    }

    /**
     * Get method help
     *
     * @return string
     */
    public function getMethodHelp() -> string
    {
        return this->methodHelp;
    }

    /**
     * Set object to use with method calls
     *
     * @param  object $object
     * @throws Server\Exception\InvalidArgumentException
     * @return \Zend\Server\Method\Definition
     */
    public function setObject(object $object) -> self
    {
        string exceptionMsg;

        if unlikely typeof $object != "object" && $object !== null {
            let exceptionMsg = "Invalid object passed to " . __CLASS__ . "::" . __METHOD__;
            throw new Server\Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->$object = $object;

        return this;
    }

    /**
     * Get object to use with method calls
     *
     * @return null|object
     */
    public function getObject() -> object
    {
        return this->$object;
    }

    /**
     * Set invoke arguments
     *
     * @param  array $invokeArguments
     * @return \Zend\Server\Method\Definition
     */
    public function setInvokeArguments(array! invokeArguments) -> self
    {
        let this->invokeArguments = invokeArguments;

        return this;
    }

    /**
     * Retrieve invoke arguments
     *
     * @return array
     */
    public function getInvokeArguments() -> array
    {
        return this->invokeArguments;
    }

    /**
     * Serialize to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        array prototypes, signatures = [], data = [];
        var prototype, callback;

        let prototypes = this->getPrototypes();
        for prototype in prototypes {
            let signatures[] = prototype->toArray();
        }
        let callback = <Callback> this->getCallback();

        let data["name"] = this->getName();
        let data["callback"] = callback->toArray();
        let data["prototypes"] = signatures;
        let data["methodHelp"] = this->getMethodHelp();
        let data["invokeArguments"] = this->getInvokeArguments();
        let data["object"] = this->getObject();

        return data;
    }

}
