
extern zend_class_entry *oauth_uri_ce;

ZEPHIR_INIT_CLASS(OAuth_Uri);

PHP_METHOD(OAuth_Uri, __construct);
PHP_METHOD(OAuth_Uri, parseUri);
PHP_METHOD(OAuth_Uri, getScheme);
PHP_METHOD(OAuth_Uri, setScheme);
PHP_METHOD(OAuth_Uri, getHost);
PHP_METHOD(OAuth_Uri, setHost);
PHP_METHOD(OAuth_Uri, getPort);
PHP_METHOD(OAuth_Uri, setPort);
PHP_METHOD(OAuth_Uri, getPath);
PHP_METHOD(OAuth_Uri, setPath);
PHP_METHOD(OAuth_Uri, getQuery);
PHP_METHOD(OAuth_Uri, setQuery);
PHP_METHOD(OAuth_Uri, addToQuery);
PHP_METHOD(OAuth_Uri, getFragment);
PHP_METHOD(OAuth_Uri, getUserInfo);
PHP_METHOD(OAuth_Uri, setUserInfo);
PHP_METHOD(OAuth_Uri, getAuthority);
PHP_METHOD(OAuth_Uri, __toString);
PHP_METHOD(OAuth_Uri, getRawAuthority);
PHP_METHOD(OAuth_Uri, getRawUserInfo);
PHP_METHOD(OAuth_Uri, getAbsoluteUri);
PHP_METHOD(OAuth_Uri, getRelativeUri);
PHP_METHOD(OAuth_Uri, hasExplicitTrailingHostSlash);
PHP_METHOD(OAuth_Uri, hasExplicitPortSpecified);
PHP_METHOD(OAuth_Uri, createFromSuperGlobals);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_parseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_setscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_setquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_addtoquery, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_setuserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, userInfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uri_createfromsuperglobals, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_uri_method_entry) {
	PHP_ME(OAuth_Uri, __construct, arginfo_oauth_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_Uri, parseUri, arginfo_oauth_uri_parseuri, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_Uri, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setScheme, arginfo_oauth_uri_setscheme, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setHost, arginfo_oauth_uri_sethost, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setPort, arginfo_oauth_uri_setport, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setPath, arginfo_oauth_uri_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setQuery, arginfo_oauth_uri_setquery, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, addToQuery, arginfo_oauth_uri_addtoquery, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getFragment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getUserInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, setUserInfo, arginfo_oauth_uri_setuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getAuthority, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getRawAuthority, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getRawUserInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getAbsoluteUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, getRelativeUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, hasExplicitTrailingHostSlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, hasExplicitPortSpecified, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Uri, createFromSuperGlobals, arginfo_oauth_uri_createfromsuperglobals, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
