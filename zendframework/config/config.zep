/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Config;

use ArrayAccess;
use Countable;
use Iterator;
/**
 * Provides a property based interface to an array.
 * The data are read-only unless $allowModifications is set to true
 * on construction.
 *
 * Implements Countable, Iterator and ArrayAccess
 * to facilitate easy access to the data.
 */
class Config implements Countable, Iterator, ArrayAccess
{
    /**
     * Whether modifications to configuration data are allowed.
     *
     * @var bool
     */
    protected allowModifications;

    /**
     * Number of elements in configuration data.
     *
     * @var int
     */
    protected count;

    /**
     * Data within the configuration.
     *
     * @var array
     */
    protected data = [];

    /**
     * Used when unsetting values during iteration to ensure we do not skip
     * the next element.
     *
     * @var bool
     */
    protected skipNextIteration;

    /**
     * Constructor.
     *
     * Data is read-only unless $allowModifications is set to true
     * on construction.
     *
     * @param  array   $array
     * @param  bool $allowModifications
     */
    public function __construct(array! $array, boolean allowModifications = false)
    {
        var k, v, className;

        let this->allowModifications = allowModifications;
        let className = get_class(this);

        for k, v in $array {
            if typeof v == "array" {
                let v = new {className}(v, allowModifications);
            }
            let this->data[k] = v;
            let this->count++;
        }
    }

    /**
     * Retrieve a value and return $default if there is no element set.
     *
     * @param  string $name
     * @param  mixed  $defaultVal
     * @return mixed
     */
    public function get(string name, defaultVal = null)
    {
        var val;

        if fetch val, this->data[name] {
            return val;
        }
        return defaultVal;
    }

    /**
     * Magic function so that $obj->value will work.
     *
     * @param  string $name
     * @return mixed
     */
    public function __get(string name)
    {
        return this->get(name);
    }

    /**
     * Set a value in the config.
     *
     * Only allow setting of a property if $allowModifications  was set to true
     * on construction. Otherwise, throw an exception.
     *
     * @param  string $name
     * @param  mixed  $value
     * @return void
     * @throws Exception\RuntimeException
     */
    public function __set(string name, var value) -> void
    {
        var className;

        if unlikely !this->allowModifications {
            throw new Exception\RuntimeException("Config is read only");
        }
        if typeof value == "array" {
            let className = get_class(this);
            let value = new {className}(value, true);
        }
        if name === null {
            let this->data[] = value;
        } else {
            let this->data[name] = value;
        }
    }

    /**
     * Deep clone of this instance to ensure that nested Zend\Configs are also
     * cloned.
     *
     * @return void
     */
    public function __clone() -> void
    {
        var data = [], k, v;

        for k, v in this->data {
            if v instanceof Config {
                let data[k] = clone v;
            } else {
                let data[k] = v;
            }
        }
        let this->data = data;
    }

    /**
     * Return an associative array of the stored data.
     *
     * @return array
     */
    public function toArray() -> array
    {
        var data = [], k, v;

        for k, v in this->data {
            if v instanceof Config {
                let data[k] = v->toArray();
            } else {
                let data[k] = v;
            }
        }
        return data;
    }

    /**
     * isset() overloading
     *
     * @param  string $name
     * @return bool
     */
    public function __isset(string name) -> boolean
    {
        return isset this->data[name];
    }

    /**
     * unset() overloading
     *
     * @param  string $name
     * @return void
     * @throws Exception\InvalidArgumentException
     */
    public function __unset(string name) -> void
    {
        if unlikely !this->allowModifications {
            throw new Exception\RuntimeException("Config is read only");
        }

        if isset this->data[name] {
            unset this->data[name];
            let this->count--;
            let this->skipNextIteration = true;
        }
    }

    /**
     * count(): defined by Countable interface.
     *
     * @see    Countable::count()
     * @return int
     */
    public function count() -> int
    {
        return this->count;
    }

    /**
     * current(): defined by Iterator interface.
     *
     * @see    Iterator::current()
     * @return mixed
     */
    public function current()
    {
        let this->skipNextIteration = false;

        return current(this->data);
    }

    /**
     * key(): defined by Iterator interface.
     *
     * @see    Iterator::key()
     * @return mixed
     */
    public function key()
    {
        return key(this->data);
    }

    /**
     * next(): defined by Iterator interface.
     *
     * @see    Iterator::next()
     * @return void
     */
    public function next() -> void
    {
        if this->skipNextIteration {
            let this->skipNextIteration = false;
            return;
        }
        next(this->data);
    }

    /**
     * rewind(): defined by Iterator interface.
     *
     * @see    Iterator::rewind()
     * @return void
     */
    public function rewind() -> void
    {
        let this->skipNextIteration = false;
        reset(this->data);
    }

    /**
     * valid(): defined by Iterator interface.
     *
     * @see    Iterator::valid()
     * @return bool
     */
    public function valid() -> boolean
    {
        var key;
        let key = this->key();

        return key !== null;
    }

    /**
     * offsetExists(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetExists()
     * @param  mixed $offset
     * @return bool
     */
    public function offsetExists(var offset) -> boolean
    {
        return this->__isset(offset);
    }

    /**
     * offsetGet(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetGet()
     * @param  mixed $offset
     * @return mixed
     */
    public function offsetGet(var offset)
    {
        return this->__get(offset);
    }

    /**
     * offsetSet(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetSet()
     * @param  mixed $offset
     * @param  mixed $value
     * @return void
     */
    public function offsetSet(var offset, var value) -> void
    {
        this->__set(offset, value);
    }

    /**
     * offsetUnset(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetUnset()
     * @param  mixed $offset
     * @return void
     */
    public function offsetUnset(offset) -> void
    {
        this->__unset(offset);
    }

    /**
     * Merge another Config with this one.
     *
     * For duplicate keys, the following will be performed:
     * - Nested Configs will be recursively merged.
     * - Items in $merge with INTEGER keys will be appended.
     * - Items in $merge with STRING keys will overwrite current values.
     *
     * @param  Config $merge
     * @return Config
     */
    public function merge(<Config> merge) -> <Config>
    {
        var k, v, v2, className, data, allowModifications;

        let className = get_class(this);
        let allowModifications = this->allowModifications;

        for k, v in iterator(merge) {
            if fetch v2, this->data[k] {
                if typeof k == "integer" {
                    let this->data[] = v;
                } elseif v instanceof Config && v2 instanceof Config {
                    v2->merge(v);
                } else {
                    let data = v->toArray();
                    if v instanceof Config {
                         let data = v->toArray();
                         let v = new {className}(data, allowModifications);
                    }
                    let this->data[k] = v;
                }
            } else {
                if v instanceof Config {
                    let data = v->toArray();
                    let v = new {className}(data, allowModifications);
                }
                let this->data[k] = v;
                let this->count++;
            }
        }

        return this;
    }

    /**
     * Prevent any more modifications being made to this instance.
     *
     * Useful after merge() has been used to merge multiple Config objects
     * into one object which should then not be modified again.
     *
     * @return void
     */
    public function setReadOnly() -> void
    {
        var val;

        let this->allowModifications = false;

        for val in this->data {
            if val instanceof Config {
                val->setReadOnly();
            }
        }
    }

    /**
     * Returns whether this Config object is read only or not.
     *
     * @return bool
     */
    public function isReadOnly() -> boolean
    {
        return !this->allowModifications;
    }

}
