
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Invalid argument exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_Math_BigInteger_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Math\\BigInteger\\Exception, ExceptionInterface, zendframework, math_biginteger_exception_exceptioninterface, NULL);

	zend_class_implements(zendframework_math_biginteger_exception_exceptioninterface_ce TSRMLS_CC, 1, zendframework_math_exception_exceptioninterface_ce);
	return SUCCESS;

}

