
extern zend_class_entry *zendframework_http_headerloader_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_HeaderLoader);

PHP_METHOD(ZendFramework_Http_HeaderLoader, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headerloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, map)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_headerloader_method_entry) {
	PHP_ME(ZendFramework_Http_HeaderLoader, __construct, arginfo_zendframework_http_headerloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
