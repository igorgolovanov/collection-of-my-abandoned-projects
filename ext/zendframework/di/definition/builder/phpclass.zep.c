
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
#include "kernel/exception.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(ZendFramework_Di_Definition_Builder_PhpClass) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di\\Definition\\Builder, PhpClass, zendframework, di_definition_builder_phpclass, zendframework_di_definition_builder_phpclass_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(zendframework_di_definition_builder_phpclass_ce, SL("defaultMethodBuilder"), "Zend\\Di\\Definition\\Builder\\InjectionMethod", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null|string
	 */
	zend_declare_property_null(zendframework_di_definition_builder_phpclass_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|\Callable|array
	 */
	zend_declare_property_string(zendframework_di_definition_builder_phpclass_ce, SL("instantiator"), "__construct", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var InjectionMethod[]
	 */
	zend_declare_property_null(zendframework_di_definition_builder_phpclass_ce, SL("injectionMethods"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_di_definition_builder_phpclass_ce, SL("superTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set name
 *
 * @param  string   $name
 * @return PhpClass
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, setName) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get name
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * @param  string|\Callable|array $instantiator
 * @return PhpClass
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, setInstantiator) {

	zval *instantiator;

	zephir_fetch_params(0, 1, 0, &instantiator);



	zephir_update_property_this(this_ptr, SL("instantiator"), instantiator TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @return array|\Callable|string
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, getInstantiator) {


	RETURN_MEMBER(this_ptr, "instantiator");

}

/**
 * @param  string   $superType
 * @return PhpClass
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, addSuperType) {

	zval *superType_param = NULL;
	zval *superType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &superType_param);

	zephir_get_strval(superType, superType_param);


	zephir_update_property_array_append(this_ptr, SL("superTypes"), superType TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get super types
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, getSuperTypes) {


	RETURN_MEMBER(this_ptr, "superTypes");

}

/**
 * Add injection method
 *
 * @param  InjectionMethod $injectionMethod
 * @return PhpClass
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, addInjectionMethod) {

	zval *injectionMethod;

	zephir_fetch_params(0, 1, 0, &injectionMethod);



	if (!(zephir_instance_of_ev(injectionMethod, zendframework_di_definition_builder_injectionmethod_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'injectionMethod' must be an instance of 'ZendFramework\\Di\\Definition\\Builder\\InjectionMethod'", "", 0);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("injectionMethods"), injectionMethod TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Create and register an injection method
 *
 * Optionally takes the method name.
 *
 * This method may be used in lieu of addInjectionMethod() in
 * order to provide a more fluent interface for building classes with
 * injection methods.
 *
 * @param  null|string     $name
 * @return InjectionMethod
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, createInjectionMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3;
	zval *name_param = NULL, *method, *_0, *_2 = NULL;
	zval *name = NULL, *builder = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("defaultMethodBuilder"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(builder, _1);
	ZEPHIR_INIT_VAR(method);
	zephir_fetch_safe_class(_2, builder);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(method, _3);
	if (zephir_has_constructor(method TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, method, "__construct", NULL);
		zephir_check_call_status();
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		ZEPHIR_CALL_METHOD(NULL, method, "setname", NULL, name);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinjectionmethod", NULL, method);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Override which class will be used by {@link createInjectionMethod()}
 *
 * @param  string   $class
 * @return PhpClass
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, setMethodBuilder) {

	zval *className_param = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	zephir_update_property_this(this_ptr, SL("defaultMethodBuilder"), className TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Determine what class will be used by {@link createInjectionMethod()}
 *
 * Mainly to provide the ability to temporarily override the class used.
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, getMethodBuilder) {


	RETURN_MEMBER(this_ptr, "defaultMethodBuilder");

}

/**
 * @return InjectionMethod[]
 */
PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, getInjectionMethods) {


	RETURN_MEMBER(this_ptr, "injectionMethods");

}

PHP_METHOD(ZendFramework_Di_Definition_Builder_PhpClass, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("superTypes"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("injectionMethods"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

