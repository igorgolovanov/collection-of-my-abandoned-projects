
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(ZendFramework_Config_AbstractConfigFactory) {

	ZEPHIR_REGISTER_CLASS(Zend\\Config, AbstractConfigFactory, zendframework, config_abstractconfigfactory, zendframework_config_abstractconfigfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_config_abstractconfigfactory_ce, SL("configs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string[]
	 */
	zend_declare_property_null(zendframework_config_abstractconfigfactory_ce, SL("defaultPatterns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string[]
	 */
	zend_declare_property_null(zendframework_config_abstractconfigfactory_ce, SL("patterns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_config_abstractconfigfactory_ce TSRMLS_CC, 1, zendframework_servicemanager_abstractfactoryinterface_ce);
	return SUCCESS;

}

/**
 * Determine if we can create a service with name
 *
 * @param ServiceLocatorInterface $serviceLocator
 * @param string $name
 * @param string $requestedName
 * @return bool
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, canCreateServiceWithName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *requestedName = NULL;
	zval *serviceLocator, *name_param = NULL, *requestedName_param = NULL, *key = NULL, *config = NULL, *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &serviceLocator, &name_param, &requestedName_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(requestedName, requestedName_param);


	if (!(zephir_instance_of_ev(serviceLocator, zendframework_servicemanager_servicelocatorinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'serviceLocator' must be an instance of 'ZendFramework\\\\ServiceManager\\\\ServiceLocatorInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	if (zephir_array_isset(_0, requestedName)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, serviceLocator, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&key, this_ptr, "match", NULL, requestedName);
	zephir_check_call_status();
	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "Config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, serviceLocator, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(config, key));

}

/**
 * Create service with name
 *
 * @param ServiceLocatorInterface $serviceLocator
 * @param string $name
 * @param string $requestedName
 * @return string|mixed|array
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, createServiceWithName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *requestedName = NULL;
	zval *serviceLocator, *name_param = NULL, *requestedName_param = NULL, *config = NULL, *key = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &serviceLocator, &name_param, &requestedName_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(requestedName, requestedName_param);


	if (!(zephir_instance_of_ev(serviceLocator, zendframework_servicemanager_servicelocatorinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'serviceLocator' must be an instance of 'ZendFramework\\\\ServiceManager\\\\ServiceLocatorInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(config);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&config, _0, requestedName, 0 TSRMLS_CC)) {
		RETURN_CCTOR(config);
	}
	ZEPHIR_CALL_METHOD(&key, this_ptr, "match", NULL, requestedName);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(config);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&config, _1, key, 0 TSRMLS_CC)) {
		zephir_update_property_array(this_ptr, SL("configs"), requestedName, config TSRMLS_CC);
		RETURN_CCTOR(config);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "Config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, serviceLocator, "get", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("configs"), requestedName, config TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("configs"), key, config TSRMLS_CC);
	RETURN_CCTOR(config);

}

/**
 * @param string $pattern
 * @return self
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, addPattern) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pattern, *patterns = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern);



	if (unlikely(Z_TYPE_P(pattern) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_config_exception_invalidargumentexception_ce, "pattern must be string", "zendframework/config/abstractconfigfactory.zep", 108);
		return;
	}
	ZEPHIR_CALL_METHOD(&patterns, this_ptr, "getpatterns",  NULL);
	zephir_check_call_status();
	Z_SET_ISREF_P(patterns);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_0, patterns, pattern);
	Z_UNSET_ISREF_P(patterns);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpatterns", NULL, patterns);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * @param array|Traversable $patterns
 * @return self
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, addPatterns) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *patterns = NULL, *pattern = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &patterns);

	ZEPHIR_SEPARATE_PARAM(patterns);


	if (zephir_is_instance_of(patterns, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, patterns);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(patterns, _0);
	}
	if (unlikely(Z_TYPE_P(patterns) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_config_exception_invalidargumentexception_ce, "patterns must be array or Traversable", "zendframework/config/abstractconfigfactory.zep", 133);
		return;
	}
	zephir_is_iterable(patterns, &_2, &_1, 0, 0, "zendframework/config/abstractconfigfactory.zep", 139);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(pattern, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addpattern", &_4, pattern);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * @param array|Traversable $patterns
 * @return self
 * @throws \InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, setPatterns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *patterns = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &patterns);

	ZEPHIR_SEPARATE_PARAM(patterns);


	if (zephir_is_instance_of(patterns, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, patterns);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(patterns, _0);
	}
	if (unlikely(Z_TYPE_P(patterns) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_config_exception_invalidargumentexception_ce, "patterns must be array or Traversable", "zendframework/config/abstractconfigfactory.zep", 155);
		return;
	}
	zephir_update_property_this(this_ptr, SL("patterns"), patterns TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return array
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, getPatterns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("patterns"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("defaultPatterns"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpatterns", NULL, _1);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "patterns");

}

/**
 * @param string $requestedName
 * @return null|string
 */
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, match) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *requestedName_param = NULL, *patterns = NULL, *pattern = NULL, *matches, **_2, *_3 = NULL, *_5;
	zval *requestedName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestedName_param);

	zephir_get_strval(requestedName, requestedName_param);
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	ZEPHIR_CALL_METHOD(&patterns, this_ptr, "getpatterns",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(patterns, &_1, &_0, 0, 0, "zendframework/config/abstractconfigfactory.zep", 187);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(pattern, _2);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, pattern, requestedName, matches);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			zephir_array_fetch_long(&_5, matches, 1, PH_NOISY | PH_READONLY, "zendframework/config/abstractconfigfactory.zep", 184 TSRMLS_CC);
			RETURN_CTOR(_5);
		}
	}
	RETURN_MM_NULL();

}

PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, __construct) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "#config[\._-](.*)$#i", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "#^(.*)[\\\\\._-]config$#i", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("defaultPatterns"), _0 TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("configs"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

