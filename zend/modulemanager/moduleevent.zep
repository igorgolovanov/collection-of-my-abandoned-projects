/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager;

/**
 * Custom event for use with module manager
 * Composes Module objects
 */
class ModuleEvent extends \Zend\EventManager\Event implements \Zend\EventManager\EventInterface
{
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

    }

    /**
     * Set the name of a given module
     *
     * @param  string $moduleName
     * @throws Exception\InvalidArgumentException
     * @return ModuleEvent
     */
    public function setModuleName(string moduleName) -> <ModuleEvent>
    {

    }

    /**
     * Get module object
     *
     * @return null|object
     */
    public function getModule() -> object
    {

    }

    /**
     * Set module object to compose in this event
     *
     * @param  object $module
     * @throws Exception\InvalidArgumentException
     * @return ModuleEvent
     */
    public function setModule(object module) -> <ModuleEvent>
    {

    }

    /**
     * Get the config listener
     *
     * @return null|Listener\ConfigMergerInterface
     */
    public function getConfigListener() -> <Listener\ConfigMergerInterface>
    {

    }

    /**
     * Set module object to compose in this event
     *
     * @param  Listener\ConfigMergerInterface $configListener
     * @return ModuleEvent
     */
    public function setConfigListener(<Listener\ConfigMergerInterface> configListener) -> <ModuleEvent>
    {

    }

}
