
extern zend_class_entry *zendframework_http_client_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Client_Adapter_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_adapter_adapterinterface_setoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_adapter_adapterinterface_connect, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_adapter_adapterinterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_OBJ_INFO(0, url, \\Zend\\Uri\\UriInterface, 0)
	ZEND_ARG_INFO(0, httpVer)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_client_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Http_Client_Adapter_AdapterInterface, setOptions, arginfo_zendframework_http_client_adapter_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(ZendFramework_Http_Client_Adapter_AdapterInterface, connect, arginfo_zendframework_http_client_adapter_adapterinterface_connect)
	PHP_ABSTRACT_ME(ZendFramework_Http_Client_Adapter_AdapterInterface, write, arginfo_zendframework_http_client_adapter_adapterinterface_write)
	PHP_ABSTRACT_ME(ZendFramework_Http_Client_Adapter_AdapterInterface, read, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Http_Client_Adapter_AdapterInterface, close, NULL)
  PHP_FE_END
};
