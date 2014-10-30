
extern zend_class_entry *zendframework_eventmanager_filterchain_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_FilterChain);

PHP_METHOD(ZendFramework_EventManager_FilterChain, __construct);
PHP_METHOD(ZendFramework_EventManager_FilterChain, run);
PHP_METHOD(ZendFramework_EventManager_FilterChain, attach);
PHP_METHOD(ZendFramework_EventManager_FilterChain, detach);
PHP_METHOD(ZendFramework_EventManager_FilterChain, getFilters);
PHP_METHOD(ZendFramework_EventManager_FilterChain, clearFilters);
PHP_METHOD(ZendFramework_EventManager_FilterChain, getResponses);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filterchain_run, 0, 0, 1)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_ARRAY_INFO(0, argv, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filterchain_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filterchain_detach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, ZendFramework\\Stdlib\\CallbackHandler, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_filterchain_method_entry) {
	PHP_ME(ZendFramework_EventManager_FilterChain, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_EventManager_FilterChain, run, arginfo_zendframework_eventmanager_filterchain_run, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_FilterChain, attach, arginfo_zendframework_eventmanager_filterchain_attach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_FilterChain, detach, arginfo_zendframework_eventmanager_filterchain_detach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_FilterChain, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_FilterChain, clearFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_FilterChain, getResponses, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
