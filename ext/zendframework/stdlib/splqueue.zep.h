
extern zend_class_entry *zendframework_stdlib_splqueue_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_SplQueue);

PHP_METHOD(ZendFramework_Stdlib_SplQueue, toArray);
PHP_METHOD(ZendFramework_Stdlib_SplQueue, serialize);
PHP_METHOD(ZendFramework_Stdlib_SplQueue, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_splqueue_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_splqueue_method_entry) {
	PHP_ME(ZendFramework_Stdlib_SplQueue, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_SplQueue, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_SplQueue, unserialize, arginfo_zendframework_stdlib_splqueue_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
