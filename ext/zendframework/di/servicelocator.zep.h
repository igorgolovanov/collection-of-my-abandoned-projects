
extern zend_class_entry *zendframework_di_servicelocator_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Di_ServiceLocator);

PHP_METHOD(ZendFramework_Di_ServiceLocator, set);
PHP_METHOD(ZendFramework_Di_ServiceLocator, get);
PHP_METHOD(ZendFramework_Di_ServiceLocator, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_di_servicelocator_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_di_servicelocator_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_di_servicelocator_method_entry) {
	PHP_ME(ZendFramework_Di_ServiceLocator, set, arginfo_zendframework_di_servicelocator_set, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Di_ServiceLocator, get, arginfo_zendframework_di_servicelocator_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Di_ServiceLocator, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
