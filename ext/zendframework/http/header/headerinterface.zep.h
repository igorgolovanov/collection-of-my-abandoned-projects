
extern zend_class_entry *zendframework_http_header_headerinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Header_HeaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_header_headerinterface_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, headerLine)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_header_headerinterface_method_entry) {
	ZEND_FENTRY(fromString, NULL, arginfo_zendframework_http_header_headerinterface_fromstring, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(ZendFramework_Http_Header_HeaderInterface, getFieldName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Http_Header_HeaderInterface, getFieldValue, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Http_Header_HeaderInterface, toString, NULL)
  PHP_FE_END
};
