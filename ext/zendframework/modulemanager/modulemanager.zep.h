
extern zend_class_entry *zendframework_modulemanager_modulemanager_ce;

ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_ModuleManager);

PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, __construct);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, onLoadModules);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModules);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModule);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, loadModuleByName);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getLoadedModules);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getModule);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getModules);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setModules);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getEvent);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setEvent);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, setEventManager);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, getEventManager);
PHP_METHOD(ZendFramework_ModuleManager_ModuleManager, attachDefaultListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_OBJ_INFO(0, eventManager, ZendFramework\\EventManager\\EventManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_loadmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_loadmodulebyname, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, ZendFramework\\EventManager\\EventInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_getloadedmodules, 0, 0, 0)
	ZEND_ARG_INFO(0, loadModules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_getmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_setmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_setevent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, ZendFramework\\ModuleManager\\ModuleEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_modulemanager_seteventmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, events, ZendFramework\\EventManager\\EventManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_modulemanager_modulemanager_method_entry) {
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, __construct, arginfo_zendframework_modulemanager_modulemanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, onLoadModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, loadModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, loadModule, arginfo_zendframework_modulemanager_modulemanager_loadmodule, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, loadModuleByName, arginfo_zendframework_modulemanager_modulemanager_loadmodulebyname, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, getLoadedModules, arginfo_zendframework_modulemanager_modulemanager_getloadedmodules, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, getModule, arginfo_zendframework_modulemanager_modulemanager_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, setModules, arginfo_zendframework_modulemanager_modulemanager_setmodules, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, getEvent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, setEvent, arginfo_zendframework_modulemanager_modulemanager_setevent, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, setEventManager, arginfo_zendframework_modulemanager_modulemanager_seteventmanager, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, getEventManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleManager, attachDefaultListeners, NULL, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
