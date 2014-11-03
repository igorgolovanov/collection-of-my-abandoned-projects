
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory) {

	ZEPHIR_REGISTER_CLASS(Zend\\Code\\Generic\\Prototype, PrototypeClassFactory, zendframework, code_generic_prototype_prototypeclassfactory, zendframework_code_generic_prototype_prototypeclassfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_code_generic_prototype_prototypeclassfactory_ce, SL("prototypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var PrototypeGenericInterface
	 */
	zend_declare_property_null(zendframework_code_generic_prototype_prototypeclassfactory_ce, SL("genericPrototype"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param PrototypeInterface[] $prototypes
 * @param PrototypeGenericInterface $genericPrototype
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, __construct) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zend_bool _0;
	zval *prototypes = NULL, *genericPrototype = NULL, *_1, *prototype = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prototypes, &genericPrototype);

	if (!prototypes) {
		ZEPHIR_INIT_VAR(prototypes);
		array_init(prototypes);
	} else {
		ZEPHIR_SEPARATE_PARAM(prototypes);
	}
	if (!genericPrototype) {
		genericPrototype = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(genericPrototype) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(genericPrototype, zendframework_code_generic_prototype_prototypegenericinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'genericPrototype' must be an instance of 'ZendFramework\\\\Code\\\\Generic\\\\Prototype\\\\PrototypeGenericInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("prototypes"), _1 TSRMLS_CC);
	if (Z_TYPE_P(prototypes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(prototypes);
		array_init_size(prototypes, 2);
		zephir_array_fast_append(prototypes, prototypes);
	}
	zephir_is_iterable(prototypes, &_3, &_2, 0, 0, "zendframework/code/generic/prototype/prototypeclassfactory.zep", 53);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(prototype, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addprototype", &_5, prototype);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(genericPrototype) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setgenericprototype", NULL, genericPrototype);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param PrototypeInterface $prototype
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, addPrototype) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *prototype, *normalized = NULL, *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prototype);



	if (!(zephir_instance_of_ev(prototype, zendframework_code_generic_prototype_prototypeinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'prototype' must be an instance of 'ZendFramework\\\\Code\\\\Generic\\\\Prototype\\\\PrototypeInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&name, prototype, "getname",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&normalized, this_ptr, "normalizename", NULL, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prototypes"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_0, normalized))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_code_reflection_exception_invalidargumentexception_ce, "A prototype with this name already exists in this manager", "zendframework/code/generic/prototype/prototypeclassfactory.zep", 70);
		return;
	}
	zephir_update_property_array(this_ptr, SL("prototypes"), normalized, prototype TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param PrototypeGenericInterface $prototype
 * @throws Exception\InvalidArgumentException
 * @return PrototypeClassFactory
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, setGenericPrototype) {

	zval *prototype, *_0;

	zephir_fetch_params(0, 1, 0, &prototype);



	if (!(zephir_instance_of_ev(prototype, zendframework_code_generic_prototype_prototypegenericinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'prototype' must be an instance of 'ZendFramework\\\\Code\\\\Generic\\\\Prototype\\\\PrototypeGenericInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("genericPrototype"), PH_NOISY_CC);
	if (unlikely(!ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zendframework_code_reflection_exception_invalidargumentexception_ce, "A default prototype is already set", "zendframework/code/generic/prototype/prototypeclassfactory.zep", 86);
		return;
	}
	zephir_update_property_this(this_ptr, SL("genericPrototype"), prototype TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @param string $name
 * @return string
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, normalizeName) {

	zval *chars;
	zval *name_param = NULL, *normalized, _0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);
	ZEPHIR_INIT_VAR(chars);
	array_init(chars);


	ZEPHIR_INIT_VAR(normalized);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "", 0);
	zephir_fast_str_replace(normalized, chars, &_0, name);
	RETURN_CCTOR(normalized);

}

/**
 * @param string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, hasPrototype) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *normalized = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&normalized, this_ptr, "normalizename", NULL, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prototypes"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, normalized));

}

/**
 * @param  string $prototypeName
 * @return PrototypeInterface
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeClassFactory, getClonedPrototype) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prototypeName_param = NULL, *normalized = NULL, *prototype, *prototypeBase = NULL, *_0 = NULL, *_2, *_3 = NULL, *_4, *_5;
	zval *prototypeName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prototypeName_param);

	zephir_get_strval(prototypeName, prototypeName_param);


	ZEPHIR_CALL_METHOD(&normalized, this_ptr, "normalizename", NULL, prototypeName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasprototype", NULL, normalized);
	zephir_check_call_status();
	_1 = !zephir_is_true(_0);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("genericPrototype"), PH_NOISY_CC);
		_1 = ZEPHIR_IS_EMPTY(_2);
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_code_reflection_exception_runtimeexception_ce, "This tag name is not supported by this tag manager", "zendframework/code/generic/prototype/prototypeclassfactory.zep", 133);
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "hasprototype", NULL, normalized);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(prototypeBase);
	ZEPHIR_INIT_VAR(prototype);
	if (!(zephir_is_true(_3))) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("genericPrototype"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(prototypeBase, _4);
		if (zephir_clone(prototype, prototypeBase TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(NULL, prototype, "setname", NULL, normalized);
		zephir_check_call_status();
	} else {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("prototypes"), PH_NOISY_CC);
		zephir_array_fetch(&_5, _4, normalized, PH_NOISY | PH_READONLY, "zendframework/code/generic/prototype/prototypeclassfactory.zep", 142 TSRMLS_CC);
		ZEPHIR_CPY_WRT(prototypeBase, _5);
		if (zephir_clone(prototype, prototypeBase TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
	}
	RETURN_CCTOR(prototype);

}

