/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

/**
 * Method Reflection
 */
class ReflectionMethod extends AbstractFunction
{
    /**
     * Parent class name
     * @var string
     */
    protected $class;

    /**
     * Parent class reflection
     * @var ReflectionClass
     */
    protected classReflection;

    /**
     * Constructor
     *
     * @param ReflectionClass $class
     * @param \ReflectionMethod $r
     * @param string $namespace
     * @param array $argv
     */
    public function __construct(<ReflectionClass> $class, <ReflectionMethod> r, string $namespace = null, array argv = [])
    {

    }

    /**
     * Return the reflection for the class that defines this method
     *
     * @return \Zend\Server\Reflection\ReflectionClass
     */
    public function getDeclaringClass() -> <ReflectionClass>
    {

    }

    /**
     * Wakeup from serialization
     *
     * Reflection needs explicit instantiation to work correctly. Re-instantiate
     * reflection object on wakeup.
     *
     * @return void
     */
    public function __wakeup() -> void
    {

    }

}
