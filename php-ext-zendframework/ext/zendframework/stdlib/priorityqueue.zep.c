
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "ext/spl/spl_heap.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_PriorityQueue) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, PriorityQueue, zendframework, stdlib_priorityqueue, zendframework_stdlib_priorityqueue_method_entry, 0);

	/**
	 * Inner queue class to use for iteration
	 * @var string
	 */
	zend_declare_property_string(zendframework_stdlib_priorityqueue_ce, SL("queueClass"), "Zend\\Stdlib\\SplPriorityQueue", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Actual items aggregated in the priority queue. Each item is an array
	 * with keys "data" and "priority".
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_priorityqueue_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Inner queue object
	 * @var SplPriorityQueue
	 */
	zend_declare_property_null(zendframework_stdlib_priorityqueue_ce, SL("queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_priorityqueue_ce, SL("EXTR_DATA"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_priorityqueue_ce, SL("EXTR_PRIORITY"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_stdlib_priorityqueue_ce, SL("EXTR_BOTH"), 3 TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_priorityqueue_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_stdlib_priorityqueue_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(zendframework_stdlib_priorityqueue_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Insert an item into the queue
 *
 * Priority defaults to 1 (low priority) if none provided.
 *
 * @param  mixed $data
 * @param  int $priority
 * @return PriorityQueue
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, insert) {

	zval *datum;
	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *data, *priority_param = NULL, *queue = NULL, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &priority_param);

	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(datum);
	array_init_size(datum, 3);
	zephir_array_update_string(&datum, SL("data"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	zephir_array_update_string(&datum, SL("priority"), &_0, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("items"), data TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getqueue", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(queue, _1);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, priority);
	ZEPHIR_CALL_METHOD(NULL, queue, "insert", NULL, datum, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Remove an item from the queue
 *
 * This is different than {@link extract()}; its purpose is to dequeue an
 * item.
 *
 * This operation is potentially expensive, as it requires
 * re-initialization and re-population of the inner queue.
 *
 * Note: this removes the first item matching the provided item found. If
 * the same item has been added multiple times, it will not remove other
 * instances.
 *
 * @param  mixed $datum
 * @return bool False if the item was not found, true otherwise.
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, remove) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_10;
	HashPosition _1, _9;
	zend_bool found = 0;
	zval *datum, *key = NULL, *item = NULL, *queue = NULL, *data = NULL, *priority = NULL, *_0, **_3, *_4, *_5, *_6 = NULL, *_7 = NULL, *_8, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datum);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/stdlib/priorityqueue.zep", 105);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(item, _3);
		zephir_array_fetch_string(&_4, item, SL("data"), PH_NOISY | PH_READONLY, "zendframework/stdlib/priorityqueue.zep", 99 TSRMLS_CC);
		if (ZEPHIR_IS_IDENTICAL(_4, datum)) {
			found = 1;
			break;
		}
	}
	if (found) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_unset(&_5, key, PH_SEPARATE);
		zephir_update_property_this(this_ptr, SL("queue"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "isempty", NULL);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			ZEPHIR_CALL_METHOD(&_7, this_ptr, "getqueue", NULL);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(queue, _7);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
			zephir_is_iterable(_8, &_10, &_9, 0, 0, "zendframework/stdlib/priorityqueue.zep", 117);
			for (
			  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			  ; zephir_hash_move_forward_ex(_10, &_9)
			) {
				ZEPHIR_GET_HVALUE(item, _11);
				ZEPHIR_OBS_NVAR(data);
				zephir_array_fetch_string(&data, item, SL("data"), PH_NOISY, "zendframework/stdlib/priorityqueue.zep", 112 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(priority);
				zephir_array_fetch_string(&priority, item, SL("priority"), PH_NOISY, "zendframework/stdlib/priorityqueue.zep", 113 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, queue, "insert", &_12, data, priority);
				zephir_check_call_status();
			}
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Is the queue empty?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, isEmpty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

/**
 * How many items are in the queue?
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Peek at the top node in the queue, based on priority.
 *
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, top) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *iterator = NULL, *item = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getiterator", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(iterator, _0);
	ZEPHIR_CALL_METHOD(&item, iterator, "top", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(item);

}

/**
 * Extract a node from the inner queue and sift up
 *
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, extract) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queue = NULL, *item = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getqueue", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(queue, _0);
	ZEPHIR_CALL_METHOD(&item, queue, "extract", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(item);

}

/**
 * Retrieve the inner iterator
 *
 * SplPriorityQueue acts as a heap, which typically implies that as items
 * are iterated, they are also removed. This does not work for situations
 * where the queue may be iterated multiple times. As such, this class
 * aggregates the values, and also injects an SplPriorityQueue. This method
 * retrieves the inner queue object, and clones it for purposes of
 * iteration.
 *
 * @return SplPriorityQueue
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *queue = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getqueue", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(queue, _0);
	if (zephir_clone(return_value, queue TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	RETURN_MM();

}

/**
 * Serialize the data structure
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *items = NULL, *serialized = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(items, _0);
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_1, items);
	zephir_check_call_status();
	RETURN_CCTOR(serialized);

}

/**
 * Unserialize a string into a PriorityQueue object
 *
 * Serialization format is compatible with {@link Zend\Stdlib\SplPriorityQueue}
 *
 * @param  string $data
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, unserialize) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *unserialized = NULL, *datum = NULL, *item = NULL, *priority = NULL, **_3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", &_0, data);
	zephir_check_call_status();
	zephir_is_iterable(unserialized, &_2, &_1, 0, 0, "zendframework/stdlib/priorityqueue.zep", 228);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(item, _3);
		ZEPHIR_OBS_NVAR(datum);
		zephir_array_fetch_string(&datum, item, SL("data"), PH_NOISY, "zendframework/stdlib/priorityqueue.zep", 223 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(priority);
		zephir_array_fetch_string(&priority, item, SL("priority"), PH_NOISY, "zendframework/stdlib/priorityqueue.zep", 224 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", &_4, datum, priority);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize to an array
 *
 * By default, returns only the item data, and in the order registered (not
 * sorted). You may provide one of the EXTR_* flags as an argument, allowing
 * the ability to return priorities or both data and priority.
 *
 * @param  int $flag
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *callback = NULL;
	zval *flag = NULL, *result = NULL, *items = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flag);

	if (!flag) {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_LONG(flag, 1);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(items, _0);
	do {
		if (ZEPHIR_IS_LONG(flag, 3)) {
			ZEPHIR_CPY_WRT(result, items);
			break;
		}
		if (ZEPHIR_IS_LONG(flag, 2)) {
			ZEPHIR_INIT_VAR(callback);
			array_init_size(callback, 3);
			zephir_array_fast_append(callback, this_ptr);
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "toPriorityArray", 1);
			zephir_array_fast_append(callback, _1);
			ZEPHIR_CALL_FUNCTION(&result, "array_map", &_2, callback, items);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(callback);
		array_init_size(callback, 3);
		zephir_array_fast_append(callback, this_ptr);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "toDataArray", 1);
		zephir_array_fast_append(callback, _1);
		ZEPHIR_CALL_FUNCTION(&result, "array_map", &_2, callback, items);
		zephir_check_call_status();
		break;
	} while(0);

	RETURN_CCTOR(result);

}

PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toDataArray) {

	zval *item_param = NULL, *_0;
	zval *item = NULL;

	zephir_fetch_params(0, 1, 0, &item_param);

	if (unlikely(Z_TYPE_P(item_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		item = item_param;



	zephir_array_fetch_string(&_0, item, SL("data"), PH_NOISY | PH_READONLY, "zendframework/stdlib/priorityqueue.zep", 269 TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toPriorityArray) {

	zval *item_param = NULL, *_0;
	zval *item = NULL;

	zephir_fetch_params(0, 1, 0, &item_param);

	if (unlikely(Z_TYPE_P(item_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'item' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		item = item_param;



	zephir_array_fetch_string(&_0, item, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/priorityqueue.zep", 274 TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Specify the internal queue class
 *
 * Please see {@link getIterator()} for details on the necessity of an
 * internal queue class. The class provided should extend SplPriorityQueue.
 *
 * @param  string $class
 * @return PriorityQueue
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, setInternalQueueClass) {

	zval *class_param = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	zephir_update_property_this(this_ptr, SL("queueClass"), class TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Does the queue contain the given datum?
 *
 * @param  mixed $datum
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, contains) {

	HashTable *_2;
	HashPosition _1;
	zval *datum, *item = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datum);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/stdlib/priorityqueue.zep", 307);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(item, _3);
		zephir_array_fetch_string(&_4, item, SL("data"), PH_NOISY | PH_READONLY, "zendframework/stdlib/priorityqueue.zep", 303 TSRMLS_CC);
		if (ZEPHIR_IS_IDENTICAL(_4, datum)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Does the queue have an item with the given priority?
 *
 * @param  int $priority
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, hasPriority) {

	HashTable *_2;
	HashPosition _1;
	zval *priority_param = NULL, *item = NULL, *_0, **_3, *_4;
	int priority;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &priority_param);

	priority = zephir_get_intval(priority_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/stdlib/priorityqueue.zep", 325);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(item, _3);
		zephir_array_fetch_string(&_4, item, SL("priority"), PH_NOISY | PH_READONLY, "zendframework/stdlib/priorityqueue.zep", 321 TSRMLS_CC);
		if (ZEPHIR_IS_LONG_IDENTICAL(_4, priority)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the inner priority queue instance
 *
 * @throws Exception\DomainException
 * @return SplPriorityQueue
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, getQueue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3;
	zval *queue = NULL, *queueClass = NULL, *_0, *_1, *_2 = NULL, *_4, *_5;
	zval *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(queue, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("queueClass"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(queueClass, _1);
		ZEPHIR_INIT_NVAR(queue);
		zephir_fetch_safe_class(_2, queueClass);
		_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(queue, _3);
		if (zephir_has_constructor(queue TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, queue, "__construct", NULL);
			zephir_check_call_status();
		}
		if (unlikely(!(zephir_instance_of_ev(queue, spl_ce_SplPriorityQueue TSRMLS_CC)))) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "PriorityQueue expects an internal queue of type SplPriorityQueue; received \"", queueClass, "\"");
			zephir_get_strval(exceptionMsg, _4);
			ZEPHIR_INIT_VAR(_5);
			object_init_ex(_5, zendframework_stdlib_exception_domainexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, exceptionMsg);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5, "zendframework/stdlib/priorityqueue.zep", 346 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_this(this_ptr, SL("queue"), queue TSRMLS_CC);
	}
	RETURN_CCTOR(queue);

}

/**
 * Add support for deep cloning
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, __clone) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		if (zephir_clone(_2, _1 TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		zephir_update_property_this(this_ptr, SL("queue"), _2 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

