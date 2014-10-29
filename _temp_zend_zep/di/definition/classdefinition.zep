/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition;

/**
 * Class definitions for a single class
 */
class ClassDefinition implements DefinitionInterface, PartialMarker
{
    /**
     * @var null|string
     */
    protected $class;

    /**
     * @var string[]
     */
    protected supertypes; // []

    /**
     * @var null|\Callable|array|string
     */
    protected instantiator;

    /**
     * @var bool[]
     */
    protected methods; // []

    /**
     * @var array
     */
    protected methodParameters; // []

    /**
     * @param string $class
     */
    public function __construct(string $class)
    {

    }

    /**
     * @param  null|\Callable|array|string $instantiator
     * @return self
     */
    public function setInstantiator(var instantiator) -> <ClassDefinition>
    {

    }

    /**
     * @param  string[] $supertypes
     * @return self
     */
    public function setSupertypes(array! supertypes) -> <ClassDefinition>
    {

    }

    /**
     * @param  string    $method
     * @param  mixed|bool|null $isRequired
     * @return self
     */
    public function addMethod(string method, isRequired = null) -> <ClassDefinition>
    {

    }

    /**
     * @param $method
     * @param $parameterName
     * @param  array           $parameterInfo (keys: required, type)
     * @return ClassDefinition
     */
    public function addMethodParameter(method, parameterName, array! parameterInfo) -> <ClassDefinition>
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getClasses()
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasClass($class)
    {

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
    public function getMethods($class)
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
    public function hasMethodParameters($class, method)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getMethodParameters($class, method)
    {

    }

}
