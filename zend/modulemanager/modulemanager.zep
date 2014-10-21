/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager;

/**
 * Module manager
 */
class ModuleManager implements ModuleManagerInterface, \Zend\EventManager\EventsCapableInterface, \Zend\EventManager\EventManagerAwareInterface
{
    /**
     * @var array An array of Module classes of loaded modules
     */
    protected loadedModules = [];

    /**
     * @var EventManagerInterface
     */
    protected events;

    /**
     * @var ModuleEvent
     */
    protected event;

    /**
     * @var bool
     */
    protected loadFinished;

    /**
     * modules
     *
     * @var array|Traversable
     */
    protected modules = [];

    /**
     * True if modules have already been loaded
     *
     * @var bool
     */
    protected modulesAreLoaded = false;

    /**
     * Constructor
     *
     * @param  array|Traversable $modules
     * @param  EventManagerInterface $eventManager
     */
    public function __construct(var modules, eventManager = null)
    {

    }

    /**
     * Handle the loadModules event
     *
     * @return void
     */
    public function onLoadModules() -> void
    {

    }

    /**
     * Load the provided modules.
     *
     * @triggers loadModules
     * @triggers loadModules.post
     * @return   ModuleManager
     */
    public function loadModules() -> <ModuleManager>
    {

    }

    /**
     * Load a specific module by name.
     *
     * @param  string|array               $module
     * @throws Exception\RuntimeException
     * @triggers loadModule.resolve
     * @triggers loadModule
     * @return mixed Module's Module class
     */
    public function loadModule(var module)
    {

    }

    /**
     * Load a module with the name
     * @param  \Zend\EventManager\EventInterface $event
     * @return mixed                            module instance
     * @throws Exception\RuntimeException
     */
    protected function loadModuleByName(<\Zend\EventManager\EventInterface> event)
    {

    }

    /**
     * Get an array of the loaded modules.
     *
     * @param  bool  $loadModules If true, load modules if they're not already
     * @return array An array of Module objects, keyed by module name
     */
    public function getLoadedModules(boolean loadModules = false) -> array
    {

    }

    /**
     * Get an instance of a module class by the module name
     *
     * @param  string $moduleName
     * @return mixed
     */
    public function getModule(string moduleName)
    {

    }

    /**
     * Get the array of module names that this manager should load.
     *
     * @return array
     */
    public function getModules() -> array
    {

    }

    /**
     * Set an array or Traversable of module names that this module manager should load.
     *
     * @param  mixed $modules array or Traversable of module names
     * @throws Exception\InvalidArgumentException
     * @return ModuleManager
     */
    public function setModules(modules) -> <ModuleManager>
    {

    }

    /**
     * Get the module event
     *
     * @return ModuleEvent
     */
    public function getEvent() -> <ModuleEvent>
    {

    }

    /**
     * Set the module event
     *
     * @param  ModuleEvent $event
     * @return ModuleManager
     */
    public function setEvent(<ModuleEvent> event) -> <ModuleManager>
    {

    }

    /**
     * Set the event manager instance used by this module manager.
     *
     * @param  EventManagerInterface $events
     * @return ModuleManager
     */
    public function setEventManager(events) -> <ModuleManager>
    {

    }

    /**
     * Retrieve the event manager
     *
     * Lazy-loads an EventManager instance if none registered.
     *
     * @return EventManagerInterface
     */
    public function getEventManager()
    {

    }

    /**
     * Register the default event listeners
     *
     * @return ModuleManager
     */
    protected function attachDefaultListeners() -> <ModuleManager>
    {

    }

}
