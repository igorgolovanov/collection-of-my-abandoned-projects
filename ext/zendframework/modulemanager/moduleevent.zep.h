
extern zend_class_entry *zendframework_modulemanager_moduleevent_ce;

ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_ModuleEvent);

PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getModuleName);
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setModuleName);
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getModule);
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setModule);
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, getConfigListener);
PHP_METHOD(ZendFramework_ModuleManager_ModuleEvent, setConfigListener);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_moduleevent_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_moduleevent_setmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_modulemanager_moduleevent_setconfiglistener, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, configListener, ZendFramework\\ModuleManager\\Listener\\ConfigMergerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_modulemanager_moduleevent_method_entry) {
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, setModuleName, arginfo_zendframework_modulemanager_moduleevent_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, getModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, setModule, arginfo_zendframework_modulemanager_moduleevent_setmodule, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, getConfigListener, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_ModuleManager_ModuleEvent, setConfigListener, arginfo_zendframework_modulemanager_moduleevent_setconfiglistener, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
