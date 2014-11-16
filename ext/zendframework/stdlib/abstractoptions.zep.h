
extern zend_class_entry *zendframework_stdlib_abstractoptions_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_AbstractOptions);

PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __construct);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, setFromArray);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, toArray);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __set);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __get);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __isset);
PHP_METHOD(ZendFramework_Stdlib_AbstractOptions, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions_setfromarray, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_abstractoptions___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_abstractoptions_method_entry) {
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, __construct, arginfo_zendframework_stdlib_abstractoptions___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, setFromArray, arginfo_zendframework_stdlib_abstractoptions_setfromarray, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, __set, arginfo_zendframework_stdlib_abstractoptions___set, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, __get, arginfo_zendframework_stdlib_abstractoptions___get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, __isset, arginfo_zendframework_stdlib_abstractoptions___isset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_AbstractOptions, __unset, arginfo_zendframework_stdlib_abstractoptions___unset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
