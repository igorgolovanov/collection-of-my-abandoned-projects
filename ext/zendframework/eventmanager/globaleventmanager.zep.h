
extern zend_class_entry *zendframework_eventmanager_globaleventmanager_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_GlobalEventManager);

PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, setEventCollection);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getEventCollection);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, trigger);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, triggerUntil);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, attach);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, detach);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getEvents);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, getListeners);
PHP_METHOD(ZendFramework_EventManager_GlobalEventManager, clearListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_seteventcollection, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, events, ZendFramework\\EventManager\\EventManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_trigger, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_triggeruntil, 0, 0, 4)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_INFO(0, argv)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_detach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, listener, ZendFramework\\Stdlib\\CallbackHandler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_globaleventmanager_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_globaleventmanager_method_entry) {
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, setEventCollection, arginfo_zendframework_eventmanager_globaleventmanager_seteventcollection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, getEventCollection, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, trigger, arginfo_zendframework_eventmanager_globaleventmanager_trigger, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, triggerUntil, arginfo_zendframework_eventmanager_globaleventmanager_triggeruntil, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, attach, arginfo_zendframework_eventmanager_globaleventmanager_attach, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, detach, arginfo_zendframework_eventmanager_globaleventmanager_detach, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, getEvents, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, getListeners, arginfo_zendframework_eventmanager_globaleventmanager_getlisteners, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_EventManager_GlobalEventManager, clearListeners, arginfo_zendframework_eventmanager_globaleventmanager_clearlisteners, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
