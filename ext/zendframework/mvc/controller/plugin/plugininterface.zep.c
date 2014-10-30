
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Controller_Plugin_PluginInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc\\Controller\\Plugin, PluginInterface, zendframework, mvc_controller_plugin_plugininterface, zendframework_mvc_controller_plugin_plugininterface_method_entry);

	return SUCCESS;

}

/**
 * Set the current controller instance
 *
 * @param  Dispatchable $controller
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Controller_Plugin_PluginInterface, setController);

/**
 * Get the current controller instance
 *
 * @return null|DispatchableInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Controller_Plugin_PluginInterface, getController);

