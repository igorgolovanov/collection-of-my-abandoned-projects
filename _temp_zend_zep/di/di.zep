/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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
     * use only specified parameters
     */
    const METHOD_IS_OPTIONAL = 0;
    
    /**
     * resolve mode RESOLVE_EAGER
     */
    const METHOD_IS_AWARE = 1;
    
    /**
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_CONSTRUCTOR = 3;
    
    /**
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_INSTANTIATOR = 3;
    
    /**
     * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
     */
    const METHOD_IS_REQUIRED = 3;
    
    /**
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
    protected instanceContext; // []

    /**
     * All the class dependencies [source][dependency]
     *
     * @var array
     */
    protected currentDependencies; // []

    /**
     * All the dependenent aliases
     *
     * @var array
     */
    protected currentAliasDependenencies; // []

    /**
     * All the class references [dependency][source]
     *
     * @var array
     */
    protected references; // []

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

        if config !== null {
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
     * @param string $name
     * @param array $params
     * @param string $method
     * @return array
     */
    protected function getCallParameters(string name, array! params, string method = "__construct") -> array
    {
        var im, definitions, param, methodParams, paramFirst;
        string className;
        array callParameters = [];

        let im = this->instanceManager;
        let definitions = this->definitions;
    
        if im->hasAlias(name) {
            let className = im->getClassFromAlias(name);
        } else {
            let className = name;
        }

        if definitions->hasClass(className) {
            if definitions->hasMethod(className, method) {
                let methodParams = definitions->getMethodParameters(className, method);
                for param in methodParams {
                    if fetch paramFirst, param[0] {
                        if isset params[paramFirst] {
                            let callParameters[paramFirst] = params[paramFirst];
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
        array context, callParameters;
        var im, fastHash, config, instance, shared;

        let context = ["GET", name, null];
        let this->instanceContext[] = context;
        let im = this->instanceManager;

        let callParameters = this->getCallParameters(name, params);

        if unlikely empty callParameters {
            let fastHash = m->hasSharedInstanceWithParameters(name, callParameters, true);
            if fastHash {
                array_pop(this->instanceContext);
                return im->getSharedInstanceWithParameters(null, [], fastHash);
            }
        }

        if im->hasSharedInstance(name, callParameters) {
            array_pop(this->instanceContext);
            return im->getSharedInstance(name, callParameters);
        }

        let config = <Config> im->getConfig(name);
        let shared = config["shared"];
        let instance = this->newInstance(name, params, shared);

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
    public function newInstance(name, array! params = [], boolean isShared = true) -> object
    {

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
    protected function createInstanceViaCallback(callback, array params, string alias) -> object
    {

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
    protected static function isSubclassOf(string className, type) -> boolean
    {
        var ref;

        if is_subclass_of(className, type) {
            return true;
        }

        if PHP_VERSION_ID >= 50307 {
            return false;
        }

        if !interface_exists(type) {
            return false;
        }
        let ref = new ReflectionClass(className);

        return ref->implementsInterface(type);
    }

}
