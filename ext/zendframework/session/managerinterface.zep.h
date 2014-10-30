
extern zend_class_entry *zendframework_session_managerinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Session_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setstorage, 0, 0, 1)
	ZEND_ARG_INFO(0, storage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setsavehandler, 0, 0, 1)
	ZEND_ARG_INFO(0, saveHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_rememberme, 0, 0, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_session_managerinterface_setvalidatorchain, 0, 0, 1)
	ZEND_ARG_INFO(0, chain)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_session_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setConfig, arginfo_zendframework_session_managerinterface_setconfig)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getConfig, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setStorage, arginfo_zendframework_session_managerinterface_setstorage)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getStorage, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setSaveHandler, arginfo_zendframework_session_managerinterface_setsavehandler)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getSaveHandler, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, sessionExists, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, start, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, destroy, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, writeClose, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setName, arginfo_zendframework_session_managerinterface_setname)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setId, arginfo_zendframework_session_managerinterface_setid)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getId, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, regenerateId, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, rememberMe, arginfo_zendframework_session_managerinterface_rememberme)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, forgetMe, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, expireSessionCookie, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, setValidatorChain, arginfo_zendframework_session_managerinterface_setvalidatorchain)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, getValidatorChain, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Session_ManagerInterface, isValid, NULL)
  PHP_FE_END
};
