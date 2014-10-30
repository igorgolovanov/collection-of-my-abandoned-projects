
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventManager) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, SharedEventManager, zendframework, eventmanager_sharedeventmanager, zendframework_eventmanager_sharedeventmanager_method_entry, 0);

	/**
	 * Identifiers with event connections
	 * @var array
	 */
	zend_declare_property_null(zendframework_eventmanager_sharedeventmanager_ce, SL("identifiers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_sharedeventmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_sharedeventaggregateawareinterface_ce);
	zend_class_implements(zendframework_eventmanager_sharedeventmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_sharedeventmanagerinterface_ce);
	return SUCCESS;

}

/**
 * Attach a listener to an event
 *
 * Allows attaching a callback to an event offered by one or more
 * identifying components. As an example, the following connects to the
 * "getAll" event of both an AbstractResource and EntityResource:
 *
 * <code>
 * $sharedEventManager = new SharedEventManager();
 * $sharedEventManager->attach(
 *     array('My\Resource\AbstractResource', 'My\Resource\EntityResource'),
 *     'getAll',
 *     function ($e) use ($cache) {
 *         if (!$id = $e->getParam('id', false)) {
 *             return;
 *         }
 *         if (!$data = $cache->load(get_class($resource) . '::getOne::' . $id )) {
 *             return;
 *         }
 *         return $data;
 *     }
 * );
 * </code>
 *
 * @param  string|array $id Identifier(s) for event emitting component(s)
 * @param  string $event
 * @param  callable $callback PHP Callback
 * @param  int $priority Priority at which listener should execute
 * @return CallbackHandler|array Either CallbackHandler or array of CallbackHandlers
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, attach) {

	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	HashTable *_2;
	HashPosition _1;
	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL;
	zval *id, *event_param = NULL, *callback, *priority_param = NULL, *i = NULL, *identifiers = NULL, *eventManager = NULL, *ids = NULL, *listeners, *_0, **_3, *_5 = NULL, *_6 = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &id, &event_param, &callback, &priority_param);

	zephir_get_strval(event, event_param);
	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	ZEPHIR_INIT_VAR(listeners);
	array_init(listeners);


	if (Z_TYPE_P(id) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(ids, id);
	} else {
		ZEPHIR_INIT_VAR(ids);
		array_init_size(ids, 2);
		zephir_array_fast_append(ids, id);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(identifiers, _0);
	zephir_is_iterable(ids, &_2, &_1, 0, 0, "zendframework/eventmanager/sharedeventmanager.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(i, _3);
		ZEPHIR_OBS_NVAR(eventManager);
		if (unlikely(zephir_array_isset_fetch(&eventManager, identifiers, i, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(eventManager);
			object_init_ex(eventManager, zendframework_eventmanager_eventmanager_ce);
			ZEPHIR_CALL_METHOD(NULL, eventManager, "__construct", &_4, i);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("identifiers"), i, eventManager TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_LONG(_6, priority);
		ZEPHIR_CALL_METHOD(&_5, eventManager, "attach", &_7, event, callback, _6);
		zephir_check_call_status();
		zephir_array_append(&listeners, _5, PH_SEPARATE, "zendframework/eventmanager/sharedeventmanager.zep", 72);
	}
	if (zephir_fast_count_int(listeners TSRMLS_CC) > 1) {
		RETURN_CCTOR(listeners);
	}
	zephir_array_fetch_long(&_8, listeners, 0, PH_NOISY | PH_READONLY, "zendframework/eventmanager/sharedeventmanager.zep", 78 TSRMLS_CC);
	RETURN_CTOR(_8);

}

/**
 * Attach a listener aggregate
 *
 * Listener aggregates accept an EventManagerInterface instance, and call attachShared()
 * one or more times, typically to attach to multiple events using local
 * methods.
 *
 * @param  SharedListenerAggregateInterface $aggregate
 * @param  int $priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link ListenerAggregateInterface::attachShared()}
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, attachAggregate) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate, *priority_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority_param);

	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (!(zephir_instance_of_ev(aggregate, zendframework_eventmanager_sharedlisteneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'ZendFramework\\\\EventManager\\\\SharedListenerAggregateInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	ZEPHIR_RETURN_CALL_METHOD(aggregate, "attachshared", NULL, this_ptr, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Detach a listener from an event offered by a given resource
 *
 * @param  string|int $id
 * @param  CallbackHandler $listener
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *listener, *eventManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &listener);



	if (!(zephir_instance_of_ev(listener, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'listener' must be an instance of 'ZendFramework\\\\Stdlib\\\\CallbackHandler'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(eventManager);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&eventManager, _0, id, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(eventManager, "detach", NULL, listener);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Detach a listener aggregate
 *
 * Listener aggregates accept a SharedEventManagerInterface instance, and call detachShared()
 * of all previously attached listeners.
 *
 * @param  SharedListenerAggregateInterface $aggregate
 * @return mixed return value of {@link SharedListenerAggregateInterface::detachShared()}
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, detachAggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	if (!(zephir_instance_of_ev(aggregate, zendframework_eventmanager_sharedlisteneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'ZendFramework\\\\EventManager\\\\SharedListenerAggregateInterface'", "", 0);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(aggregate, "detachshared", NULL, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieve all registered events for a given resource
 *
 * @param  string|int $id
 * @return array
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, getEvents) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *wildcard;
	zval *id, *eventManager = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);

	ZEPHIR_INIT_VAR(wildcard);
	ZVAL_STRING(wildcard, "*", 1);


	ZEPHIR_OBS_VAR(eventManager);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&eventManager, _0, id, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(eventManager, "getevents", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = !ZEPHIR_IS_EQUAL(id, wildcard);
	if (_1) {
		ZEPHIR_OBS_NVAR(eventManager);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		_1 = zephir_array_isset_fetch(&eventManager, _2, wildcard, 0 TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(eventManager, "getevents", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Retrieve all listeners for a given identifier and event
 *
 * @param  string|int $id
 * @param  string|int $event
 * @return false|PriorityQueue
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, getListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id, *event, *eventManager, *listeners = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &event);



	ZEPHIR_OBS_VAR(eventManager);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&eventManager, _0, id, 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&listeners, eventManager, "getlisteners", NULL, event);
		zephir_check_call_status();
		RETURN_CCTOR(listeners);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Clear all listeners for a given identifier, optionally for a specific event
 *
 * @param  string|int $id
 * @param  null|string $event
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, clearListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL;
	zval *id, *event_param = NULL, *eventManager, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id, &event_param);

	if (!event_param) {
		ZEPHIR_INIT_VAR(event);
		ZVAL_EMPTY_STRING(event);
	} else {
		zephir_get_strval(event, event_param);
	}


	ZEPHIR_OBS_VAR(eventManager);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&eventManager, _0, id, 0 TSRMLS_CC)) {
		if (!ZEPHIR_IS_STRING_IDENTICAL(event, "")) {
			ZEPHIR_RETURN_CALL_METHOD(eventManager, "clearlisteners", NULL, event);
			zephir_check_call_status();
			RETURN_MM();
		}
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
		zephir_array_unset(&_1, id, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(ZendFramework_EventManager_SharedEventManager, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("identifiers"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

