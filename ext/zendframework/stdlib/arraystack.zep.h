
extern zend_class_entry *zendframework_stdlib_arraystack_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayStack);

PHP_METHOD(ZendFramework_Stdlib_ArrayStack, getIterator);

ZEPHIR_INIT_FUNCS(zendframework_stdlib_arraystack_method_entry) {
	PHP_ME(ZendFramework_Stdlib_ArrayStack, getIterator, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
