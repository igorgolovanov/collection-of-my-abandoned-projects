/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager;

use Zend\EventManager\Event;

/**
 * Custom event for use with module manager
 * Composes Module objects
 */
class ModuleEvent extends Event
{

    /**
     * Module events triggered by eventmanager
     */
    const EVENT_MERGE_CONFIG = "mergeConfig";
    const EVENT_LOAD_MODULES = "loadModules";
    const EVENT_LOAD_MODULE_RESOLVE = "loadModule.resolve";
    const EVENT_LOAD_MODULE = "loadModule";
    const EVENT_LOAD_MODULES_POST = "loadModules.post";

    /**
     * @var mixed
     */
    protected module;

    /**
     * @var string
     */
    protected moduleName;

    /**
     * @var Listener\ConfigMergerInterface
     */
    protected configListener;

    /**
     * Get the name of a given module
     *
     * @return string
     */
    public function getModuleName() -> string
    {
        return this->moduleName;
    }

    /**
     * Set the name of a given module
     *
     * @param  string $moduleName
     * @throws Exception\InvalidArgumentException
     * @return ModuleEvent
     */
    public function setModuleName(string! moduleName) -> <ModuleEvent>
    {
        let this->moduleName = moduleName;

        return this;
    }

    /**
     * Get module object
     *
     * @return null|object
     */
    public function getModule() -> object|null
    {
        return this->module;
    }

    /**
     * Set module object to compose in this event
     *
     * @param  object $module
     * @throws Exception\InvalidArgumentException
     * @return ModuleEvent
     */
    public function setModule(object! module) -> <ModuleEvent>
    {
        let this->module = module;

        return this;
    }

    /**
     * Get the config listener
     *
     * @return null|Listener\ConfigMergerInterface
     */
    public function getConfigListener() -> <Listener\ConfigMergerInterface>|null
    {
        return this->configListener;
    }

    /**
     * Set module object to compose in this event
     *
     * @param  Listener\ConfigMergerInterface $configListener
     * @return ModuleEvent
     */
    public function setConfigListener(<Listener\ConfigMergerInterface> configListener) -> <ModuleEvent>
    {
        this->setParam("configListener", configListener);
        let this->configListener = configListener;

        return $this;
    }

}
