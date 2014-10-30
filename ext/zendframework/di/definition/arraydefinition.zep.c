
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(ZendFramework_Di_Definition_ArrayDefinition) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di\\Definition, ArrayDefinition, zendframework, di_definition_arraydefinition, zendframework_di_definition_arraydefinition_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_di_definition_arraydefinition_ce, SL("dataArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_di_definition_arraydefinition_ce TSRMLS_CC, 1, zendframework_di_definition_definitioninterface_ce);
	return SUCCESS;

}

/**
 * @param array $dataArray
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, __construct) {

	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2, *_8;
	HashPosition _1, _7;
	zval *dataArray_param = NULL, *_0, *className = NULL, *type = NULL, *definition = NULL, *requirement = NULL, *methods = NULL, **_3, _4 = zval_used_for_init, *_5 = NULL, **_9;
	zval *dataArray = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dataArray_param);

	if (unlikely(Z_TYPE_P(dataArray_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dataArray' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		dataArray = dataArray_param;



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("dataArray"), _0 TSRMLS_CC);
	zephir_is_iterable(dataArray, &_2, &_1, 1, 0, "zendframework/di/definition/arraydefinition.zep", 45);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(className, _2, _1);
		ZEPHIR_GET_HVALUE(definition, _3);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 0);
		ZEPHIR_CALL_FUNCTION(&_5, "array_change_key_case", &_6, definition, &_4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(definition, _5);
		ZEPHIR_OBS_NVAR(methods);
		if (zephir_array_isset_string_fetch(&methods, definition, SS("methods"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(methods) == IS_ARRAY) {
				zephir_is_iterable(methods, &_8, &_7, 0, 0, "zendframework/di/definition/arraydefinition.zep", 41);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HMKEY(requirement, _8, _7);
					ZEPHIR_GET_HVALUE(type, _9);
					if (Z_TYPE_P(requirement) != IS_LONG) {
						ZEPHIR_CALL_CE_STATIC(&_5, zendframework_di_definition_builder_injectionmethod_ce, "detectmethodrequirement", &_10, requirement);
						zephir_check_call_status();
						zephir_array_update_multi(&definition, &_5 TSRMLS_CC, SL("sz"), 3, SL("methods"), type);
					}
				}
			}
		}
		zephir_array_update_zval(&dataArray, className, &definition, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("dataArray"), dataArray TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, getClasses) {

	zval *classes, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(classes);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	zephir_array_keys(classes, _0 TSRMLS_CC);
	RETURN_CCTOR(classes);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, hasClass) {

	zval *class_param = NULL, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_key_exists(_0, class TSRMLS_CC));

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, getClassSupertypes) {

	zval *emptyArray;
	zval *class_param = NULL, *classData, *supertypes, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);
	ZEPHIR_INIT_VAR(emptyArray);
	array_init(emptyArray);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&classData, _0, class, 1 TSRMLS_CC)) {
		if (zephir_array_isset_string_fetch(&supertypes, classData, SS("supertypes"), 1 TSRMLS_CC)) {
			RETURN_CTOR(supertypes);
		}
	}
	RETURN_CTOR(emptyArray);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, getInstantiator) {

	zval *class_param = NULL, *classData, *instantiator = NULL, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&classData, _0, class, 1 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(instantiator);
		if (!(zephir_array_isset_string_fetch(&instantiator, classData, SS("instantiator"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(instantiator);
			ZVAL_STRING(instantiator, "__construct", 1);
		}
	}
	RETURN_CCTOR(instantiator);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, hasMethods) {

	int count = 0;
	zval *class_param = NULL, *classData, *methods, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	ZEPHIR_OBS_VAR(classData);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&classData, _0, class, 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(methods);
		if (zephir_array_isset_string_fetch(&methods, classData, SS("methods"), 0 TSRMLS_CC)) {
			count = zephir_fast_count_int(methods TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(count > 0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, hasMethod) {

	zval *class_param = NULL, *method_param = NULL, *classData, *methods, *_0;
	zval *class = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_param, &method_param);

	zephir_get_strval(class, class_param);
	zephir_get_strval(method, method_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&classData, _0, class, 1 TSRMLS_CC)) {
		if (zephir_array_isset_string_fetch(&methods, classData, SS("methods"), 1 TSRMLS_CC)) {
			if (zephir_array_isset(methods, method)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, getMethods) {

	zval *emptyArray;
	zval *class_param = NULL, *classData, *methods, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);
	ZEPHIR_INIT_VAR(emptyArray);
	array_init(emptyArray);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&classData, _0, class, 1 TSRMLS_CC)) {
		if (zephir_array_isset_string_fetch(&methods, classData, SS("methods"), 1 TSRMLS_CC)) {
			RETURN_CTOR(methods);
		}
	}
	RETURN_CTOR(emptyArray);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, hasMethodParameters) {

	zval *class_param = NULL, *method_param = NULL, *_0, *_1, *_2;
	zval *class = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_param, &method_param);

	zephir_get_strval(class, class_param);
	zephir_get_strval(method, method_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, class, PH_NOISY | PH_READONLY, "zendframework/di/definition/arraydefinition.zep", 154 TSRMLS_CC);
	zephir_array_fetch_string(&_2, _1, SL("parameters"), PH_READONLY, "zendframework/di/definition/arraydefinition.zep", 154 TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, method));

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, getMethodParameters) {

	zval *emptyArray;
	zval *class_param = NULL, *method_param = NULL, *params, *classParams, *methodParams, *_0;
	zval *class = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_param, &method_param);

	zephir_get_strval(class, class_param);
	zephir_get_strval(method, method_param);
	ZEPHIR_INIT_VAR(emptyArray);
	array_init(emptyArray);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dataArray"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&params, _0, class, 1 TSRMLS_CC)) {
		if (zephir_array_isset_string_fetch(&classParams, params, SS("parameters"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_fetch(&methodParams, classParams, method, 1 TSRMLS_CC)) {
				RETURN_CTOR(methodParams);
			}
		}
	}
	RETURN_CTOR(emptyArray);

}

/**
 * @return array
 */
PHP_METHOD(ZendFramework_Di_Definition_ArrayDefinition, toArray) {


	RETURN_MEMBER(this_ptr, "dataArray");

}

