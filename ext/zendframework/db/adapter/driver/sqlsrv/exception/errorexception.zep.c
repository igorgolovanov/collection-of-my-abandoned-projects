
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_Sqlsrv_Exception_ErrorException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Db\\Adapter\\Driver\\Sqlsrv\\Exception, ErrorException, zendframework, db_adapter_driver_sqlsrv_exception_errorexception, zendframework_db_adapter_exception_errorexception_ce, zendframework_db_adapter_driver_sqlsrv_exception_errorexception_method_entry, 0);

	/**
	 * Errors
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_db_adapter_driver_sqlsrv_exception_errorexception_ce, SL("errors"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_db_adapter_driver_sqlsrv_exception_errorexception_ce TSRMLS_CC, 1, zendframework_db_adapter_driver_sqlsrv_exception_exceptioninterface_ce);
	return SUCCESS;

}

/**
 * Construct
 *
 * @param  bool $errors
 */
PHP_METHOD(ZendFramework_Db_Adapter_Driver_Sqlsrv_Exception_ErrorException, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *errors = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &errors);

	if (!errors) {
		ZEPHIR_CPY_WRT(errors, ZEPHIR_GLOBAL(global_false));
	} else {
		ZEPHIR_SEPARATE_PARAM(errors);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("errors"), _0 TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(errors)) {
		ZEPHIR_CALL_FUNCTION(&errors, "sqlsrv_errors", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("errors"), errors TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

