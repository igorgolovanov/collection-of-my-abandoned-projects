
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_AbstractOptions) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, AbstractOptions, zendframework, stdlib_abstractoptions, zendframework_stdlib_abstractoptions_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * We use the __ prefix to avoid collisions with properties in
	 * user-implementations.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(zendframework_stdlib_abstractoptions_ce, SL("__strictMode__"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_abstractoptions_ce TSRMLS_CC, 1, zendframework_stdlib_parameterobjectinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param  array|Traversable|null $options
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfromarray", NULL, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set one or more configuration properties
 *
 * @param  array|Traversable|AbstractOptions $options
 * @throws Exception\InvalidArgumentException
 * @return AbstractOptions Provides fluent interface
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, setFromArray) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *options = NULL, *key = NULL, *value = NULL, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);

	ZEPHIR_SEPARATE_PARAM(options);


	if (zephir_instance_of_ev(options, zendframework_stdlib_abstractoptions_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&options, options, "toarray",  NULL);
		zephir_check_call_status();
	}
	_0 = Z_TYPE_P(options) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(options, SL("ZendFramework\\Stdlib\\Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SSS(exceptionMsg, "Parameter provided to ", "AbstractOptions:setFromArray", " must be an array, Traversable or Zend\\Stdlib\\AbstractOptions");
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/stdlib/abstractoptions.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(options, &_3, &_2, 0, 0, "zendframework/stdlib/abstractoptions.zep", 59);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_5, key, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Cast to array
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data, *key = NULL, *value = NULL, *normalizedKey = NULL, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(data);
	array_init(data);

	zephir_is_iterable(this, &_1, &_0, 0, 0, "zendframework/stdlib/abstractoptions.zep", 84);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (ZEPHIR_IS_STRING_IDENTICAL(key, "__strictMode__")) {
			continue;
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "/([A-Z])/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_NULL(_4);
		ZEPHIR_CALL_FUNCTION(&normalizedKey, "preg_replace_callback", &_5, _3, _4, key);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		zephir_array_update_zval(&data, normalizedKey, &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

/**
 * Set a configuration property
 *
 * @see ParameterObject::__set()
 * @param string $key
 * @param mixed $value
 * @throws Exception\BadMethodCallException
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __set) {

	zend_bool _9, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *key_param = NULL, *value, _0, _1, *_2 = NULL, *_4, _5, _6, *_8, *_10, *_11;
	zval *key = NULL, *setter = NULL, *exceptionMsg = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(setter);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "_", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	zephir_fast_str_replace(setter, &_0, &_1, key);
	ZEPHIR_CALL_FUNCTION(&_2, "ucwords", &_3, setter);
	zephir_check_call_status();
	zephir_get_strval(setter, _2);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, " ", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "", 0);
	zephir_fast_str_replace(_4, &_5, &_6, setter);
	zephir_get_strval(setter, _4);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "set", setter);
	ZEPHIR_CPY_WRT(setter, _7);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("__strictMode__"), PH_NOISY_CC);
	_9 = zephir_is_true(_8);
	if (_9) {
		_9 = !(zephir_method_exists(this_ptr, setter TSRMLS_CC)  == SUCCESS);
	}
	if (unlikely(_9)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVSVS(exceptionMsg, "The option \"", key, "\" does not have a matching ", setter, " setter method which must be defined");
		ZEPHIR_INIT_VAR(_10);
		object_init_ex(_10, zendframework_stdlib_exception_badmethodcallexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10, "zendframework/stdlib/abstractoptions.zep", 112 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("__strictMode__"), PH_NOISY_CC);
	_12 = !zephir_is_true(_11);
	if (_12) {
		_12 = !(zephir_method_exists(this_ptr, setter TSRMLS_CC)  == SUCCESS);
	}
	if (_12) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(setter), NULL, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a configuration property
 *
 * @see ParameterObject::__get()
 * @param string $key
 * @throws Exception\BadMethodCallException
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *key_param = NULL, _0, _1, *_2 = NULL, *_4, _5, _6, *_8;
	zval *key = NULL, *getter = NULL, *exceptionMsg = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(getter);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "_", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	zephir_fast_str_replace(getter, &_0, &_1, key);
	ZEPHIR_CALL_FUNCTION(&_2, "ucwords", &_3, getter);
	zephir_check_call_status();
	zephir_get_strval(getter, _2);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, " ", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "", 0);
	zephir_fast_str_replace(_4, &_5, &_6, getter);
	zephir_get_strval(getter, _4);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SV(_7, "get", getter);
	ZEPHIR_CPY_WRT(getter, _7);
	if (unlikely(!(zephir_method_exists(this_ptr, getter TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVSVS(exceptionMsg, "The option \"", key, "\" does not have a matching ", getter, " getter method which must be defined");
		ZEPHIR_INIT_VAR(_8);
		object_init_ex(_8, zendframework_stdlib_exception_badmethodcallexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8, "zendframework/stdlib/abstractoptions.zep", 145 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, Z_STRVAL_P(getter), NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Test if a configuration property is null
 * @see ParameterObject::__isset()
 * @param string $key
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&value, this_ptr, "__get", NULL, key);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(value) != IS_NULL);

}

/**
 * Set a configuration property to NULL
 *
 * @see ParameterObject::__unset()
 * @param string $key
 * @throws Exception\InvalidArgumentException
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *e = NULL, *_0 = NULL, *_1;
	zval *key = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);



	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0);
		ZVAL_NULL(_0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, key, _0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_is_instance_of(e, SL("Exception\\BadMethodCallException") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_INIT_VAR(exceptionMsg);
			ZEPHIR_CONCAT_SVS(exceptionMsg, "The class property $", key, "cannot be unset as NULL is an invalid value for it");
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, zendframework_stdlib_exception_invalidargumentexception_ce);
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 0);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg, _0, e);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "zendframework/stdlib/abstractoptions.zep", 182 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

