
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_FlushableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, FlushableInterface, zendframework, cache_storage_flushableinterface, zendframework_cache_storage_flushableinterface_method_entry);

	return SUCCESS;

}

/**
 * Flush the whole storage
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_FlushableInterface, flush);

