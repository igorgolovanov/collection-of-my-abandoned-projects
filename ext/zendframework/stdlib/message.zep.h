
extern zend_class_entry *zendframework_stdlib_message_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Message);

PHP_METHOD(ZendFramework_Stdlib_Message, setMetadata);
PHP_METHOD(ZendFramework_Stdlib_Message, getMetadata);
PHP_METHOD(ZendFramework_Stdlib_Message, setContent);
PHP_METHOD(ZendFramework_Stdlib_Message, getContent);
PHP_METHOD(ZendFramework_Stdlib_Message, toString);
PHP_METHOD(ZendFramework_Stdlib_Message, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_message_setmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_message_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_message_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_message_method_entry) {
	PHP_ME(ZendFramework_Stdlib_Message, setMetadata, arginfo_zendframework_stdlib_message_setmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Message, getMetadata, arginfo_zendframework_stdlib_message_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Message, setContent, arginfo_zendframework_stdlib_message_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Message, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Message, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_Message, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
