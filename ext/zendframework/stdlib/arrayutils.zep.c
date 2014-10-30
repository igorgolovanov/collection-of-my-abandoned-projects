
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Utility class for testing and manipulation of PHP arrays.
 *
 * Declared abstract, as we have no need for instantiation.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayUtils) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, ArrayUtils, zendframework, stdlib_arrayutils, zendframework_stdlib_arrayutils_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Test whether an array contains one or more string keys
 *
 * @param  mixed $value
 * @param  bool  $allowEmpty    Should an empty array() return true
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasStringKeys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool allowEmpty;
	zval *value, *allowEmpty_param = NULL, *keys, *filtered = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowEmpty_param);

	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(value))) {
		RETURN_MM_BOOL(allowEmpty);
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, value TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "is_string", 0);
	ZEPHIR_CALL_FUNCTION(&filtered, "array_filter", &_1, keys, &_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(filtered TSRMLS_CC) > 0) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Test whether an array contains one or more integer keys
 *
 * @param  mixed $value
 * @param  bool  $allowEmpty    Should an empty array() return true
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasIntegerKeys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool allowEmpty;
	zval *value, *allowEmpty_param = NULL, *keys, *filtered = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowEmpty_param);

	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(value))) {
		RETURN_MM_BOOL(allowEmpty);
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, value TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "is_int", 0);
	ZEPHIR_CALL_FUNCTION(&filtered, "array_filter", &_1, keys, &_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(filtered TSRMLS_CC) > 0) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Test whether an array contains one or more numeric keys.
 *
 * A numeric key can be one of the following:
 * - an integer 1,
 * - a string with a number '20'
 * - a string with negative number: '-1000'
 * - a float: 2.2120, -78.150999
 * - a string with float:  '4000.99999', '-10.10'
 *
 * @param  mixed $value
 * @param  bool  $allowEmpty    Should an empty array() return true
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasNumericKeys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool allowEmpty;
	zval *value, *allowEmpty_param = NULL, *keys, *filtered = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowEmpty_param);

	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(value))) {
		RETURN_MM_BOOL(allowEmpty);
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, value TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "is_numeric", 0);
	ZEPHIR_CALL_FUNCTION(&filtered, "array_filter", &_1, keys, &_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(filtered TSRMLS_CC) > 0) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Test whether an array is a list
 *
 * A list is a collection of values assigned to continuous integer keys
 * starting at 0 and ending at count() - 1.
 *
 * For example:
 * <code>
 * $list = array('a', 'b', 'c', 'd');
 * $list = array(
 *     0 => 'foo',
 *     1 => 'bar',
 *     2 => array('foo' => 'baz'),
 * );
 * </code>
 *
 * @param  mixed $value
 * @param  bool  $allowEmpty    Is an empty list a valid list?
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, isList) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zend_bool allowEmpty;
	zval *value, *allowEmpty_param = NULL, *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowEmpty_param);

	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(value))) {
		RETURN_MM_BOOL(allowEmpty);
	}
	ZEPHIR_CALL_FUNCTION(&values, "array_values", &_0, value);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(values, value));

}

/**
 * Test whether an array is a hash table.
 *
 * An array is a hash table if:
 *
 * 1. Contains one or more non-integer keys, or
 * 2. Integer keys are non-continuous or misaligned (not starting with 0)
 *
 * For example:
 * <code>
 * $hash = array(
 *     'foo' => 15,
 *     'bar' => false,
 * );
 * $hash = array(
 *     1995  => 'Birth of PHP',
 *     2009  => 'PHP 5.3.0',
 *     2012  => 'PHP 5.4.0',
 * );
 * $hash = array(
 *     'formElement,
 *     'options' => array( 'debug' => true ),
 * );
 * </code>
 *
 * @param  mixed $value
 * @param  bool  $allowEmpty    Is an empty array() a valid hash table?
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, isHashTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zend_bool allowEmpty;
	zval *value, *allowEmpty_param = NULL, *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowEmpty_param);

	if (!allowEmpty_param) {
		allowEmpty = 0;
	} else {
		allowEmpty = zephir_get_boolval(allowEmpty_param);
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(value))) {
		RETURN_MM_BOOL(allowEmpty);
	}
	ZEPHIR_CALL_FUNCTION(&values, "array_values", &_0, value);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(values, value));

}

/**
 * Checks if a value exists in an array.
 *
 * Due to "foo" == 0 === TRUE with in_array when strict = false, an option
 * has been added to prevent this. When $strict = 0/false, the most secure
 * non-strict check is implemented. if $strict = -1, the default in_array
 * non-strict behaviour is used.
 *
 * @param mixed $needle
 * @param array $haystack
 * @param int|bool $strict
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, inArray) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	zend_bool _1, _7;
	zval *type = NULL;
	zval *haystack = NULL;
	zval *needle = NULL, *haystack_param = NULL, *strict = NULL, *h = NULL, *i = NULL, *_0, *_2 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &needle, &haystack_param, &strict);

	ZEPHIR_SEPARATE_PARAM(needle);
	if (unlikely(Z_TYPE_P(haystack_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'haystack' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		haystack = haystack_param;

	if (!strict) {
		strict = ZEPHIR_GLOBAL(global_false);
	}


	if (zephir_is_true(strict)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_gettype(_0, needle TSRMLS_CC);
		zephir_get_strval(type, _0);
		_1 = ZEPHIR_IS_STRING(type, "integer");
		if (!(_1)) {
			_1 = ZEPHIR_IS_STRING(type, "double");
		}
		if (_1) {
			ZEPHIR_CALL_FUNCTION(&_2, "strval", &_3, needle);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(needle, _2);
		}
		if (ZEPHIR_IS_STRING(type, "string")) {
			zephir_is_iterable(haystack, &_5, &_4, 1, 0, "zendframework/stdlib/arrayutils.zep", 222);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HMKEY(i, _5, _4);
				ZEPHIR_GET_HVALUE(h, _6);
				_7 = Z_TYPE_P(h) == IS_LONG;
				if (!(_7)) {
					_7 = Z_TYPE_P(h) == IS_DOUBLE;
				}
				if (_7) {
					ZEPHIR_CALL_FUNCTION(&_2, "strval", &_3, h);
					zephir_check_call_status();
					zephir_array_update_zval(&haystack, i, &_2, PH_COPY | PH_SEPARATE);
				}
			}
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", &_8, needle, haystack, strict);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convert an iterator to an array.
 *
 * Converts an iterator to an array. The $recursive flag, on by default,
 * hints whether or not you want to do so recursively.
 *
 * @param  array|Traversable  $iterator     The array or Traversable object to convert
 * @param  bool               $recursive    Recursively check all nested structures
 * @throws Exception\InvalidArgumentException if $iterator is not an array or a Traversable object
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, iteratorToArray) {

	zephir_fcall_cache_entry *_9 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zend_bool recursive, _0, _7;
	zval *iterator, *recursive_param = NULL, *key = NULL, *value = NULL, *data = NULL, *_1, **_4, *_5 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &iterator, &recursive_param);

	if (!recursive_param) {
		recursive = 1;
	} else {
		recursive = zephir_get_boolval(recursive_param);
	}


	_0 = Z_TYPE_P(iterator) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(iterator, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SS(exceptionMsg, "ArrayUtils:iteratorToArray", " expects an array or Traversable object");
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/stdlib/arrayutils.zep", 246 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(recursive)) {
		if (Z_TYPE_P(iterator) != IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&data, "iterator_to_array", NULL, iterator);
			zephir_check_call_status();
			RETURN_CCTOR(data);
		}
		RETVAL_ZVAL(iterator, 1, 0);
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(iterator, SS("toarray") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&data, iterator, "toarray",  NULL);
		zephir_check_call_status();
		RETURN_CCTOR(data);
	}
	ZEPHIR_INIT_NVAR(data);
	array_init(data);
	zephir_is_iterable(iterator, &_3, &_2, 0, 0, "zendframework/stdlib/arrayutils.zep", 274);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_FUNCTION(&_5, "is_scalar", &_6, value);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
			continue;
		}
		_7 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_7)) {
			_7 = zephir_is_instance_of(value, SL("Traversable") TSRMLS_CC);
		}
		if (_7) {
			ZEPHIR_CALL_STATIC(&_8, "iteratortoarray", &_9, value, (recursive ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_8, PH_COPY | PH_SEPARATE);
			continue;
		}
		zephir_array_update_zval(&data, key, &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

/**
 * Merge two arrays together.
 *
 * If an integer key exists in both arrays and preserveNumericKeys is false, the value
 * from the second array will be appended to the first array. If both values are arrays, they
 * are merged together, else the value of the second array overwrites the one of the first array.
 *
 * @param  array $a
 * @param  array $b
 * @param  bool  $preserveNumericKeys
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, merge) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_bool preserveNumericKeys, _3;
	zval *a_param = NULL, *b_param = NULL, *preserveNumericKeys_param = NULL, *key = NULL, *value = NULL, *av = NULL, **_2, *_5 = NULL;
	zval *a = NULL, *b = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &a_param, &b_param, &preserveNumericKeys_param);

	if (unlikely(Z_TYPE_P(a_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'a' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		a = a_param;

	if (unlikely(Z_TYPE_P(b_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'b' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		b = b_param;

	if (!preserveNumericKeys_param) {
		preserveNumericKeys = 0;
	} else {
		preserveNumericKeys = zephir_get_boolval(preserveNumericKeys_param);
	}


	zephir_is_iterable(b, &_1, &_0, 0, 0, "zendframework/stdlib/arrayutils.zep", 309);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (zephir_array_isset(a, key)) {
			_3 = Z_TYPE_P(value) == IS_LONG;
			if (_3) {
				_3 = !preserveNumericKeys;
			}
			if (_3) {
				Z_SET_ISREF_P(a);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, a, value);
				Z_UNSET_ISREF_P(a);
				zephir_check_call_status();
				continue;
			}
			if (Z_TYPE_P(value) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(av);
				zephir_array_fetch(&av, a, key, PH_NOISY, "zendframework/stdlib/arrayutils.zep", 300 TSRMLS_CC);
				if (Z_TYPE_P(av) == IS_ARRAY) {
					ZEPHIR_CALL_STATIC(&_5, "merge", &_6, av, value, (preserveNumericKeys ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					zephir_array_update_zval(&a, key, &_5, PH_COPY | PH_SEPARATE);
					continue;
				}
			}
		}
		zephir_array_update_zval(&a, key, &value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(a);

}

