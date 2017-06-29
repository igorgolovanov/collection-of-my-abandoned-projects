
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Invalid argument exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_Math_BigInteger_Exception_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Math\\BigInteger\\Exception, InvalidArgumentException, zendframework, math_biginteger_exception_invalidargumentexception, zendframework_math_exception_invalidargumentexception_ce, NULL, 0);

	zend_class_implements(zendframework_math_biginteger_exception_invalidargumentexception_ce TSRMLS_CC, 1, zendframework_math_biginteger_exception_exceptioninterface_ce);
	return SUCCESS;

}

