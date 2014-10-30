
extern zend_class_entry *zendframework_server_server_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Server_Server);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_addfunction, 0, 0, 1)
	ZEND_ARG_INFO(0, function)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_setclass, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
	ZEND_ARG_INFO(0, namespace)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_fault, 0, 0, 0)
	ZEND_ARG_INFO(0, fault)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_loadfunctions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_setpersistence, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_server_setreturnresponse, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_server_server_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, addFunction, arginfo_zendframework_server_server_addfunction)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, setClass, arginfo_zendframework_server_server_setclass)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, fault, arginfo_zendframework_server_server_fault)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, handle, arginfo_zendframework_server_server_handle)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, getFunctions, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, loadFunctions, arginfo_zendframework_server_server_loadfunctions)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, setPersistence, arginfo_zendframework_server_server_setpersistence)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, setReturnResponse, arginfo_zendframework_server_server_setreturnresponse)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, getReturnResponse, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Server_Server, getResponse, NULL)
  PHP_FE_END
};
