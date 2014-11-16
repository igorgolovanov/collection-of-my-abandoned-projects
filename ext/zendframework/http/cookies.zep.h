
extern zend_class_entry *zendframework_http_cookies_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Cookies);

PHP_METHOD(ZendFramework_Http_Cookies, fromString);
PHP_METHOD(ZendFramework_Http_Cookies, addCookie);
PHP_METHOD(ZendFramework_Http_Cookies, addCookiesFromResponse);
PHP_METHOD(ZendFramework_Http_Cookies, getAllCookies);
PHP_METHOD(ZendFramework_Http_Cookies, getMatchingCookies);
PHP_METHOD(ZendFramework_Http_Cookies, getCookie);
PHP_METHOD(ZendFramework_Http_Cookies, _flattenCookiesArray);
PHP_METHOD(ZendFramework_Http_Cookies, _matchDomain);
PHP_METHOD(ZendFramework_Http_Cookies, _matchPath);
PHP_METHOD(ZendFramework_Http_Cookies, fromResponse);
PHP_METHOD(ZendFramework_Http_Cookies, isEmpty);
PHP_METHOD(ZendFramework_Http_Cookies, reset);
PHP_METHOD(ZendFramework_Http_Cookies, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_addcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, cookie)
	ZEND_ARG_INFO(0, refUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_addcookiesfromresponse, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, ZendFramework\\Http\\Response, 0)
	ZEND_ARG_INFO(0, refUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_getallcookies, 0, 0, 0)
	ZEND_ARG_INFO(0, retAs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_getmatchingcookies, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, matchSessionCookies)
	ZEND_ARG_INFO(0, retAs)
	ZEND_ARG_INFO(0, now)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_getcookie, 0, 0, 2)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, cookieName)
	ZEND_ARG_INFO(0, retAs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies__flattencookiesarray, 0, 0, 1)
	ZEND_ARG_INFO(0, ptr)
	ZEND_ARG_INFO(0, retAs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies__matchdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies__matchpath, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, domains, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_cookies_fromresponse, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, response, ZendFramework\\Http\\Response, 0)
	ZEND_ARG_INFO(0, refUri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_cookies_method_entry) {
	PHP_ME(ZendFramework_Http_Cookies, fromString, arginfo_zendframework_http_cookies_fromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Cookies, addCookie, arginfo_zendframework_http_cookies_addcookie, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, addCookiesFromResponse, arginfo_zendframework_http_cookies_addcookiesfromresponse, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, getAllCookies, arginfo_zendframework_http_cookies_getallcookies, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, getMatchingCookies, arginfo_zendframework_http_cookies_getmatchingcookies, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, getCookie, arginfo_zendframework_http_cookies_getcookie, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, _flattenCookiesArray, arginfo_zendframework_http_cookies__flattencookiesarray, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Cookies, _matchDomain, arginfo_zendframework_http_cookies__matchdomain, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Cookies, _matchPath, arginfo_zendframework_http_cookies__matchpath, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Cookies, fromResponse, arginfo_zendframework_http_cookies_fromresponse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Cookies, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Cookies, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
