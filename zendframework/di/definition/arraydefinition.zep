/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di\Definition;

use Zend\Di\Definition\Builder\InjectionMethod;

/**
 * Class definitions based on a given array
 */
class ArrayDefinition implements DefinitionInterface
{
    /**
     * @var array
     */
    protected dataArray = [];

    /**
     * @param array $dataArray
     */
    public function __construct(array! dataArray)
    {
        var className, type, definition, requirement, methods;

        for className, definition in dataArray {
            let definition = array_change_key_case(definition, CASE_LOWER);

            if fetch methods, definition["methods"] {
                if typeof methods == "array" {
                    for requirement, type in methods {
                        if typeof requirement != "integer"  {
                            let definition["methods"][type] = InjectionMethod::detectMethodRequirement(requirement);
                        }
                    }
                }
            }
            let dataArray[className] = definition;
        }
        let this->dataArray = dataArray;
    }

    /**
     * {@inheritDoc}
     */
    public function getClasses() -> array
    {
        var classes;
        let classes = array_keys(this->dataArray);

        return classes;
    }

    /**
     * {@inheritDoc}
     */
    public function hasClass(string $class) -> boolean
    {
        return array_key_exists($class, this->dataArray);
    }

    /**
     * {@inheritDoc}
     */
    public function getClassSupertypes(string $class) -> array
    {
        var classData, supertypes;
        array emptyArray = [];

        if fetch classData, this->dataArray[$class] {
            if fetch supertypes, classData["supertypes"] {
                return supertypes;
            }
        }

        return emptyArray;
    }

    /**
     * {@inheritDoc}
     */
    public function getInstantiator(string $class) -> string|array
    {
        var classData, instantiator;

        if fetch classData, this->dataArray[$class] {
            if !fetch instantiator, classData["instantiator"] {
                let instantiator = "__construct";
            }
        }
        return instantiator;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethods(string $class) -> boolean
    {
        var classData, methods;
        int count = 0;

        if fetch classData, this->dataArray[$class] {
            if fetch methods, classData["methods"] {
                let count = count(methods);
            }
        }
        return count > 0;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethod(string $class, string method) -> boolean
    {
        var classData, methods;

        if fetch classData, this->dataArray[$class] {
            if fetch methods, classData["methods"] {
                if isset methods[method] {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function getMethods(string $class) -> array
    {
        var classData, methods;
        array emptyArray = [];

        if fetch classData, this->dataArray[$class] {
            if fetch methods, classData["methods"] {
                return methods;
            }
        }

        return emptyArray;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethodParameters(string $class, string method) -> boolean
    {
        return isset this->dataArray[$class]["parameters"][method];
    }

    /**
     * {@inheritDoc}
     */
    public function getMethodParameters(string $class, string method) -> boolean
    {
        var params, classParams, methodParams;
        array emptyArray = [];

        if fetch params, this->dataArray[$class] {
            if fetch classParams, params["parameters"] {
                if fetch methodParams, classParams[method] {
                    return methodParams;
                }
            }
        }

        return emptyArray;
    }

    /**
     * @return array
     */
    public function toArray() -> array
    {
        return this->dataArray;
    }

}
