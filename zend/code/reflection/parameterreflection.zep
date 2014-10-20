
namespace Zend\Code\Reflection;

class ParameterReflection extends \ReflectionParameter implements \Reflector, ReflectionInterface
{
    /**
     * @var bool
     */
    protected isFromMethod = false;

    /**
     * Get declaring class reflection object
     *
     * @return ClassReflection
     */
    public function getDeclaringClass() -> <ClassReflection>
    {

    }

    /**
     * Get class reflection object
     *
     * @return ClassReflection
     */
    public function getClass() -> <ClassReflection>
    {

    }

    /**
     * Get declaring function reflection object
     *
     * @return FunctionReflection|MethodReflection
     */
    public function getDeclaringFunction() -> <FunctionReflection>|<MethodReflection>
    {

    }

    /**
     * Get parameter type
     *
     * @return string
     */
    public function getType() -> string
    {

    }

    public function toString()
    {

    }

    public function __toString()
    {

    }

}
