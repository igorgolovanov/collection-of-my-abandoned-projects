
extern zend_class_entry *oauth_v1_service_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_Service);

PHP_METHOD(OAuth_V1_Service, __construct);
PHP_METHOD(OAuth_V1_Service, getSignature);
PHP_METHOD(OAuth_V1_Service, getAuthorizationUri);
PHP_METHOD(OAuth_V1_Service, request);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_service___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, credentials)
	ZEND_ARG_INFO(0, client)
	ZEND_ARG_INFO(0, storage)
	ZEND_ARG_INFO(0, signature)
	ZEND_ARG_INFO(0, baseApiUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_service_getauthorizationuri, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_service_request, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_service_method_entry) {
	PHP_ME(OAuth_V1_Service, __construct, arginfo_oauth_v1_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_V1_Service, getSignature, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Service, getAuthorizationUri, arginfo_oauth_v1_service_getauthorizationuri, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Service, request, arginfo_oauth_v1_service_request, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
