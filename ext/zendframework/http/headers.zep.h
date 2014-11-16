
extern zend_class_entry *zendframework_http_headers_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Headers);

PHP_METHOD(ZendFramework_Http_Headers, fromString);
PHP_METHOD(ZendFramework_Http_Headers, setPluginClassLoader);
PHP_METHOD(ZendFramework_Http_Headers, getPluginClassLoader);
PHP_METHOD(ZendFramework_Http_Headers, addHeaders);
PHP_METHOD(ZendFramework_Http_Headers, addHeaderLine);
PHP_METHOD(ZendFramework_Http_Headers, addHeader);
PHP_METHOD(ZendFramework_Http_Headers, removeHeader);
PHP_METHOD(ZendFramework_Http_Headers, clearHeaders);
PHP_METHOD(ZendFramework_Http_Headers, get);
PHP_METHOD(ZendFramework_Http_Headers, has);
PHP_METHOD(ZendFramework_Http_Headers, next);
PHP_METHOD(ZendFramework_Http_Headers, key);
PHP_METHOD(ZendFramework_Http_Headers, valid);
PHP_METHOD(ZendFramework_Http_Headers, rewind);
PHP_METHOD(ZendFramework_Http_Headers, current);
PHP_METHOD(ZendFramework_Http_Headers, count);
PHP_METHOD(ZendFramework_Http_Headers, toString);
PHP_METHOD(ZendFramework_Http_Headers, toArray);
PHP_METHOD(ZendFramework_Http_Headers, forceLoading);
PHP_METHOD(ZendFramework_Http_Headers, lazyLoadHeader);
PHP_METHOD(ZendFramework_Http_Headers, createKey);
PHP_METHOD(ZendFramework_Http_Headers, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_setpluginclassloader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pluginClassLoader, ZendFramework\\Loader\\PluginClassLocator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_addheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_addheaderline, 0, 0, 1)
	ZEND_ARG_INFO(0, headerFieldNameOrLine)
	ZEND_ARG_INFO(0, fieldValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_addheader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, header, ZendFramework\\Http\\Header\\HeaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_removeheader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, header, ZendFramework\\Http\\Header\\HeaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_lazyloadheader, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_headers_createkey, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_headers_method_entry) {
	PHP_ME(ZendFramework_Http_Headers, fromString, arginfo_zendframework_http_headers_fromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Headers, setPluginClassLoader, arginfo_zendframework_http_headers_setpluginclassloader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, getPluginClassLoader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, addHeaders, arginfo_zendframework_http_headers_addheaders, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, addHeaderLine, arginfo_zendframework_http_headers_addheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, addHeader, arginfo_zendframework_http_headers_addheader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, removeHeader, arginfo_zendframework_http_headers_removeheader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, clearHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, get, arginfo_zendframework_http_headers_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, has, arginfo_zendframework_http_headers_has, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, forceLoading, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Headers, lazyLoadHeader, arginfo_zendframework_http_headers_lazyloadheader, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Headers, createKey, arginfo_zendframework_http_headers_createkey, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Headers, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
