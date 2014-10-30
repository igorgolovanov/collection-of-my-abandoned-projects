
extern zend_class_entry *zendframework_eventmanager_responsecollection_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_ResponseCollection);

PHP_METHOD(ZendFramework_EventManager_ResponseCollection, stopped);
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, setStopped);
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, first);
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, last);
PHP_METHOD(ZendFramework_EventManager_ResponseCollection, contains);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_responsecollection_setstopped, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_responsecollection_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_responsecollection_method_entry) {
	PHP_ME(ZendFramework_EventManager_ResponseCollection, stopped, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_ResponseCollection, setStopped, arginfo_zendframework_eventmanager_responsecollection_setstopped, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_ResponseCollection, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_ResponseCollection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_ResponseCollection, contains, arginfo_zendframework_eventmanager_responsecollection_contains, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
