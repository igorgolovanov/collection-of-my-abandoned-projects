
extern zend_class_entry *oauth_tokenstorage_memory_ce;

ZEPHIR_INIT_CLASS(OAuth_TokenStorage_Memory);

PHP_METHOD(OAuth_TokenStorage_Memory, __construct);
PHP_METHOD(OAuth_TokenStorage_Memory, retrieveAccessToken);
PHP_METHOD(OAuth_TokenStorage_Memory, storeAccessToken);
PHP_METHOD(OAuth_TokenStorage_Memory, hasAccessToken);
PHP_METHOD(OAuth_TokenStorage_Memory, clearToken);
PHP_METHOD(OAuth_TokenStorage_Memory, clearAllTokens);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorage_memory_retrieveaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorage_memory_storeaccesstoken, 0, 0, 2)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorage_memory_hasaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenstorage_memory_cleartoken, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_tokenstorage_memory_method_entry) {
	PHP_ME(OAuth_TokenStorage_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_TokenStorage_Memory, retrieveAccessToken, arginfo_oauth_tokenstorage_memory_retrieveaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_TokenStorage_Memory, storeAccessToken, arginfo_oauth_tokenstorage_memory_storeaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_TokenStorage_Memory, hasAccessToken, arginfo_oauth_tokenstorage_memory_hasaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_TokenStorage_Memory, clearToken, arginfo_oauth_tokenstorage_memory_cleartoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_TokenStorage_Memory, clearAllTokens, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
