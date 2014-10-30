
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Module manager interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_ModuleManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager, ModuleManagerInterface, zendframework, modulemanager_modulemanagerinterface, zendframework_modulemanager_modulemanagerinterface_method_entry);

	zend_class_implements(zendframework_modulemanager_modulemanagerinterface_ce TSRMLS_CC, 1, zendframework_eventmanager_eventmanagerawareinterface_ce);
	return SUCCESS;

}

/**
 * Load the provided modules.
 *
 * @return ModuleManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_ModuleManagerInterface, loadModules);

/**
 * Load a specific module by name.
 *
 * @param  string $moduleName
 * @return mixed Module's Module class
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_ModuleManagerInterface, loadModule);

/**
 * Get an array of the loaded modules.
 *
 * @param  bool $loadModules If true, load modules if they're not already
 * @return array An array of Module objects, keyed by module name
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_ModuleManagerInterface, getLoadedModules);

/**
 * Get the array of module names that this manager should load.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_ModuleManagerInterface, getModules);

/**
 * Set an array or Traversable of module names that this module manager should load.
 *
 * @param  mixed $modules array or Traversable of module names
 * @return ModuleManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_ModuleManagerInterface, setModules);

