
extern zend_class_entry *oauth_serviceinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_serviceinterface_request, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_serviceinterface_getauthorizationuri, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_ServiceInterface, request, arginfo_oauth_serviceinterface_request)
	PHP_ABSTRACT_ME(OAuth_ServiceInterface, getAuthorizationUri, arginfo_oauth_serviceinterface_getauthorizationuri)
	PHP_ABSTRACT_ME(OAuth_ServiceInterface, getAuthorizationEndpoint, NULL)
	PHP_ABSTRACT_ME(OAuth_ServiceInterface, getAccessTokenEndpoint, NULL)
	PHP_FE_END
};
