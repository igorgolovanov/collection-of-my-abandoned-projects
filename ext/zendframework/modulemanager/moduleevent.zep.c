
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Custom event for use with module manager
 * Composes Module objects
 */
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_ModuleEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\ModuleManager, ModuleEvent, zendframework, modulemanager_moduleevent, zendframework_eventmanager_event_ce, zendframework_modulemanager_moduleevent_method_entry, 0);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zendframework_modulemanager_moduleevent_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(zendframework_modulemanager_moduleevent_ce, SL("moduleName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Listener\ConfigMergerInterface
	 */
	zend_declare_property_null(zendframework_modulemanager_moduleevent_ce, SL("configListener"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Module events triggered by eventmanager
	 */
	zend_declare_class_constant_string(zendframework_modulemanager_moduleevent_ce, SL("EVENT_MERGE_CONFIG"), "mergeConfig" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_modulemanager_moduleevent_ce, SL("EVENT_LOAD_MODULES"), "loadModules" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_modulemanager_moduleevent_ce, SL("EVENT_LOAD_MODULE_RESOLVE"), "loadModule.resolve" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_modulemanager_moduleevent_ce, SL("EVENT_LOAD_MODULE"), "loadModule" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_modulemanager_moduleevent_ce, SL("EVENT_LOAD_MODULES_POST"), "loadModules.post" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get the name of a given module
 *
 * @return string
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getModuleName) {


	RETURN_MEMBER(this_ptr, "moduleName");

}

/**
 * Set the name of a given module
 *
 * @param  string $moduleName
 * @throws Exception\InvalidArgumentException
 * @return ModuleEvent
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setModuleName) {

	zval *moduleName_param = NULL;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (unlikely(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(moduleName);
		ZVAL_EMPTY_STRING(moduleName);
	}


	zephir_update_property_this(this_ptr, SL("moduleName"), moduleName TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get module object
 *
 * @return null|object
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getModule) {


	RETURN_MEMBER(this_ptr, "module");

}

/**
 * Set module object to compose in this event
 *
 * @param  object $module
 * @throws Exception\InvalidArgumentException
 * @return ModuleEvent
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setModule) {

	zval *module;

	zephir_fetch_params(0, 1, 0, &module);

	if (unlikely(Z_TYPE_P(module) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be an object") TSRMLS_CC);
		RETURN_NULL();
	}



	zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get the config listener
 *
 * @return null|Listener\ConfigMergerInterface
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getConfigListener) {


	RETURN_MEMBER(this_ptr, "configListener");

}

/**
 * Set module object to compose in this event
 *
 * @param  Listener\ConfigMergerInterface $configListener
 * @return ModuleEvent
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setConfigListener) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *configListener, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configListener);



	if (!(zephir_instance_of_ev(configListener, zendframework_modulemanager_listener_configmergerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'configListener' must be an instance of 'ZendFramework\\\\ModuleManager\\\\Listener\\\\ConfigMergerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "configListener", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setparam", NULL, _0, configListener);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("configListener"), configListener TSRMLS_CC);
	RETURN_THIS();

}

