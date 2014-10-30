
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "Zend/zend_closures.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(ZendFramework_Di_ServiceLocator) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di, ServiceLocator, zendframework, di_servicelocator, zendframework_di_servicelocator_method_entry, 0);

	/**
	 * Map of service names to methods
	 *
	 * As an example, you might define a getter method "getFoo", and map it to
	 * the service name "foo":
	 *
	 * <code>
	 * protected $map = array('foo' => 'getFoo');
	 * </code>
	 *
	 * When encountered, the return value of that method will be used.
	 *
	 * Methods mapped in this way may expect a single, array argument, the
	 * $params passed to {@link get()}, if any.
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_di_servicelocator_ce, SL("map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Registered services and cached values
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_di_servicelocator_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_di_servicelocator_ce TSRMLS_CC, 1, zendframework_di_servicelocatorinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_ServiceLocator, set) {

	zval *name_param = NULL, *service;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &service);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Retrieve a registered service
 *
 * Tests first if a value is registered for the service, and, if so,
 * returns it.
 *
 * If the value returned is a non-object callback or closure, the return
 * value is retrieved, stored, and returned. Parameters passed to the method
 * are passed to the callback, but only on the first retrieval.
 *
 * If the service requested matches a method in the method map, the return
 * value of that method is returned. Parameters are passed to the matching
 * method.
 *
 * @param  string $name
 * @param  array  $params
 * @return mixed
 */
PHP_METHOD(ZendFramework_Di_ServiceLocator, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1, _2;
	zval *params = NULL;
	zval *name_param = NULL, *params_param = NULL, *service = NULL, *method, *_0, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &params_param);

	zephir_get_strval(name, name_param);
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


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		_1 = zephir_instance_of_ev(service, zend_ce_closure TSRMLS_CC);
		if (!(_1)) {
			_2 = Z_TYPE_P(service) != IS_OBJECT;
			if (_2) {
				_2 = zephir_is_callable(service TSRMLS_CC);
			}
			_1 = _2;
		}
		if (_1) {
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_3, service, params);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(service, _3);
			zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
		}
		RETURN_CCTOR(service);
	}
	ZEPHIR_OBS_VAR(method);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&method, _4, name, 0 TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, Z_STRVAL_P(method), NULL, params);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(ZendFramework_Di_ServiceLocator, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("services"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("map"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

