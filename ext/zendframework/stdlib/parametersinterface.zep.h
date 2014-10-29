
extern zend_class_entry *zendframework_stdlib_parametersinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ParametersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parametersinterface___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parametersinterface_fromarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parametersinterface_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parametersinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_parametersinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_parametersinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, __construct, arginfo_zendframework_stdlib_parametersinterface___construct)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, fromArray, arginfo_zendframework_stdlib_parametersinterface_fromarray)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, fromString, arginfo_zendframework_stdlib_parametersinterface_fromstring)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, toArray, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, toString, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, get, arginfo_zendframework_stdlib_parametersinterface_get)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_ParametersInterface, set, arginfo_zendframework_stdlib_parametersinterface_set)
  PHP_FE_END
};
