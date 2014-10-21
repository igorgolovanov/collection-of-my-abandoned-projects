/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

class ServiceListener implements ServiceListenerInterface, \Zend\EventManager\ListenerAggregateInterface
{
    /**
     * @var \Zend\Stdlib\CallbackHandler[]
     */
    protected listeners = [];

    /**
     * Default service manager used to fulfill other SMs that need to be lazy loaded
     *
     * @var ServiceManager
     */
    protected defaultServiceManager;

    /**
     * @var array
     */
    protected defaultServiceConfig;

    /**
     * @var array
     */
    protected serviceManagers = [];

    /**
     * @param ServiceManager $serviceManager
     * @param null|array $configuration
     */
    public function __construct(serviceManager, array configuration = null)
    {

    }

    /**
     * @param  array $configuration
     * @return ServiceListener
     */
    public function setDefaultServiceConfig(array configuration) -> <ServiceListener>
    {

    }

    /**
     * @param  ServiceManager|string $serviceManager  Service Manager instance or name
     * @param  string                $key             Configuration key
     * @param  string                $moduleInterface FQCN as string
     * @param  string                $method          Method name
     * @throws Exception\RuntimeException
     * @return ServiceListener
     */
    public function addServiceManager(string serviceManager, string key, string moduleInterface, string method) -> <ServiceListener>
    {

    }

    /**
     * @param  EventManagerInterface $events
     * @return ServiceListener
     */
    public function attach(events) -> <ServiceListener>
    {

    }

    /**
     * @param  EventManagerInterface $events
     * @return void
     */
    public function detach(events) -> void
    {

    }

    /**
     * Retrieve service manager configuration from module, and
     * configure the service manager.
     *
     * If the module does not implement a specific interface and does not
     * implement a specific method, does nothing. Also, if the return value
     * of that method is not a ServiceConfig object, or not an array or
     * Traversable that can seed one, does nothing.
     *
     * The interface and method name can be set by adding a new service manager
     * via the addServiceManager() method.
     *
     * @param  ModuleEvent $e
     * @return void
     */
    public function onLoadModule(e) -> void
    {

    }

    /**
     * Use merged configuration to configure service manager
     *
     * If the merged configuration has a non-empty, array 'service_manager'
     * key, it will be passed to a ServiceManager Config object, and
     * used to configure the service manager.
     *
     * @param  ModuleEvent $e
     * @throws Exception\RuntimeException
     * @return void
     */
    public function onLoadModulesPost(e) -> void
    {

    }

    /**
     * Merge a service configuration container
     *
     * Extracts the various service configuration arrays, and then merges with
     * the internal service configuration.
     *
     * @param  ServiceConfig|string $config Instance of ServiceConfig or class name
     * @throws Exception\RuntimeException
     * @return array
     */
    protected function serviceConfigToArray(string config) -> array
    {

    }

}
