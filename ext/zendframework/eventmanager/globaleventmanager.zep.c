
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Event manager: notification system
 *
 * Use the EventManager when you want to create a per-instance notification
 * system for your objects.
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_GlobalEventManager) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, GlobalEventManager, zendframework, eventmanager_globaleventmanager, zendframework_eventmanager_globaleventmanager_method_entry, 0);

	/**
	 * @var EventManagerInterface
	 */
	zend_declare_property_null(zendframework_eventmanager_globaleventmanager_ce, SL("events"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set the event collection on which this will operate
 *
 * @param  null|EventManagerInterface $events
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, setEventCollection) {

	zend_bool _0;
	zval *events = NULL, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &events);

	if (!events) {
		events = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(events) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(events, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'events' must be an instance of 'ZendFramework\\\\EventManager\\\\EventManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("events"), &events TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Get event collection on which this operates
 *
 * @return EventManagerInterface
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getEventCollection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className, *events = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(events);
	ZVAL_NULL(events);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&events, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("events") TSRMLS_CC);
        
	if (Z_TYPE_P(events) == IS_NULL) {
		ZEPHIR_INIT_NVAR(events);
		object_init_ex(events, zendframework_eventmanager_eventmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, events, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(NULL, "seteventcollection", NULL, events);
		zephir_check_call_status();
	}
	RETURN_CCTOR(events);

}

/**
 * Trigger an event
 *
 * @param  string $event
 * @param  object|string $context
 * @param  array|object $argv
 * @return ResponseCollection
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, trigger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *context, *argv = NULL, *events = NULL, *_0 = NULL;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &context, &argv);

	zephir_get_strval(event, event_param);
	if (!argv) {
		ZEPHIR_INIT_VAR(argv);
		array_init(argv);
	}


	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_RETURN_CALL_METHOD(events, "trigger", NULL, event, context, argv);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Trigger listeners until return value of one causes a callback to evaluate
 * to true.
 *
 * @param  string $event
 * @param  string|object $context
 * @param  array|object $argv
 * @param  callable $callback
 * @return ResponseCollection
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, triggerUntil) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *context, *argv, *callback, *events = NULL, *_0 = NULL;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &event_param, &context, &argv, &callback);

	zephir_get_strval(event, event_param);


	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_RETURN_CALL_METHOD(events, "triggeruntil", NULL, event, context, argv, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Attach a listener to an event
 *
 * @param  string $event
 * @param  callable $callback
 * @param  int $priority
 * @return CallbackHandler
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, attach) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *callback, *priority_param = NULL, *events = NULL, *_0 = NULL, *_1;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &callback, &priority_param);

	zephir_get_strval(event, event_param);
	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, priority);
	ZEPHIR_RETURN_CALL_METHOD(events, "attach", NULL, event, callback, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Detach a callback from a listener
 *
 * @param  CallbackHandler $listener
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *listener, *events = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &listener);



	if (!(zephir_instance_of_ev(listener, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'listener' must be an instance of 'ZendFramework\\\\Stdlib\\\\CallbackHandler'", "", 0);
		return;
	}
	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_RETURN_CALL_METHOD(events, "detach", NULL, listener);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve list of events this object manages
 *
 * @return array
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getEvents) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *events = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_RETURN_CALL_METHOD(events, "getevents", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve all listeners for a given event
 *
 * @param  string $event
 * @return PriorityQueue|array
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *events = NULL, *_0 = NULL;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(event, event_param);


	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_RETURN_CALL_METHOD(events, "getlisteners", NULL, event);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Clear all listeners for a given event
 *
 * @param  string $event
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, clearListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *events = NULL, *_0 = NULL;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(event, event_param);


	ZEPHIR_CALL_STATIC(&_0, "geteventcollection", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_CALL_METHOD(NULL, events, "clearlisteners", NULL, event);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

