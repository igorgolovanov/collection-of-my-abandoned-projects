
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
#include "ext/spl/spl_heap.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/iterator.h"
#include "kernel/hash.h"
#include "kernel/operators.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Serializable version of SplPriorityQueue
 *
 * Also, provides predictable heap order for datums added with the same priority
 * (i.e., they will be emitted in the same order they are enqueued).
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_SplPriorityQueue) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib, SplPriorityQueue, zendframework, stdlib_splpriorityqueue, spl_ce_SplPriorityQueue, zendframework_stdlib_splpriorityqueue_method_entry, 0);

	/**
	 * @var int Seed used to ensure queue order for items of the same priority
	 */
	zend_declare_property_null(zendframework_stdlib_splpriorityqueue_ce, SL("serial"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_splpriorityqueue_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Insert a value with a given priority
 *
 * Utilizes {@var $serial} to ensure that values of equal priority are
 * emitted in the same order in which they are inserted.
 *
 * @param  mixed $datum
 * @param  mixed $priority
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, insert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *datum, *priority = NULL, *serial = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &datum, &priority);

	ZEPHIR_SEPARATE_PARAM(priority);


	if (Z_TYPE_P(priority) != IS_ARRAY) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("serial"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(serial, _0);
		ZEPHIR_INIT_NVAR(priority);
		array_init_size(priority, 3);
		zephir_array_fast_append(priority, priority);
		zephir_array_fast_append(priority, serial);
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("serial") TSRMLS_CC));
	}
	ZEPHIR_CALL_PARENT(NULL, zendframework_stdlib_splpriorityqueue_ce, this_ptr, "insert", NULL, datum, priority);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Serialize to an array
 *
 * Array will be priority => data pairs
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, toArray) {

	zend_object_iterator *_0;
	zval *item = NULL, *data;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(data);
	array_init(data);

	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		item = *tmp;
		}
		zephir_array_append(&data, item, PH_SEPARATE, "zendframework/stdlib/splpriorityqueue.zep", 59);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(data);

}

/**
 * Serialize
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, serialize) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serialized = NULL, *data = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_0, data);
	zephir_check_call_status();
	RETURN_CCTOR(serialized);

}

/**
 * Deserialize
 *
 * @param  string $data
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, unserialize) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *unserialized = NULL, *item = NULL, *value = NULL, *priority = NULL, **_3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", &_0, data);
	zephir_check_call_status();
	zephir_is_iterable(unserialized, &_2, &_1, 0, 0, "zendframework/stdlib/splpriorityqueue.zep", 98);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(item, _3);
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_string_fetch(&value, item, SS("data"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(priority);
			if (zephir_array_isset_string_fetch(&priority, item, SS("priority"), 0 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", &_4, value, priority);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

