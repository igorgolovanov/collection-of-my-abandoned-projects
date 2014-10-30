
extern zend_class_entry *zendframework_stdlib_stringutils_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_StringUtils);

PHP_METHOD(ZendFramework_Stdlib_StringUtils, _singleByteEncodings);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getRegisteredWrappers);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, registerWrapper);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, unregisterWrapper);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, resetRegisteredWrappers);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getWrapper);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getSingleByteEncodings);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, isSingleByteEncoding);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, isValidUtf8);
PHP_METHOD(ZendFramework_Stdlib_StringUtils, hasPcreUnicodeSupport);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringutils_registerwrapper, 0, 0, 1)
	ZEND_ARG_INFO(0, wrapper)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringutils_unregisterwrapper, 0, 0, 1)
	ZEND_ARG_INFO(0, wrapper)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringutils_getwrapper, 0, 0, 0)
	ZEND_ARG_INFO(0, encoding)
	ZEND_ARG_INFO(0, convertEncoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringutils_issinglebyteencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringutils_isvalidutf8, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_stringutils_method_entry) {
	PHP_ME(ZendFramework_Stdlib_StringUtils, _singleByteEncodings, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, getRegisteredWrappers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, registerWrapper, arginfo_zendframework_stdlib_stringutils_registerwrapper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, unregisterWrapper, arginfo_zendframework_stdlib_stringutils_unregisterwrapper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, resetRegisteredWrappers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, getWrapper, arginfo_zendframework_stdlib_stringutils_getwrapper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, getSingleByteEncodings, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, isSingleByteEncoding, arginfo_zendframework_stdlib_stringutils_issinglebyteencoding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, isValidUtf8, arginfo_zendframework_stdlib_stringutils_isvalidutf8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_StringUtils, hasPcreUnicodeSupport, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
