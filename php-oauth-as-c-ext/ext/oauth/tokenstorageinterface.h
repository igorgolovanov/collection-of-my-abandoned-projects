
extern zend_class_entry *oauth_tokenstorageinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_TokenStorageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorageinterface_retrieveaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorageinterface_storeaccesstoken, 0, 0, 2)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorageinterface_hasaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorageinterface_cleartoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_tokenstorageinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_TokenStorageInterface, retrieveAccessToken, arginfo_oauth_tokenstorageinterface_retrieveaccesstoken)
	PHP_ABSTRACT_ME(OAuth_TokenStorageInterface, storeAccessToken, arginfo_oauth_tokenstorageinterface_storeaccesstoken)
	PHP_ABSTRACT_ME(OAuth_TokenStorageInterface, hasAccessToken, arginfo_oauth_tokenstorageinterface_hasaccesstoken)
	PHP_ABSTRACT_ME(OAuth_TokenStorageInterface, clearToken, arginfo_oauth_tokenstorageinterface_cleartoken)
	PHP_ABSTRACT_ME(OAuth_TokenStorageInterface, clearAllTokens, NULL)
	PHP_FE_END
};
