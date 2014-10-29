/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager;

use ReflectionClass;

class ServiceManager implements ServiceLocatorInterface
{
    const SCOPE_PARENT = "parent";
    const SCOPE_CHILD = "child";

    /**
     * Lookup for canonicalized names.
     *
     * @var array
     */
    protected canonicalNames; // []

    /**
     * @var bool
     */
    protected allowOverride = false;

    /**
     * @var array
     */
    protected invokableClasses; // []

    /**
     * @var string|callable|\Closure|FactoryInterface[]
     */
    protected factories; // []

    /**
     * @var AbstractFactoryInterface[]
     */
    protected abstractFactories; // []

    /**
     * @var array[]
     */
    protected delegators; // []

    /**
     * @var array
     */
    protected pendingAbstractFactoryRequests; // []

    /**
     * @var integer
     */
    protected nestedContextCounter = -1;

    /**
     * @var array
     */
    protected nestedContext; // []

    /**
     * @var array
     */
    protected shared; // []

    /**
     * Registered services and cached values
     *
     * @var array
     */
    protected instances; // []

    /**
     * @var array
     */
    protected aliases; // []

    /**
     * @var array
     */
    protected initializers; // []

    /**
     * @var ServiceManager[]
     */
    protected peeringServiceManagers; // []

    /**
     * Whether or not to share by default
     *
     * @var bool
     */
    protected shareByDefault = true;

    /**
     * @var bool
     */
    protected retrieveFromPeeringManagerFirst = false;

    /**
     * @var bool Track whether not to throw exceptions during create()
     */
    protected throwExceptionInCreate = true;

    /**
     * @var array map of characters to be replaced through strtr
     */
    protected canonicalNamesReplacements; // ["-": "", "_": "", " ": "", "\": "", "/": ""]

    /**
     * Constructor
     *
     * @param ConfigInterface $config
     */
    public function __construct(<ConfigInterface> config = null)
    {
        if config !== null {
            config->configureServiceManager(this);
        }
    }

    /**
     * Set allow override
     *
     * @param $allowOverride
     * @return ServiceManager
     */
    public function setAllowOverride(boolean allowOverride) -> <ServiceManager>
    {
        let this->allowOverride = allowOverride;
        return this;
    }

    /**
     * Get allow override
     *
     * @return bool
     */
    public function getAllowOverride() -> boolean
    {
        return this->allowOverride;
    }

    /**
     * Set flag indicating whether services are shared by default
     *
     * @param  bool $shareByDefault
     * @return ServiceManager
     * @throws Exception\RuntimeException if allowOverride is false
     */
    public function setShareByDefault(boolean shareByDefault) -> <ServiceManager>
    {

    }

    /**
     * Are services shared by default?
     *
     * @return bool
     */
    public function shareByDefault() -> boolean
    {
        return this->shareByDefault;
    }

    /**
     * Set throw exceptions in create
     *
     * @param  bool $throwExceptionInCreate
     * @return ServiceManager
     */
    public function setThrowExceptionInCreate(boolean throwExceptionInCreate) -> <ServiceManager>
    {
        let this->throwExceptionInCreate = throwExceptionInCreate;
        return this;
    }

    /**
     * Get throw exceptions in create
     *
     * @return bool
     */
    public function getThrowExceptionInCreate() -> boolean
    {
        return this->throwExceptionInCreate;
    }

    /**
     * Set flag indicating whether to pull from peering manager before attempting creation
     *
     * @param  bool $retrieveFromPeeringManagerFirst
     * @return ServiceManager
     */
    public function setRetrieveFromPeeringManagerFirst(boolean retrieveFromPeeringManagerFirst = true) -> <ServiceManager>
    {
        let this->retrieveFromPeeringManagerFirst = retrieveFromPeeringManagerFirst;
        return this;
    }

    /**
     * Should we retrieve from the peering manager prior to attempting to create a service?
     *
     * @return bool
     */
    public function retrieveFromPeeringManagerFirst() -> boolean
    {
        return this->retrieveFromPeeringManagerFirst;
    }

    /**
     * Set invokable class
     *
     * @param  string  $name
     * @param  string  $invokableClass
     * @param  bool $shared
     * @return ServiceManager
     * @throws Exception\InvalidServiceNameException
     */
    public function setInvokableClass(string name, string invokableClass, boolean shared = null) -> <ServiceManager>
    {

    }

    /**
     * Set factory
     *
     * @param  string                           $name
     * @param  string|FactoryInterface|callable $factory
     * @param  bool                             $shared
     * @return ServiceManager
     * @throws Exception\InvalidArgumentException
     * @throws Exception\InvalidServiceNameException
     */
    public function setFactory(string name, var factory, boolean shared = null) -> <ServiceManager>
    {

    }

    /**
     * Add abstract factory
     *
     * @param  AbstractFactoryInterface|string $factory
     * @param  bool                            $topOfStack
     * @return ServiceManager
     * @throws Exception\InvalidArgumentException if the abstract factory is invalid
     */
    public function addAbstractFactory(var factory, boolean topOfStack = true) -> <ServiceManager>
    {

    }

    /**
     * Sets the given service name as to be handled by a delegator factory
     *
     * @param  string $serviceName          name of the service being the delegate
     * @param  string $delegatorFactoryName name of the service being the delegator factory
     *
     * @return ServiceManager
     */
    public function addDelegator(string serviceName, string delegatorFactoryName) -> <ServiceManager>
    {

    }

    /**
     * Add initializer
     *
     * @param  callable|InitializerInterface $initializer
     * @param  bool                          $topOfStack
     * @return ServiceManager
     * @throws Exception\InvalidArgumentException
     */
    public function addInitializer(<InitializerInterface> initializer, boolean topOfStack = true) -> <ServiceManager>
    {

    }

    /**
     * Register a service with the locator
     *
     * @param  string  $name
     * @param  mixed   $service
     * @return ServiceManager
     * @throws Exception\InvalidServiceNameException
     */
    public function setService(string name, service) -> <ServiceManager>
    {

    }

    /**
     * @param  string $name
     * @param  bool   $isShared
     * @return ServiceManager
     * @throws Exception\ServiceNotFoundException
     */
    public function setShared(string name, boolean isShared) -> <ServiceManager>
    {

    }

    /**
     * Resolve the alias for the given canonical name
     *
     * @param  string $cName The canonical name to resolve
     * @return string The resolved canonical name
     */
    protected function resolveAlias(string cName) -> string
    {

    }

    /**
     * Retrieve a registered instance
     *
     * @param  string  $name
     * @param  bool    $usePeeringServiceManagers
     * @throws Exception\ServiceNotFoundException
     * @return object|array
     */
    public function get(string name, boolean usePeeringServiceManagers = true) -> object|array
    {

    }

    /**
     * Create an instance of the requested service
     *
     * @param  string|array $name
     *
     * @return bool|object
     */
    public function create(var name) -> boolean|object
    {

    }

    /**
     * Creates a callback that uses a delegator to create a service
     *
     * @param DelegatorFactoryInterface|callable $delegatorFactory the delegator factory
     * @param string                             $rName            requested service name
     * @param string                             $cName            canonical service name
     * @param callable                           $creationCallback callback for instantiating the real service
     *
     * @return callable
     */
    private function createDelegatorCallback(<DelegatorFactoryInterface> delegatorFactory, string rName, string cName, creationCallback)
    {

    }

    /**
     * Actually creates the service
     *
     * @param string $rName real service name
     * @param string $cName canonicalized service name
     *
     * @return bool|mixed|null|object
     * @throws Exception\ServiceNotFoundException
     *
     * @internal this method is internal because of PHP 5.3 compatibility - do not explicitly use it
     */
    public function doCreate(string rName, string cName)
    {

    }

    /**
     * Determine if we can create an instance.
     * Proxies to has()
     *
     * @param  string|array $name
     * @param  bool         $checkAbstractFactories
     * @return bool
     * @deprecated this method is being deprecated as of zendframework 2.3, and may be removed in future major versions
     */
    public function canCreate(var name, boolean checkAbstractFactories = true) -> boolean
    {

    }

    /**
     * Determine if an instance exists.
     *
     * @param  string|array  $name  An array argument accepts exactly two values.
     *                              Example: array('canonicalName', 'requestName')
     * @param  bool          $checkAbstractFactories
     * @param  bool          $usePeeringServiceManagers
     * @return bool
     */
    public function has(var name, boolean checkAbstractFactories = true, boolean usePeeringServiceManagers = true) -> boolean
    {

    }

    /**
     * Determine if we can create an instance from an abstract factory.
     *
     * @param  string $cName
     * @param  string $rName
     * @return bool
     */
    public function canCreateFromAbstractFactory(string cName, string rName) -> boolean
    {

    }

    /**
     * Ensure the alias definition will not result in a circular reference
     *
     * @param  string $alias
     * @param  string $nameOrAlias
     * @throws Exception\CircularReferenceException
     * @return self
     */
    protected function checkForCircularAliasReference(string alias, string nameOrAlias) -> <ServiceManager>
    {

    }

    /**
     * @param  string $alias
     * @param  string $nameOrAlias
     * @return ServiceManager
     * @throws Exception\ServiceNotFoundException
     * @throws Exception\InvalidServiceNameException
     */
    public function setAlias(string alias, string nameOrAlias) -> <ServiceManager>
    {

    }

    /**
     * Determine if we have an alias
     *
     * @param  string $alias
     * @return bool
     */
    public function hasAlias(string alias) -> boolean
    {
        string name;
        let name = this->canonicalizeName(alias);

        return isset this->aliases[name];
    }

    /**
     * Create scoped service manager
     *
     * @param  string $peering
     * @return ServiceManager
     */
    public function createScopedServiceManager(string peering = self::SCOPE_PARENT) -> <ServiceManager>
    {
        var scopedServiceManager;
        let scopedServiceManager = new ServiceManager();

        switch peering {
            case self::SCOPE_PARENT:
                let scopedServiceManager->peeringServiceManagers[] = this;
                break;
            case self::SCOPE_CHILD:
                let this->peeringServiceManagers[] = scopedServiceManager;
                break;
        }
        return scopedServiceManager;
    }

    /**
     * Add a peering relationship
     *
     * @param  ServiceManager $manager
     * @param  string         $peering
     * @return ServiceManager
     */
    public function addPeeringServiceManager(<ServiceManager> manager, string peering = self::SCOPE_PARENT) -> <ServiceManager>
    {
        switch peering {
            case self::SCOPE_PARENT:
                let this->peeringServiceManagers[] = manager;
                break;
            case self::SCOPE_CHILD:
                let manager->peeringServiceManagers[] = this;
                break;
        }
        return this;
    }

    /**
     * Canonicalize name
     *
     * @param  string $name
     * @return string
     */
    protected function canonicalizeName(string name) -> string
    {
        var canonicalName;

        if fetch canonicalName, this->canonicalNames[name] {
            return canonicalName;
        }

        let canonicalName = strtr(name, this->canonicalNamesReplacements);
        let canonicalName = strtolower(canonicalName);
        let this->canonicalNames[name] = canonicalName;

        return canonicalName;
    }

    /**
     * Create service via callback
     *
     * @param  callable $callable
     * @param  string   $cName
     * @param  string   $rName
     * @throws Exception\ServiceNotCreatedException
     * @throws Exception\ServiceNotFoundException
     * @throws Exception\CircularDependencyFoundException
     * @return object
     */
    protected function createServiceViaCallback(callable, string cName, string rName) -> object
    {

    }

    /**
     * Retrieve a keyed list of all registered services. Handy for debugging!
     *
     * @return array
     */
    public function getRegisteredServices() -> array
    {
        array services = [];

        let services["invokableClasses"] = array_keys(this->invokableClasses);
        let services["factories"] = array_keys(this->factories);
        let services["aliases"] = array_keys(this->aliases);
        let services["instances"] = array_keys(this->instances);

        return services;
    }

    /**
     * Retrieve a keyed list of all canonical names. Handy for debugging!
     *
     * @return array
     */
    public function getCanonicalNames() -> array
    {
        return this->canonicalNames;
    }

    /**
     * Allows to override the canonical names lookup map with predefined
     * values.
     *
     * @param array $canonicalNames
     * @return ServiceManager
     */
    public function setCanonicalNames(array canonicalNames) -> <ServiceManager>
    {
        let this->canonicalNames = canonicalNames;
        return this;
    }

    /**
     * Attempt to retrieve an instance via a peering manager
     *
     * @param  string $name
     * @return mixed
     */
    protected function retrieveFromPeeringManager(string name)
    {

    }

    /**
     * Attempt to create an instance via an invokable class
     *
     * @param  string $canonicalName
     * @param  string $requestedName
     * @return null|\stdClass
     * @throws Exception\ServiceNotFoundException If resolved class does not exist
     */
    protected function createFromInvokable(string canonicalName, string requestedName) -> <\stdClass>|null
    {
        string invokable, exceptionMsg, method, requestedNameMsg = "";
        var instance;

        let invokable = this->invokableClasses[canonicalName];

        if !class_exists(invokable) {
            let exceptionMsg = "%s: failed retrieving \"%s%s\" via invokable class \"%s\"; class does not exist";
            let method = get_class(this) + "::" + __FUNCTION__;
            if requestedName {
                let requestedNameMsg = "(alias: " + requestedName + ")";
            }
            let exceptionMsg = sprintf(exceptionMsg, method, canonicalName, requestedNameMsg, invokable);

            throw new Exception\ServiceNotFoundException(exceptionMsg);
        }

        let instance = new {invokable}();

        return instance;
    }

    /**
     * Attempt to create an instance via a factory
     *
     * @param  string $canonicalName
     * @param  string $requestedName
     * @return mixed
     * @throws Exception\ServiceNotCreatedException If factory is not callable
     */
    protected function createFromFactory(string canonicalName, string requestedName)
    {

    }

    /**
     * Attempt to create an instance via an abstract factory
     *
     * @param  string $canonicalName
     * @param  string $requestedName
     * @return object|null
     * @throws Exception\ServiceNotCreatedException If abstract factory is not callable
     */
    protected function createFromAbstractFactory(string canonicalName, string requestedName) -> object
    {

    }

    /**
     *
     * @param string $cName
     * @return self
     */
    protected function checkNestedContextStart(string cName) -> <ServiceManager>
    {
        if this->nestedContextCounter === -1 || !isset this->nestedContext[cName] {
            let this->nestedContext[cName] = null;
        }
        let this->nestedContextCounter = this->nestedContextCounter - 1;
        return this;
    }

    /**
     *
     * @param bool $force
     * @return self
     */
    protected function checkNestedContextStop(boolean force = false) -> <ServiceManager>
    {
        if force {
            let this->nestedContextCounter = -1;
            let this->nestedContext = [];
        } else {
            let this->nestedContextCounter = this->nestedContextCounter - 1;
            if this->nestedContextCounter === -1 {
                let this->nestedContext = [];
            }
        }
        return this;
    }

    /**
     * @param $canonicalName
     * @param $requestedName
     * @return mixed
     * @throws Exception\ServiceNotCreatedException
     */
    protected function createDelegatorFromFactory(canonicalName, requestedName)
    {

    }

    /**
     * Checks if the object has this class as one of its parents
     *
     * @see https://bugs.php.net/bug.php?id=53727
     * @see https://github.com/zendframework/zf2/pull/1807
     *
     * @param string $className
     * @param string $type
     * @return bool
     *
     * @deprecated this method is being deprecated as of zendframework 2.2, and may be removed in future major versions
     */
    protected static function isSubclassOf(string className, string type) -> boolean
    {
        var ref;

        if is_subclass_of(className, type) {
            return true;
        }

        if PHP_VERSION_ID >= 50307 {
            return false;
        }

        if interface_exists(type) {
            return false;
        }

        let ref = new ReflectionClass(className);

        return ref->implementsInterface(type);
    }

    /**
     * Unregister a service
     *
     * Called when $allowOverride is true and we detect that a service being
     * added to the instance already exists. This will remove the duplicate
     * entry, and also any shared flags previously registered.
     *
     * @param  string $canonical
     * @return void
     */
    protected function unregisterService(string canonical) -> void
    {
        array types;
        string type;

        let types = ["invokableClasses", "factories", "aliases"];

        for type in types {
            if isset this->{type}[canonical] {
                unset this->{type}[canonical];
                break;
            }
        }

        if isset this->instances[canonical] {
            unset this->instances[canonical];
        }


        if isset this->shared[canonical] {
            unset this->shared[canonical];
        }
    }

}
