
extern zend_class_entry *zendframework_eventmanager_eventinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_settarget, 0, 0, 1)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_eventinterface_stoppropagation, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_eventinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, getName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, getTarget, NULL)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, getParams, NULL)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, getParam, arginfo_zendframework_eventmanager_eventinterface_getparam)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, setName, arginfo_zendframework_eventmanager_eventinterface_setname)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, setTarget, arginfo_zendframework_eventmanager_eventinterface_settarget)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, setParams, arginfo_zendframework_eventmanager_eventinterface_setparams)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, setParam, arginfo_zendframework_eventmanager_eventinterface_setparam)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, stopPropagation, arginfo_zendframework_eventmanager_eventinterface_stoppropagation)
	PHP_ABSTRACT_ME(ZendFramework_EventManager_EventInterface, propagationIsStopped, NULL)
  PHP_FE_END
};
