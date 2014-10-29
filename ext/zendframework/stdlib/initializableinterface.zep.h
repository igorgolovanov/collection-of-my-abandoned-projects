
extern zend_class_entry *zendframework_stdlib_initializableinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_InitializableInterface);

ZEPHIR_INIT_FUNCS(zendframework_stdlib_initializableinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_InitializableInterface, init, NULL)
  PHP_FE_END
};
