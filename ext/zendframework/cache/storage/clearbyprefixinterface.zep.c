
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_ClearByPrefixInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, ClearByPrefixInterface, zendframework, cache_storage_clearbyprefixinterface, zendframework_cache_storage_clearbyprefixinterface_method_entry);

	return SUCCESS;

}

/**
 * Remove items matching given prefix
 *
 * @param string $prefix
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_ClearByPrefixInterface, clearByPrefix);

