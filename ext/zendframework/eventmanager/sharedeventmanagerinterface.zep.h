
extern zend_class_entry *zendframework_eventmanager_sharedeventmanagerinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanagerinterface_getlisteners, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanagerinterface_attach, 0, 0, 3)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanagerinterface_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_OBJ_INFO(0, listener, Zend\\Stdlib\\CallbackHandler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanagerinterface_getevents, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_sharedeventmanagerinterface_clearlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_sharedeventmanagerinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_EventManager_SharedEventManagerInterface, getListeners, arginfo_zendframework_eventmanager_sharedeventmanagerinterface_getlisteners)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_SharedEventManagerInterface, attach, arginfo_zendframework_eventmanager_sharedeventmanagerinterface_attach)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_SharedEventManagerInterface, detach, arginfo_zendframework_eventmanager_sharedeventmanagerinterface_detach)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_SharedEventManagerInterface, getEvents, arginfo_zendframework_eventmanager_sharedeventmanagerinterface_getevents)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_SharedEventManagerInterface, clearListeners, arginfo_zendframework_eventmanager_sharedeventmanagerinterface_clearlisteners)
  PHP_FE_END
};
