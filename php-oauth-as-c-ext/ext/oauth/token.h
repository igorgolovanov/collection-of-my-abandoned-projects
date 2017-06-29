
extern zend_class_entry *oauth_token_ce;

ZEPHIR_INIT_CLASS(OAuth_Token);

PHP_METHOD(OAuth_Token, __construct);
PHP_METHOD(OAuth_Token, getAccessToken);
PHP_METHOD(OAuth_Token, setAccessToken);
PHP_METHOD(OAuth_Token, getRefreshToken);
PHP_METHOD(OAuth_Token, setRefreshToken);
PHP_METHOD(OAuth_Token, getEndOfLife);
PHP_METHOD(OAuth_Token, setEndOfLife);
PHP_METHOD(OAuth_Token, setLifetime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_token___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, accessToken)
	ZEND_ARG_INFO(0, refreshToken)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_token_setaccesstoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_token_setrefreshtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_token_setendoflife, 0, 0, 1)
	ZEND_ARG_INFO(0, endOfLife)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_token_setlifetime, 0, 0, 1)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_token_method_entry) {
	PHP_ME(OAuth_Token, __construct, arginfo_oauth_token___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_Token, getAccessToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, setAccessToken, arginfo_oauth_token_setaccesstoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, getRefreshToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, setRefreshToken, arginfo_oauth_token_setrefreshtoken, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, getEndOfLife, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, setEndOfLife, arginfo_oauth_token_setendoflife, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_Token, setLifetime, arginfo_oauth_token_setlifetime, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
