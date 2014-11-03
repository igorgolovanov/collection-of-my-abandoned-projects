
extern zend_class_entry *zendframework_config_abstractconfigfactory_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Config_AbstractConfigFactory);

PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, canCreateServiceWithName);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, createServiceWithName);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, addPattern);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, addPatterns);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, setPatterns);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, getPatterns);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, match);
PHP_METHOD(ZendFramework_Config_AbstractConfigFactory, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_cancreateservicewithname, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, serviceLocator, ZendFramework\\ServiceManager\\ServiceLocatorInterface, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, requestedName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_createservicewithname, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, serviceLocator, ZendFramework\\ServiceManager\\ServiceLocatorInterface, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, requestedName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_addpattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_addpatterns, 0, 0, 1)
	ZEND_ARG_INFO(0, patterns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_setpatterns, 0, 0, 1)
	ZEND_ARG_INFO(0, patterns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_abstractconfigfactory_match, 0, 0, 1)
	ZEND_ARG_INFO(0, requestedName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_config_abstractconfigfactory_method_entry) {
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, canCreateServiceWithName, arginfo_zendframework_config_abstractconfigfactory_cancreateservicewithname, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, createServiceWithName, arginfo_zendframework_config_abstractconfigfactory_createservicewithname, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, addPattern, arginfo_zendframework_config_abstractconfigfactory_addpattern, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, addPatterns, arginfo_zendframework_config_abstractconfigfactory_addpatterns, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, setPatterns, arginfo_zendframework_config_abstractconfigfactory_setpatterns, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, getPatterns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, match, arginfo_zendframework_config_abstractconfigfactory_match, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Config_AbstractConfigFactory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
