
extern zend_class_entry *zendframework_stdlib_hydrator_hydrationinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_HydrationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_hydrator_hydrationinterface_hydrate, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_hydrator_hydrationinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_Hydrator_HydrationInterface, hydrate, arginfo_zendframework_stdlib_hydrator_hydrationinterface_hydrate)
  PHP_FE_END
};
