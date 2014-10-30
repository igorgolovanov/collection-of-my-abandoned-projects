
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "ext/spl/spl_array.h"

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventManager) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, EventManager, zendframework, eventmanager_eventmanager, zendframework_eventmanager_eventmanager_method_entry, 0);

	/**
	 * Subscribed events and their listeners
	 * @var array Array of PriorityQueue objects
	 */
	zend_declare_property_null(zendframework_eventmanager_eventmanager_ce, SL("events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string Class representing the event being emitted
	 */
	zend_declare_property_string(zendframework_eventmanager_eventmanager_ce, SL("eventClass"), "Zend\\\\EventManager\\\\Event", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Identifiers, used to pull shared signals from SharedEventManagerInterface instance
	 * @var array
	 */
	zend_declare_property_null(zendframework_eventmanager_eventmanager_ce, SL("identifiers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Shared event manager
	 * @var false|null|SharedEventManagerInterface
	 */
	zend_declare_property_null(zendframework_eventmanager_eventmanager_ce, SL("sharedManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_eventmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_eventmanagerinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Allows optionally specifying identifier(s) to use to pull signals from a
 * SharedEventManagerInterface.
 *
 * @param  null|string|int|array|Traversable $identifiers
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &identifiers);

	if (!identifiers) {
		identifiers = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("identifiers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("events"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setidentifiers", NULL, identifiers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the event class to utilize
 *
 * @param  string $class
 * @return EventManager
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, setEventClass) {

	zval *class_param = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	if (unlikely(Z_TYPE_P(class_param) != IS_STRING && Z_TYPE_P(class_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'class' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(class_param) == IS_STRING)) {
		zephir_get_strval(class, class_param);
	} else {
		ZEPHIR_INIT_VAR(class);
		ZVAL_EMPTY_STRING(class);
	}


	zephir_update_property_this(this_ptr, SL("eventClass"), class TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Set shared event manager
 *
 * @param SharedEventManagerInterface $sharedEventManager
 * @return EventManager
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, setSharedManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *sharedEventManager;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sharedEventManager);



	if (!(zephir_instance_of_ev(sharedEventManager, zendframework_eventmanager_sharedeventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'sharedEventManager' must be an instance of 'ZendFramework\\\\EventManager\\\\SharedEventManagerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("sharedManager"), sharedEventManager TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, zendframework_eventmanager_staticeventmanager_ce, "setinstance", &_0, sharedEventManager);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Remove any shared event manager currently attached
 *
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, unsetSharedManager) {


	zephir_update_property_this(this_ptr, SL("sharedManager"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Get shared event manager
 *
 * If one is not defined, but we have a static instance in
 * StaticEventManager, that one will be used and set in this instance.
 *
 * If none is available in the StaticEventManager, a boolean false is
 * returned.
 *
 * @return false|SharedEventManagerInterface
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, getSharedManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_bool _1;
	zval *sharedManager = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sharedManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(sharedManager, _0);
	_1 = ZEPHIR_IS_FALSE_IDENTICAL(sharedManager);
	if (!(_1)) {
		_1 = zephir_instance_of_ev(sharedManager, zendframework_eventmanager_sharedeventmanagerinterface_ce TSRMLS_CC);
	}
	if (_1) {
		RETURN_CCTOR(sharedManager);
	}
	ZEPHIR_CALL_CE_STATIC(&_2, zendframework_eventmanager_staticeventmanager_ce, "hasinstance", &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_CE_STATIC(&sharedManager, zendframework_eventmanager_staticeventmanager_ce, "getinstance", &_4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("sharedManager"), sharedManager TSRMLS_CC);
	RETURN_CCTOR(sharedManager);

}

/**
 * Get the identifier(s) for this EventManager
 *
 * @return array
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, getIdentifiers) {


	RETURN_MEMBER(this_ptr, "identifiers");

}

/**
 * Set the identifiers (overrides any currently set identifiers)
 *
 * @param string|int|array|Traversable $identifiers
 * @return EventManager Provides a fluent interface
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, setIdentifiers) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (zephir_is_instance_of(identifiers, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, identifiers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(identifiers, _0);
	}
	if (Z_TYPE_P(identifiers) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(identifiers);
		array_init_size(identifiers, 2);
		zephir_array_fast_append(identifiers, identifiers);
	}
	zephir_update_property_this(this_ptr, SL("identifiers"), identifiers TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Add some identifier(s) (appends to any currently set identifiers)
 *
 * @param string|int|array|Traversable $identifiers
 * @return EventManager Provides a fluent interface
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, addIdentifiers) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifiers);

	ZEPHIR_SEPARATE_PARAM(identifiers);


	if (Z_TYPE_P(identifiers) != IS_ARRAY) {
		if (zephir_is_instance_of(identifiers, SL("Traversable") TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, identifiers);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(identifiers, _0);
		} else {
			ZEPHIR_INIT_NVAR(identifiers);
			array_init_size(identifiers, 2);
			zephir_array_fast_append(identifiers, identifiers);
		}
	}
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("identifiers"), PH_NOISY_CC);
	zephir_fast_array_merge(_1, &(_2), &(identifiers) TSRMLS_CC);
	ZEPHIR_CPY_WRT(identifiers, _1);
	ZEPHIR_CALL_FUNCTION(&_0, "array_unique", &_3, identifiers);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(identifiers, _0);
	zephir_update_property_this(this_ptr, SL("identifiers"), identifiers TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Trigger all listeners for a given event
 *
 * Can emulate triggerUntil() if the last argument provided is a callback.
 *
 * @param  string $event
 * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
 * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
 * @param  null|callable $callback
 * @return ResponseCollection All listener return values
 * @throws Exception\InvalidCallbackException
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, trigger) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, *target = NULL, *argv = NULL, *callback = NULL, *e = NULL, *eventClass = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &event, &target, &argv, &callback);

	ZEPHIR_SEPARATE_PARAM(event);
	if (!target) {
		target = ZEPHIR_GLOBAL(global_null);
	}
	if (!argv) {
		ZEPHIR_INIT_VAR(argv);
		array_init(argv);
	}
	if (!callback) {
		ZEPHIR_CPY_WRT(callback, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(callback);
	}


	if (zephir_instance_of_ev(event, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(e, event);
		ZEPHIR_CALL_METHOD(&event, e, "getname",  NULL);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(callback, target);
	} else {
		if (zephir_instance_of_ev(target, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(e, target);
			ZEPHIR_CPY_WRT(callback, argv);
			ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(e);
			if (zephir_instance_of_ev(argv, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(e, argv);
				ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "settarget", NULL, target);
				zephir_check_call_status();
			} else {
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("eventClass"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(eventClass, _0);
				_1 = zend_fetch_class(Z_STRVAL_P(eventClass), Z_STRLEN_P(eventClass), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(e, _1);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "settarget", NULL, target);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "setparams", NULL, argv);
				zephir_check_call_status();
			}
		}
	}
	if (unlikely(!zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_eventmanager_exception_invalidcallbackexception_ce, "Invalid callback provided", "zendframework/eventmanager/eventmanager.zep", 220);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, e, "stoppropagation", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "triggerlisteners", NULL, event, e, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Trigger listeners until return value of one causes a callback to
 * evaluate to true
 *
 * Triggers listeners until the provided callback evaluates the return
 * value of one as true, or until all listeners have been executed.
 *
 * @param  string $event
 * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
 * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
 * @param  callable $callback
 * @return ResponseCollection
 * @throws Exception\InvalidCallbackException if invalid callable provided
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, triggerUntil) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, *target, *argv = NULL, *callback = NULL, *e = NULL, *eventClass = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &event, &target, &argv, &callback);

	ZEPHIR_SEPARATE_PARAM(event);
	if (!argv) {
		argv = ZEPHIR_GLOBAL(global_null);
	}
	if (!callback) {
		ZEPHIR_CPY_WRT(callback, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(callback);
	}


	if (zephir_instance_of_ev(event, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(e, event);
		ZEPHIR_CALL_METHOD(&event, e, "getname",  NULL);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(callback, target);
	} else {
		if (zephir_instance_of_ev(target, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(e, target);
			ZEPHIR_CPY_WRT(callback, argv);
			ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(e);
			if (zephir_instance_of_ev(argv, zendframework_eventmanager_eventinterface_ce TSRMLS_CC)) {
				ZEPHIR_CPY_WRT(e, argv);
				ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "settarget", NULL, target);
				zephir_check_call_status();
			} else {
				_0 = zephir_fetch_nproperty_this(this_ptr, SL("eventClass"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(eventClass, _0);
				_1 = zend_fetch_class(Z_STRVAL_P(eventClass), Z_STRLEN_P(eventClass), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(e, _1);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, e, "setname", NULL, event);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "settarget", NULL, target);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, e, "setparams", NULL, argv);
				zephir_check_call_status();
			}
		}
	}
	if (unlikely(!zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_eventmanager_exception_invalidcallbackexception_ce, "Invalid callback provided", "zendframework/eventmanager/eventmanager.zep", 272);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, e, "stoppropagation", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "triggerlisteners", NULL, event, e, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Attach a listener to an event
 *
 * The first argument is the event, and the next argument describes a
 * callback that will respond to that event. A CallbackHandler instance
 * describing the event listener combination will be returned.
 *
 * The last argument indicates a priority at which the event should be
 * executed. By default, this value is 1; however, you may set it for any
 * integer value. Higher values have higher priority (i.e., execute first).
 *
 * You can specify "*" for the event name. In such cases, the listener will
 * be triggered for every event.
 *
 * @param  string|array|ListenerAggregateInterface $event An event or array of event names. If a ListenerAggregateInterface, proxies to {@link attachAggregate()}.
 * @param  callable|int $callback If string $event provided, expects PHP callback; for a ListenerAggregateInterface $event, this will be the priority
 * @param  int $priority If provided, the priority at which to register the callable
 * @return CallbackHandler|mixed CallbackHandler if attaching callable (to allow later unsubscribe); mixed if attaching aggregate
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, attach) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *metadata;
	zval *exceptionMsg = NULL;
	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event, *callback = NULL, *priority_param = NULL, *listeners, *name = NULL, *listener, *_0 = NULL, **_3, *_4 = NULL, _5 = zval_used_for_init, *_7, *_8, *_9 = NULL, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &event, &callback, &priority_param);

	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}
	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (zephir_instance_of_ev(event, zendframework_eventmanager_listeneraggregateinterface_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attachaggregate", NULL, event, callback);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (unlikely(Z_TYPE_P(callback) == IS_NULL)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SS(exceptionMsg, "EventManager:attach", ": expects a callback; none provided");
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zendframework_eventmanager_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "zendframework/eventmanager/eventmanager.zep", 315 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(event) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(listeners);
		array_init(listeners);
		zephir_is_iterable(event, &_2, &_1, 0, 0, "zendframework/eventmanager/eventmanager.zep", 325);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(name, _3);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_LONG(&_5, priority);
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "attach", &_6, name, callback, &_5);
			zephir_check_call_status();
			zephir_array_append(&listeners, _4, PH_SEPARATE, "zendframework/eventmanager/eventmanager.zep", 323);
		}
		RETURN_CCTOR(listeners);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_fetch(&_8, _7, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 329 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_8)) {
		ZEPHIR_INIT_LNVAR(_0);
		object_init_ex(_0, zendframework_stdlib_priorityqueue_ce);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("events"), event, _0 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(metadata);
	array_init_size(metadata, 3);
	zephir_array_update_string(&metadata, SL("event"), &event, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, priority);
	zephir_array_update_string(&metadata, SL("priority"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(listener);
	object_init_ex(listener, zendframework_stdlib_callbackhandler_ce);
	ZEPHIR_CALL_METHOD(NULL, listener, "__construct", NULL, callback, metadata);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	zephir_array_fetch(&_11, _10, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 337 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_9);
	ZVAL_LONG(_9, priority);
	ZEPHIR_CALL_METHOD(NULL, _11, "insert", NULL, listener, _9);
	zephir_check_call_status();
	RETURN_CCTOR(listener);

}

/**
 * Attach a listener aggregate
 *
 * Listener aggregates accept an EventManagerInterface instance, and call attach()
 * one or more times, typically to attach to multiple events using local
 * methods.
 *
 * @param  ListenerAggregateInterface $aggregate
 * @param  int $priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link ListenerAggregateInterface::attach()}
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, attachAggregate) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate, *priority_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aggregate, &priority_param);

	if (!priority_param) {
		priority = 1;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	if (!(zephir_instance_of_ev(aggregate, zendframework_eventmanager_listeneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'ZendFramework\\\\EventManager\\\\ListenerAggregateInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, priority);
	ZEPHIR_CALL_METHOD(NULL, aggregate, "attach", NULL, this_ptr, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Unsubscribe a listener from an event
 *
 * @param  CallbackHandler|ListenerAggregateInterface $listener
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 * @throws Exception\InvalidArgumentException if invalid listener provided
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, detach) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *listener, *event = NULL, *events = NULL, *returns = NULL, *expected = NULL, *_0 = NULL, *_1, *_2, *_3, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &listener);



	if (!(zephir_instance_of_ev(listener, zendframework_eventmanager_listeneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'listener' must be an instance of 'ZendFramework\\\\EventManager\\\\ListenerAggregateInterface'", "", 0);
		return;
	}
	if (zephir_instance_of_ev(listener, zendframework_eventmanager_listeneraggregateinterface_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "detachaggregate", NULL, listener);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (unlikely(!(zephir_instance_of_ev(listener, zendframework_stdlib_callbackhandler_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_0);
		zephir_gettype(_0, listener TSRMLS_CC);
		ZEPHIR_CPY_WRT(expected, _0);
		if (ZEPHIR_IS_STRING(expected, "object")) {
			ZEPHIR_INIT_VAR(expected);
			zephir_get_class(expected, listener, 0 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SSVS(_1, "EventManager:detach", ": expected a ListenerAggregateInterface or CallbackHandler; received \"", expected, "\"");
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_eventmanager_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/eventmanager/eventmanager.zep", 380 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(events, _3);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "event", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&event, listener, "getmetadatum", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_4 = !zephir_is_true(event);
	if (!(_4)) {
		zephir_array_fetch(&_5, events, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 386 TSRMLS_CC);
		_4 = ZEPHIR_IS_EMPTY(_5);
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch(&_6, events, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 390 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&returns, _6, "remove", NULL, listener);
	zephir_check_call_status();
	if (!(zephir_is_true(returns))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch(&_7, events, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 395 TSRMLS_CC);
	if (!(zephir_fast_count_int(_7 TSRMLS_CC))) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		zephir_array_unset(&_3, event, PH_SEPARATE);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Detach a listener aggregate
 *
 * Listener aggregates accept an EventManagerInterface instance, and call detach()
 * of all previously attached listeners.
 *
 * @param  ListenerAggregateInterface $aggregate
 * @return mixed return value of {@link ListenerAggregateInterface::detach()}
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, detachAggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &aggregate);



	if (!(zephir_instance_of_ev(aggregate, zendframework_eventmanager_listeneraggregateinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'aggregate' must be an instance of 'ZendFramework\\\\EventManager\\\\ListenerAggregateInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, aggregate, "detach", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Retrieve all registered events
 *
 * @return array
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, getEvents) {

	zval *events = NULL, *keys, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, events TSRMLS_CC);
	RETURN_CCTOR(keys);

}

/**
 * Retrieve all listeners for a given event
 *
 * @param  string $event
 * @return PriorityQueue
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, getListeners) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *events = NULL, *exists, *_0, *_1;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(event, event_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(exists);
	ZVAL_BOOL(exists, zephir_array_key_exists(events, event TSRMLS_CC));
	if (!(zephir_is_true(exists))) {
		object_init_ex(return_value, zendframework_stdlib_priorityqueue_ce);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	zephir_array_fetch(&_1, events, event, PH_NOISY | PH_READONLY, "zendframework/eventmanager/eventmanager.zep", 447 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Clear all listeners for a given event
 *
 * @param  string $event
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, clearListeners) {

	zval *event_param = NULL, *_0, *_1;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(event, event_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (zephir_array_isset(_0, event)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
		zephir_array_unset(&_1, event, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepare arguments
 *
 * Use this method if you want to be able to modify arguments from within a
 * listener. It returns an ArrayObject of the arguments, which may then be
 * passed to trigger() or triggerUntil().
 *
 * @param  array $args
 * @return ArrayObject
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, prepareArgs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args_param = NULL;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	if (unlikely(Z_TYPE_P(args_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'args' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		args = args_param;



	object_init_ex(return_value, spl_ce_ArrayObject);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Trigger listeners
 *
 * Actual functionality for triggering listeners, to which both trigger() and triggerUntil()
 * delegate.
 *
 * @param  string           $event Event name
 * @param  EventInterface $e
 * @param  null|callable    $callback
 * @return ResponseCollection
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, triggerListeners) {

	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL, *_11 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	HashTable *_6;
	HashPosition _5;
	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *e, *callback = NULL, *responses, *listeners = NULL, *wildcardListeners = NULL, *listener = NULL, *last = NULL, *listenerCallback = NULL, *listenerCallbackResponse = NULL, *callbackResponse = NULL, *sharedListeners = NULL, *sharedWildcardListeners = NULL, *_0 = NULL, *_1 = NULL, *_4, **_7;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event_param, &e, &callback);

	zephir_get_strval(event, event_param);
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(e, zendframework_eventmanager_eventinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'e' must be an instance of 'ZendFramework\\\\EventManager\\\\EventInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(responses);
	object_init_ex(responses, zendframework_eventmanager_responsecollection_ce);
	if (zephir_has_constructor(responses TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, responses, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlisteners", NULL, event);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(listeners, _0);
	ZEPHIR_CALL_METHOD(&sharedListeners, this_ptr, "getsharedlisteners", NULL, event);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&sharedWildcardListeners, this_ptr, "getsharedlisteners", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getlisteners", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(wildcardListeners, _0);
	_2 = (zephir_fast_count_int(sharedListeners TSRMLS_CC)) ? 1 : 0;
	if (!(_2)) {
		_2 = (zephir_fast_count_int(sharedWildcardListeners TSRMLS_CC)) ? 1 : 0;
	}
	_3 = _2;
	if (!(_3)) {
		_3 = (zephir_fast_count_int(wildcardListeners TSRMLS_CC)) ? 1 : 0;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_4);
		if (zephir_clone(_4, listeners TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(listeners, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insertlisteners", NULL, listeners, sharedListeners);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insertlisteners", NULL, listeners, sharedWildcardListeners);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insertlisteners", NULL, listeners, wildcardListeners);
		zephir_check_call_status();
	}
	zephir_is_iterable(listeners, &_6, &_5, 0, 0, "zendframework/eventmanager/eventmanager.zep", 540);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(listener, _7);
		ZEPHIR_CALL_METHOD(&listenerCallback, listener, "getcallback",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&listenerCallbackResponse, "call_user_func", &_8, listenerCallback, e);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, responses, "push", &_9, listenerCallbackResponse);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, e, "propagationisstopped",  NULL);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_BOOL(_1, 1);
			ZEPHIR_CALL_METHOD(NULL, responses, "setstopped", &_10, _1);
			zephir_check_call_status();
			break;
		}
		if (zephir_is_true(callback)) {
			ZEPHIR_CALL_METHOD(&last, responses, "last",  &_11);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&callbackResponse, "call_user_func", &_8, callback, last);
			zephir_check_call_status();
			if (zephir_is_true(callbackResponse)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_BOOL(_1, 1);
				ZEPHIR_CALL_METHOD(NULL, responses, "setstopped", &_10, _1);
				zephir_check_call_status();
				break;
			}
		}
	}
	RETURN_CCTOR(responses);

}

/**
 * Get list of all listeners attached to the shared event manager for
 * identifiers registered by this instance
 *
 * @param  string $event
 * @return array
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, getSharedListeners) {

	zend_bool _5;
	HashTable *_3, *_7;
	HashPosition _2, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, *sharedManager = NULL, *id = NULL, *listeners = NULL, *listener = NULL, *identifiers = NULL, *sharedListeners, _0, *_1, **_4, **_8;
	zval *event = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(event, event_param);
	ZEPHIR_INIT_VAR(sharedListeners);
	array_init(sharedListeners);


	ZEPHIR_CALL_METHOD(&sharedManager, this_ptr, "getsharedmanager",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(sharedManager))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&identifiers, this_ptr, "getidentifiers",  NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "*", 0);
	if (!(zephir_fast_in_array(&_0, identifiers TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "*", 1);
		zephir_array_append(&identifiers, _1, PH_SEPARATE, "zendframework/eventmanager/eventmanager.zep", 562);
	}
	zephir_is_iterable(identifiers, &_3, &_2, 0, 0, "zendframework/eventmanager/eventmanager.zep", 581);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(id, _4);
		ZEPHIR_CALL_METHOD(&listeners, sharedManager, "getlisteners", NULL, id, event);
		zephir_check_call_status();
		if (!(zephir_is_true(listeners))) {
			continue;
		}
		_5 = Z_TYPE_P(listeners) != IS_ARRAY;
		if (_5) {
			_5 = !(zephir_is_instance_of(listeners, SL("Traversable") TSRMLS_CC));
		}
		if (_5) {
			continue;
		}
		zephir_is_iterable(listeners, &_7, &_6, 0, 0, "zendframework/eventmanager/eventmanager.zep", 579);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(listener, _8);
			if (!(zephir_instance_of_ev(listener, zendframework_stdlib_callbackhandler_ce TSRMLS_CC))) {
				continue;
			}
			zephir_array_append(&sharedListeners, listener, PH_SEPARATE, "zendframework/eventmanager/eventmanager.zep", 577);
		}
	}
	RETURN_CCTOR(sharedListeners);

}

/**
 * Add listeners to the master queue of listeners
 *
 * Used to inject shared listeners and wildcard listeners.
 *
 * @param  PriorityQueue $masterListeners
 * @param  PriorityQueue $listeners
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_EventManager, insertListeners) {

	zephir_fcall_cache_entry *_6 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *masterListeners, *listeners, *listener = NULL, *priority = NULL, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &masterListeners, &listeners);



	if (!(zephir_instance_of_ev(masterListeners, zendframework_stdlib_priorityqueue_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'masterListeners' must be an instance of 'ZendFramework\\\\Stdlib\\\\PriorityQueue'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(listeners, zendframework_stdlib_priorityqueue_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'listeners' must be an instance of 'ZendFramework\\\\Stdlib\\\\PriorityQueue'", "", 0);
		return;
	}
	zephir_is_iterable(listeners, &_1, &_0, 0, 0, "zendframework/eventmanager/eventmanager.zep", 610);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(listener, _2);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "priority", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&priority, listener, "getmetadatum", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		if (Z_TYPE_P(priority) == IS_NULL) {
			ZEPHIR_INIT_NVAR(priority);
			ZVAL_LONG(priority, 1);
		} else {
			if (Z_TYPE_P(priority) == IS_ARRAY) {
				Z_SET_ISREF_P(priority);
				ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_5, priority);
				Z_UNSET_ISREF_P(priority);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(priority, _4);
			}
		}
		ZEPHIR_CALL_METHOD(NULL, masterListeners, "insert", &_6, listener, priority);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

