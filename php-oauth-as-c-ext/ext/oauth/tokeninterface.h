
extern zend_class_entry *oauth_tokeninterface_ce;

ZEPHIR_INIT_CLASS(OAuth_TokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokeninterface_setaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokeninterface_setrefreshtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokeninterface_setendoflife, 0, 0, 1)
	ZEND_ARG_INFO(0, endOfLife)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokeninterface_setlifetime, 0, 0, 1)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_tokeninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_TokenInterface, getAccessToken, NULL)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, setAccessToken, arginfo_oauth_tokeninterface_setaccesstoken)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, getRefreshToken, NULL)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, setRefreshToken, arginfo_oauth_tokeninterface_setrefreshtoken)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, getEndOfLife, NULL)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, setEndOfLife, arginfo_oauth_tokeninterface_setendoflife)
	PHP_ABSTRACT_ME(OAuth_TokenInterface, setLifetime, arginfo_oauth_tokeninterface_setlifetime)
	PHP_FE_END
};
