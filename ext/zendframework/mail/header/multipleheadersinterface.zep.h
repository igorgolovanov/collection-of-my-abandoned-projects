
extern zend_class_entry *zendframework_mail_header_multipleheadersinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mail_Header_MultipleHeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mail_header_multipleheadersinterface_tostringmultipleheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_mail_header_multipleheadersinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Mail_Header_MultipleHeadersInterface, toStringMultipleHeaders, arginfo_zendframework_mail_header_multipleheadersinterface_tostringmultipleheaders)
  PHP_FE_END
};