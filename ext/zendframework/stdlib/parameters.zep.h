
extern zend_class_entry *zendframework_stdlib_parameters_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Parameters);

PHP_METHOD(ZendFramework_Stdlib_Parameters, __construct);
PHP_METHOD(ZendFramework_Stdlib_Parameters, fromArray);
PHP_METHOD(ZendFramework_Stdlib_Parameters, fromString);
PHP_METHOD(ZendFramework_Stdlib_Parameters, toArray);
PHP_METHOD(ZendFramework_Stdlib_Parameters, toString);
PHP_METHOD(ZendFramework_Stdlib_Parameters, offsetGet);
PHP_METHOD(ZendFramework_Stdlib_Parameters, get);
PHP_METHOD(ZendFramework_Stdlib_Parameters, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters_fromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parameters_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_parameters_method_entry) {
	PHP_ME(ZendFramework_Stdlib_Parameters, __construct, arginfo_zendframework_stdlib_parameters___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Stdlib_Parameters, fromArray, arginfo_zendframework_stdlib_parameters_fromarray, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, fromString, arginfo_zendframework_stdlib_parameters_fromstring, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, offsetGet, arginfo_zendframework_stdlib_parameters_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, get, arginfo_zendframework_stdlib_parameters_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Parameters, set, arginfo_zendframework_stdlib_parameters_set, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
