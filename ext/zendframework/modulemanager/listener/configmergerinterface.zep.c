
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Config merger interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Listener_ConfigMergerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Listener, ConfigMergerInterface, zendframework, modulemanager_listener_configmergerinterface, zendframework_modulemanager_listener_configmergerinterface_method_entry);

	return SUCCESS;

}

/**
 * getMergedConfig
 *
 * @param  bool $returnConfigAsObject
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Listener_ConfigMergerInterface, getMergedConfig);

/**
 * setMergedConfig
 *
 * @param  array $config
 * @return ConfigMergerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Listener_ConfigMergerInterface, setMergedConfig);

