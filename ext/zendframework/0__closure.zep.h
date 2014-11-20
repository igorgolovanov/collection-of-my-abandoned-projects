
extern zend_class_entry *zendframework_0__closure_ce;

ZEPHIR_INIT_CLASS(zendframework_0__closure);

PHP_METHOD(zendframework_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_0__closure___invoke, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, letters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_0__closure_method_entry) {
	PHP_ME(zendframework_0__closure, __invoke, arginfo_zendframework_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
  PHP_FE_END
};
