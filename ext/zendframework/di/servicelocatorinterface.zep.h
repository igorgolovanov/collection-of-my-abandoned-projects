
extern zend_class_entry *zendframework_di_servicelocatorinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Di_ServiceLocatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_di_servicelocatorinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_di_servicelocatorinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Di_ServiceLocatorInterface, set, arginfo_zendframework_di_servicelocatorinterface_set)
  PHP_FE_END
};
