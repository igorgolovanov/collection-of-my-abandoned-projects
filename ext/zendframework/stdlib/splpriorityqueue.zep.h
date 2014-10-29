
extern zend_class_entry *zendframework_stdlib_splpriorityqueue_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_SplPriorityQueue);

PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, insert);
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, toArray);
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, serialize);
PHP_METHOD(ZendFramework_Stdlib_SplPriorityQueue, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_splpriorityqueue_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, datum)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_splpriorityqueue_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_splpriorityqueue_method_entry) {
	PHP_ME(ZendFramework_Stdlib_SplPriorityQueue, insert, arginfo_zendframework_stdlib_splpriorityqueue_insert, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_SplPriorityQueue, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_SplPriorityQueue, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_SplPriorityQueue, unserialize, arginfo_zendframework_stdlib_splpriorityqueue_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
