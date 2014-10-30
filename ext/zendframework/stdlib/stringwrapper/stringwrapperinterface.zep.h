
extern zend_class_entry *zendframework_stdlib_stringwrapper_stringwrapperinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_issupported, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
	ZEND_ARG_INFO(0, convertEncoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
	ZEND_ARG_INFO(0, convertEncoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strlen, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_substr, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strpos, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_convert, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, reverse)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_wordwrap, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, break)
	ZEND_ARG_INFO(0, cut)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strpad, 0, 0, 2)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, padLength)
	ZEND_ARG_INFO(0, padString)
	ZEND_ARG_INFO(0, padType)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_stringwrapper_stringwrapperinterface_method_entry) {
	ZEND_FENTRY(isSupported, NULL, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_issupported, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getSupportedEncodings, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, setEncoding, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_setencoding)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, getConvertEncoding, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strlen, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strlen)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, substr, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_substr)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strpos, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strpos)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, convert, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_convert)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, wordWrap, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_wordwrap)
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strPad, arginfo_zendframework_stdlib_stringwrapper_stringwrapperinterface_strpad)
  PHP_FE_END
};
