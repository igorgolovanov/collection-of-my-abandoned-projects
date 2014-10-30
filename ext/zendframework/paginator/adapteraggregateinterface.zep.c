
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
 * Interface that aggregates a Zend\Paginator\Adapter\Abstract just like IteratorAggregate does for Iterators.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Paginator_AdapterAggregateInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Paginator, AdapterAggregateInterface, zendframework, paginator_adapteraggregateinterface, zendframework_paginator_adapteraggregateinterface_method_entry);

	return SUCCESS;

}

/**
 * Return a fully configured Paginator Adapter from this method.
 *
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Paginator_AdapterAggregateInterface, getPaginatorAdapter);

