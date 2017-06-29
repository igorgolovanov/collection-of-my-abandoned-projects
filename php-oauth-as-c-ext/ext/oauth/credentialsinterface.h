
extern zend_class_entry *oauth_credentialsinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_CredentialsInterface);

ZEPHIR_INIT_FUNCS(oauth_credentialsinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_CredentialsInterface, getCallbackUrl, NULL)
	PHP_ABSTRACT_ME(OAuth_CredentialsInterface, getConsumerId, NULL)
	PHP_ABSTRACT_ME(OAuth_CredentialsInterface, getConsumerSecret, NULL)
	PHP_FE_END
};
