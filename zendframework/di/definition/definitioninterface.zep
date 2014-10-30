/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di\Definition;

interface DefinitionInterface
{
    /**
     * Retrieves classes in this definition
     *
     * @abstract
     * @return string[]
     */
    public function getClasses() -> array;

    /**
     * Return whether the class exists in this definition
     *
     * @abstract
     * @param  string $class
     * @return bool
     */
    public function hasClass(string $class) -> boolean;

    /**
     * Return the supertypes for this class
     *
     * @abstract
     * @param  string   $class
     * @return string[]
     */
    public function getClassSupertypes(string $class) -> array;

    /**
     * @abstract
     * @param  string       $class
     * @return string|array
     */
    public function getInstantiator(string $class) -> string|array;

    /**
     * Return if there are injection methods
     *
     * @abstract
     * @param  string $class
     * @return bool
     */
    public function hasMethods(string $class) -> boolean;

    /**
     * Return an array of the injection methods for a given class
     *
     * @abstract
     * @param  string   $class
     * @return string[]
     */
    public function getMethods(string $class) -> array;

    /**
     * @abstract
     * @param  string $class
     * @param  string $method
     * @return bool
     */
    public function hasMethod(string $class, string method) -> boolean;

    /**
     * @abstract
     * @param $class
     * @param $method
     * @return bool
     */
    public function hasMethodParameters(string $class, string method) -> boolean;

    /**
     * getMethodParameters() return information about a methods parameters.
     *
     * Should return an ordered named array of parameters for a given method.
     * Each value should be an array, of length 4 with the following information:
     *
     * array(
     *     0, // string|null: Type Name (if it exists)
     *     1, // bool: whether this param is required
     *     2, // string: fully qualified path to this parameter
     *     3, // mixed: default value
     * );
     *
     *
     * @abstract
     * @param  string $class
     * @param  string $method
     * @return array
     */
    public function getMethodParameters(string $class, string method) -> array;

}
