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
    protected classes = [];

    /**
     * Create classes from array
     *
     * @param  array $builderData
     * @return void
     */
    public function createClassesFromArray(array! builderData) -> void
    {
        var className, classInfo, instance, builder, 
            type, typeData, superType, 
            injectionMethodName, injectionMethodData, injectionMethod, 
            parameterName, parameterType;

        for className, classInfo in builderData {
            let builder = new Builder\PhpClass();
            builder->setName(className);

            for type, typeData in classInfo {
                switch strtolowe(type) {
                    case "supertypes":
                        for superType in typeData {
                            builder->addSuperType(superType);
                        }
                        break;
                    case "instantiator":
                        builder->setInstantiator(typeData);
                        break;    
                    case "methods":
                    case "method":
                        for injectionMethodName, injectionMethodData in typeData {
                            let injectionMethod = new Builder\InjectionMethod();
                            injectionMethod->setName(injectionMethodName);

                            for parameterName, parameterType in injectionMethodData {
                                if !parameterType {
                                    let parameterType = null;
                                }
                                injectionMethod->addParameter(parameterName, parameterType);
                            }
                            builder->addInjectionMethod(injectionMethod);
                        }
                        break;    
                }
            }
            this->addClass(builder);
        }
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
    public function getClassSupertypes(string $class) -> array
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getInstantiator(string $class) -> string|array
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function hasMethods(string $class) -> boolean
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getMethods(string $class) -> array
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function hasMethod(string $class, string method) -> boolean
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethodParameters(string $class, string method) -> boolean
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\RuntimeException
     */
    public function getMethodParameters(string $class, string method) -> array
    {

    }

}
