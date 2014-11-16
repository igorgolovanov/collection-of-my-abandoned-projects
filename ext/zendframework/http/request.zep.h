
extern zend_class_entry *zendframework_http_request_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Request);

PHP_METHOD(ZendFramework_Http_Request, fromString);
PHP_METHOD(ZendFramework_Http_Request, setMethod);
PHP_METHOD(ZendFramework_Http_Request, getMethod);
PHP_METHOD(ZendFramework_Http_Request, setUri);
PHP_METHOD(ZendFramework_Http_Request, getUri);
PHP_METHOD(ZendFramework_Http_Request, getUriString);
PHP_METHOD(ZendFramework_Http_Request, setQuery);
PHP_METHOD(ZendFramework_Http_Request, getQuery);
PHP_METHOD(ZendFramework_Http_Request, setPost);
PHP_METHOD(ZendFramework_Http_Request, getPost);
PHP_METHOD(ZendFramework_Http_Request, getCookie);
PHP_METHOD(ZendFramework_Http_Request, setFiles);
PHP_METHOD(ZendFramework_Http_Request, getFiles);
PHP_METHOD(ZendFramework_Http_Request, getHeaders);
PHP_METHOD(ZendFramework_Http_Request, getHeader);
PHP_METHOD(ZendFramework_Http_Request, isOptions);
PHP_METHOD(ZendFramework_Http_Request, isPropFind);
PHP_METHOD(ZendFramework_Http_Request, isGet);
PHP_METHOD(ZendFramework_Http_Request, isHead);
PHP_METHOD(ZendFramework_Http_Request, isPost);
PHP_METHOD(ZendFramework_Http_Request, isPut);
PHP_METHOD(ZendFramework_Http_Request, isDelete);
PHP_METHOD(ZendFramework_Http_Request, isTrace);
PHP_METHOD(ZendFramework_Http_Request, isConnect);
PHP_METHOD(ZendFramework_Http_Request, isPatch);
PHP_METHOD(ZendFramework_Http_Request, isXmlHttpRequest);
PHP_METHOD(ZendFramework_Http_Request, isFlashRequest);
PHP_METHOD(ZendFramework_Http_Request, renderRequestLine);
PHP_METHOD(ZendFramework_Http_Request, toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_setquery, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, query, ZendFramework\\Stdlib\\ParametersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_setpost, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, post, ZendFramework\\Stdlib\\ParametersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_setfiles, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, files, ZendFramework\\Stdlib\\ParametersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_getfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_getheaders, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_request_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultVal)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_request_method_entry) {
	PHP_ME(ZendFramework_Http_Request, fromString, arginfo_zendframework_http_request_fromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Request, setMethod, arginfo_zendframework_http_request_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, setUri, arginfo_zendframework_http_request_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getUriString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, setQuery, arginfo_zendframework_http_request_setquery, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getQuery, arginfo_zendframework_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, setPost, arginfo_zendframework_http_request_setpost, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getPost, arginfo_zendframework_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getCookie, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, setFiles, arginfo_zendframework_http_request_setfiles, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getFiles, arginfo_zendframework_http_request_getfiles, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getHeaders, arginfo_zendframework_http_request_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, getHeader, arginfo_zendframework_http_request_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isPropFind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isTrace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isConnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isPatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isXmlHttpRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, isFlashRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, renderRequestLine, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Request, toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
