/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Config;

/**
 * Provides a property based interface to an array.
 * The data are read-only unless $allowModifications is set to true
 * on construction.
 *
 * Implements Countable, Iterator and ArrayAccess
 * to facilitate easy access to the data.
 */
class Config implements \Countable, \Iterator, \Traversable, \ArrayAccess
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

    }

    /**
     * Retrieve a value and return $default if there is no element set.
     *
     * @param  string $name
     * @param  mixed  $default
     * @return mixed
     */
    public function get(string name, $default = null)
    {

    }

    /**
     * Magic function so that $obj->value will work.
     *
     * @param  string $name
     * @return mixed
     */
    public function __get(string name)
    {

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
    public function __set(string name, value) -> void
    {

    }

    /**
     * Deep clone of this instance to ensure that nested Zend\Configs are also
     * cloned.
     *
     * @return void
     */
    public function __clone() -> void
    {

    }

    /**
     * Return an associative array of the stored data.
     *
     * @return array
     */
    public function toArray() -> array
    {

    }

    /**
     * isset() overloading
     *
     * @param  string $name
     * @return bool
     */
    public function __isset(string name) -> boolean
    {

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

    }

    /**
     * count(): defined by Countable interface.
     *
     * @see    Countable::count()
     * @return int
     */
    public function count() -> int
    {

    }

    /**
     * current(): defined by Iterator interface.
     *
     * @see    Iterator::current()
     * @return mixed
     */
    public function current()
    {

    }

    /**
     * key(): defined by Iterator interface.
     *
     * @see    Iterator::key()
     * @return mixed
     */
    public function key()
    {

    }

    /**
     * next(): defined by Iterator interface.
     *
     * @see    Iterator::next()
     * @return void
     */
    public function next() -> void
    {

    }

    /**
     * rewind(): defined by Iterator interface.
     *
     * @see    Iterator::rewind()
     * @return void
     */
    public function rewind() -> void
    {

    }

    /**
     * valid(): defined by Iterator interface.
     *
     * @see    Iterator::valid()
     * @return bool
     */
    public function valid() -> boolean
    {

    }

    /**
     * offsetExists(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetExists()
     * @param  mixed $offset
     * @return bool
     */
    public function offsetExists(offset) -> boolean
    {

    }

    /**
     * offsetGet(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetGet()
     * @param  mixed $offset
     * @return mixed
     */
    public function offsetGet(offset)
    {

    }

    /**
     * offsetSet(): defined by ArrayAccess interface.
     *
     * @see    ArrayAccess::offsetSet()
     * @param  mixed $offset
     * @param  mixed $value
     * @return void
     */
    public function offsetSet(offset, value) -> void
    {

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

    }

    /**
     * Returns whether this Config object is read only or not.
     *
     * @return bool
     */
    public function isReadOnly() -> boolean
    {

    }

}
