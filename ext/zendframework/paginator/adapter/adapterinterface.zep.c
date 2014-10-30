
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
 * Interface for pagination adapters.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Paginator_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Paginator\\Adapter, AdapterInterface, zendframework, paginator_adapter_adapterinterface, zendframework_paginator_adapter_adapterinterface_method_entry);

	zend_class_implements(zendframework_paginator_adapter_adapterinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Returns a collection of items for a page.
 *
 * @param  int $offset Page offset
 * @param  int $itemCountPerPage Number of items per page
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Paginator_Adapter_AdapterInterface, getItems);

