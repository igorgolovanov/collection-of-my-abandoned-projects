
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
 * Exception thrown when one or more method arguments are invalid
 */
ZEPHIR_INIT_CLASS(ZendFramework_Soap_Exception_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Soap\\Exception, InvalidArgumentException, zendframework, soap_exception_invalidargumentexception, spl_ce_InvalidArgumentException, NULL, 0);

	zend_class_implements(zendframework_soap_exception_invalidargumentexception_ce TSRMLS_CC, 1, zendframework_soap_exception_exceptioninterface_ce);
	return SUCCESS;

}

