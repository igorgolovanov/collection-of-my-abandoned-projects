
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * ErrorHandler that can be used to catch internal PHP errors
 * and convert to an ErrorException instance.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ErrorHandler) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, ErrorHandler, zendframework, stdlib_errorhandler, zendframework_stdlib_errorhandler_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Active stack
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_errorhandler_ce, SL("stack"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Check if this error handler is active
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, started) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_STATIC("getnestedlevel", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get the current nested level
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, getNestedLevel) {

	zval *className, *stackData = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(stackData);
	ZVAL_NULL(stackData);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        
	if (Z_TYPE_P(stackData) == IS_ARRAY) {
		RETURN_MM_LONG(zephir_fast_count_int(stackData TSRMLS_CC));
	}
	RETURN_MM_LONG(0);

}

/**
 * Starting the error handler
 *
 * @param int $errorLevel
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, start) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0;
	zval *errorLevel_param = NULL, *className, *stackData = NULL, *_1, _2;
	int errorLevel, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &errorLevel_param);

	if (!errorLevel_param) {
		errorLevel = 2;
	} else {
		errorLevel = zephir_get_intval(errorLevel_param);
	}
	ZEPHIR_INIT_VAR(stackData);
	ZVAL_NULL(stackData);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        
	if (zephir_is_true(stackData)) {
		ZEPHIR_INIT_VAR(_0);
		array_init_size(_0, 3);
		zephir_array_fast_append(_0, className);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "addError", 1);
		zephir_array_fast_append(_0, _1);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, errorLevel);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", &_3, _0, &_2);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(stackData) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(stackData);
		array_init(stackData);
	}
	zephir_array_append(&stackData, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "zendframework/stdlib/errorhandler.zep", 79);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Stopping the error handler
 *
 * @param  bool $throw Throw the ErrorException if any
 * @return null|ErrorException
 * @throws ErrorException If an error has been catched and $throw is true
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, stop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *throw_param = NULL, *errorException = NULL, *className, *stackData = NULL;
	zend_bool throw, _0, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &throw_param);

	if (!throw_param) {
		throw = 0;
	} else {
		throw = zephir_get_boolval(throw_param);
	}
	ZEPHIR_INIT_VAR(errorException);
	ZVAL_NULL(errorException);
	ZEPHIR_INIT_VAR(stackData);
	ZVAL_NULL(stackData);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        
	_0 = Z_TYPE_P(stackData) == IS_ARRAY;
	if (_0) {
		_0 = !ZEPHIR_IS_EMPTY(stackData);
	}
	if (_0) {
		Z_SET_ISREF_P(stackData);
		ZEPHIR_CALL_FUNCTION(&errorException, "array_pop", &_1, stackData);
		Z_UNSET_ISREF_P(stackData);
		zephir_check_call_status();
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
            
		if (!(ZEPHIR_IS_EMPTY(stackData))) {
			ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", &_2);
			zephir_check_call_status();
		}
		_3 = zephir_is_true(errorException);
		if (_3) {
			_3 = throw;
		}
		if (_3) {
			zephir_throw_exception_debug(errorException, "zendframework/stdlib/errorhandler.zep", 113 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(errorException);

}

/**
 * Stop all active handler
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, clean) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *className, *stackData = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(stackData);
	ZVAL_NULL(stackData);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        
	if (!(ZEPHIR_IS_EMPTY(stackData))) {
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", &_0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(stackData);
	array_init(stackData);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Add an error to the stack
 *
 * @param int    $errno
 * @param string $errstr
 * @param string $errfile
 * @param int    $errline
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, addError) {

	zval *errstr = NULL, *errfile = NULL;
	zval *errno_param = NULL, *errstr_param = NULL, *errfile_param = NULL, *errline_param = NULL, *stackData = NULL, *className, *stackIndex = NULL, *stackItem = NULL, *_0, *_1, *_2, *_3;
	int errno, errline, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &errno_param, &errstr_param, &errfile_param, &errline_param);

	errno = zephir_get_intval(errno_param);
	if (!errstr_param) {
		ZEPHIR_INIT_VAR(errstr);
		ZVAL_STRING(errstr, "", 1);
	} else {
		zephir_get_strval(errstr, errstr_param);
	}
	if (!errfile_param) {
		ZEPHIR_INIT_VAR(errfile);
		ZVAL_STRING(errfile, "", 1);
	} else {
		zephir_get_strval(errfile, errfile_param);
	}
	if (!errline_param) {
		errline = 0;
	} else {
		errline = zephir_get_intval(errline_param);
	}
	ZEPHIR_INIT_VAR(stackData);
	ZVAL_NULL(stackData);
	ZEPHIR_INIT_VAR(stackItem);
	ZVAL_NULL(stackItem);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        
	if (Z_TYPE_P(stackData) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(stackData);
		array_init(stackData);
	}
	ZEPHIR_INIT_VAR(stackIndex);
	ZVAL_LONG(stackIndex, zephir_fast_count_int(stackData TSRMLS_CC));
	ZEPHIR_SEPARATE(stackIndex);
	zephir_decrement(stackIndex);
	if (ZEPHIR_LT_LONG(stackIndex, 0)) {
		ZEPHIR_INIT_NVAR(stackIndex);
		ZVAL_LONG(stackIndex, 0);
	}
	if (zephir_array_isset(stackData, stackIndex)) {
		ZEPHIR_OBS_NVAR(stackItem);
		zephir_array_fetch(&stackItem, stackData, stackIndex, PH_NOISY, "zendframework/stdlib/errorhandler.zep", 169 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, errno);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, errline);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, errstr, _1, _2, errfile, _3, stackItem);
	zephir_check_call_status();
	zephir_array_update_zval(&stackData, stackIndex, &_0, PH_COPY | PH_SEPARATE);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

