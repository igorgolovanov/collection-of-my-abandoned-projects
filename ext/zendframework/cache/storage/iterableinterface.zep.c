
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
 *
 * @method IteratorInterface getIterator() Get the storage iterator
 */
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_IterableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, IterableInterface, zendframework, cache_storage_iterableinterface, NULL);

	zend_class_implements(zendframework_cache_storage_iterableinterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

