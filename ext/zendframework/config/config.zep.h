
extern zend_class_entry *zendframework_config_config_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Config_Config);

PHP_METHOD(ZendFramework_Config_Config, __construct);
PHP_METHOD(ZendFramework_Config_Config, get);
PHP_METHOD(ZendFramework_Config_Config, __get);
PHP_METHOD(ZendFramework_Config_Config, __set);
PHP_METHOD(ZendFramework_Config_Config, __clone);
PHP_METHOD(ZendFramework_Config_Config, toArray);
PHP_METHOD(ZendFramework_Config_Config, __isset);
PHP_METHOD(ZendFramework_Config_Config, __unset);
PHP_METHOD(ZendFramework_Config_Config, count);
PHP_METHOD(ZendFramework_Config_Config, current);
PHP_METHOD(ZendFramework_Config_Config, key);
PHP_METHOD(ZendFramework_Config_Config, next);
PHP_METHOD(ZendFramework_Config_Config, rewind);
PHP_METHOD(ZendFramework_Config_Config, valid);
PHP_METHOD(ZendFramework_Config_Config, offsetExists);
PHP_METHOD(ZendFramework_Config_Config, offsetGet);
PHP_METHOD(ZendFramework_Config_Config, offsetSet);
PHP_METHOD(ZendFramework_Config_Config, offsetUnset);
PHP_METHOD(ZendFramework_Config_Config, merge);
PHP_METHOD(ZendFramework_Config_Config, setReadOnly);
PHP_METHOD(ZendFramework_Config_Config, isReadOnly);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, array, 0)
	ZEND_ARG_INFO(0, allowModifications)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_config_merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, merge, ZendFramework\\Config\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_config_config_method_entry) {
	PHP_ME(ZendFramework_Config_Config, __construct, arginfo_zendframework_config_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Config_Config, get, arginfo_zendframework_config_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, __get, arginfo_zendframework_config_config___get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, __set, arginfo_zendframework_config_config___set, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, __isset, arginfo_zendframework_config_config___isset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, __unset, arginfo_zendframework_config_config___unset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, offsetExists, arginfo_zendframework_config_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, offsetGet, arginfo_zendframework_config_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, offsetSet, arginfo_zendframework_config_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, offsetUnset, arginfo_zendframework_config_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, merge, arginfo_zendframework_config_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, setReadOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Config_Config, isReadOnly, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
