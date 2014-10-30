
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
ZEPHIR_INIT_CLASS(ZendFramework_Paginator_ScrollingStyle_ScrollingStyleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Paginator\\ScrollingStyle, ScrollingStyleInterface, zendframework, paginator_scrollingstyle_scrollingstyleinterface, zendframework_paginator_scrollingstyle_scrollingstyleinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an array of "local" pages given a page number and range.
 *
 * @param  Paginator $paginator
 * @param  int $pageRange (Optional) Page range
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Paginator_ScrollingStyle_ScrollingStyleInterface, getPages);

