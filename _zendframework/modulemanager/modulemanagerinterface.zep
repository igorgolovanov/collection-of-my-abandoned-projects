/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager;

use Zend\EventManager\EventManagerAwareInterface;

/**
 * Module manager interface
 */
interface ModuleManagerInterface extends EventManagerAwareInterface
{
    /**
     * Load the provided modules.
     *
     * @return ModuleManagerInterface
     */
    public function loadModules() -> <ModuleManagerInterface>;

    /**
     * Load a specific module by name.
     *
     * @param  string $moduleName
     * @return mixed Module's Module class
     */
    public function loadModule(string moduleName);

    /**
     * Get an array of the loaded modules.
     *
     * @param  bool $loadModules If true, load modules if they're not already
     * @return array An array of Module objects, keyed by module name
     */
    public function getLoadedModules(boolean loadModules) -> array;

    /**
     * Get the array of module names that this manager should load.
     *
     * @return array
     */
    public function getModules() -> array;

    /**
     * Set an array or Traversable of module names that this module manager should load.
     *
     * @param  mixed $modules array or Traversable of module names
     * @return ModuleManagerInterface
     */
    public function setModules(modules) -> <ModuleManagerInterface>;

}
