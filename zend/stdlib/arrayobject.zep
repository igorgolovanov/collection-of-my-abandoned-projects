/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

use ArrayAccess;
use Countable;
use IteratorAggregate;
use Serializable;

/**
* Custom framework ArrayObject implementation
*
* Extends version-specific "abstract" implementation.
*/
class ArrayObject implements IteratorAggregate, ArrayAccess, Serializable, Countable
{
    /**
     * Properties of the object have their normal functionality
     * when accessed as list (var_dump, foreach, etc.).
     */
    const STD_PROP_LIST = 1;
    
    /**
     * Entries can be accessed as properties (read and write).
     */
    const ARRAY_AS_PROPS = 2;

    /**
     * @var array
     */
    protected storage;

    /**
     * @var int
     */
    protected flag;

    /**
     * @var string
     */
    protected iteratorClass;

    /**
     * @var array
     */
    protected protectedProperties;

    /**
     * Constructor
     *
     * @param array  $input
     * @param int    $flags
     * @param string $iteratorClass
     */
    public function __construct(array input = [], int flags = self::STD_PROP_LIST, string iteratorClass = "ArrayIterator")
    {
        this->setFlags(flags);
        let this->storage = input;
        this->setIteratorClass(iteratorClass);
        let this->protectedProperties = array_keys(get_object_vars(this));
    }

    /**
     * Returns whether the requested key exists
     *
     * @param  mixed $key
     * @return bool
     */
    public function __isset(var key) -> boolean
    {
        string exceptionMsg;
        if this->flag == self::ARRAY_AS_PROPS {
            return this->offsetExists(key);
        }
        if unlikely in_array(key, this->protectedProperties) {
            let exceptionMsg = "\"" . key . "\" is a protected property, use a different key";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        return isset this->{key};
    }

    /**
     * Sets the value at the specified key to value
     *
     * @param  mixed $key
     * @param  mixed $value
     * @return void
     */
    public function __set(var key, var value) -> void
    {
        string exceptionMsg;

        if this->flag == self::ARRAY_AS_PROPS {
            return this->offsetSet(key, value);
        }
        if unlikely in_array(key, this->protectedProperties) {
            let exceptionMsg = "\"" . key . "\" is a protected property, use a different key";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->{key} = value;
    }

    /**
     * Unsets the value at the specified key
     *
     * @param  mixed $key
     * @return void
     */
    public function __unset(var key) -> void
    {
        string exceptionMsg;

        if this->flag == self::ARRAY_AS_PROPS {
            return this->offsetUnset(key);
        }
        if unlikely in_array(key, this->protectedProperties) {
            let exceptionMsg = "\"" . key . "\" is a protected property, use a different key";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        unset this->{key};
    }

    /**
     * Returns the value at the specified key by reference
     *
     * @param  mixed $key
     * @return mixed
     */
    public function &__get(var key)
    {
        string exceptionMsg;
        var ret;

        if this->flag == self::ARRAY_AS_PROPS {
            let ret =& this->offsetGet(key);
            return ret;
        }
        if unlikely in_array(key, this->protectedProperties) {
            let exceptionMsg = "\"" . key . "\" is a protected property, use a different key";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        return this->{key};
    }

    /**
     * Appends the value
     *
     * @param  mixed $value
     * @return void
     */
    public function append(var value) -> void
    {
        let this->storage[] = value;
    }

    /**
     * Sort the entries by value
     *
     * @return void
     */
    public function asort() -> void
    {
        asort(this->storage);
    }

    /**
     * Get the number of public properties in the ArrayObject
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->storage);
    }

    /**
     * Exchange the array for another one.
     *
     * @param  array|ArrayObject $data
     * @return array
     */
    public function exchangeArray(var data) -> array
    {
        string type;
        array storage;

        let type = typeof data;
        if unlikely type != "array" && type != "object" {
            throw new Exception\InvalidArgumentException("Passed variable is not an array or object, using empty array instead");
        }

        if type == "object" && (type instanceof ArrayObject || type instanceof \ArrayObject) {
            let data = data->getArrayCopy();
        }

        let storage = this->storage;
        let this->storage = data;

        return storage;
    }

    /**
     * Creates a copy of the ArrayObject.
     *
     * @return array
     */
    public function getArrayCopy() -> array
    {
        return this->storage;
    }

    /**
     * Gets the behavior flags.
     *
     * @return int
     */
    public function getFlags() -> int
    {
        return this->flag;
    }

    /**
     * Create a new iterator from an ArrayObject instance
     *
     * @return \Iterator
     */
    public function getIterator() -> <\Iterator>
    {
        string className;
        var itertor;
        array storage;

        let storage = this->storage;
        let className = this->iteratorClass;
        let iterator = <\Iterator> new {className}(storage);

        return iterator;
    }

    /**
     * Gets the iterator classname for the ArrayObject.
     *
     * @return string
     */
    public function getIteratorClass() -> string
    {
        return this->iteratorClass;
    }

    /**
     * Sort the entries by key
     *
     * @return void
     */
    public function ksort() -> void
    {
        ksort(this->storage);
    }

    /**
     * Sort an array using a case insensitive "natural order" algorithm
     *
     * @return void
     */
    public function natcasesort() -> void
    {
        natcasesort(this->storage);
    }

    /**
     * Sort entries using a "natural order" algorithm
     *
     * @return void
     */
    public function natsort() -> void
    {
        natsort(this->storage);
    }

    /**
     * Returns whether the requested key exists
     *
     * @param  mixed $key
     * @return bool
     */
    public function offsetExists(key) -> boolean
    {
        return isset this->storage[key];
    }

    /**
     * Returns the value at the specified key
     *
     * @param  mixed $key
     * @return mixed
     */
    public function &offsetGet(key)
    {
        var ret = null;

        if !this->offsetExists(key) {
            return ret;
        }

        let ret =& this->storage[key];

        return ret;
    }

    /**
     * Sets the value at the specified key to value
     *
     * @param  mixed $key
     * @param  mixed $value
     * @return void
     */
    public function offsetSet(var key, var value) -> void
    {
        let this->storage[key] = value;
    }

    /**
     * Unsets the value at the specified key
     *
     * @param  mixed $key
     * @return void
     */
    public function offsetUnset(var key) -> void
    {
        if this->offsetExists(key) {
            unset this->storage[key];
        }
    }

    /**
     * Serialize an ArrayObject
     *
     * @return string
     */
    public function serialize() -> string
    {
        array vars;
        string serialized;

        let vars = get_object_vars(this);
        let serialized = serialize(vars);

        return serialized;
    }

    /**
     * Sets the behavior flags
     *
     * @param  int  $flags
     * @return void
     */
    public function setFlags(int flags) -> void
    {
        let this->flag = flags;
    }

    /**
     * Sets the iterator classname for the ArrayObject
     *
     * @param  string $class
     * @return void
     */
    public function setIteratorClass(string $class) -> void
    {
        if class_exists($class) {
            let this->iteratorClass = $class;
            return;
        }

        if strpos($class, "\\") === 0 {
            let $class = "\\" + $class;
            if class_exists($class) {
                let this->iteratorClass = $class;
                return; 
            }
        }

        throw new Exception\InvalidArgumentException("The iterator class does not exist");
    }

    /**
     * Sort the entries with a user-defined comparison function and maintain key association
     *
     * @param  callable $function
     * @return void
     */
    public function uasort(callable $function) -> void
    {
        if is_callable($function) {
            uasort(this->storage, $function);
        }
    }

    /**
     * Sort the entries by keys using a user-defined comparison function
     *
     * @param  callable $function
     * @return void
     */
    public function uksort(callable $function) -> void
    {
        if is_callable($function) {
            uksort(this->storage, $function);
        }
    }

    /**
     * Unserialize an ArrayObject
     *
     * @param  string $data
     * @return void
     */
    public function unserialize(string data) -> void
    {
        array unserialized, vars;
        var k, v;

        let unserialized = unserialize(data);
        let vars = get_object_vars(this);
        let this->protectedProperties = array_keys(vars);

        this->setFlags(unserialized["flag"]);
        this->exchangeArray(unserialized["storage"]);
        this->setIteratorClass(unserialized["iteratorClass"]);

        for v, k in unserialized {
            case "flag":
                this->setFlags(v);
                break;

            case "storage":
                this->exchangeArray(v);
                break;

            case "iteratorClass":
                this->setIteratorClass(v);
                break;

            case "protectedProperties":
                break;

            default:
                this->__set(k, v);
        }
    }

}
