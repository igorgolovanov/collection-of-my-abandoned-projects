/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager;

/**
 * ServiceManager implementation for managing plugins
 *
 * Automatically registers an initializer which should be used to verify that
 * a plugin instance is of a valid type. Additionally, allows plugins to accept
 * an array of options for the constructor, which can be used to configure
 * the plugin when retrieved. Finally, enables the allowOverride property by
 * default to allow registering factories, aliases, and invokables to take
 * the place of those provided by the implementing class.
 */
abstract class AbstractPluginManager extends ServiceManager implements ServiceLocatorInterface, ServiceLocatorAwareInterface
{
    const SCOPE_PARENT = "parent";

    const SCOPE_CHILD = "child";

    /**
     * Allow overriding by default
     *
     * @var bool
     */
    protected allowOverride = true;

    /**
     * Whether or not to auto-add a class as an invokable class if it exists
     *
     * @var bool
     */
    protected autoAddInvokableClass = true;

    /**
     * Options to use when creating an instance
     *
     * @var mixed
     */
    protected creationOptions;

    /**
     * The main service locator
     *
     * @var ServiceLocatorInterface
     */
    protected serviceLocator;

    /**
     * Constructor
     *
     * Add a default initializer to ensure the plugin is valid after instance
     * creation.
     *
     * @param  null|ConfigInterface $configuration
     */
    public function __construct(<ConfigInterface> configuration = null)
    {
        parent::__construct(configuration);


    }

    /**
     * Validate the plugin
     *
     * Checks that the filter loaded is either a valid callback or an instance
     * of FilterInterface.
     *
     * @param  mixed $plugin
     * @return void
     * @throws Exception\RuntimeException if invalid
     */
    abstract public function validatePlugin(plugin) -> void;

    /**
     * Retrieve a service from the manager by name
     *
     * Allows passing an array of options to use when creating the instance.
     * createFromInvokable() will use these and pass them to the instance
     * constructor if not null and a non-empty array.
     *
     * @param  string $name
     * @param  array $options
     * @param  bool $usePeeringServiceManagers
     * @return object
     */
    public function get(string name, array options = [], boolean usePeeringServiceManagers = true) -> object
    {

    }

    /**
     * Register a service with the locator.
     *
     * Validates that the service object via validatePlugin() prior to
     * attempting to register it.
     *
     * @param  string $name
     * @param  mixed $service
     * @param  bool $shared
     * @return AbstractPluginManager
     * @throws Exception\InvalidServiceNameException
     */
    public function setService(string name, service, boolean shared = true) -> <AbstractPluginManager>
    {
        if service {
            this->validatePlugin(service);
        }
        parent::setService(name, service, shared);
        return this;
    }

    /**
     * Set the main service locator so factories can have access to it to pull deps
     *
     * @param ServiceLocatorInterface $serviceLocator
     * @return AbstractPluginManager
     */
    public function setServiceLocator(<ServiceLocatorInterface> serviceLocator) -> <AbstractPluginManager>
    {
        let this->serviceLocator = serviceLocator;
        return this;
    }

    /**
     * Get the main plugin manager. Useful for fetching dependencies from within factories.
     *
     * @return ServiceLocatorInterface
     */
    public function getServiceLocator() -> <ServiceLocatorInterface>
    {
        return this->serviceLocator;
    }

    /**
     * Attempt to create an instance via an invokable class
     *
     * Overrides parent implementation by passing $creationOptions to the
     * constructor, if non-null.
     *
     * @param  string $canonicalName
     * @param  string $requestedName
     * @return null|\stdClass
     * @throws Exception\ServiceNotCreatedException If resolved class does not exist
     */
    protected function createFromInvokable(string canonicalName, string requestedName) -> <\stdClass>
    {
        
    }

    /**
     * Attempt to create an instance via a factory class
     *
     * Overrides parent implementation by passing $creationOptions to the
     * constructor, if non-null.
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

}
