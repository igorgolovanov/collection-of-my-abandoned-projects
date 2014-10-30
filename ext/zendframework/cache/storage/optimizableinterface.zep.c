
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_OptimizableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, OptimizableInterface, zendframework, cache_storage_optimizableinterface, zendframework_cache_storage_optimizableinterface_method_entry);

	return SUCCESS;

}

/**
 * Optimize the storage
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_OptimizableInterface, optimize);

