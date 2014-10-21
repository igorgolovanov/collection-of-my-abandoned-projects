/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use ReflectionParameter;

class ParameterReflection extends ReflectionParameter implements ReflectionInterface
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
