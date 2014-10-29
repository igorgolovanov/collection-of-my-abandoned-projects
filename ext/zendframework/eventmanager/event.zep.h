
extern zend_class_entry *zendframework_eventmanager_event_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_Event);

PHP_METHOD(ZendFramework_EventManager_Event, __construct);
PHP_METHOD(ZendFramework_EventManager_Event, getName);
PHP_METHOD(ZendFramework_EventManager_Event, getTarget);
PHP_METHOD(ZendFramework_EventManager_Event, setParams);
PHP_METHOD(ZendFramework_EventManager_Event, getParams);
PHP_METHOD(ZendFramework_EventManager_Event, getParam);
PHP_METHOD(ZendFramework_EventManager_Event, setName);
PHP_METHOD(ZendFramework_EventManager_Event, setTarget);
PHP_METHOD(ZendFramework_EventManager_Event, setParam);
PHP_METHOD(ZendFramework_EventManager_Event, stopPropagation);
PHP_METHOD(ZendFramework_EventManager_Event, propagationIsStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_settarget, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_event_stoppropagation, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_event_method_entry) {
	PHP_ME(ZendFramework_EventManager_Event, __construct, arginfo_zendframework_eventmanager_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_EventManager_Event, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, getTarget, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, setParams, arginfo_zendframework_eventmanager_event_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, getParam, arginfo_zendframework_eventmanager_event_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, setName, arginfo_zendframework_eventmanager_event_setname, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, setTarget, arginfo_zendframework_eventmanager_event_settarget, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, setParam, arginfo_zendframework_eventmanager_event_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, stopPropagation, arginfo_zendframework_eventmanager_event_stoppropagation, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Event, propagationIsStopped, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
