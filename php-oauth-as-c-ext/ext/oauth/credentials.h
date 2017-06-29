
extern zend_class_entry *oauth_credentials_ce;

ZEPHIR_INIT_CLASS(OAuth_Credentials);

PHP_METHOD(OAuth_Credentials, __construct);
PHP_METHOD(OAuth_Credentials, getCallbackUrl);
PHP_METHOD(OAuth_Credentials, getConsumerId);
PHP_METHOD(OAuth_Credentials, getConsumerSecret);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_credentials___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, consumerId)
	ZEND_ARG_INFO(0, consumerSecret)
	ZEND_ARG_INFO(0, callbackUrl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_credentials_method_entry) {
	PHP_ME(OAuth_Credentials, __construct, arginfo_oauth_credentials___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_Credentials, getCallbackUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Credentials, getConsumerId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Credentials, getConsumerSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
