
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_ClearByNamespaceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, ClearByNamespaceInterface, zendframework, cache_storage_clearbynamespaceinterface, zendframework_cache_storage_clearbynamespaceinterface_method_entry);

	return SUCCESS;

}

/**
 * Remove items of given namespace
 *
 * @param string $namespace
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_ClearByNamespaceInterface, clearByNamespace);

