
extern zend_class_entry *oauth_service_ce;

ZEPHIR_INIT_CLASS(OAuth_Service);

PHP_METHOD(OAuth_Service, __construct);
PHP_METHOD(OAuth_Service, getCredentials);
PHP_METHOD(OAuth_Service, getClient);
PHP_METHOD(OAuth_Service, getTokenStorage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_service___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, credentials)
	ZEND_ARG_INFO(0, client)
	ZEND_ARG_INFO(0, storage)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_service_method_entry) {
	PHP_ME(OAuth_Service, __construct, arginfo_oauth_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_Service, getCredentials, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_Service, getClient, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_Service, getTokenStorage, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
