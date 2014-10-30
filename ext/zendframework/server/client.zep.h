
extern zend_class_entry *zendframework_server_client_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Server_Client);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_server_client_call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_server_client_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Server_Client, call, arginfo_zendframework_server_client_call)
  PHP_FE_END
};
