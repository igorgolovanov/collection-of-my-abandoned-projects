
extern zend_class_entry *oauth_uriinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_UriInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_setscheme, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_sethost, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_setquery, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_addtoquery, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_uriinterface_setuserinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, userInfo)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_uriinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_UriInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setScheme, arginfo_oauth_uriinterface_setscheme)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getHost, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setHost, arginfo_oauth_uriinterface_sethost)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getPort, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setPort, arginfo_oauth_uriinterface_setport)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getPath, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setPath, arginfo_oauth_uriinterface_setpath)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getQuery, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setQuery, arginfo_oauth_uriinterface_setquery)
	PHP_ABSTRACT_ME(OAuth_UriInterface, addToQuery, arginfo_oauth_uriinterface_addtoquery)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getFragment, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getUserInfo, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, setUserInfo, arginfo_oauth_uriinterface_setuserinfo)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getAuthority, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, __toString, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getRawAuthority, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getRawUserInfo, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getAbsoluteUri, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, getRelativeUri, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, hasExplicitTrailingHostSlash, NULL)
	PHP_ABSTRACT_ME(OAuth_UriInterface, hasExplicitPortSpecified, NULL)
	PHP_FE_END
};
