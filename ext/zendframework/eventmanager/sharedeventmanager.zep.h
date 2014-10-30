
extern zend_class_entry *zendframework_eventmanager_sharedeventmanager_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventManager);

PHP_METHOD(ZendFramework_EventManager_SharedEventManager, attach);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, attachAggregate);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, detach);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, detachAggregate);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, getEvents);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, getListeners);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, clearListeners);
PHP_METHOD(ZendFramework_EventManager_SharedEventManager, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_attach, 0, 0, 3)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_attachaggregate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aggregate, ZendFramework\\EventManager\\SharedListenerAggregateInterface, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_OBJ_INFO(0, listener, ZendFramework\\Stdlib\\CallbackHandler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_detachaggregate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aggregate, ZendFramework\\EventManager\\SharedListenerAggregateInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_getevents, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_getlisteners, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanager_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_sharedeventmanager_method_entry) {
	PHP_ME(ZendFramework_EventManager_SharedEventManager, attach, arginfo_zendframework_eventmanager_sharedeventmanager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, attachAggregate, arginfo_zendframework_eventmanager_sharedeventmanager_attachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, detach, arginfo_zendframework_eventmanager_sharedeventmanager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, detachAggregate, arginfo_zendframework_eventmanager_sharedeventmanager_detachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, getEvents, arginfo_zendframework_eventmanager_sharedeventmanager_getevents, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, getListeners, arginfo_zendframework_eventmanager_sharedeventmanager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, clearListeners, arginfo_zendframework_eventmanager_sharedeventmanager_clearlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_SharedEventManager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
