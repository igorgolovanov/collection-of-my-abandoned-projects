
extern zend_class_entry *zendframework_http_abstractmessage_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_AbstractMessage);

PHP_METHOD(ZendFramework_Http_AbstractMessage, setVersion);
PHP_METHOD(ZendFramework_Http_AbstractMessage, getVersion);
PHP_METHOD(ZendFramework_Http_AbstractMessage, setHeaders);
PHP_METHOD(ZendFramework_Http_AbstractMessage, getHeaders);
PHP_METHOD(ZendFramework_Http_AbstractMessage, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_abstractmessage_setversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_abstractmessage_setheaders, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, headers, ZendFramework\\Http\\Headers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_abstractmessage_method_entry) {
	PHP_ME(ZendFramework_Http_AbstractMessage, setVersion, arginfo_zendframework_http_abstractmessage_setversion, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_AbstractMessage, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_AbstractMessage, setHeaders, arginfo_zendframework_http_abstractmessage_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_AbstractMessage, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_AbstractMessage, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
