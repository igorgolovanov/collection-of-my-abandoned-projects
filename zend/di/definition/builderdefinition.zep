/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition;

use Zend\Di\Exception;

/**
 * Class definitions based on a configuration array
 */
class BuilderDefinition implements DefinitionInterface
{
    /**
     * @var string
     */
    protected defaultClassBuilder = "Zend\Di\Definition\Builder\PhpClass";

    /**
     * @var Builder\PhpClass[]
     */
    protected classes; // []

    /**
     * Create classes from array
     *
     * @param  array $builderData
     * @return void
     */
    public function createClassesFromArray(array! builderData) -> void
    {

    }

    /**
     * Add class
     *
     * @param  Builder\PhpClass  $phpClass
     * @return BuilderDefinition
     */
    public function addClass(<Builder\PhpClass> phpClass) -> <BuilderDefinition>
    {
        let this->classes[] = phpClass;
        return this;
    }

    /**
     * Create a class builder object using default class builder class
     *
     * This method is a factory that can be used in place of addClass().
     *
     * @param  null|string      $name Optional name of class to assign
     * @return Builder\PhpClass
     */
    public function createClass(string name = null) -> <Builder\PhpClass>
    {
        string builderClass;
        var classObj;

        let builderClass = this->defaultClassBuilder;
        var classObj = <Builder\PhpClass> new {builderClass}();

        if name !== null {
            classObj->setName(name);
        }
        this->addClass(classObj);

        return classObj;
    }

    /**
     * Set the class to use with {@link createClass()}
     *
     * @param  string            $class
     * @return BuilderDefinition
     */
    public function setClassBuilder(string $class) -> <BuilderDefinition>
    {
        let this->defaultClassBuilder = $class;
        return this;
    }

    /**
     * Get the class used for {@link createClass()}
     *
     * This is primarily to allow developers to temporarily override
     * the builder strategy.
     *
     * @return string
     */
    public function getClassBuilder() -> string
    {
        return this->defaultClassBuilder;
    }

    /**
     * {@inheritDoc}
     */
    public function getClasses()
    {
        array classNames = [];
        var classObj;

        for classObj in this->classes {
            let classNames[] = classObj->getName();
        }
        return classNames;
    }

    /**
     * {@inheritDoc}
     */
    public function hasClass(string $class) -> boolean
    {
        boolean result = false;
        var classObj;
        string name;

        for classObj in this->classes {
            let name = classObj->getName();
            if name === $class {
                let result = true;
                break;
            }
        }

        return result;
    }

    /**
     * @param  string                $name
     * @return bool|Builder\PhpClass
     */
    protected function getClass(string name) -> boolean|<Builder\PhpClass>
    {
        var classObj, result = false;
        string name;

        for classObj in this->classes {
            let name = classObj->getName();
            if name === $class {
                let result = classObj;
                break;
            }
        }

        return result;
    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getClassSupertypes(string $class)
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getInstantiator($class)
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function hasMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function hasMethod($class, method)
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
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getMethodParameters($class, method)
    {

    }

}
