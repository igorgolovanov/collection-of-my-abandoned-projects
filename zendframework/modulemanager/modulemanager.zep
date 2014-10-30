/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager;

use Zend\EventManager\EventManager;
use Zend\EventManager\EventManagerInterface;
use Zend\EventManager\EventInterface;

/**
 * Module manager
 */
class ModuleManager implements ModuleManagerInterface
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
    public function __construct(var modules, <EventManagerInterface> eventManager = null)
    {
        this->setModules(modules);
        if eventManager !== null {
            this->setEventManager(eventManager);
        }
    }

    /**
     * Handle the loadModules event
     *
     * @return void
     */
    public function onLoadModules() -> void
    {
        var modules, moduleName, module, className;
        string exceptionMsg;

        if this->modulesAreLoaded === true {
            return;
        }

        let modules = this->getModules();
        for moduleName, module in modules {
            if typeof module == "object" {
                if unlikely typeof moduleName != "string" {
                    let className = get_class(module);
                    let exceptionMsg = "Module (" . className . ") must have a key identifier.";

                    throw new Exception\RuntimeException(exceptionMsg);
                }
                let module = [moduleName: module];
            }
            this->loadModule(module);
        }
        let this->modulesAreLoaded = true;
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
        var events, event;

        if this->modulesAreLoaded !== true {
            let events = <EventManagerInterface> this->getEventManager();
            let event = <EventInterface> this->getEvent();

            events->trigger(ModuleEvent::EVENT_LOAD_MODULES, this, event);
            /**
            * Having a dedicated .post event abstracts the complexity of priorities from the user.
            * Users can attach to the .post event and be sure that important
            * things like config merging are complete without having to worry if
            * they set a low enough priority.
            */
            let event = <EventInterface> this->getEvent();
            events->trigger(ModuleEvent::EVENT_LOAD_MODULES_POST, this, event);
        }
        return this;
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
        var moduleName, moduleClass, event, events;


        if typeof module == "array" {
            let moduleName = key(module);
            let module = current(module);
        } else {
            let moduleName = module;
        }

        if fetch moduleClass, this->loadedModules[moduleName] {
            return moduleClass;
        }

        /*
        * Keep track of nested module loading using the $loadFinished
        * property.
        *
        * Increment the value for each loadModule() call and then decrement
        * once the loading process is complete.
        *
        * To load a module, we clone the event if we are inside a nested
        * loadModule() call, and use the original event otherwise.
        */
        if !isset this->loadFinished {
            let this->loadFinished = 0;
        }

        let event = <EventInterface> this->getEvent();
        if this->loadFinished > 0 {
            let event = clone event;
        }
        event->setModuleName(moduleName);

        let this->loadFinished++;

        if typeof module != "object" {
            let module = this->loadModuleByName(event);
        }
        event->setModule(module);

        let this->loadedModules[moduleName] = module;
        let events = <EventManagerInterface> this->getEventManager();

        events->trigger(ModuleEvent::EVENT_LOAD_MODULE, this, event);

        let this->loadFinished--;

        return module;
    }

    /**
     * Load a module with the name
     * @param  \Zend\EventManager\EventInterface $event
     * @return mixed                            module instance
     * @throws Exception\RuntimeException
     */
    protected function loadModuleByName(<EventInterface> event)
    {
        var events, result, module, moduleName;
        string exceptionMsg;

        let events = <EventManagerInterface> this->getEventManager();
        let result = events->trigger(ModuleEvent::EVENT_LOAD_MODULE_RESOLVE, this, event, "is_object");
        // todo: add response collection
        let module = result->last();

        if unlikely typeof module != "object" {
            let moduleName = event->getModuleName();
            let exceptionMsg = "Module (" . moduleName . ") could not be initialized.";
            throw new Exception\RuntimeException(exceptionMsg);
        }
        return module;
    }

    /**
     * Get an array of the loaded modules.
     *
     * @param  bool  $loadModules If true, load modules if they're not already
     * @return array An array of Module objects, keyed by module name
     */
    public function getLoadedModules(boolean loadModules = false) -> array
    {
        if loadModules {
            this->loadModules();
        }
        return this->loadedModules;
    }

    /**
     * Get an instance of a module class by the module name
     *
     * @param  string $moduleName
     * @return mixed
     */
    public function getModule(string moduleName)
    {
        var module;

        if fetch module, this->loadedModules[moduleName] {
            return module;
        }
        return null;
    }

    /**
     * Get the array of module names that this manager should load.
     *
     * @return array
     */
    public function getModules() -> array
    {
        return this->modules;
    }

    /**
     * Set an array or Traversable of module names that this module manager should load.
     *
     * @param  mixed $modules array or Traversable of module names
     * @throws Exception\InvalidArgumentException
     * @return ModuleManager
     */
    public function setModules(var modules) -> <ModuleManager>
    {
        string exceptionMsg;

        if unlikely typeof modules != "array" && !(modules instanceof \Traversable) {
            let exceptionMsg = "Parameter to " . __CLASS__ . "\'s " .  __METHOD__ . " method must be an array or implement the Traversable interface";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->modules = modules;
        return this;
    }

    /**
     * Get the module event
     *
     * @return ModuleEvent
     */
    public function getEvent() -> <ModuleEvent>
    {
        var event;

        let event = this->event;
        if !(event instanceof ModuleEvent) {
            let event = new ModuleEvent();
            this->setEvent(event);
        }
        return event;
    }

    /**
     * Set the module event
     *
     * @param  ModuleEvent $event
     * @return ModuleManager
     */
    public function setEvent(<ModuleEvent> event) -> <ModuleManager>
    {
        let this->event = event;

        return this;
    }

    /**
     * Set the event manager instance used by this module manager.
     *
     * @param  EventManagerInterface $events
     * @return ModuleManager
     */
    public function setEventManager(<EventManagerInterface> events) -> <ModuleManager>
    {
        var className;

        let className = get_class(this);
        events->setIdentifiers([__CLASS__, className, "module_manager"]);
        let this->events = events;
        this->attachDefaultListeners();

        return this;
    }

    /**
     * Retrieve the event manager
     *
     * Lazy-loads an EventManager instance if none registered.
     *
     * @return EventManagerInterface
     */
    public function getEventManager() -> <EventManagerInterface>
    {
        var events;

        let events = this->events;
        if !(events instanceof EventManagerInterface) {
            let events = new EventManager();
            this->setEventManager(events);
        }
        return events;
    }

    /**
     * Register the default event listeners
     *
     * @return ModuleManager
     */
    protected function attachDefaultListeners() -> <ModuleManager>
    {
        var events;

        let events = <EventManagerInterface> this->getEventManager();
        events->attach(ModuleEvent::EVENT_LOAD_MODULES, [this, "onLoadModules"]);

        return this;
    }

}
