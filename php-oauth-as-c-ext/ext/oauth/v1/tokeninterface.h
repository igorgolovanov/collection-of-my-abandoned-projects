
extern zend_class_entry *oauth_v1_tokeninterface_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_TokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_tokeninterface_setaccesstokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_tokeninterface_setrequesttokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_tokeninterface_setrequesttoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_tokeninterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, getAccessTokenSecret, NULL)
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, setAccessTokenSecret, arginfo_oauth_v1_tokeninterface_setaccesstokensecret)
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, getRequestTokenSecret, NULL)
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, setRequestTokenSecret, arginfo_oauth_v1_tokeninterface_setrequesttokensecret)
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, getRequestToken, NULL)
	PHP_ABSTRACT_ME(OAuth_V1_TokenInterface, setRequestToken, arginfo_oauth_v1_tokeninterface_setrequesttoken)
	PHP_FE_END
};
