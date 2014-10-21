/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

/**
 * Server methods metadata
 */
class Definition implements \Countable, \Iterator, \Traversable
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
    public function __construct(array methods = null)
    {

    }

    /**
     * Set flag indicating whether or not overwriting existing methods is allowed
     *
     * @param mixed $flag
     * @return \Zend\Server\Definition
     */
    public function setOverwriteExistingMethods(flag) -> <Definition>
    {

    }

    /**
     * Add method to definition
     *
     * @param  array|\Zend\Server\Method\Definition $method
     * @param  null|string $name
     * @return \Zend\Server\Definition
     * @throws \Zend\Server\Exception\InvalidArgumentException if duplicate or invalid method provided
     */
    public function addMethod(var method, string name = null) -> <Definition>
    {

    }

    /**
     * Add multiple methods
     *
     * @param  array $methods Array of \Zend\Server\Method\Definition objects or arrays
     * @return \Zend\Server\Definition
     */
    public function addMethods(array! methods) -> <Definition>
    {

    }

    /**
     * Set all methods at once (overwrite)
     *
     * @param  array $methods Array of \Zend\Server\Method\Definition objects or arrays
     * @return \Zend\Server\Definition
     */
    public function setMethods(array! methods) -> <Definition>
    {

    }

    /**
     * Does the definition have the given method?
     *
     * @param  string $method
     * @return bool
     */
    public function hasMethod(string method) -> boolean
    {

    }

    /**
     * Get a given method definition
     *
     * @param  string $method
     * @return null|\Zend\Server\Method\Definition
     */
    public function getMethod(string method) -> <Method\Definition>
    {

    }

    /**
     * Get all method definitions
     *
     * @return array Array of \Zend\Server\Method\Definition objects
     */
    public function getMethods() -> array
    {

    }

    /**
     * Remove a method definition
     *
     * @param  string $method
     * @return \Zend\Server\Definition
     */
    public function removeMethod(string method) -> <Definition>
    {

    }

    /**
     * Clear all method definitions
     *
     * @return \Zend\Server\Definition
     */
    public function clearMethods() -> <Definition>
    {

    }

    /**
     * Cast definition to an array
     *
     * @return array
     */
    public function toArray() -> array
    {

    }

    /**
     * Countable: count of methods
     *
     * @return int
     */
    public function count() -> int
    {

    }

    /**
     * Iterator: current item
     *
     * @return Method\Definition
     */
    public function current() -> <Method\Definition>
    {

    }

    /**
     * Iterator: current item key
     *
     * @return int|string
     */
    public function key() -> int|string
    {

    }

    /**
     * Iterator: advance to next method
     *
     * @return Method\Definition
     */
    public function next() -> <Method\Definition>
    {

    }

    /**
     * Iterator: return to first method
     *
     * @return void
     */
    public function rewind() -> void
    {

    }

    /**
     * Iterator: is the current index valid?
     *
     * @return bool
     */
    public function valid() -> boolean
    {

    }

}
