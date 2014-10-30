
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_Plugin_PluginInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage\\Plugin, PluginInterface, zendframework, cache_storage_plugin_plugininterface, zendframework_cache_storage_plugin_plugininterface_method_entry);

	zend_class_implements(zendframework_cache_storage_plugin_plugininterface_ce TSRMLS_CC, 1, zendframework_eventmanager_listeneraggregateinterface_ce);
	return SUCCESS;

}

/**
 * Set options
 *
 * @param  PluginOptions $options
 * @return PluginInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_Plugin_PluginInterface, setOptions);

/**
 * Get options
 *
 * @return PluginOptions
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_Plugin_PluginInterface, getOptions);

