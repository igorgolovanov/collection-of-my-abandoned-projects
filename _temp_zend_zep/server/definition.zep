/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

use Countable;
use Iterator;

/**
 * Server methods metadata
 */
class Definition implements Countable, Iterator
{
    /**
     * @var array Array of \Zend\Server\Method\Definition objects
     */
    protected methods = [];

    /**
     * @var bool Whether or not overwriting existing methods is allowed
     */
    protected overwriteExistingMethods = false;

    /**
     * Constructor
     *
     * @param  null|array $methods
     */
    public function __construct(var methods = null)
    {
        if typeof methods == "array" {
            this->setMethods(methods);
        }
    }

    /**
     * Set flag indicating whether or not overwriting existing methods is allowed
     *
     * @param mixed $flag
     * @return \Zend\Server\Definition
     */
    public function setOverwriteExistingMethods(boolean flag) -> <Definition>
    {
        let this->overwriteExistingMethods = flag;

        return this;
    }

    /**
     * Add method to definition
     *
     * @param  array|\Zend\Server\Method\Definition $method
     * @param  null|string $name
     * @return \Zend\Server\Definition
     * @throws \Zend\Server\Exception\InvalidArgumentException if duplicate or invalid method provided
     */
    public function addMethod(var method, var name = null) -> <Definition>
    {
        string exceptionMsg;

        if typeof method == "array" {
            let method = new Method\Definition(method);
        } else {
            if unlikely !(method instanceof Method\Definition) {
                throw new Exception\InvalidArgumentException("Invalid method provided");
            }
        }

        if typeof name = "integer" || typeof name = "double" {
            let name = null;
        }

        if name !== null {
            method->setName(name);
        } else {
            let name = method->getName();
        }

        if unlikely name === null {
            throw new Exception\InvalidArgumentException("No method name provided");
        }

        if !this->overwriteExistingMethods && isset this->methods[name] {
            let exceptionMsg = "Method by name of \"" . name . "\" already exists";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->methods[name] = method;

        return this;
    }

    /**
     * Add multiple methods
     *
     * @param  array $methods Array of \Zend\Server\Method\Definition objects or arrays
     * @return \Zend\Server\Definition
     */
    public function addMethods(array! methods) -> <Definition>
    {
        var key, method;

        for key, method in methods {
            this->addMethod(method, key);
        }

        return this;
    }

    /**
     * Set all methods at once (overwrite)
     *
     * @param  array $methods Array of \Zend\Server\Method\Definition objects or arrays
     * @return \Zend\Server\Definition
     */
    public function setMethods(array! methods) -> <Definition>
    {
        this->clearMethods();
        this->addMethods(methods);

        return this;
    }

    /**
     * Does the definition have the given method?
     *
     * @param  string $method
     * @return bool
     */
    public function hasMethod(string method) -> boolean
    {
        return array_key_exists(method, this->methods);
    }

    /**
     * Get a given method definition
     *
     * @param  string $method
     * @return null|\Zend\Server\Method\Definition
     */
    public function getMethod(string method) -> <Method\Definition>|boolean
    {
        if this->hasMethod(method) {
            return this->methods[method];
        }
        return false;
    }

    /**
     * Get all method definitions
     *
     * @return array Array of \Zend\Server\Method\Definition objects
     */
    public function getMethods() -> array
    {
        return this->methods;
    }

    /**
     * Remove a method definition
     *
     * @param  string $method
     * @return \Zend\Server\Definition
     */
    public function removeMethod(string method) -> <Definition>
    {
        if this->hasMethod(method) {
            unset this->methods[method];
        }
        return this;
    }

    /**
     * Clear all method definitions
     *
     * @return \Zend\Server\Definition
     */
    public function clearMethods() -> <Definition>
    {
        let this->methods = [];
        return this;
    }

    /**
     * Cast definition to an array
     *
     * @return array
     */
    public function toArray() -> array
    {
        array result = [], methods;
        var method, key;

        let methods = this->getMethods();
        for key, method in methods {
            let result[key] = method->toArray();
        }

        return result;
    }

    /**
     * Countable: count of methods
     *
     * @return int
     */
    public function count() -> int
    {
        var count;
        let count = count(this->methods);

        return count;
    }

    /**
     * Iterator: current item
     *
     * @return Method\Definition
     */
    public function current() -> <Method\Definition>
    {
        var current;
        let current = <Method\Definition> current(this->methods);

        return current;
    }

    /**
     * Iterator: current item key
     *
     * @return int|string
     */
    public function key() -> int|string
    {
        var key;
        let key = key(this->methods);

        return key;
    }

    /**
     * Iterator: advance to next method
     *
     * @return Method\Definition
     */
    public function next() -> <Method\Definition>
    {
        var next;
        let next = next(this->methods);

        return next;
    }

    /**
     * Iterator: return to first method
     *
     * @return void
     */
    public function rewind() -> void
    {
        reset(this->methods);
    }

    /**
     * Iterator: is the current index valid?
     *
     * @return bool
     */
    public function valid() -> boolean
    {
        boolean valid;

        let valid = this->current();

        return valid;
    }

}
