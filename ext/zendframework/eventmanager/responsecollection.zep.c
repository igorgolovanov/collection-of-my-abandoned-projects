
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/iterator.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Collection of signal handler return values
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_ResponseCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\EventManager, ResponseCollection, zendframework, eventmanager_responsecollection, spl_ce_SplStack, zendframework_eventmanager_responsecollection_method_entry, 0);

	zend_declare_property_bool(zendframework_eventmanager_responsecollection_ce, SL("stopped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Did the last response provided trigger a short circuit of the stack?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, stopped) {


	RETURN_MEMBER(this_ptr, "stopped");

}

/**
 * Mark the collection as stopped (or its opposite)
 *
 * @param  bool $flag
 * @return ResponseCollection
 */
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, setStopped) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 1, 0, &flag_param);

	flag = zephir_get_boolval(flag_param);


	zephir_update_property_this(this_ptr, SL("stopped"), flag ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Convenient access to the first handler return value.
 *
 * @return mixed The first handler return value
 */
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, first) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_PARENT(zendframework_eventmanager_responsecollection_ce, this_ptr, "bottom", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convenient access to the last handler return value.
 *
 * If the collection is empty, returns null. Otherwise, returns value
 * returned by last handler.
 *
 * @return mixed The last handler return value
 */
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, last) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	if (zephir_fast_count_int(this_ptr TSRMLS_CC) == 0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_PARENT(zendframework_eventmanager_responsecollection_ce, this_ptr, "top", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if any of the responses match the given value.
 *
 * @param  mixed $value The value to look for among responses
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, contains) {

	zend_object_iterator *_0;
	zval *value, *response = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		response = *tmp;
		}
		if (ZEPHIR_IS_IDENTICAL(response, value)) {
			RETURN_MM_BOOL(1);
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

