
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/iterator.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Specialized priority queue implementation for use with an intercepting
 * filter chain.
 *
 * Allows removal
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_Filter_FilterIterator) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\EventManager\\Filter, FilterIterator, zendframework, eventmanager_filter_filteriterator, zendframework_stdlib_splpriorityqueue_ce, zendframework_eventmanager_filter_filteriterator_method_entry, 0);

	return SUCCESS;

}

/**
 * Does the queue contain a given value?
 *
 * @param  mixed $datum
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, contains) {

	zend_object_iterator *_0;
	zval *datum, *chain, *item = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datum);



	ZEPHIR_INIT_VAR(chain);
	if (zephir_clone(chain, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	_0 = zephir_get_iterator(chain TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		item = *tmp;
		}
		if (ZEPHIR_IS_IDENTICAL(item, datum)) {
			RETURN_MM_BOOL(1);
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

/**
 * Remove a value from the queue
 *
 * This is an expensive operation. It must first iterate through all values,
 * and then re-populate itself. Use only if absolutely necessary.
 *
 * @param  mixed $datum
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, remove) {

	HashTable *_6;
	HashPosition _5;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *items;
	zend_bool removed = 0;
	zval *datum, *item = NULL, *data = NULL, *priority = NULL, *_0 = NULL, *_1 = NULL, **_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datum);

	ZEPHIR_INIT_VAR(items);
	array_init(items);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setextractflags", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "isempty",  &_2);
		zephir_check_call_status();
		if (!(!(zephir_is_true(_1)))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&item, this_ptr, "extract",  &_3);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(data);
		if (zephir_array_isset_string_fetch(&data, item, SS("data"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_IDENTICAL(data, datum)) {
				removed = 1;
				continue;
			}
		}
		Z_SET_ISREF_P(items);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, items, item);
		Z_UNSET_ISREF_P(items);
		zephir_check_call_status();
	}
	zephir_is_iterable(items, &_6, &_5, 0, 0, "zendframework/eventmanager/filter/filteriterator.zep", 79);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(item, _7);
		ZEPHIR_OBS_NVAR(data);
		if (zephir_array_isset_string_fetch(&data, item, SS("data"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(priority);
			if (zephir_array_isset_string_fetch(&priority, item, SS("priority"), 0 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", &_8, data, priority);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setextractflags", NULL, _0);
	zephir_check_call_status();
	RETURN_MM_BOOL(removed);

}

/**
 * Iterate the next filter in the chain
 *
 * Iterates and calls the next filter in the chain.
 *
 * @param  mixed $context
 * @param  array $params
 * @param  FilterIterator $chain
 * @return mixed
 */
PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, next) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _1;
	zval *params = NULL;
	zval *context = NULL, *params_param = NULL, *chain = NULL, *next = NULL, *callback = NULL, *returns = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &context, &params_param, &chain);

	if (!context) {
		context = ZEPHIR_GLOBAL(global_null);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
	if (unlikely(Z_TYPE_P(params_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'params' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		params = params_param;

	}
	if (!chain) {
		chain = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(chain) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(chain, zendframework_eventmanager_filter_filteriterator_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'chain' must be an instance of 'ZendFramework\\\\EventManager\\\\Filter\\\\FilterIterator'", "", 0);
		return;
	}
	_1 = ZEPHIR_IS_EMPTY(context);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, chain, "isempty",  NULL);
		zephir_check_call_status();
		_1 = zephir_is_true(_2);
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&next, this_ptr, "extract",  NULL);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(next, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&callback, next, "getcallback",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&returns, "call_user_func", &_3, callback, context, params, chain);
	zephir_check_call_status();
	RETURN_CCTOR(returns);

}

