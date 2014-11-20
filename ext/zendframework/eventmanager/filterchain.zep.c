
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
* FilterChain: intercepting filter manager
*/
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_FilterChain) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, FilterChain, zendframework, eventmanager_filterchain, zendframework_eventmanager_filterchain_method_entry, 0);

	/**
	 * @var Filter\FilterIterator All filters
	 */
	zend_declare_property_null(zendframework_eventmanager_filterchain_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_filterchain_ce TSRMLS_CC, 1, zendframework_eventmanager_filter_filterinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Initializes Filter\FilterIterator in which filters will be aggregated
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zendframework_eventmanager_filter_filteriterator_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("filters"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Apply the filters
 *
 * Begins iteration of the filters.
 *
 * @param  mixed $context Object under observation
 * @param  mixed $argv Associative array of arguments
 * @return mixed
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, run) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL;
	zval *context, *argv_param = NULL, *chain, *filters = NULL, *next = NULL, *returns = NULL, *callback = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &context, &argv_param);

	if (!argv_param) {
		ZEPHIR_INIT_VAR(argv);
		array_init(argv);
	} else {
	if (unlikely(Z_TYPE_P(argv_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'argv' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		argv = argv_param;

	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getfilters", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filters, _0);
	ZEPHIR_INIT_VAR(chain);
	if (zephir_clone(chain, filters TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, chain, "isempty", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&next, chain, "extract", NULL);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(next, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&callback, next, "getcallback", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&returns, "call_user_func", &_1, callback, context, argv, chain);
	zephir_check_call_status();
	RETURN_CCTOR(returns);

}

/**
 * Connect a filter to the chain
 *
 * @param  callable $callback PHP Callback
 * @param  int $priority Priority in the queue at which to execute; defaults to 1 (higher numbers == higher priority)
 * @return CallbackHandler (to allow later unsubscribe)
 * @throws Exception\InvalidCallbackException
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, attach) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *priority_param = NULL, *filter, *filters = NULL, *metadata, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &priority_param);

	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	ZEPHIR_INIT_VAR(metadata);
	array_init(metadata);


	if (unlikely(ZEPHIR_IS_EMPTY(callback))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_eventmanager_exception_invalidcallbackexception_ce, "No callback provided", "zendframework/eventmanager/filterchain.zep", 77);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	zephir_array_update_string(&metadata, SL("priority"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(filter);
	object_init_ex(filter, zendframework_stdlib_callbackhandler_ce);
	ZEPHIR_CALL_METHOD(NULL, filter, "__construct", NULL, callback, metadata);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getfilters", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filters, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, priority);
	ZEPHIR_CALL_METHOD(NULL, filters, "insert", NULL, filter, _2);
	zephir_check_call_status();
	RETURN_CCTOR(filter);

}

/**
 * Detach a filter from the chain
 *
 * @param  CallbackHandler $filter
 * @return bool Returns true if filter found and unsubscribed; returns false otherwise
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filter, *filters = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	if (!(zephir_instance_of_ev(filter, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'filter' must be an instance of 'ZendFramework\\Stdlib\\CallbackHandler'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getfilters", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filters, _0);
	ZEPHIR_RETURN_CALL_METHOD(filters, "remove", NULL, filter);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve all filters
 *
 * @return Filter\FilterIterator
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, getFilters) {


	RETURN_MEMBER(this_ptr, "filters");

}

/**
 * Clear all filters
 *
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, clearFilters) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zendframework_eventmanager_filter_filteriterator_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("filters"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return current responses
 *
 * Only available while the chain is still being iterated. Returns the
 * current ResponseCollection.
 *
 * @return null|ResponseCollection
 */
PHP_METHOD(ZendFramework_EventManager_FilterChain, getResponses) {


	RETURN_NULL();

}

