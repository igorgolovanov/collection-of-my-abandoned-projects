/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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
    protected dataArray; // []

    /**
     * @param array $dataArray
     */
    public function __construct(array! dataArray)
    {
        string className, type;
        var definition, requirement;

        for definition, className in dataArray {
            let definition = array_change_key_case(definition, CASE_LOWER);

            if isset definition["methods"] && typeof definition["methods"] == "array" {
                for requirement, type in definition["methods"] {
                    if typeof requirement != "int"  {
                        let definition["methods"][type] = InjectionMethod::detectMethodRequirement(requirement);
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
        array classes;
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
    public function getClassSupertypes($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getInstantiator($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethod($class, method)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethodParameters($class, method)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getMethodParameters($class, method)
    {

    }

    /**
     * @return array
     */
    public function toArray() -> array
    {
        return this->dataArray;
    }

}
