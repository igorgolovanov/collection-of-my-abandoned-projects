
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_PriorityList) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, PriorityList, zendframework, stdlib_prioritylist, zendframework_stdlib_prioritylist_method_entry, 0);

	/**
	 * Internal list of all items.
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_prioritylist_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Serial assigned to items to preserve LIFO.
	 *
	 * @var int
	 */
	zend_declare_property_long(zendframework_stdlib_prioritylist_ce, SL("serial"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Serial order mode
	 * @var integer
	 */
	zend_declare_property_long(zendframework_stdlib_prioritylist_ce, SL("isLIFO"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Internal counter to avoid usage of count().
	 *
	 * @var int
	 */
	zend_declare_property_long(zendframework_stdlib_prioritylist_ce, SL("count"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether the list was already sorted.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(zendframework_stdlib_prioritylist_ce, SL("sorted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_prioritylist_ce, SL("EXTR_DATA"), 0x00000001 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_prioritylist_ce, SL("EXTR_PRIORITY"), 0x00000002 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_prioritylist_ce, SL("EXTR_BOTH"), 0x00000003 TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_prioritylist_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(zendframework_stdlib_prioritylist_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Insert a new item.
 *
 * @param  string  $name
 * @param  mixed $value
 * @param  int $priority
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, insert) {

	zval *data;
	int priority;
	zval *name_param = NULL, *value, *priority_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value, &priority_param);

	zephir_get_strval(name, name_param);
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	ZEPHIR_INIT_VAR(data);
	array_init(data);


	zephir_update_property_this(this_ptr, SL("sorted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("count"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	zephir_update_property_this(this_ptr, SL("count"), _1 TSRMLS_CC);
	zephir_array_update_string(&data, SL("data"), &value, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, priority);
	zephir_array_update_string(&data, SL("priority"), &_2, PH_COPY | PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serial"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("serial"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("serial") TSRMLS_CC));
	zephir_update_property_array(this_ptr, SL("items"), name, data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(ZendFramework_Stdlib_PriorityList, setPriority) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *priority_param = NULL, *_0, *_1 = NULL;
	zval *name = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &priority_param);

	zephir_get_strval(name, name_param);
	priority = zephir_get_intval(priority_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	if (unlikely(!zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "item ", name, " not found");
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/stdlib/prioritylist.zep", 87 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, priority);
	zephir_update_property_array_multi(this_ptr, SL("items"), &_1 TSRMLS_CC, SL("zs"), 3, name, SL("priority"));
	zephir_update_property_this(this_ptr, SL("sorted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Remove a item.
 *
 * @param  string $name
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, remove) {

	zval *name_param = NULL, *items = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(items, _0);
	if (Z_TYPE_P(items) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(items);
		array_init(items);
	}
	if (!(zephir_array_isset(items, name))) {
		RETURN_MM_NULL();
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("count") TSRMLS_CC));
	zephir_array_unset(&items, name, PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("items"), items TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Remove all items.
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, clear) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("serial"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("count"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("sorted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a item.
 *
 * @param  string $name
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, get) {

	zval *name_param = NULL, *item, *data, *items = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(items, _0);
	if (Z_TYPE_P(items) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	if (zephir_array_isset_fetch(&item, items, name, 1 TSRMLS_CC)) {
		if (zephir_array_isset_string_fetch(&data, item, SS("data"), 1 TSRMLS_CC)) {
			RETURN_CTOR(data);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Sort all items.
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, sort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *_0, *_1, *_2;
	zval *callback;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sorted"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(callback);
		array_init_size(callback, 3);
		zephir_array_fast_append(callback, this_ptr);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "compare", 1);
		zephir_array_fast_append(callback, _1);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		Z_SET_ISREF_P(_2);
		ZEPHIR_CALL_FUNCTION(NULL, "uasort", &_3, _2, callback);
		Z_UNSET_ISREF_P(_2);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("sorted"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Compare the priority of two items.
 *
 * @param  array $item1,
 * @param  array $item2
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, compare) {

	int result;
	zval *item1_param = NULL, *item2_param = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *item1 = NULL, *item2 = NULL;

	zephir_fetch_params(0, 2, 0, &item1_param, &item2_param);

	if (unlikely(Z_TYPE_P(item1_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item1' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		item1 = item1_param;

	if (unlikely(Z_TYPE_P(item2_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item2' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		item2 = item2_param;



	zephir_array_fetch_string(&_0, item1, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 184 TSRMLS_CC);
	zephir_array_fetch_string(&_1, item2, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 184 TSRMLS_CC);
	if (ZEPHIR_IS_IDENTICAL(_0, _1)) {
		zephir_array_fetch_string(&_2, item1, SL("serial"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 185 TSRMLS_CC);
		zephir_array_fetch_string(&_3, item2, SL("serial"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 185 TSRMLS_CC);
		if (ZEPHIR_GT(_2, _3)) {
			result = -1;
		} else {
			result = 1;
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("isLIFO"), PH_NOISY_CC);
		result = (result * zephir_get_numberval(_4));
	} else {
		zephir_array_fetch_string(&_2, item1, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 192 TSRMLS_CC);
		zephir_array_fetch_string(&_3, item2, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 192 TSRMLS_CC);
		if (ZEPHIR_GT(_2, _3)) {
			result = -1;
		} else {
			result = 1;
		}
	}
	RETURN_LONG(result);

}

/**
 * Get/Set serial order mode
 *
 * @param bool $flag
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, isLIFO) {

	int isLIFO;
	zval *flag_param = NULL, *_0 = NULL, *_1, *_2;
	zend_bool flag;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 0;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	if (flag != 0) {
		ZEPHIR_INIT_VAR(_0);
		if (flag == 1) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 1);
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, -1);
		}
		isLIFO = zephir_get_numberval(_0);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("isLIFO"), PH_NOISY_CC);
		if (!ZEPHIR_IS_LONG_IDENTICAL(_1, isLIFO)) {
			ZEPHIR_INIT_ZVAL_NREF(_2);
			ZVAL_LONG(_2, isLIFO);
			zephir_update_property_this(this_ptr, SL("isLIFO"), _2 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("sorted"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("isLIFO"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_1, 1));

}

/**
 * rewind(): defined by Iterator interface.
 *
 * @see    Iterator::rewind()
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, rewind) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sort", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * current(): defined by Iterator interface.
 *
 * @see    Iterator::current()
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, current) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *node = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&node, "current", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(node)) {
		zephir_array_fetch_string(&_2, node, SL("data"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 246 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

/**
 * key(): defined by Iterator interface.
 *
 * @see    Iterator::key()
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, key) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
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
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *node = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&node, "next", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(node)) {
		zephir_array_fetch_string(&_2, node, SL("data"), PH_NOISY | PH_READONLY, "zendframework/stdlib/prioritylist.zep", 274 TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

/**
 * valid(): defined by Iterator interface.
 *
 * @see    Iterator::valid()
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *current = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&current, this_ptr, "current", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(current));

}

/**
 * count(): defined by Countable interface.
 *
 * @see    Countable::count()
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, count) {


	RETURN_MEMBER(this_ptr, "count");

}

/**
 * Return list as array
 *
 * @param int $flag
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityList, toArray) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL;
	zval *flag = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flag);

	if (!flag) {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_LONG(flag, 0x00000001);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sort", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(flag, 0x00000003)) {
		RETURN_MM_MEMBER(this_ptr, "items");
	}
	if (ZEPHIR_IS_LONG(flag, 0x00000002)) {
		ZEPHIR_INIT_VAR(callback);
		array_init_size(callback, 3);
		zephir_array_fast_append(callback, this_ptr);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "_returnItemPriority", 1);
		zephir_array_fast_append(callback, _0);
	} else {
		ZEPHIR_INIT_NVAR(callback);
		array_init_size(callback, 3);
		zephir_array_fast_append(callback, this_ptr);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_returnItemData", 1);
		zephir_array_fast_append(callback, _0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_map", &_2, callback, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(ZendFramework_Stdlib_PriorityList, _returnItemPriority) {

	zval *item_param = NULL, *priority;
	zval *item = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item_param);

	zephir_get_arrval(item, item_param);


	if (zephir_array_isset_string_fetch(&priority, item, SS("priority"), 1 TSRMLS_CC)) {
		RETURN_CTOR(priority);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(ZendFramework_Stdlib_PriorityList, _returnItemData) {

	zval *item_param = NULL, *data;
	zval *item = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item_param);

	zephir_get_arrval(item, item_param);


	if (zephir_array_isset_string_fetch(&data, item, SS("data"), 1 TSRMLS_CC)) {
		RETURN_CTOR(data);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(ZendFramework_Stdlib_PriorityList, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

