
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_TotalSpaceCapableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, TotalSpaceCapableInterface, zendframework, cache_storage_totalspacecapableinterface, zendframework_cache_storage_totalspacecapableinterface_method_entry);

	return SUCCESS;

}

/**
 * Get total space in bytes
 *
 * @return int|float
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_TotalSpaceCapableInterface, getTotalSpace);

