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
        string ns, name, method, exceptionMsg, description, 
            returnType, type;
        var definition, proto, prototype, table, callback, 
            parameter, param, defaultValue;
        array invokeArgs, prototypes, parameters, paramOptions;

        let ns = reflection->getNamespace();
        let name = reflection->getName();
        let method = name;

        if !empty ns {
            let method = ns . "." . method;
        }
        let table = <Definition> this->table;

        if unlikely !this->overwriteExistingMethods && table->hasMethod(method) {
            let exceptionMsg = "Duplicate method registered: " . method;
            throw new Exception\RuntimeException(exceptionMsg);
        }

        let definition = new Method\Definition();
        let callback = <Method\Callback> this->_buildCallback(reflection);
        let description = reflection->getDescription();
        let invokeArgs = reflection->getInvokeArguments();

        definition->setName(method);
        definition->setCallback(callback);
        definition->setMethodHelp(description);
        definition->setInvokeArguments(invokeArgs);

        let methods = reflection->getMethods();
        for proto in methods {
            let prototype = new Method\Prototype(); 
            let returnType = proto->getReturnType();
            let returnType = this-_fixType(returnType);

            prototype->setReturnType(returnType);

            let parameters = this->getParameters();
            for parameter in parameters {
                let type = parameter->getType();
                let type = this->_fixType(type);

                let paramOptions = [];
                let paramOptions["type"] = type;
                let paramOptions["name"] = parameter->getName();
                let paramOptions["optional"] = parameter->isOptional();

                let param = Method\Parameter(paramOptions);

                if parameter->isDefaultValueAvailable() {
                    let defaultValue = parameter->getDefaultValue();
                    param->setDefaultValue(defaultValue);
                }
                prototype->addParameter(param);
            }
            definition->addPrototype(prototype);
        }

        if typeof $class == "object" {
            definition->setObject($class);
        }

        table->addMethod(definition);

        return definition;
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
        var callback, func, result, obj, reflection;
        string type, className, methodName;
        array options, invokeArgs;

        let callback = <Method\Callback> invokable->getCallback();
        let type = callback->getType();

        if type == "function" {
            let func = callback->getFunction();
            let result = call_user_func_array(func, params);

            return result;
        }

        let className = callback->getClass();
        let methodName = callback->getMethod();

        if type == "static" {
            let options = [className, methodName];
            let result = call_user_func_array(options, params);

            return result;
        }

        let obj = invokable->getObject();

        if typeof obj != "object" {
            let invokeArgs = invokable->getInvokeArguments();
            if empty invokeArgs {
                let reflection = new ReflectionClass(className);
                let obj = reflection->newInstanceArgs(invokeArgs);
            } else {
                let obj = new {className}();
            }
        }

        let options = [obj, methodName];
        let result = call_user_func_array(options, params);

        return result;
    }

    /**
     * Map PHP type to protocol type
     *
     * @param  string $type
     * @return string
     */
    abstract protected function _fixType(string type) -> string;

}
