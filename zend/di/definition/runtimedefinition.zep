/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition;

use Zend\Code\Annotation\AnnotationCollection;
use Zend\Code\Reflection;
use Zend\Di\Di;

/**
 * Class definitions based on runtime reflection
 */
class RuntimeDefinition implements DefinitionInterface
{
    /**
     * @var array
     */
    protected classes; // []

    /**
     * @var bool
     */
    protected explicitLookups = false;

    /**
     * @var IntrospectionStrategy
     */
    protected introspectionStrategy;

    /**
     * @var array
     */
    protected injectionMethods; // []

    /**
     * Constructor
     *
     * @param null|IntrospectionStrategy $introspectionStrategy
     * @param array|null                 $explicitClasses
     */
    public function __construct(<IntrospectionStrategy> introspectionStrategy = null, array! explicitClasses = null)
    {

    }

    /**
     * @param  IntrospectionStrategy $introspectionStrategy
     * @return void
     */
    public function setIntrospectionStrategy(<IntrospectionStrategy> introspectionStrategy) -> void
    {

    }

    /**
     * @return IntrospectionStrategy
     */
    public function getIntrospectionStrategy() -> <IntrospectionStrategy>
    {

    }

    /**
     * Set explicit classes
     *
     * @param array $explicitClasses
     */
    public function setExplicitClasses(array! explicitClasses)
    {

    }

    /**
     * @param string $class
     */
    public function forceLoadClass(string $class)
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
     * @param string $class
     */
    protected function hasProcessedClass(string $class)
    {

    }

    /**
     * @param string $class
     * @param bool $forceLoad
     */
    protected function processClass(string $class, boolean forceLoad = false)
    {

    }

    /**
     * @param array                                  $def
     * @param \Zend\Code\Reflection\ClassReflection  $rClass
     * @param \Zend\Code\Reflection\MethodReflection $rMethod
     */
    protected function processParams(array def, <\Zend\Code\Reflection\ClassReflection> rClass, <\Zend\Code\Reflection\MethodReflection> rMethod)
    {

    }

}
