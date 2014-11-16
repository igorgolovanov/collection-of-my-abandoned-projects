
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_array.h"
#include "kernel/string.h"
#include "kernel/hash.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
* Custom framework ArrayObject implementation
*
* Extends version-specific "abstract" implementation.
*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayObject) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, ArrayObject, zendframework, stdlib_arrayobject, zendframework_stdlib_arrayobject_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_arrayobject_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_null(zendframework_stdlib_arrayobject_ce, SL("flag"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(zendframework_stdlib_arrayobject_ce, SL("iteratorClass"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_arrayobject_ce, SL("protectedProperties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Properties of the object have their normal functionality
	 * when accessed as list (var_dump, foreach, etc.).
	 */
	zend_declare_class_constant_long(zendframework_stdlib_arrayobject_ce, SL("STD_PROP_LIST"), 1 TSRMLS_CC);

	/**
	 * Entries can be accessed as properties (read and write).
	 */
	zend_declare_class_constant_long(zendframework_stdlib_arrayobject_ce, SL("ARRAY_AS_PROPS"), 2 TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_arrayobject_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(zendframework_stdlib_arrayobject_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(zendframework_stdlib_arrayobject_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(zendframework_stdlib_arrayobject_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array  $input
 * @param int    $flags
 * @param string $iteratorClass
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *iteratorClass = NULL;
	int flags, ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *flags_param = NULL, *iteratorClass_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *input = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &input_param, &flags_param, &iteratorClass_param);

	if (!input_param) {
		ZEPHIR_INIT_VAR(input);
		array_init(input);
	} else {
		zephir_get_arrval(input, input_param);
	}
	if (!flags_param) {
		flags = 1;
	} else {
		flags = zephir_get_intval(flags_param);
	}
	if (!iteratorClass_param) {
		ZEPHIR_INIT_VAR(iteratorClass);
		ZVAL_STRING(iteratorClass, "ArrayIterator", 1);
	} else {
		zephir_get_strval(iteratorClass, iteratorClass_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, flags);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setflags", NULL, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("storage"), input TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setiteratorclass", NULL, iteratorClass);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "get_object_vars", &_2, this_ptr);
	zephir_check_call_status();
	zephir_array_keys(_0, _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("protectedProperties"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether the requested key exists
 *
 * @param  mixed $key
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *key, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("flag"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 2)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("protectedProperties"), PH_NOISY_CC);
	if (unlikely(zephir_fast_in_array(key, _1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "\"", key, "\" is a protected property, use a different key");
		zephir_get_strval(exceptionMsg, _2);
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/arrayobject.zep", 84 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, key TSRMLS_CC));

}

/**
 * Sets the value at the specified key to value
 *
 * @param  mixed $key
 * @param  mixed $value
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *key, *value, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("flag"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 2)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, key, value);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("protectedProperties"), PH_NOISY_CC);
	if (unlikely(zephir_fast_in_array(key, _1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "\"", key, "\" is a protected property, use a different key");
		zephir_get_strval(exceptionMsg, _2);
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/arrayobject.zep", 106 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsets the value at the specified key
 *
 * @param  mixed $key
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *key, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("flag"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 2)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetunset", NULL, key);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("protectedProperties"), PH_NOISY_CC);
	if (unlikely(zephir_fast_in_array(key, _1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "\"", key, "\" is a protected property, use a different key");
		zephir_get_strval(exceptionMsg, _2);
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/arrayobject.zep", 127 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the value at the specified key by reference
 *
 * @param  mixed $key
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *key, *ret = NULL, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("flag"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 2)) {
		ZEPHIR_CALL_METHOD(&ret, this_ptr, "offsetget", NULL, key);
		zephir_check_call_status();
		RETURN_CCTOR(ret);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("protectedProperties"), PH_NOISY_CC);
	if (unlikely(zephir_fast_in_array(key, _1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "\"", key, "\" is a protected property, use a different key");
		zephir_get_strval(exceptionMsg, _2);
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/stdlib/arrayobject.zep", 150 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_zval(&_4, this_ptr, key, PH_NOISY_CC);
	RETURN_CCTOR(_4);

}

/**
 * Appends the value
 *
 * @param  mixed $value
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, append) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_array_append(this_ptr, SL("storage"), value TSRMLS_CC);

}

/**
 * Sort the entries by value
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, asort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "asort", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the number of public properties in the ArrayObject
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Exchange the array for another one.
 *
 * @param  array|ArrayObject $data
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, exchangeArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1, _2, _3;
	zval *storage = NULL;
	zval *type = NULL;
	zval *data = NULL, *_0, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);

	ZEPHIR_SEPARATE_PARAM(data);


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, data TSRMLS_CC);
	zephir_get_strval(type, _0);
	_1 = !ZEPHIR_IS_STRING(type, "array");
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(type, "object");
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_stdlib_exception_invalidargumentexception_ce, "Passed variable is not an array or object, using empty array instead", "zendframework/stdlib/arrayobject.zep", 200);
		return;
	}
	_2 = ZEPHIR_IS_STRING(type, "object");
	if (_2) {
		_3 = zephir_instance_of_ev(data, zendframework_stdlib_arrayobject_ce TSRMLS_CC);
		if (!(_3)) {
			_3 = zephir_instance_of_ev(data, spl_ce_ArrayObject TSRMLS_CC);
		}
		_2 = _3;
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&data, data, "getarraycopy",  NULL);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(storage, _4);
	zephir_update_property_this(this_ptr, SL("storage"), data TSRMLS_CC);
	RETURN_CTOR(storage);

}

/**
 * Creates a copy of the ArrayObject.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getArrayCopy) {


	RETURN_MEMBER(this_ptr, "storage");

}

/**
 * Gets the behavior flags.
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getFlags) {


	RETURN_MEMBER(this_ptr, "flag");

}

/**
 * Create a new iterator from an ArrayObject instance
 *
 * @return \Iterator
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *className, *iterator, *storage = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(storage, _0);
	className = zephir_fetch_nproperty_this(this_ptr, SL("iteratorClass"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(iterator);
	_1 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(iterator, _1);
	if (zephir_has_constructor(iterator TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, storage);
		zephir_check_call_status();
	}
	RETURN_CCTOR(iterator);

}

/**
 * Gets the iterator classname for the ArrayObject.
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getIteratorClass) {


	RETURN_MEMBER(this_ptr, "iteratorClass");

}

/**
 * Sort the entries by key
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, ksort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sort an array using a case insensitive "natural order" algorithm
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, natcasesort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "natcasesort", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sort entries using a "natural order" algorithm
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, natsort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "natsort", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether the requested key exists
 *
 * @param  mixed $key
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetExists) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, key));

}

/**
 * Returns the value at the specified key
 *
 * @param  mixed $key
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *ret = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_INIT_VAR(ret);
	ZVAL_NULL(ret);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, key);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_CCTOR(ret);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(ret);
	zephir_array_fetch(&ret, _1, key, PH_NOISY, "zendframework/stdlib/arrayobject.zep", 314 TSRMLS_CC);
	RETURN_CCTOR(ret);

}

/**
 * Sets the value at the specified key to value
 *
 * @param  mixed $key
 * @param  mixed $value
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetSet) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("storage"), key, value TSRMLS_CC);

}

/**
 * Unsets the value at the specified key
 *
 * @param  mixed $key
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "offsetexists", NULL, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		zephir_array_unset(&_1, key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize an ArrayObject
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *vars = NULL, *serialized = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", &_0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_1, vars);
	zephir_check_call_status();
	RETURN_CCTOR(serialized);

}

/**
 * Sets the behavior flags
 *
 * @param  int  $flags
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, setFlags) {

	zval *flags_param = NULL, *_0;
	int flags;

	zephir_fetch_params(0, 1, 0, &flags_param);

	flags = zephir_get_intval(flags_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, flags);
	zephir_update_property_this(this_ptr, SL("flag"), _0 TSRMLS_CC);

}

/**
 * Sets the iterator classname for the ArrayObject
 *
 * @param  string $class
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, setIteratorClass) {

	zval *class_param = NULL, _0, *_1;
	zval *class = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	if (zephir_class_exists(class, 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("iteratorClass"), class TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\\", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, class, &_0, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "\\", class);
		ZEPHIR_CPY_WRT(class, _2);
		if (zephir_class_exists(class, 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("iteratorClass"), class TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_stdlib_exception_invalidargumentexception_ce, "The iterator class does not exist", "zendframework/stdlib/arrayobject.zep", 392);
	return;

}

/**
 * Sort the entries with a user-defined comparison function and maintain key association
 *
 * @param  callable $function
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, uasort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *function, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &function);



	if (zephir_is_callable(function TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		Z_SET_ISREF_P(_0);
		ZEPHIR_CALL_FUNCTION(NULL, "uasort", &_1, _0, function);
		Z_UNSET_ISREF_P(_0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sort the entries by keys using a user-defined comparison function
 *
 * @param  callable $function
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, uksort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *function, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &function);



	if (zephir_is_callable(function TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		Z_SET_ISREF_P(_0);
		ZEPHIR_CALL_FUNCTION(NULL, "uksort", &_1, _0, function);
		Z_UNSET_ISREF_P(_0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Unserialize an ArrayObject
 *
 * @param  string $data
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, unserialize) {

	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	HashTable *_8;
	HashPosition _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *data_param = NULL, *unserialized = NULL, *vars = NULL, *k = NULL, *v = NULL, *_2, *_3, *_4, *_5, *_6 = NULL, **_9;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", &_0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&vars, "get_object_vars", &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_array_keys(_2, vars TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("protectedProperties"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, unserialized, SL("flag"), PH_NOISY | PH_READONLY, "zendframework/stdlib/arrayobject.zep", 436 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setflags", NULL, _3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, unserialized, SL("storage"), PH_NOISY | PH_READONLY, "zendframework/stdlib/arrayobject.zep", 437 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", NULL, _4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, unserialized, SL("iteratorClass"), PH_NOISY | PH_READONLY, "zendframework/stdlib/arrayobject.zep", 438 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setiteratorclass", NULL, _5);
	zephir_check_call_status();
	if (Z_TYPE_P(unserialized) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_6, "iterator_to_array", NULL, unserialized);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(unserialized, _6);
	}
	zephir_is_iterable(unserialized, &_8, &_7, 0, 0, "zendframework/stdlib/arrayobject.zep", 465);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(v, _8, _7);
		ZEPHIR_GET_HVALUE(k, _9);
		do {
			if (ZEPHIR_IS_STRING(k, "flag")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setflags", &_10, v);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(k, "storage")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", &_11, v);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(k, "iteratorClass")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setiteratorclass", &_12, v);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(k, "protectedProperties")) {
				break;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_13, k, v);
			zephir_check_call_status();
		} while(0);

	}
	ZEPHIR_MM_RESTORE();

}

