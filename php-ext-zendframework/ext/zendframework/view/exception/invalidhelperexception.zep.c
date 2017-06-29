
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Invalid helper exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Exception_InvalidHelperException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\View\\Exception, InvalidHelperException, zendframework, view_exception_invalidhelperexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	zend_class_implements(zendframework_view_exception_invalidhelperexception_ce TSRMLS_CC, 1, zendframework_view_exception_exceptioninterface_ce);
	return SUCCESS;

}

