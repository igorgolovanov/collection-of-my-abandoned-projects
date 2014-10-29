/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

use Zend\Server\Reflection\ReflectionClass;
use Zend\Server\Reflection\ReflectionFunction;

/**
 * Reflection for determining method signatures to use with server classes
 */
class Reflection
{
    /**
     * Perform class reflection to create dispatch signatures
     *
     * Creates a {@link \Zend\Server\Reflection\ClassReflection} object for the class or
     * object provided.
     *
     * If extra arguments should be passed to dispatchable methods, these may
     * be provided as an array to $argv.
     *
     * @param string|object $class Class name or object
     * @param  bool|array $argv Optional arguments to be used during the method call
     * @param string $namespace Optional namespace with which to prefix the
     * method name (used for the signature key). Primarily to avoid collisions,
     * also for XmlRpc namespacing
     * @return \Zend\Server\Reflection\ReflectionClass
     * @throws \Zend\Server\Reflection\Exception\InvalidArgumentException
     */
    public static function reflectClass(var $class, var argv = false, string $namespace = "") -> <ReflectionClass>
    {
        var reflection;

        if typeof $class == "object" {
            let reflection = new \ReflectionObject($class);
        } else {
            if unlikely !class_exists($class) {
                throw new Reflection\Exception\InvalidArgumentException("Invalid class or object passed to attachClass()");
            } 
            let reflection = new \ReflectionClass($class);
        }

        if unlikely typeof argv != "array" {
            throw new Reflection\Exception\InvalidArgumentException("Invalid argv argument passed to reflectClass");
        }

        return new ReflectionClass(reflection, $namespace, argv);
    }

    /**
     * Perform function reflection to create dispatch signatures
     *
     * Creates dispatch prototypes for a function. It returns a
     * {@link Zend\Server\Reflection\FunctionReflection} object.
     *
     * If extra arguments should be passed to the dispatchable function, these
     * may be provided as an array to $argv.
     *
     * @param string $function Function name
     * @param  bool|array $argv Optional arguments to be used during the method call
     * @param string $namespace Optional namespace with which to prefix the
     * function name (used for the signature key). Primarily to avoid
     * collisions, also for XmlRpc namespacing
     * @return \Zend\Server\Reflection\ReflectionFunction
     * @throws \Zend\Server\Reflection\Exception\InvalidArgumentException
     */
    public static function reflectFunction(string $function, var argv = false, string $namespace = "") -> <Reflection\ReflectionFunction>
    {
        string exceptionMsg;
        var reflection;

        if unlikely empty $function || !function_exists($function) {
            let exceptionMsg = "Invalid function \"" . $function . "\" passed to reflectFunction";
            throw new Reflection\Exception\InvalidArgumentException(exceptionMsg);
        }

        if unlikely typeof argv != "array" {
            throw new Reflection\Exception\InvalidArgumentException("Invalid argv argument passed to reflectFunction");
        }

        let reflection = new \ReflectionFunction($function);

        return new ReflectionFunction(reflection, $namespace, argv);
    }

}
