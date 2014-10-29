
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/
/**
 * CallbackHandler
 *
 * A handler for an event, event, filterchain, etc. Abstracts PHP callbacks,
 * primarily to allow for lazy-loading and ensuring availability of default
 * arguments (currying).
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_CallbackHandler) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, CallbackHandler, zendframework, stdlib_callbackhandler, zendframework_stdlib_callbackhandler_method_entry, 0);

	/**
	 * @var string|array|callable PHP callback to invoke
	 */
	zend_declare_property_null(zendframework_stdlib_callbackhandler_ce, SL("callback"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Callback metadata, if any
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_callbackhandler_ce, SL("metadata"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * PHP version is greater as 5.4rc1?
	 * @var bool
	 */
	zend_declare_property_null(zendframework_stdlib_callbackhandler_ce, SL("isPhp54"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param  string|array|object|callable $callback PHP callback
 * @param  array                        $metadata  Callback metadata
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metadata = NULL;
	zval *callback, *metadata_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &metadata_param);

	if (!metadata_param) {
		ZEPHIR_INIT_VAR(metadata);
		array_init(metadata);
	} else {
	if (unlikely(Z_TYPE_P(metadata_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'metadata' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		metadata = metadata_param;

	}


	zephir_update_property_this(this_ptr, SL("metadata"), metadata TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registercallback", NULL, callback);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers the callback provided in the constructor
 *
 * @param  callable $callback
 * @throws Exception\InvalidCallbackException
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, registerCallback) {

	zval *callback;

	zephir_fetch_params(0, 1, 0, &callback);

	if (unlikely(zephir_is_callable(callback TSRMLS_CC) != 1)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'callback' must be callable") TSRMLS_CC);
		RETURN_NULL();
	}



	if (unlikely(!zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zendframework_stdlib_exception_invalidcallbackexception_ce, "Invalid callback provided; not callable", "zendframework/stdlib/callbackhandler.zep", 61);
		return;
	}
	zephir_update_property_this(this_ptr, SL("callback"), callback TSRMLS_CC);

}

/**
 * Retrieve registered callback
 *
 * @return callable
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getCallback) {


	RETURN_MEMBER(this_ptr, "callback");

}

/**
 * Invoke handler
 *
 * @param  array $args Arguments to pass to callback
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, call) {

	zend_bool _4;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_6 = NULL;
	int argCount, ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL, *callback = NULL, *result = NULL, *arg1 = NULL, *arg2 = NULL, *arg3 = NULL, *className, *isPhp54 = NULL, *_0, _1, _2;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
	if (unlikely(Z_TYPE_P(args_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'args' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		args = args_param;

	}
	ZEPHIR_INIT_VAR(isPhp54);
	ZVAL_NULL(isPhp54);


	ZEPHIR_CALL_METHOD(&callback, this_ptr, "getcallback",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&isPhp54, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("isPhp54") TSRMLS_CC);
        
	if (Z_TYPE_P(isPhp54) == IS_NULL) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "5.4.0rc1", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, ">=", 0);
		ZEPHIR_CALL_FUNCTION(&isPhp54, "version_compare", &_3, _0, &_1, &_2);
		zephir_check_call_status();
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("isPhp54"), &isPhp54 TSRMLS_CC);
            
	}
	argCount = zephir_fast_count_int(args TSRMLS_CC);
	if (zephir_is_true(isPhp54)) {
		if (Z_TYPE_P(callback) == IS_STRING) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "validatestringcallbackfor54", NULL, callback);
			zephir_check_call_status();
			_4 = !ZEPHIR_IS_TRUE_IDENTICAL(result);
			if (_4) {
				_4 = argCount <= 3;
			}
			if (_4) {
				ZEPHIR_CPY_WRT(callback, result);
				zephir_update_property_this(this_ptr, SL("callback"), result TSRMLS_CC);
			}
		}
	}
	do {
		if (argCount == 0) {
			if (zephir_is_true(isPhp54)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&result, callback, NULL);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, callback);
				zephir_check_call_status();
			}
			break;
		}
		if (argCount == 1) {
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg1, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			if (zephir_is_true(isPhp54)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&result, callback, NULL, arg1);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, callback, arg1);
				zephir_check_call_status();
			}
			break;
		}
		if (argCount == 2) {
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg1, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg2, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			if (zephir_is_true(isPhp54)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&result, callback, NULL, arg1, arg2);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, callback, arg1, arg2);
				zephir_check_call_status();
			}
			break;
		}
		if (argCount == 3) {
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg1, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg2, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			Z_SET_ISREF_P(args);
			ZEPHIR_CALL_FUNCTION(&arg3, "array_shift", &_6, args);
			Z_UNSET_ISREF_P(args);
			zephir_check_call_status();
			if (zephir_is_true(isPhp54)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&result, callback, NULL, arg1, arg2, arg3);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_5, callback, arg1, arg2, arg3);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_NVAR(result);
		ZEPHIR_CALL_USER_FUNC_ARRAY(result, callback, args);
		zephir_check_call_status();
	} while(0);

	RETURN_CCTOR(result);

}

/**
 * Invoke as functor
 *
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *args = NULL, *result = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "call", NULL, args);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Get all callback metadata
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getMetadata) {


	RETURN_MEMBER(this_ptr, "metadata");

}

/**
 * Retrieve a single metadatum
 *
 * @param  string $name
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getMetadatum) {

	zval *name_param = NULL, *value, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("metadata"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Validate a static method call
 *
 * Validates that a static method call in PHP 5.4 will actually work
 *
 * @param  string $callback
 * @return true|array
 * @throws Exception\InvalidCallbackException if invalid
 */
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, validateStringCallbackFor54) {

	zend_class_entry *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *callback_param = NULL, *parts, *ref, *m = NULL, *className, *method, _0, *_1 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL;
	zval *callback = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback_param);

	zephir_get_strval(callback, callback_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "::", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strstr", &_2, callback, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL("::"), callback, 2  TSRMLS_CC);
	ZEPHIR_OBS_VAR(className);
	zephir_array_fetch_long(&className, parts, 0, PH_NOISY, "zendframework/stdlib/callbackhandler.zep", 225 TSRMLS_CC);
	ZEPHIR_OBS_VAR(method);
	zephir_array_fetch_long(&method, parts, 1, PH_NOISY, "zendframework/stdlib/callbackhandler.zep", 226 TSRMLS_CC);
	if (unlikely(!zephir_class_exists(className, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Static method call \"", callback, "\" refers to a class that does not exist");
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidcallbackexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/callbackhandler.zep", 230 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(ref);
	_4 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(ref, _4);
	ZEPHIR_CALL_METHOD(NULL, ref, "__construct", NULL, className);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, ref, "hasmethod", NULL, method);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_NVAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Static method call \"", callback, "\" refers to a class that does not exist");
		ZEPHIR_INIT_LNVAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidcallbackexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/callbackhandler.zep", 237 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_6, ref, "getmethod", NULL, method);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(m, _6);
	ZEPHIR_CALL_METHOD(&_6, m, "isstatic",  NULL);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_6))) {
		ZEPHIR_INIT_NVAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Static method call \"", callback, "\" refers to a class that does not exist");
		ZEPHIR_INIT_LNVAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidcallbackexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/callbackhandler.zep", 244 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, className);
	zephir_array_fast_append(return_value, method);
	RETURN_MM();

}

