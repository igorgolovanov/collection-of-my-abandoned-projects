
extern zend_class_entry *zendframework_stdlib_errorhandler_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ErrorHandler);

PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, started);
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, getNestedLevel);
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, start);
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, stop);
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, clean);
PHP_METHOD(ZendFramework_Stdlib_ErrorHandler, addError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_errorhandler_start, 0, 0, 0)
	ZEND_ARG_INFO(0, errorLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_errorhandler_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, throw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_errorhandler_adderror, 0, 0, 1)
	ZEND_ARG_INFO(0, errno)
	ZEND_ARG_INFO(0, errstr)
	ZEND_ARG_INFO(0, errfile)
	ZEND_ARG_INFO(0, errline)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_errorhandler_method_entry) {
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, started, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, getNestedLevel, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, start, arginfo_zendframework_stdlib_errorhandler_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, stop, arginfo_zendframework_stdlib_errorhandler_stop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, clean, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ErrorHandler, addError, arginfo_zendframework_stdlib_errorhandler_adderror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
