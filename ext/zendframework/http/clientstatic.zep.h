
extern zend_class_entry *zendframework_http_clientstatic_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_ClientStatic);

PHP_METHOD(ZendFramework_Http_ClientStatic, getStaticClient);
PHP_METHOD(ZendFramework_Http_ClientStatic, get);
PHP_METHOD(ZendFramework_Http_ClientStatic, post);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_clientstatic_get, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_clientstatic_post, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_clientstatic_method_entry) {
	PHP_ME(ZendFramework_Http_ClientStatic, getStaticClient, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_ClientStatic, get, arginfo_zendframework_http_clientstatic_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_ClientStatic, post, arginfo_zendframework_http_clientstatic_post, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
