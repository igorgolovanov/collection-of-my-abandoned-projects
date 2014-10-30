
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_IteratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, IteratorInterface, zendframework, cache_storage_iteratorinterface, zendframework_cache_storage_iteratorinterface_method_entry);

	zend_declare_class_constant_long(zendframework_cache_storage_iteratorinterface_ce, SL("CURRENT_AS_SELF"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_cache_storage_iteratorinterface_ce, SL("CURRENT_AS_KEY"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_cache_storage_iteratorinterface_ce, SL("CURRENT_AS_VALUE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_cache_storage_iteratorinterface_ce, SL("CURRENT_AS_METADATA"), 3 TSRMLS_CC);

	zend_class_implements(zendframework_cache_storage_iteratorinterface_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Get storage instance
 *
 * @return StorageInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_IteratorInterface, getStorage);

/**
 * Get iterator mode
 *
 * @return int Value of IteratorInterface::CURRENT_AS_*
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_IteratorInterface, getMode);

/**
 * Set iterator mode
 *
 * @param int $mode Value of IteratorInterface::CURRENT_AS_*
 * @return IteratorInterface Fluent interface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_IteratorInterface, setMode);

