
extern zend_class_entry *zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_hydrate, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_extract, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface, hydrate, arginfo_zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_hydrate)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface, extract, arginfo_zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_extract)
  PHP_FE_END
};