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
    public function __construct(<ReflectionClass> $class, <ReflectionMethod> r, string $namespace = null, var argv = [])
    {
        string classNamespace, className;

        let this->classReflection = $class;
        let this->reflection = r;

        let classNamespace = $class->getNamespace();

        // Determine namespace
        if !empty $namespace {
            this->setNamespace($namespace);
        } else {
            if !empty classNamespace {
                this->setNamespace(classNamespace);
            }
        }

        // Determine arguments
        if typeof argv == "array" {
            let this->argv = argv;
        }

        // If method call, need to store some info on the class
        let className = $class->getName()
        this->$class = className;
        // Perform some introspection
        this->reflect();
    }

    /**
     * Return the reflection for the class that defines this method
     *
     * @return \Zend\Server\Reflection\ReflectionClass
     */
    public function getDeclaringClass() -> <ReflectionClass>
    {
        return this->classReflection;
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
        array args;
        string className, className2, ns;
        var classRefl, classRefl2, methodRefl;

        let ns = this->getNamespace();
        let className = this->$class;
        let args = this->getInvokeArguments();

        let classRefl = new \ReflectionClass(className);
        let classRefl2 = new ReflectionClass(classRefl, ns, args);
        let className2 = classRefl2->getName();
        let methodRefl = \ReflectionMethod(className2, className);

        let this->classReflection = classRefl;
        let this->reflection = methodRefl;
    }

}
