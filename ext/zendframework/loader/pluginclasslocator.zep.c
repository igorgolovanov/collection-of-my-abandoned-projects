
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
 * Plugin class locator interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Loader_PluginClassLocator) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Loader, PluginClassLocator, zendframework, loader_pluginclasslocator, zendframework_loader_pluginclasslocator_method_entry);

	zend_class_implements(zendframework_loader_pluginclasslocator_ce TSRMLS_CC, 1, zendframework_loader_shortnamelocator_ce);
	zend_class_implements(zendframework_loader_pluginclasslocator_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * Register a class to a given short name
 *
 * @param  string $shortName
 * @param  string $className
 * @return PluginClassLocator
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_PluginClassLocator, registerPlugin);

/**
 * Unregister a short name lookup
 *
 * @param  mixed $shortName
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_PluginClassLocator, unregisterPlugin);

/**
 * Get a list of all registered plugins
 *
 * @return array|Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_PluginClassLocator, getRegisteredPlugins);

