
extern zend_class_entry *zendframework_eventmanager_eventmanager_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventManager);

PHP_METHOD(ZendFramework_EventManager_EventManager, __construct);
PHP_METHOD(ZendFramework_EventManager_EventManager, setEventClass);
PHP_METHOD(ZendFramework_EventManager_EventManager, setSharedManager);
PHP_METHOD(ZendFramework_EventManager_EventManager, unsetSharedManager);
PHP_METHOD(ZendFramework_EventManager_EventManager, getSharedManager);
PHP_METHOD(ZendFramework_EventManager_EventManager, getIdentifiers);
PHP_METHOD(ZendFramework_EventManager_EventManager, setIdentifiers);
PHP_METHOD(ZendFramework_EventManager_EventManager, addIdentifiers);
PHP_METHOD(ZendFramework_EventManager_EventManager, trigger);
PHP_METHOD(ZendFramework_EventManager_EventManager, triggerUntil);
PHP_METHOD(ZendFramework_EventManager_EventManager, attach);
PHP_METHOD(ZendFramework_EventManager_EventManager, attachAggregate);
PHP_METHOD(ZendFramework_EventManager_EventManager, detach);
PHP_METHOD(ZendFramework_EventManager_EventManager, detachAggregate);
PHP_METHOD(ZendFramework_EventManager_EventManager, getEvents);
PHP_METHOD(ZendFramework_EventManager_EventManager, getListeners);
PHP_METHOD(ZendFramework_EventManager_EventManager, clearListeners);
PHP_METHOD(ZendFramework_EventManager_EventManager, prepareArgs);
PHP_METHOD(ZendFramework_EventManager_EventManager, triggerListeners);
PHP_METHOD(ZendFramework_EventManager_EventManager, getSharedListeners);
PHP_METHOD(ZendFramework_EventManager_EventManager, insertListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_seteventclass, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_setsharedmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, sharedEventManager, ZendFramework\\EventManager\\SharedEventManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_setidentifiers, 0, 0, 1)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_addidentifiers, 0, 0, 1)
	ZEND_ARG_INFO(0, identifiers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_trigger, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, argv)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_triggeruntil, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, argv)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_attachaggregate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aggregate, ZendFramework\\EventManager\\ListenerAggregateInterface, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_detach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, listener, ZendFramework\\EventManager\\ListenerAggregateInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_detachaggregate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, aggregate, ZendFramework\\EventManager\\ListenerAggregateInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_prepareargs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_triggerlisteners, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_OBJ_INFO(0, e, ZendFramework\\EventManager\\EventInterface, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_getsharedlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventmanager_insertlisteners, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, masterListeners, ZendFramework\\Stdlib\\PriorityQueue, 0)
	ZEND_ARG_OBJ_INFO(0, listeners, ZendFramework\\Stdlib\\PriorityQueue, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_eventmanager_method_entry) {
	PHP_ME(ZendFramework_EventManager_EventManager, __construct, arginfo_zendframework_eventmanager_eventmanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_EventManager_EventManager, setEventClass, arginfo_zendframework_eventmanager_eventmanager_seteventclass, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, setSharedManager, arginfo_zendframework_eventmanager_eventmanager_setsharedmanager, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, unsetSharedManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, getSharedManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, getIdentifiers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, setIdentifiers, arginfo_zendframework_eventmanager_eventmanager_setidentifiers, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, addIdentifiers, arginfo_zendframework_eventmanager_eventmanager_addidentifiers, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, trigger, arginfo_zendframework_eventmanager_eventmanager_trigger, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, triggerUntil, arginfo_zendframework_eventmanager_eventmanager_triggeruntil, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, attach, arginfo_zendframework_eventmanager_eventmanager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, attachAggregate, arginfo_zendframework_eventmanager_eventmanager_attachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, detach, arginfo_zendframework_eventmanager_eventmanager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, detachAggregate, arginfo_zendframework_eventmanager_eventmanager_detachaggregate, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, getEvents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, getListeners, arginfo_zendframework_eventmanager_eventmanager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, clearListeners, arginfo_zendframework_eventmanager_eventmanager_clearlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, prepareArgs, arginfo_zendframework_eventmanager_eventmanager_prepareargs, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_EventManager, triggerListeners, arginfo_zendframework_eventmanager_eventmanager_triggerlisteners, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_EventManager_EventManager, getSharedListeners, arginfo_zendframework_eventmanager_eventmanager_getsharedlisteners, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_EventManager_EventManager, insertListeners, arginfo_zendframework_eventmanager_eventmanager_insertlisteners, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
