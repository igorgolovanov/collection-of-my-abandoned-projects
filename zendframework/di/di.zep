/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di;

use Closure;
use ReflectionClass;
use Zend\Di\Exception\RuntimeException as DiRuntimeException;
use Zend\ServiceManager\Exception\ExceptionInterface as ServiceManagerException;

/**
 * Dependency injector that can generate instances using class definitions and configured instance parameters
 */
class Di implements DependencyInjectionInterface
{
    /**
     * Resolve method policy
     *
     * EAGER: explore type preference or go through
     */
    const RESOLVE_EAGER = 1;

    /**
     * Resolve method policy
     *
     * STRICT: explore type preference or throw exception
     */
    const RESOLVE_STRICT = 2;

    /**
     *
     * use only specified parameters
     */
    const METHOD_IS_OPTIONAL = 0;

    /**
     *
     * resolve mode RESOLVE_EAGER
     */
    const METHOD_IS_AWARE = 1;

    /**
     *
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_CONSTRUCTOR = 3;

    /**
     *
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_INSTANTIATOR = 3;

    /**
     *
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_REQUIRED = 3;

    /**
     *
     * resolve mode RESOLVE_EAGER
     */
    const METHOD_IS_EAGER = 1;

    /**
     * @var DefinitionList
     */
    protected definitions;

    /**
     * @var InstanceManager
     */
    protected instanceManager;

    /**
     * @var string
     */
    protected instanceContext = [];

    /**
     * All the class dependencies [source][dependency]
     *
     * @var array
     */
    protected currentDependencies = [];

    /**
     * All the dependenent aliases
     *
     * @var array
     */
    protected currentAliasDependenencies = [];

    /**
     * All the class references [dependency][source]
     *
     * @var array
     */
    protected references = [];

    /**
     * Constructor
     *
     * @param null|DefinitionList  $definitions
     * @param null|InstanceManager $instanceManager
     * @param null|Config   $config
     */
    public function __construct(<DefinitionList> definitions = null, <InstanceManager> instanceManager = null, <Config> config = null)
    {
        if definitions === null {
            let definitions = new DefinitionList(new Definition\RuntimeDefinition());
        }
        if instanceManager === null {
            let instanceManager = new InstanceManager();
        }

        let this->definitions = definitions;
        let this->instanceManager = instanceManager;

        if config {
            this->configure(config);
        }
    }

    /**
     * Provide a configuration object to configure this instance
     *
     * @param  Config $config
     * @return void
     */
    public function configure(<Config> config) -> void
    {
        config->configure(this);
    }

    /**
     * @param  DefinitionList $definitions
     * @return self
     */
    public function setDefinitionList(<DefinitionList> definitions) -> <Di>
    {
        let this->definitions = definitions;

        return this;
    }

    /**
     * @return DefinitionList
     */
    public function definitions() -> <DefinitionList>
    {
        return this->definitions;
    }

    /**
     * Set the instance manager
     *
     * @param  InstanceManager $instanceManager
     * @return Di
     */
    public function setInstanceManager(<InstanceManager> instanceManager) -> <Di>
    {
        let this->instanceManager = instanceManager;

        return this;
    }

    /**
     *
     * @return InstanceManager
     */
    public function instanceManager() -> <InstanceManager>
    {
        return this->instanceManager;
    }

    /**
     * Utility method used to retrieve the class of a particular instance. This is here to allow extending classes to
     * override how class names are resolved
     *
     * @internal this method is used by the ServiceLocator\DependencyInjectorProxy class to interact with instances
     *           and is a hack to be used internally until a major refactor does not split the `resolveMethodParameters`. Do not
     *           rely on its functionality.
     * @param  Object $instance
     * @return string
     */
    protected function getClass(object instance) -> string
    {
        return get_class(instance);
    }

    /**
     * @param $name
     * @param array $params
     * @param string $method
     * @return array
     */
    protected function getCallParameters(name, array! params, string method = "__construct") -> array
    {
        var im, className, definitions, callParameters = [], param, methodParameters, val, val2;

        let im = <InstanceManager> this->instanceManager;
        let definitions = <DefinitionList> this->definitions;

        let className = im->hasAlias(name) ? im->getClassFromAlias(name) : name;

        if definitions->hasClass(className) {
            if definitions->hasMethod(className, method) {
                let methodParameters = definitions->getMethodParameters(className, method);
                for param in methodParameters {
                    if fetch val, param[0] {
                        if fetch val2, params[val] {
                            let callParameters[val] = val2;
                        }
                    }
                }
            }
            return callParameters;
        }
        return params;
    }

    /**
     * Lazy-load a class
     *
     * Attempts to load the class (or service alias) provided. If it has been
     * loaded before, the previous instance will be returned (unless the service
     * definition indicates shared instances should not be used).
     *
     * @param  string      $name   Class name or service alias
     * @param  null|array  $params Parameters to pass to the constructor
     * @return object|null
     */
    public function get(string name, array! params = []) -> object|null
    {
         var im, callParameters, fastHash, instance;

        array_push(this->instanceContext, ["GET", name, null]); // todo: check it

        let im = <InstanceManager> this->instanceManager;
        let callParameters = this->getCallParameters(name, params);

        if !empty callParameters && callParameters {
            let fastHash = im->hasSharedInstanceWithParameters(name, callParameters, true);
            if fastHash {
                array_pop(this->instanceContext);

                return im->getSharedInstanceWithParameters(null, [], fastHash);
            }
        }

        if im->hasSharedInstance(name, callParameters) {
            array_pop(this->instanceContext);

            return im->getSharedInstance(name, callParameters);
        }

        let config = im->getConfig($name);
        let instance = this->newInstance(name, params, config["shared"]);

        array_pop(this->instanceContext);

        return instance;
    }

    /**
     * Retrieve a new instance of a class
     *
     * Forces retrieval of a discrete instance of the given class, using the
     * constructor parameters provided.
     *
     * @param  mixed                            $name     Class name or service alias
     * @param  array                            $params   Parameters to pass to the constructor
     * @param  bool                             $isShared
     * @return object|null
     * @throws Exception\ClassNotFoundException
     * @throws Exception\RuntimeException
     */
    public function newInstance(string name, array! params = [], boolean isShared = true) -> object
    {
        var im, className, definitions, alias = null, instantiator,
            injectionMethods, supertype, supertypes, p1, p2, instance,
            callParameters;
        string exceptionMsg;

        // localize dependencies
        let im = <InstanceManager> this->instanceManager();
        let definitions = <DefinitionList> this->definitions;

        if im->hasAlias(name) {
            let className = im->getClassFromAlias(name);
            let alias = name;
        } else {
            let className = name;
        }

        array_push(this->instanceContext, ["NEW", className, alias]);

        if unlikely !definitions->hasClass(className) {
            let exceptionMsg = "Class ";
            if alias {
                let exceptionMsg .= "(specified by alias " . alias . ") ";
            }
            let exceptionMsg .= className . " could not be located in provided definitions.";

            throw new Exception\ClassNotFoundException(exceptionMsg);
        }

        let instantiator = definitions->getInstantiator(className);
        let injectionMethods[className] = definitions->getMethods(className);
        let supertypes = definitions->getClassSupertypes(className);

        for supertype in supertypes {
            let injectionMethods[supertype] = definitions->getMethods(supertype);
        }

        if unlikely instantiator !== "__construct" && !is_callable(instantiator, false) {
            if typeof instantiator == "array" {
                let p1 = isset instantiator[0] ? instantiator[0] : "NoClassGiven";
                let p2 = isset instantiator[1] ? instantiator[1] : "NoMethodGiven";
                let exceptionMsg = "Invalid instantiator:" . p1 . "::" . p2 . "() is not callable.";
            } else {
                let p1 = typeof instantiator;
                let exceptionMsg = "Invalid instantiator of type \"" . p1 . "\" for \"" . name . "\"."
            }
            throw new Exception\RuntimeException(exceptionMsg);
        }

        if instantiator === "__construct" {
            let instance = $this->createInstanceViaConstructor(className, params, alias);
            if isset injectionMethods["__construct"] {
                unset injectionMethods["__construct"];
            }
        } else {
            let instance = this->createInstanceViaCallback(instantiator, params, alias);
        }

        if isShared {
            let callParameters = this->getCallParameters(name, params);
            if callParameters {
                im->addSharedInstanceWithParameters(instance, name, callParameters);
            } else {
                im->>addSharedInstance(instance, name);
            }
        }

        this->handleInjectDependencies(instance, injectionMethods, params, className, alias, name);

        array_pop(this->instanceContext);

        return instance;
    }

    /**
     * Inject dependencies
     *
     * @param  object $instance
     * @param  array  $params
     * @return void
     */
    public function injectDependencies(object instance, array! params = []) -> void
    {
        var definitions, className, injectionMethod = [], parentClass, interfaces, implementInterface;

        let definitions = <DefinitionList> this->definitions();
        let className = this->getClass(instance);

        if definitions->hasClass(className) {
            let injectionMethod[className] = definitions->getMethods(className)
        } else {
            let injectionMethod[className] = [];
        }

        let parentClass = get_parent_class(className);

        while parentClass {
            if definitions->hasClass(parentClass) {
                injectionMethods[parentClass] = definitions->getMethods(parentClass);
            }
            let parentClass = get_parent_class(parentClass);
        }

        let interfaces = class_implements(className);
        for implementInterface in interfaces {
            if definitions->hasClass(implementInterface) {
                injectionMethods[implementInterface] = definitions->getMethods(implementInterface);
            }
        }

        this->handleInjectDependencies(instance, injectionMethods, params, className, null, null);
    }

    /**
     * @param object      $instance
     * @param array       $injectionMethods
     * @param array       $params
     * @param string|null $instanceClass
     * @param string|null$instanceAlias
     * @param  string                     $requestedName
     * @throws Exception\RuntimeException
     */
    protected function handleInjectDependencies(object instance, array injectionMethods, array params, string instanceClass, instanceAlias, string requestedName)
    {
        var definitions, className, im, classMethods = ["__construct": true], type,
            typeInjectionMethods, typeInjectionMethod, methodRequirementType, instanceConfig,
            injections, objectsToInject = [], methodsToCall = [], injectName, injectValue, tmp,
            methodCallArgs, objectToInject, objectToInjectClass, calledMethods,
            methodParams, methodParam, methodInfo;
        string injectNameType, injectValueType;

        // localize dependencies
        let definitions = <DefinitionList> this->definitions;
        let im = <InstanceManager> this->instanceManager();

        if injectionMethods {
            for type, typeInjectionMethods in injectionMethods {
                for typeInjectionMethod, methodRequirementType in typeInjectionMethods {
                    if !isset calledMethods[typeInjectionMethod] {
                        if this->resolveAndCallInjectionMethodForInstance(instance, typeInjectionMethod, params, instanceAlias, methodRequirementType, type) {
                            let calledMethods[typeInjectionMethod] = true;
                        }
                    }
                }
            }

            if requestedName {
                let instanceConfig = im->getConfig(requestedName);
                if fetch injections, instanceConfig["injections"] {
                    for injectName, injectValue in injections {
                        let injectNameType = typeof injectName;
                        let injectValueType = typeof injectValue;

                        if unlikely injectNameType == "integer" && injectValueType == "array" {
                            throw new Exception\RuntimeException("An injection was provided with a keyed index and an array of data, try using the name of a particular method as a key for your injection data.");
                        }

                        if injectNameType == "integer" && injectValueType == "string" {
                            let objectsToInject[] = this->get(injectValue, params);
                        } elseif injectNameType == "string" && injectValueType == "array" {
                            let tmp = key(injectValue);
                            if typeof tmp == "string" {
                                let methodsToCall[] = ["method": injectName, "args": injectValue];
                            } else {
                                for methodCallArgs in injectValue {
                                    let methodsToCall[] = ["method": injectName, "args": methodCallArgs];
                                }
                            }
                        } elseif injectValueType == "object" {
                            let objectsToInject[] = injectValue;
                        }
                    }
                    if objectsToInject {
                        for objectToInject in objectsToInject {
                            let calledMethods = ["__construct": true];
                            for type, typeInjectionMethods in injectionMethods {
                                for typeInjectionMethod, methodRequirementType in typeInjectionMethods {
                                    if !isset calledMethods[typeInjectionMethod] {
                                        let methodParams = definitions->getMethodParameters(type, typeInjectionMethod);
                                        if methodParams {
                                            for methodParam in methodParams {
                                                let objectToInjectClass = this->getClass(objectToInject);
                                                if objectToInjectClass == methodParam[1] || self::isSubclassOf(objectToInjectClass, methodParam[1]) {
                                                    let tmp = [methodParam[0]: objectToInject];
                                                    if this->resolveAndCallInjectionMethodForInstance(instance, typeInjectionMethod, tmp, instanceAlias, self::METHOD_IS_REQUIRED, type) {
                                                        let calledMethods[typeInjectionMethod] = true;
                                                    }
                                                    continue 3;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if methodsToCall {
                        for methodInfo in methodsToCall {
                            this->resolveAndCallInjectionMethodForInstance(instance, methodInfo["method"], methodInfo["args"], instanceAlias,  self::METHOD_IS_REQUIRED, instanceClass);
                        }
                    }
                }
            }
        }
    }

    /**
     * Retrieve a class instance based on class name
     *
     * Any parameters provided will be used as constructor arguments. If any
     * given parameter is a DependencyReference object, it will be fetched
     * from the container so that the instance may be injected.
     *
     * @param  string      $class
     * @param  array       $params
     * @param  string|null $alias
     * @return object
     */
    protected function createInstanceViaConstructor(string $class, array params, string alias = null) -> object
    {
        var className, callParameters = [], definitions, instance, r;
        string exceptionMsg;

        let definitions = <DefinitionList> this->definitions;

        if definitions->hasMethod($class, "__construct") {
            let callParameters = this->resolveMethodParameters($class, "__construct", params, alias, self::METHOD_IS_CONSTRUCTOR, true);
        }
        if unlikely !class_exists($class) {
            if unlikely interface_exists($class) {
                let exceptionMsg = "Cannot instantiate interface \"" . $class . "\"";
                throw new Exception\ClassNotFoundException(exceptionMsg);
            }
            let exceptionMsg = "Class \"" . $class . "\" does not exist; cannot instantiate";
            throw new Exception\ClassNotFoundException(exceptionMsg);
        }

        // Hack to avoid Reflection in most common use cases
        switch count(callParameters) {
            case 0:
                let instance = new {$class}();
                break;
            case 1:
                let instance = new {$class}(callParameters[0]);
                break;
            case 2:
                let instance = new {$class}(callParameters[0], callParameters[1]);
                break;
            case 3:
                let instance = new {$class}(callParameters[0], callParameters[1], callParameters[2]);
                break;
            case 4:
                let instance = new {$class}(callParameters[0], callParameters[1], callParameters[2], callParameters[3]);
                break;
            case 5:
                let instance = new {$class}(callParameters[0], callParameters[1], callParameters[2], callParameters[3], callParameters[4]);
                break;
            default:
                let r = new \ReflectionClass($class);
                let instance = r->newInstanceArgs(callParameters);
                break;
        }

        return instance;
    }

    /**
     * Get an object instance from the defined callback
     *
     * @param  callable                           $callback
     * @param  array                              $params
     * @param  string                             $alias
     * @return object
     * @throws Exception\InvalidCallbackException
     * @throws Exception\RuntimeException
     */
    protected function createInstanceViaCallback(callable callback, array params, string alias) -> object
    {
        var className, method, callParameters = [], definitions;

        if unlikely !is_callable(callback) {
            throw new Exception\InvalidCallbackException("An invalid constructor callback was provided");
        }

        if unlikely typeof callback != "array" && (typeof callback != "string" || strpos(callback, "::") === false) {
            throw new Exception\RuntimeException("Invalid callback type provided to " . __METHOD__);
        }

        if typeof callback == "array" {
            let className = callback[0];
            let method = callback[1];

            if typeof className == "object" {
                let className = this->getClass(className);
            }
        }

        let definitions = <DefinitionList> this->definitions;

        if definitions->hasMethod(className, method) {
            let callParameters = this->resolveMethodParameters(className, method, params, alias, self::METHOD_IS_INSTANTIATOR, true);
        }

        return call_user_func_array(callback, callParameters);
    }

    /**
     * This parameter will handle any injection methods and resolution of
     * dependencies for such methods
     *
     * @param  object      $instance
     * @param  string      $method
     * @param  array       $params
     * @param  string      $alias
     * @param  bool        $methodRequirementType
     * @param  string|null $methodClass
     * @return bool
     */
    protected function resolveAndCallInjectionMethodForInstance(object instance, string method, array params, string alias, boolean methodRequirementType, string methodClass = null) -> boolean
    {
        var callParameters, callParametersFill;

        if !methodClass {
            let methodClass = this->getClass(instance);
        }
        let callParameters = this->resolveMethodParameters(methodClass, method, params, alias, methodRequirementType);

        if callParameters === false {
            return false;
        }
        let callParametersFill = array_fill(0, count(callParameters), null);
        if callParameters === callParametersFill {
            call_user_func_array([instance, method], callParameters);

            return true;
        }
        return false;
    }

    /**
     * Resolve parameters referencing other services
     *
     * @param  string                                $class
     * @param  string                                $method
     * @param  array                                 $callTimeUserParams
     * @param  string                                $alias
     * @param  int|bool                              $methodRequirementType
     * @param  bool                                  $isInstantiator
     * @throws Exception\MissingPropertyException
     * @throws Exception\CircularDependencyException
     * @return array
     */
    protected function resolveMethodParameters(string $class, string method, array! callTimeUserParams, string alias, var methodRequirementType, boolean isInstantiator = false) -> array
    {
        var resolvedParams = [], injectionMethodParameters, definitions,
            computedParams = ["value": [], "retrieval": [], "optional": []], iConfig = [],
            aliases, im, instanceContext0, requestedClass = null, requestedAlias = null, newParameters,
            name, param, parameters, newName, info, fqParamPos, fqParamName, name, type,
            isRequired, thisIndex, pInstances, pInstance, pInstanceClass, value, fqParamVal, dConfig;
        int index;
        string exceptionMsg;

        if typeof methodRequirementType == "boolean" {
            if isInstantiator {
                let methodRequirementType = Di::METHOD_IS_INSTANTIATOR;
            } elseif methodRequirementType {
                let methodRequirementType = Di::METHOD_IS_REQUIRED;
            } else {
                let methodRequirementType = Di::METHOD_IS_OPTIONAL;
            }
        }

        let definitions = <DefinitionList> this->definitions;
        let injectionMethodParameters = definitions->getMethodParameters($class, method);
        let im = <InstanceManager> this->instanceManager;
        let aliases = im->getAliases();

        // for the alias in the dependency tree
        if alias && im->hasConfig(alias) {
            let iConfig["thisAlias"] = im->getConfig(alias);
        }

        // for the current class in the dependency tree
        if im->hasConfig($class) {
            let iConfig["thisClass"] = im->getConfig($class);
        }

        // for the parent class, provided we are deeper than one node
        let instanceContext = this->instanceContext;
        if isset instanceContext[0] {
            let instanceContext = this->instanceContext;
            if instanceContext[0][0] === "NEW" {
                let requestedClass = instanceContext[0][1];
                let requestedAlias = instanceContext[0][2];
            } else {
                let requestedClass = instanceContext[1][1];
                let requestedAlias = instanceContext[1][2];
            }
        }

        if requestedClass != $class && im->hasConfig(requestedClass) {
            let iConfig["requestedClass"] = im->getConfig(requestedClass);

            if fetch parameters, iConfig["requestedClass"]["parameters"]
                let newParameters = [];
                for name, param in parameters {
                    let newName = requestedClass . "::" . method . "::" . name;
                    let newParameters[newName] = param;
                }
                let iConfig["requestedClass"]["parameters"] = newParameters;
            }

            if requestedAlias {
                let iConfig["requestedAlias"] = im->getConfig(requestedAlias);
            }
        }

        // This is a 2 pass system for resolving parameters
        // first pass will find the sources, the second pass will order them and resolve lookups if they exist
        // MOST methods will only have a single parameters to resolve, so this should be fast

        for fqParamPos, info in injectionMethodParameters {
            let name = info[0];
            let type = info[1];
            let isRequired = info[2];

            let fqParamName = substr_replace(fqParamPos, ":" . name, strrpos($fqParamPos, ":"));

            // PRIORITY 1 - consult user provided parameters
            if isset callTimeUserParams[fqParamPos] || isset callTimeUserParams[name] {

                // todo:
                continue;
            }

            // PRIORITY 2 -specific instance configuration (thisAlias) - this alias
            // PRIORITY 3 -THEN specific instance configuration (thisClass) - this class
            // PRIORITY 4 -THEN specific instance configuration (requestedAlias) - requested alias
            // PRIORITY 5 -THEN specific instance configuration (requestedClass) - requested class
            for thisIndex in ["thisAlias", "thisClass", "requestedAlias", "requestedClass"] {
                // check the provided parameters config
                // todo:
            }

            // PRIORITY 6 - globally preferred implementations

            // next consult alias level preferred instances
            // RESOLVE_EAGER wants to inject the cross-cutting concerns.
            // If you want to retrieve an instance from TypePreferences,
            // use AwareInterface or specify the method requirement option METHOD_IS_EAGER at ClassDefinition
            if methodRequirementType & self::RESOLVE_EAGER {
                if alias && im->hasTypePreferences(alias) {
                    let pInstances = im->getTypePreferences(alias);
                    for pInstance in pInstances {
                        if typeof pInstance == "object" {
                            let computedParams["value"][fqParamPos] = pInstance;
                            continue;
                        }

                        if im->hasAlias(pInstance) {
                            let pInstanceClass = im->getClassFromAlias(pInstance);
                        } else {
                            let pInstanceClass = pInstance;
                        }

                        if pInstanceClass === type || self::isSubclassOf(pInstanceClass, type) {
                            let computedParams["retrieval"][fqParamPos] = [pInstance, pInstanceClass];
                            continue 2;
                        }
                    }
                }

                // next consult class level preferred instances
                if type && im->hasTypePreferences(type) {
                    let pInstances = im->getTypePreferences(alias);
                    for pInstance in pInstances {
                        if typeof pInstance == "object" {
                            let computedParams["value"][fqParamPos] = pInstance;
                            continue;
                        }

                        if im->hasAlias(pInstance) {
                            let pInstanceClass = im->getClassFromAlias(pInstance);
                        } else {
                            let pInstanceClass = pInstance;
                        }

                        if pInstanceClass === type || self::isSubclassOf(pInstanceClass, type) {
                            let computedParams["retrieval"][fqParamPos] = [pInstance, pInstanceClass];
                            continue 2;
                        }
                    }
                }
            }

            if !isRequired {
                let computedParams["optional"][fqParamPos] = true;
            }

            if type && isRequired && (methodRequirementType & self::RESOLVE_EAGER) {
                let computedParams["retrieval"][fqParamPos] = [type, type];
            }
        }

        let index = 0;
        for fqParamPos, value in injectionMethodParameters {
            let name = value[0];
            if fetch fqParamVal, computedParams["value"][fqParamPos] {
                let resolvedParams[index] = fqParamVal;
            } elseif fetch fqParamVal, computedParams["retrieval"][fqParamPos] {
                // detect circular dependencies! (they can only happen in instantiators)
                if unlikely isInstantiator && in_array(fqParamVal[1], this->currentDependencies) &&
                    (!isset alias || in_array(fqParamVal[0], this->currentAliasDependenencies) {
                    let exceptionMsg = "Circular dependency detected: " . $class . " depends on " . value[1] . " and viceversa";
                    if isset alias {
                        let exceptionMsg .= " (Aliased as " . alias . ")";
                    }
                    throw new Exception\CircularDependencyException(exceptionMsg);
                }

                array_push(this->currentDependencies, $class);
                if isset alias {
                    array_push(this->currentAliasDependenencies, alias);
                }

                let dConfig = im->getConfig(fqParamVal[0]);

                try {
                    if dConfig["shared"] === false {
                        let resolvedParams[index] = this->newInstance(fqParamVal[0], callTimeUserParams, false);
                    } else {
                        let resolvedParams[index] = this->get(fqParamVal[0], callTimeUserParams);
                    }
                } catch DiRuntimeException|ServiceManagerException {
                    //finally ( be aware to do at the end of flow)
                    array_pop(this->currentDependencies);
                    if isset alias {
                        array_pop(this->currentAliasDependenencies);
                    }
                    if methodRequirementType & self::RESOLVE_STRICT {
                        // if this item was marked strict,
                        // plus it cannot be resolve, and no value exist, bail out
                        let exceptionMsg = "Missing ";
                        if value[0] === null {
                            let exceptionMsg .= "value";
                        } else {
                            let exceptionMsg .= "instance/object";
                        }
                        let exceptionMsg .= " for parameter " . name . " for " . $class . "::" . method;

                        throw new Exception\MissingPropertyException(exceptionMsg, e->getCode(), e);
                    }
                    return false;
                }

                array_pop(this->currentDependencies);
                if isset alias {
                    array_pop(this->currentAliasDependenencies);
                }
            } elseif unlikely !array_key_exists(fqParamPos, computedParams["optional"]) {
                if methodRequirementType & self::RESOLVE_STRICT {
                    // if this item was marked strict,
                    // plus it cannot be resolve, and no value exist, bail out
                    let exceptionMsg = "Missing ";
                    if value[0] === null {
                        let exceptionMsg .= "value";
                    } else {
                        let exceptionMsg .= "instance/object";
                    }
                    let exceptionMsg .= " for parameter " . name . " for " . $class . "::" . method;

                    throw new Exception\MissingPropertyException(exceptionMsg);
                }
                return false;
            } else {
                let resolvedParams[index] = value[3];
            }
            let index++;
        }

        return resolvedParams; // return ordered list of parameters
    }

    /**
     * Checks if the object has this class as one of its parents
     *
     * @see https://bugs.php.net/bug.php?id=53727
     * @see https://github.com/zendframework/zf2/pull/1807
     *
     * @param string $className
     * @param $type
     * @return bool
     */
    protected static function isSubclassOf(string className, string type) -> boolean
    {
        var r;

        if is_subclass_of(className, type) {
            return true;
        }
        if PHP_VERSION_ID >= 50307 || !interface_exists(type) {
            return false;
        }

        let r = new ReflectionClass(className);

        return r->implementsInterface(type);
    }

}
