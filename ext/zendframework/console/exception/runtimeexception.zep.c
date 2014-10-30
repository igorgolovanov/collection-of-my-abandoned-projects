
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Console_Exception_RuntimeException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Console\\Exception, RuntimeException, zendframework, console_exception_runtimeexception, spl_ce_RuntimeException, zendframework_console_exception_runtimeexception_method_entry, 0);

	/**
	 * Usage
	 *
	 * @var string
	 */
	zend_declare_property_string(zendframework_console_exception_runtimeexception_ce, SL("usage"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_console_exception_runtimeexception_ce TSRMLS_CC, 1, zendframework_console_exception_exceptioninterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string $message
 * @param string $usage
 */
PHP_METHOD(ZendFramework_Console_Exception_RuntimeException, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *usage_param = NULL;
	zval *message = NULL, *usage = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &usage_param);

	zephir_get_strval(message, message_param);
	if (!usage_param) {
		ZEPHIR_INIT_VAR(usage);
		ZVAL_STRING(usage, "", 1);
	} else {
		zephir_get_strval(usage, usage_param);
	}


	zephir_update_property_this(this_ptr, SL("usage"), usage TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, zendframework_console_exception_runtimeexception_ce, this_ptr, "__construct", NULL, message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the usage
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Console_Exception_RuntimeException, getUsageMessage) {


	RETURN_MEMBER(this_ptr, "usage");

}

