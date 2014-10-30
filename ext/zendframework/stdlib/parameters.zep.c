
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
#include "ext/spl/spl_array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Parameters) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib, Parameters, zendframework, stdlib_parameters, spl_ce_ArrayObject, zendframework_stdlib_parameters_method_entry, 0);

	zend_class_implements(zendframework_stdlib_parameters_ce TSRMLS_CC, 1, zendframework_stdlib_parametersinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Enforces that we have an array, and enforces parameter access to array
 * elements.
 *
 * @param  array $values
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *_0;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &values_param);

	if (!values_param) {
	ZEPHIR_INIT_VAR(values);
	ZVAL_NULL(values);
	} else {
	if (unlikely(Z_TYPE_P(values_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'values' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		values = values_param;

	}


	if (ZEPHIR_IS_STRING_IDENTICAL(values, "")) {
		ZEPHIR_INIT_NVAR(values);
		array_init(values);
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_PARENT(NULL, zendframework_stdlib_parameters_ce, this_ptr, "__construct", NULL, values, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Populate from native PHP array
 *
 * @param  array $values
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, fromArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	if (unlikely(Z_TYPE_P(values_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'values' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		values = values_param;



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", NULL, values);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Populate from query string
 *
 * @param  string $string
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *string_param = NULL, *data;
	zval *string = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &string_param);

	zephir_get_strval(string, string_param);
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	Z_SET_ISREF_P(data);
	ZEPHIR_CALL_FUNCTION(NULL, "parse_str", &_0, string, data);
	Z_UNSET_ISREF_P(data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fromarray", NULL, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize to native PHP array
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getarraycopy", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Serialize to query string
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("http_build_query", &_0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve by key
 *
 * Returns null if the key does not exist.
 *
 * @param  string $name
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, name);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_PARENT(zendframework_stdlib_parameters_ce, this_ptr, "offsetget", NULL, name);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * @param string $name
 * @param mixed $default optional default value
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultVal);

	zephir_get_strval(name, name_param);
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, name);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_PARENT(zendframework_stdlib_parameters_ce, this_ptr, "offsetget", NULL, name);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(defaultVal, 1, 0);
	RETURN_MM();

}

/**
 * @param string $name
 * @param mixed $value
 * @return Parameters
 */
PHP_METHOD(ZendFramework_Stdlib_Parameters, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

