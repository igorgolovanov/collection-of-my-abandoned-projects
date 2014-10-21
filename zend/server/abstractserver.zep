/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

use ReflectionClass;

/**
 * Abstract Server implementation
 */
abstract class AbstractServer implements Server
{
    /**
     * @var bool Flag; whether or not overwriting existing methods is allowed
     */
    protected overwriteExistingMethods = false;

    /**
     * @var Definition
     */
    protected table;

    /**
     * Constructor
     *
     * Setup server description
     *
     */
    public function __construct()
    {
        var table;
        boolean overwriteExistingMethods;


        let table = new Definition();
        let this->table = table;
        let overwriteExistingMethods = this->overwriteExistingMethods;

        table->setOverwriteExistingMethods(overwriteExistingMethods);
    }

    /**
     * Returns a list of registered methods
     *
     * Returns an array of method definitions.
     *
     * @return Definition
     */
    public function getFunctions() -> <Definition>
    {
        return this->table;
    }

    /**
     * Build callback for method signature
     *
     * @param  Reflection\AbstractFunction $reflection
     * @return Method\Callback
     */
    protected function _buildCallback(<Reflection\AbstractFunction> reflection) -> <Method\Callback>
    {
        var callback, declaredClass;
        string name, type, className;

        let callback = new Method\Callback();
        let name = reflection->getName();

        if reflection instanceof Reflection\ReflectionMethod {
            if reflection->isStatic() {
                callback->setType("static");
            } else {
                callback->setType("instance");
            }
            let declaredClass = <ReflectionClass> reflection->getDeclaringClass();
            let className = declaredClass->getName();

            callback->setClass(className);
            callback->setMethod(name);
        } else {
            if reflection instanceof Reflection\ReflectionFunction {
                callback->setType("function");
                callback->setFunction(name);
            }
        }

        return callback;
    }

    /**
     * Build a method signature
     *
     * @param  Reflection\AbstractFunction $reflection
     * @param  null|string|object $class
     * @return Method\Definition
     * @throws Exception\RuntimeException on duplicate entry
     */
    protected function _buildSignature(<Reflection\AbstractFunction> reflection, var $class = null) -> <Method\Definition>
    {

    }

    /**
     * Dispatch method
     *
     * @param  Method\Definition $invokable
     * @param  array $params
     * @return mixed
     */
    protected function _dispatch(<Method\Definition> invokable, array! params)
    {

    }

    /**
     * Map PHP type to protocol type
     *
     * @param  string $type
     * @return string
     */
    abstract protected function _fixType(string type) -> string;

}
