
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(ZendFramework_Di_Definition_Builder_InjectionMethod) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di\\Definition\\Builder, InjectionMethod, zendframework, di_definition_builder_injectionmethod, zendframework_di_definition_builder_injectionmethod_method_entry, 0);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(zendframework_di_definition_builder_injectionmethod_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_di_definition_builder_injectionmethod_ce, SL("parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param  string|null $name
 * @return InjectionMethod
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return null|string
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * @param  string          $name
 * @param  string|null     $class
 * @param  mixed|null      $isRequired
 * @param  mixed|null      $default
 * @return InjectionMethod
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, addParameter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *class = NULL, *isRequired = NULL, *defaultVal = NULL, *param, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &name_param, &class, &isRequired, &defaultVal);

	zephir_get_strval(name, name_param);
	if (!class) {
		class = ZEPHIR_GLOBAL(global_null);
	}
	if (!isRequired) {
		isRequired = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(param);
	array_init(param);


	zephir_array_append(&param, name, PH_SEPARATE, "zendframework/di/definition/builder/injectionmethod.zep", 58);
	zephir_array_append(&param, class, PH_SEPARATE, "zendframework/di/definition/builder/injectionmethod.zep", 59);
	ZEPHIR_CALL_SELF(&_0, "detectmethodrequirement", NULL, isRequired);
	zephir_check_call_status();
	zephir_array_append(&param, _0, PH_SEPARATE, "zendframework/di/definition/builder/injectionmethod.zep", 60);
	zephir_array_append(&param, defaultVal, PH_SEPARATE, "zendframework/di/definition/builder/injectionmethod.zep", 61);
	zephir_update_property_array_append(this_ptr, SL("parameters"), param TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return array
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, getParameters) {


	RETURN_MEMBER(this_ptr, "parameters");

}

/**
 *
 * @param mixed $requirement
 * @return int
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, detectMethodRequirement) {

	zval *type = NULL, *req = NULL;
	int result = 0;
	zval *requirement, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requirement);



	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, requirement TSRMLS_CC);
	zephir_get_strval(type, _0);
	if (ZEPHIR_IS_STRING(type, "boolean")) {
		if (zephir_is_true(requirement)) {
			RETURN_MM_LONG(3);
		}
		RETURN_MM_LONG(0);
	}
	if (Z_TYPE_P(requirement) == IS_NULL) {
		RETURN_MM_LONG(3);
	}
	if (ZEPHIR_IS_STRING(type, "integer")) {
		RETVAL_ZVAL(requirement, 1, 0);
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "string")) {
		ZEPHIR_INIT_VAR(req);
		zephir_fast_strtolower(req, requirement);
		do {
			if (ZEPHIR_IS_STRING(req, "eager")) {
				result = 1;
				break;
			}
			if (ZEPHIR_IS_STRING(req, "instantiator")) {
				result = 3;
				break;
			}
			if (ZEPHIR_IS_STRING(req, "constructor")) {
				result = 3;
				break;
			}
			if (ZEPHIR_IS_STRING(req, "optional")) {
				result = 0;
				break;
			}
			if (ZEPHIR_IS_STRING(req, "aware")) {
				result = 1;
				break;
			}
			result = 3;
		} while(0);

	}
	RETURN_MM_LONG(result);

}

PHP_METHOD(ZendFramework_Di_Definition_Builder_InjectionMethod, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("parameters"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

