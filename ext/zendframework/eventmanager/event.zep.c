
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_Event) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, Event, zendframework, eventmanager_event, zendframework_eventmanager_event_method_entry, 0);

	/**
	 * @var string Event name
	 */
	zend_declare_property_null(zendframework_eventmanager_event_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|object The event target
	 */
	zend_declare_property_null(zendframework_eventmanager_event_ce, SL("target"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array|ArrayAccess|object The event parameters
	 */
	zend_declare_property_null(zendframework_eventmanager_event_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool Whether or not to stop propagation
	 */
	zend_declare_property_bool(zendframework_eventmanager_event_ce, SL("stopPropagation"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_event_ce TSRMLS_CC, 1, zendframework_eventmanager_eventinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Accept a target and its parameters.
 *
 * @param  string $name Event name
 * @param  string|object $target
 * @param  array|ArrayAccess $params
 */
PHP_METHOD(ZendFramework_EventManager_Event, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *target = NULL, *params = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &name_param, &target, &params);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!target) {
		target = ZEPHIR_GLOBAL(global_null);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("params"), _0 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(name))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, name);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(target) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "settarget", NULL, target);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(params) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparams", NULL, params);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get event name
 *
 * @return string
 */
PHP_METHOD(ZendFramework_EventManager_Event, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * Get the event target
 *
 * This may be either an object, or the name of a static method.
 *
 * @return string|object
 */
PHP_METHOD(ZendFramework_EventManager_Event, getTarget) {


	RETURN_MEMBER(this_ptr, "target");

}

/**
 * Set parameters
 *
 * Overwrites parameters
 *
 * @param  array|ArrayAccess|object $params
 * @return Event
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_EventManager_Event, setParams) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *type = NULL, *exceptionMsg = NULL;
	zval *params, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params);



	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, params TSRMLS_CC);
	zephir_get_strval(type, _0);
	_1 = !ZEPHIR_IS_STRING(type, "array");
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(type, "object");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Event parameters must be an array or object; received \"", type, "\"");
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_eventmanager_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/eventmanager/event.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get all parameters
 *
 * @return array|object|ArrayAccess
 */
PHP_METHOD(ZendFramework_EventManager_Event, getParams) {


	RETURN_MEMBER(this_ptr, "params");

}

/**
 * Get an individual parameter
 *
 * If the parameter does not exist, the $default value will be returned.
 *
 * @param  string|int $name
 * @param  mixed $default
 * @return mixed
 */
PHP_METHOD(ZendFramework_EventManager_Event, getParam) {

	zend_bool _1;
	zval *name, *default = NULL, *params = NULL, *item, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &default);

	if (!default) {
		default = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(params, _0);
	_1 = Z_TYPE_P(params) == IS_ARRAY;
	if (!(_1)) {
		_1 = zephir_is_instance_of(params, SL("ArrayAccess") TSRMLS_CC);
	}
	if (_1) {
		if (zephir_array_isset_fetch(&item, params, name, 1 TSRMLS_CC)) {
			RETURN_CTOR(item);
		}
		RETVAL_ZVAL(default, 1, 0);
		RETURN_MM();
	}
	if (zephir_isset_property_zval(params, name TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_zval(&_2, params, name, PH_NOISY_CC);
		RETURN_CCTOR(_2);
	}
	RETVAL_ZVAL(default, 1, 0);
	RETURN_MM();

}

/**
 * Set the event name
 *
 * @param  string $name
 * @return Event
 */
PHP_METHOD(ZendFramework_EventManager_Event, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Set the event target/context
 *
 * @param  null|string|object $target
 * @return Event
 */
PHP_METHOD(ZendFramework_EventManager_Event, setTarget) {

	zval *target;

	zephir_fetch_params(0, 1, 0, &target);



	zephir_update_property_this(this_ptr, SL("target"), target TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set an individual parameter to a value
 *
 * @param  string|int $name
 * @param  mixed $value
 * @return Event
 */
PHP_METHOD(ZendFramework_EventManager_Event, setParam) {

	zend_bool _1;
	zval *name, *value, *params = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(params, _0);
	_1 = Z_TYPE_P(params) == IS_ARRAY;
	if (!(_1)) {
		_1 = zephir_is_instance_of(params, SL("ArrayAccess") TSRMLS_CC);
	}
	if (_1) {
		zephir_update_property_array(this_ptr, SL("params"), name, value TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(params, name, value TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Stop further event propagation
 *
 * @param  bool $flag
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_Event, stopPropagation) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	zephir_update_property_this(this_ptr, SL("stopPropagation"), flag ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Is propagation stopped?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_Event, propagationIsStopped) {


	RETURN_MEMBER(this_ptr, "stopPropagation");

}

