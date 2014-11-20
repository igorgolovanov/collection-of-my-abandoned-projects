
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
#include "ext/spl/spl_dllist.h"
#include "kernel/iterator.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Serializable version of SplQueue
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_SplQueue) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib, SplQueue, zendframework, stdlib_splqueue, spl_ce_SplQueue, zendframework_stdlib_splqueue_method_entry, 0);

	zend_class_implements(zendframework_stdlib_splqueue_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Return an array representing the queue
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Stdlib_SplQueue, toArray) {

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
		zephir_array_append(&data, item, PH_SEPARATE, "zendframework/stdlib/splqueue.zep", 29);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(data);

}

/**
 * Serialize
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_SplQueue, serialize) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serialized = NULL, *data = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_0, data);
	zephir_check_call_status();
	RETURN_CCTOR(serialized);

}

/**
 * Unserialize
 *
 * @param  string $data
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_SplQueue, unserialize) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL, *unserialized = NULL, *item = NULL, **_3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_CALL_FUNCTION(&unserialized, "unserialize", &_0, data);
	zephir_check_call_status();
	zephir_is_iterable(unserialized, &_2, &_1, 0, 0, "zendframework/stdlib/splqueue.zep", 64);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(item, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", &_4, item);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

