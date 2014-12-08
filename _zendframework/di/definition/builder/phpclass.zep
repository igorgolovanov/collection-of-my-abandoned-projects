/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di\Definition\Builder;

/**
 * Object containing definitions for a single class
 */
class PhpClass
{
    /**
     * @var string
     */
    protected defaultMethodBuilder = "Zend\Di\Definition\Builder\InjectionMethod";

    /**
     * @var null|string
     */
    protected name;

    /**
     * @var string|\Callable|array
     */
    protected instantiator = "__construct";

    /**
     * @var InjectionMethod[]
     */
    protected injectionMethods = [];

    /**
     * @var array
     */
    protected superTypes = [];

    /**
     * Set name
     *
     * @param  string   $name
     * @return PhpClass
     */
    public function setName(string name) -> <PhpClass>
    {
        let this->name = name;
        return this;
    }

    /**
     * Get name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @param  string|\Callable|array $instantiator
     * @return PhpClass
     */
    public function setInstantiator(var instantiator) -> <PhpClass>
    {
        let this->instantiator = instantiator;
        return this;
    }

    /**
     * @return array|\Callable|string
     */
    public function getInstantiator() -> array|string
    {
        return this->instantiator;
    }

    /**
     * @param  string   $superType
     * @return PhpClass
     */
    public function addSuperType(string superType) -> <PhpClass>
    {
        let this->superTypes[] = superType;

        return this;
    }

    /**
     * Get super types
     *
     * @return array
     */
    public function getSuperTypes() -> array
    {
        return this->superTypes;
    }

    /**
     * Add injection method
     *
     * @param  InjectionMethod $injectionMethod
     * @return PhpClass
     */
    public function addInjectionMethod(<InjectionMethod> injectionMethod) -> <PhpClass>
    {
        let this->injectionMethods[] = injectionMethod;
        return this;
    }

    /**
     * Create and register an injection method
     *
     * Optionally takes the method name.
     *
     * This method may be used in lieu of addInjectionMethod() in
     * order to provide a more fluent interface for building classes with
     * injection methods.
     *
     * @param  null|string     $name
     * @return InjectionMethod
     */
    public function createInjectionMethod(string name = null) -> <InjectionMethod>
    {
        var method;
        string builder;

        let builder = (string) this->defaultMethodBuilder;


        let method =  new {builder}(); //todo:<InjectionMethod>

        if name !== null {
            method->setName(name);
        }
        this->addInjectionMethod(method);

        return this;
    }

    /**
     * Override which class will be used by {@link createInjectionMethod()}
     *
     * @param  string   $class
     * @return PhpClass
     */
    public function setMethodBuilder(string className) -> <PhpClass>
    {
        let this->defaultMethodBuilder = className;
        return this;
    }

    /**
     * Determine what class will be used by {@link createInjectionMethod()}
     *
     * Mainly to provide the ability to temporarily override the class used.
     *
     * @return string
     */
    public function getMethodBuilder() -> string
    {
        return this->defaultMethodBuilder;
    }

    /**
     * @return InjectionMethod[]
     */
    public function getInjectionMethods() -> array
    {
        return this->injectionMethods;
    }

}
