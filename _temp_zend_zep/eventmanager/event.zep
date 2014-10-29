/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

/**
 * Representation of an event
 *
 * Encapsulates the target context and parameters passed, and provides some
 * behavior for interacting with the event manager.
 */
class Event implements EventInterface
{
    /**
     * @var string Event name
     */
    protected name;

    /**
     * @var string|object The event target
     */
    protected target;

    /**
     * @var array|ArrayAccess|object The event parameters
     */
    protected params = [];

    /**
     * @var bool Whether or not to stop propagation
     */
    protected stopPropagation = false;

    /**
     * Constructor
     *
     * Accept a target and its parameters.
     *
     * @param  string $name Event name
     * @param  string|object $target
     * @param  array|ArrayAccess $params
     */
    public function __construct(string name = null, var target = null, var params = null)
    {
        if !empty name {
            this->setName(name);
        }
        if target !== null {
            this->setTarget(target);
        }
        if params !== null {
            this->setParams(params);
        }
    }

    /**
     * Get event name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Get the event target
     *
     * This may be either an object, or the name of a static method.
     *
     * @return string|object
     */
    public function getTarget() -> string|object
    {
        return this->target;
    }

    /**
     * Set parameters
     *
     * Overwrites parameters
     *
     * @param  array|ArrayAccess|object $params
     * @return Event
     * @throws Exception\InvalidArgumentException
     */
    public function setParams(var params) -> <Event>
    {
        string type, exceptionMsg;

        let type = typeof params;
        if type != "array" && type != "object" {
            let exceptionMsg = "Event parameters must be an array or object; received \"" . type . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->params = params;

        return this;
    }

    /**
     * Get all parameters
     *
     * @return array|object|ArrayAccess
     */
    public function getParams() -> array|object|<\ArrayAccess>
    {
        return this->params;
    }

    /**
     * Get an individual parameter
     *
     * If the parameter does not exist, the $default value will be returned.
     *
     * @param  string|int $name
     * @param  mixed $default
     * @return mixed
     */
    public function getParam(var name, var $default = null)
    {
        var params, item;
        let params = this->params;

        if typeof params == "array" || params instanceof \ArrayAccess {
            if fetch item, params[name] {
                return item;        
            } 
            return $default;
        }
        if isset params->{name} {
            return params->{name};
        }
        return $default;
    }

    /**
     * Set the event name
     *
     * @param  string $name
     * @return Event
     */
    public function setName(string name) -> <Event>
    {
        let this->name = name;
        return this;
    }

    /**
     * Set the event target/context
     *
     * @param  null|string|object $target
     * @return Event
     */
    public function setTarget(var target) -> <Event>
    {
        let this->target = target;
        return this;
    }

    /**
     * Set an individual parameter to a value
     *
     * @param  string|int $name
     * @param  mixed $value
     * @return Event
     */
    public function setParam(var name, value) -> <Event>
    {
        var params;

        if typeof params == "array" || params instanceof \ArrayAccess {
            let this->params[name] = value;
        } else {
            let params = this->params;
            let params->{name} = value;
        }
        return this;
    }

    /**
     * Stop further event propagation
     *
     * @param  bool $flag
     * @return void
     */
    public function stopPropagation(boolean flag = true) -> void
    {
        let this->stopPropagation = flag;
    }

    /**
     * Is propagation stopped?
     *
     * @return bool
     */
    public function propagationIsStopped() -> boolean
    {
        return this->stopPropagation;
    }

}
