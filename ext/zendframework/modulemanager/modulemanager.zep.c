
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_ModuleManager) {

	ZEPHIR_REGISTER_CLASS(Zend\\ModuleManager, ModuleManager, zendframework, modulemanager_modulemanager, zendframework_modulemanager_modulemanager_method_entry, 0);

	/**
	 * @var array An array of Module classes of loaded modules
	 */
	zend_declare_property_null(zendframework_modulemanager_modulemanager_ce, SL("loadedModules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var EventManagerInterface
	 */
	zend_declare_property_null(zendframework_modulemanager_modulemanager_ce, SL("events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var ModuleEvent
	 */
	zend_declare_property_null(zendframework_modulemanager_modulemanager_ce, SL("event"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(zendframework_modulemanager_modulemanager_ce, SL("loadFinished"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * modules
	 *
	 * @var array|Traversable
	 */
	zend_declare_property_null(zendframework_modulemanager_modulemanager_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * True if modules have already been loaded
	 *
	 * @var bool
	 */
	zend_declare_property_bool(zendframework_modulemanager_modulemanager_ce, SL("modulesAreLoaded"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_modulemanager_modulemanager_ce TSRMLS_CC, 1, zendframework_modulemanager_modulemanagerinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param  array|Traversable $modules
 * @param  EventManagerInterface $eventManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *modules, *eventManager = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &modules, &eventManager);

	if (!eventManager) {
		eventManager = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(eventManager) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(eventManager, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventManager' must be an instance of 'ZendFramework\\EventManager\\EventManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("modules"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("loadedModules"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodules", NULL, modules);
	zephir_check_call_status();
	if (Z_TYPE_P(eventManager) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventmanager", NULL, eventManager);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handle the loadModules event
 *
 * @return void
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, onLoadModules) {

	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *modules = NULL, *moduleName = NULL, *module = NULL, *className = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modulesAreLoaded"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&modules, this_ptr, "getmodules", NULL);
	zephir_check_call_status();
	zephir_is_iterable(modules, &_2, &_1, 0, 0, "zendframework/modulemanager/modulemanager.zep", 97);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HKEY(moduleName, _2, _1);
		ZEPHIR_GET_HVALUE(module, _3);
		if (Z_TYPE_P(module) == IS_OBJECT) {
			if (unlikely(Z_TYPE_P(moduleName) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(className);
				zephir_get_class(className, module, 0 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Module (", className, ") must have a key identifier.");
				zephir_get_strval(exceptionMsg, _4);
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, zendframework_modulemanager_exception_runtimeexception_ce);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_6, exceptionMsg);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "zendframework/modulemanager/modulemanager.zep", 91 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(module);
			array_init_size(module, 2);
			zephir_array_update_zval(&module, moduleName, &module, PH_COPY);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadmodule", &_7, module);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("modulesAreLoaded"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Load the provided modules.
 *
 * @triggers loadModules
 * @triggers loadModules.post
 * @return   ModuleManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModules) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *events = NULL, *event = NULL, *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modulesAreLoaded"), PH_NOISY_CC);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "geteventmanager", NULL);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(events, _1);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getevent", NULL);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(event, _1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "loadModules", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, events, "trigger", NULL, _2, this_ptr, event);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getevent", NULL);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(event, _1);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "loadModules.post", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, events, "trigger", NULL, _2, this_ptr, event);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Load a specific module by name.
 *
 * @param  string|array               $module
 * @throws Exception\RuntimeException
 * @triggers loadModule.resolve
 * @triggers loadModule
 * @return mixed Module's Module class
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *module = NULL, *moduleName = NULL, *moduleClass, *event = NULL, *events = NULL, *_1 = NULL, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module);

	ZEPHIR_SEPARATE_PARAM(module);


	if (Z_TYPE_P(module) == IS_ARRAY) {
		Z_SET_ISREF_P(module);
		ZEPHIR_CALL_FUNCTION(&moduleName, "key", &_0, module);
		Z_UNSET_ISREF_P(module);
		zephir_check_call_status();
		Z_SET_ISREF_P(module);
		ZEPHIR_CALL_FUNCTION(&_1, "current", &_2, module);
		Z_UNSET_ISREF_P(module);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(module, _1);
	} else {
		ZEPHIR_CPY_WRT(moduleName, module);
	}
	ZEPHIR_OBS_VAR(moduleClass);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("loadedModules"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&moduleClass, _3, moduleName, 0 TSRMLS_CC)) {
		RETURN_CCTOR(moduleClass);
	}
	if (!(zephir_isset_property(this_ptr, SS("loadFinished") TSRMLS_CC))) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_LONG(_4, 0);
		zephir_update_property_this(this_ptr, SL("loadFinished"), _4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getevent", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(event, _1);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("loadFinished"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_4, 0)) {
		ZEPHIR_INIT_VAR(_5);
		if (zephir_clone(_5, event TSRMLS_CC) == FAILURE) {
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(event, _5);
	}
	ZEPHIR_CALL_METHOD(NULL, event, "setmodulename", NULL, moduleName);
	zephir_check_call_status();
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("loadFinished") TSRMLS_CC));
	if (Z_TYPE_P(module) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&module, this_ptr, "loadmodulebyname", NULL, event);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, event, "setmodule", NULL, module);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("loadedModules"), moduleName, module TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "geteventmanager", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _1);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "loadModule", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, events, "trigger", NULL, _6, this_ptr, event);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("loadFinished") TSRMLS_CC));
	RETVAL_ZVAL(module, 1, 0);
	RETURN_MM();

}

/**
 * Load a module with the name
 * @param  \Zend\EventManager\EventInterface $event
 * @return mixed                            module instance
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModuleByName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *event, *events = NULL, *result = NULL, *module = NULL, *moduleName = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	if (!(zephir_instance_of_ev(event, zendframework_eventmanager_eventinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'ZendFramework\\EventManager\\EventInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geteventmanager", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadModule.resolve", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "is_object", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&result, events, "trigger", NULL, _1, this_ptr, event, _2);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, result, "last", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(module, _0);
	if (unlikely(Z_TYPE_P(module) != IS_OBJECT)) {
		ZEPHIR_CALL_METHOD(&moduleName, event, "getmodulename", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Module (", moduleName, ") could not be initialized.");
		zephir_get_strval(exceptionMsg, _3);
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, zendframework_modulemanager_exception_runtimeexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/modulemanager/modulemanager.zep", 208 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(module);

}

/**
 * Get an array of the loaded modules.
 *
 * @param  bool  $loadModules If true, load modules if they're not already
 * @return array An array of Module objects, keyed by module name
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getLoadedModules) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *loadModules_param = NULL;
	zend_bool loadModules;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &loadModules_param);

	if (!loadModules_param) {
		loadModules = 0;
	} else {
		loadModules = zephir_get_boolval(loadModules_param);
	}


	if (loadModules) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadmodules", NULL);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "loadedModules");

}

/**
 * Get an instance of a module class by the module name
 *
 * @param  string $moduleName
 * @return mixed
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getModule) {

	zval *moduleName_param = NULL, *module, *_0;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("loadedModules"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&module, _0, moduleName, 1 TSRMLS_CC)) {
		RETURN_CTOR(module);
	}
	RETURN_MM_NULL();

}

/**
 * Get the array of module names that this manager should load.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getModules) {


	RETURN_MEMBER(this_ptr, "modules");

}

/**
 * Set an array or Traversable of module names that this module manager should load.
 *
 * @param  mixed $modules array or Traversable of module names
 * @throws Exception\InvalidArgumentException
 * @return ModuleManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setModules) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *exceptionMsg = NULL;
	zval *modules, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules);



	_0 = Z_TYPE_P(modules) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(modules, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SSSSS(exceptionMsg, "Parameter to ", "ModuleManager", "\'s ", "ModuleManager:setModules", " method must be an array or implement the Traversable interface");
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_modulemanager_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/modulemanager/modulemanager.zep", 266 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("modules"), modules TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get the module event
 *
 * @return ModuleEvent
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("event"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(event, _0);
	if (!(zephir_instance_of_ev(event, zendframework_modulemanager_moduleevent_ce TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(event);
		object_init_ex(event, zendframework_modulemanager_moduleevent_ce);
		ZEPHIR_CALL_METHOD(NULL, event, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setevent", NULL, event);
		zephir_check_call_status();
	}
	RETURN_CCTOR(event);

}

/**
 * Set the module event
 *
 * @param  ModuleEvent $event
 * @return ModuleManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setEvent) {

	zval *event;

	zephir_fetch_params(0, 1, 0, &event);



	if (!(zephir_instance_of_ev(event, zendframework_modulemanager_moduleevent_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'event' must be an instance of 'ZendFramework\\ModuleManager\\ModuleEvent'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("event"), event TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set the event manager instance used by this module manager.
 *
 * @param  EventManagerInterface $events
 * @return ModuleManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setEventManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *events, *className, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &events);



	if (!(zephir_instance_of_ev(events, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'events' must be an instance of 'ZendFramework\\EventManager\\EventManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 4);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "ModuleManager", 1);
	zephir_array_fast_append(_0, _1);
	zephir_array_fast_append(_0, className);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "module_manager", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_METHOD(NULL, events, "setidentifiers", NULL, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("events"), events TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attachdefaultlisteners", NULL);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Retrieve the event manager
 *
 * Lazy-loads an EventManager instance if none registered.
 *
 * @return EventManagerInterface
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getEventManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *events = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(events, _0);
	if (!(zephir_instance_of_ev(events, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(events);
		object_init_ex(events, zendframework_eventmanager_eventmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, events, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventmanager", NULL, events);
		zephir_check_call_status();
	}
	RETURN_CCTOR(events);

}

/**
 * Register the default event listeners
 *
 * @return ModuleManager
 */
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, attachDefaultListeners) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *events = NULL, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geteventmanager", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_fast_append(_1, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "onLoadModules", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "loadModules", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, events, "attach", NULL, _2, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

