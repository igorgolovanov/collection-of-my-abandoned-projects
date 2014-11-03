
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/iterator.h"

ZEPHIR_INIT_CLASS(ZendFramework_Config_Config) {

	ZEPHIR_REGISTER_CLASS(Zend\\Config, Config, zendframework, config_config, zendframework_config_config_method_entry, 0);

	/**
	 * Whether modifications to configuration data are allowed.
	 *
	 * @var bool
	 */
	zend_declare_property_null(zendframework_config_config_ce, SL("allowModifications"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Number of elements in configuration data.
	 *
	 * @var int
	 */
	zend_declare_property_null(zendframework_config_config_ce, SL("count"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Data within the configuration.
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_config_config_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Used when unsetting values during iteration to ensure we do not skip
	 * the next element.
	 *
	 * @var bool
	 */
	zend_declare_property_null(zendframework_config_config_ce, SL("skipNextIteration"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_config_config_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_config_config_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(zendframework_config_config_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * Data is read-only unless $allowModifications is set to true
 * on construction.
 *
 * @param  array   $array
 * @param  bool $allowModifications
 */
PHP_METHOD(ZendFramework_Config_Config, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_4;
	HashTable *_2;
	HashPosition _1;
	zend_bool allowModifications;
	zval *array_param = NULL, *allowModifications_param = NULL, *_0, *k = NULL, *v = NULL, *className, **_3;
	zval *array = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &array_param, &allowModifications_param);

	if (unlikely(Z_TYPE_P(array_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'array' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		array = array_param;

	if (!allowModifications_param) {
		allowModifications = 0;
	} else {
		allowModifications = zephir_get_boolval(allowModifications_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("allowModifications"), allowModifications ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	zephir_is_iterable(array, &_2, &_1, 0, 0, "zendframework/config/config.zep", 77);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(v);
			_4 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(v, _4);
			if (zephir_has_constructor(v TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, v, "__construct", NULL, v, (allowModifications ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
			}
		}
		zephir_update_property_array(this_ptr, SL("data"), k, v TSRMLS_CC);
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("count") TSRMLS_CC));
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve a value and return $default if there is no element set.
 *
 * @param  string $name
 * @param  mixed  $defaultVal
 * @return mixed
 */
PHP_METHOD(ZendFramework_Config_Config, get) {

	zval *name_param = NULL, *defaultVal = NULL, *val, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultVal);

	zephir_get_strval(name, name_param);
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&val, _0, name, 1 TSRMLS_CC)) {
		RETURN_CTOR(val);
	}
	RETVAL_ZVAL(defaultVal, 1, 0);
	RETURN_MM();

}

/**
 * Magic function so that $obj->value will work.
 *
 * @param  string $name
 * @return mixed
 */
PHP_METHOD(ZendFramework_Config_Config, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set a value in the config.
 *
 * Only allow setting of a property if $allowModifications  was set to true
 * on construction. Otherwise, throw an exception.
 *
 * @param  string $name
 * @param  mixed  $value
 * @return void
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Config_Config, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *name_param = NULL, *value = NULL, *className, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);
	ZEPHIR_SEPARATE_PARAM(value);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowModifications"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_config_exception_runtimeexception_ce, "Config is read only", "zendframework/config/config.zep", 123);
		return;
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(value);
		_1 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(value, _1);
		if (zephir_has_constructor(value TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_BOOL(_2, 1);
			ZEPHIR_CALL_METHOD(NULL, value, "__construct", NULL, value, _2);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		zephir_update_property_array_append(this_ptr, SL("data"), value TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("data"), name, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deep clone of this instance to ensure that nested Zend\Configs are also
 * cloned.
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, __clone) {

	HashTable *_2;
	HashPosition _1;
	zval *data, *k = NULL, *v = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(data);
	array_init(data);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/config/config.zep", 153);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (zephir_instance_of_ev(v, zendframework_config_config_ce TSRMLS_CC)) {
			ZEPHIR_INIT_LNVAR(_4);
			if (zephir_clone(_4, v TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			zephir_array_update_zval(&data, k, &_4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return an associative array of the stored data.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Config_Config, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *data, *k = NULL, *v = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(data);
	array_init(data);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/config/config.zep", 172);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (zephir_instance_of_ev(v, zendframework_config_config_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_4, v, "toarray",  NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&data, k, &_4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * isset() overloading
 *
 * @param  string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Config_Config, __isset) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * unset() overloading
 *
 * @param  string $name
 * @return void
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Config_Config, __unset) {

	zval *name_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowModifications"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_config_exception_runtimeexception_ce, "Config is read only", "zendframework/config/config.zep", 196);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	if (zephir_array_isset(_1, name)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		zephir_array_unset(&_2, name, PH_SEPARATE);
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("count") TSRMLS_CC));
		zephir_update_property_this(this_ptr, SL("skipNextIteration"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * count(): defined by Countable interface.
 *
 * @see    Countable::count()
 * @return int
 */
PHP_METHOD(ZendFramework_Config_Config, count) {


	RETURN_MEMBER(this_ptr, "count");

}

/**
 * current(): defined by Iterator interface.
 *
 * @see    Iterator::current()
 * @return mixed
 */
PHP_METHOD(ZendFramework_Config_Config, current) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("skipNextIteration"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("current", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * key(): defined by Iterator interface.
 *
 * @see    Iterator::key()
 * @return mixed
 */
PHP_METHOD(ZendFramework_Config_Config, key) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("key", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * next(): defined by Iterator interface.
 *
 * @see    Iterator::next()
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("skipNextIteration"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_update_property_this(this_ptr, SL("skipNextIteration"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_1);
	ZEPHIR_CALL_FUNCTION(NULL, "next", &_2, _1);
	Z_UNSET_ISREF_P(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * rewind(): defined by Iterator interface.
 *
 * @see    Iterator::rewind()
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, rewind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("skipNextIteration"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * valid(): defined by Iterator interface.
 *
 * @see    Iterator::valid()
 * @return bool
 */
PHP_METHOD(ZendFramework_Config_Config, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&key, this_ptr, "key",  NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(key) != IS_NULL);

}

/**
 * offsetExists(): defined by ArrayAccess interface.
 *
 * @see    ArrayAccess::offsetExists()
 * @param  mixed $offset
 * @return bool
 */
PHP_METHOD(ZendFramework_Config_Config, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__isset", NULL, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * offsetGet(): defined by ArrayAccess interface.
 *
 * @see    ArrayAccess::offsetGet()
 * @param  mixed $offset
 * @return mixed
 */
PHP_METHOD(ZendFramework_Config_Config, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__get", NULL, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * offsetSet(): defined by ArrayAccess interface.
 *
 * @see    ArrayAccess::offsetSet()
 * @param  mixed $offset
 * @param  mixed $value
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * offsetUnset(): defined by ArrayAccess interface.
 *
 * @see    ArrayAccess::offsetUnset()
 * @param  mixed $offset
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *offset;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__unset", NULL, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Merge another Config with this one.
 *
 * For duplicate keys, the following will be performed:
 * - Nested Configs will be recursively merged.
 * - Items in $merge with INTEGER keys will be appended.
 * - Items in $merge with STRING keys will overwrite current values.
 *
 * @param  Config $merge
 * @return Config
 */
PHP_METHOD(ZendFramework_Config_Config, merge) {

	zend_class_entry *_3, *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zend_object_iterator *_1;
	zval *merge, *k = NULL, *v = NULL, *v2 = NULL, *className, *data = NULL, *allowModifications = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &merge);



	if (!(zephir_instance_of_ev(merge, zendframework_config_config_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'merge' must be an instance of 'ZendFramework\\\\Config\\\\Config'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowModifications"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(allowModifications, _0);
	_1 = zephir_get_iterator(merge TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(k, _1);
		{ zval **tmp; 
		_1->funcs->get_current_data(_1, &tmp TSRMLS_CC);
		v = *tmp;
		}
		ZEPHIR_OBS_NVAR(v2);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&v2, _0, k, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(k) == IS_LONG) {
				zephir_update_property_array_append(this_ptr, SL("data"), v TSRMLS_CC);
			_2 = zephir_instance_of_ev(v, zendframework_config_config_ce TSRMLS_CC);
			if (_2) {
				_2 = zephir_instance_of_ev(v2, zendframework_config_config_ce TSRMLS_CC);
			}
			} else if (_2) {
				ZEPHIR_CALL_METHOD(NULL, v2, "merge", NULL, v);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&data, v, "toarray",  NULL);
				zephir_check_call_status();
				if (zephir_instance_of_ev(v, zendframework_config_config_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&data, v, "toarray",  NULL);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(v);
					_3 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
					object_init_ex(v, _3);
					if (zephir_has_constructor(v TSRMLS_CC)) {
						ZEPHIR_CALL_METHOD(NULL, v, "__construct", NULL, data, allowModifications);
						zephir_check_call_status();
					}
				}
				zephir_update_property_array(this_ptr, SL("data"), k, v TSRMLS_CC);
			}
		} else {
			if (zephir_instance_of_ev(v, zendframework_config_config_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&data, v, "toarray",  NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(v);
				_4 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(v, _4);
				if (zephir_has_constructor(v TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, v, "__construct", NULL, data, allowModifications);
					zephir_check_call_status();
				}
			}
			zephir_update_property_array(this_ptr, SL("data"), k, v TSRMLS_CC);
			RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("count") TSRMLS_CC));
		}
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Prevent any more modifications being made to this instance.
 *
 * Useful after merge() has been used to merge multiple Config objects
 * into one object which should then not be modified again.
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Config_Config, setReadOnly) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *val = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("allowModifications"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/config/config.zep", 395);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(val, _3);
		if (zephir_instance_of_ev(val, zendframework_config_config_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, val, "setreadonly", NULL);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether this Config object is read only or not.
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Config_Config, isReadOnly) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowModifications"), PH_NOISY_CC);
	RETURN_BOOL(!zephir_is_true(_0));

}

