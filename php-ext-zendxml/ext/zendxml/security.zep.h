
extern zend_class_entry *zendxml_security_ce;

ZEPHIR_INIT_CLASS(ZendXml_Security);

PHP_METHOD(ZendXml_Security, heuristicScan);
PHP_METHOD(ZendXml_Security, scan);
PHP_METHOD(ZendXml_Security, scanErrorHandler);
PHP_METHOD(ZendXml_Security, scanFile);
PHP_METHOD(ZendXml_Security, isPhpFpm);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendxml_security_heuristicscan, 0, 0, 1)
	ZEND_ARG_INFO(0, xml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendxml_security_scan, 0, 0, 1)
	ZEND_ARG_INFO(0, xml)
	ZEND_ARG_OBJ_INFO(0, dom, DOMDocument, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendxml_security_scanerrorhandler, 0, 0, 2)
	ZEND_ARG_INFO(0, errno)
	ZEND_ARG_INFO(0, errstr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendxml_security_scanfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_OBJ_INFO(0, dom, DOMDocument, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendxml_security_method_entry) {
	PHP_ME(ZendXml_Security, heuristicScan, arginfo_zendxml_security_heuristicscan, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(ZendXml_Security, scan, arginfo_zendxml_security_scan, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendXml_Security, scanErrorHandler, arginfo_zendxml_security_scanerrorhandler, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendXml_Security, scanFile, arginfo_zendxml_security_scanfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendXml_Security, isPhpFpm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
