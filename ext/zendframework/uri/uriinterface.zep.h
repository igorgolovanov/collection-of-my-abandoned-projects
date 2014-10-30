
extern zend_class_entry *zendframework_uri_uriinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Uri_UriInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_makerelative, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setuserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, userInfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_uri_uriinterface_setfragment, 0, 0, 1)
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_uri_uriinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, __construct, arginfo_zendframework_uri_uriinterface___construct)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, isValid, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, isValidRelative, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, isAbsolute, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, parse, arginfo_zendframework_uri_uriinterface_parse)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, toString, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, normalize, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, makeRelative, arginfo_zendframework_uri_uriinterface_makerelative)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getUserInfo, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getHost, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getPort, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getPath, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getQuery, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getQueryAsArray, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, getFragment, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setScheme, arginfo_zendframework_uri_uriinterface_setscheme)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setUserInfo, arginfo_zendframework_uri_uriinterface_setuserinfo)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setHost, arginfo_zendframework_uri_uriinterface_sethost)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setPort, arginfo_zendframework_uri_uriinterface_setport)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setPath, arginfo_zendframework_uri_uriinterface_setpath)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setQuery, arginfo_zendframework_uri_uriinterface_setquery)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, setFragment, arginfo_zendframework_uri_uriinterface_setfragment)
	PHP_ABSTRACT_ME(ZendFramework_Uri_UriInterface, __toString, NULL)
  PHP_FE_END
};
