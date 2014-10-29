
extern zend_class_entry *zendframework_stdlib_response_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Response);

PHP_METHOD(ZendFramework_Stdlib_Response, test);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_response_test, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, r, Zend\\Stdlib\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_response_method_entry) {
	PHP_ME(ZendFramework_Stdlib_Response, test, arginfo_zendframework_stdlib_response_test, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
