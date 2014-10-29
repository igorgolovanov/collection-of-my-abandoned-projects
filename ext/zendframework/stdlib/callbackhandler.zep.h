
extern zend_class_entry *zendframework_stdlib_callbackhandler_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_CallbackHandler);

PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, __construct);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, registerCallback);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getCallback);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, call);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, __invoke);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getMetadata);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, getMetadatum);
PHP_METHOD(ZendFramework_Stdlib_CallbackHandler, validateStringCallbackFor54);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_callbackhandler___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, metadata, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_callbackhandler_registercallback, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_callbackhandler_call, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_callbackhandler_getmetadatum, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_callbackhandler_validatestringcallbackfor54, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_callbackhandler_method_entry) {
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, __construct, arginfo_zendframework_stdlib_callbackhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, registerCallback, arginfo_zendframework_stdlib_callbackhandler_registercallback, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, getCallback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, call, arginfo_zendframework_stdlib_callbackhandler_call, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, getMetadata, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, getMetadatum, arginfo_zendframework_stdlib_callbackhandler_getmetadatum, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_CallbackHandler, validateStringCallbackFor54, arginfo_zendframework_stdlib_callbackhandler_validatestringcallbackfor54, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
