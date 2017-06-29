
extern zend_class_entry *oauth_v1_token_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_Token);

PHP_METHOD(OAuth_V1_Token, getAccessTokenSecret);
PHP_METHOD(OAuth_V1_Token, setAccessTokenSecret);
PHP_METHOD(OAuth_V1_Token, getRequestTokenSecret);
PHP_METHOD(OAuth_V1_Token, setRequestTokenSecret);
PHP_METHOD(OAuth_V1_Token, getRequestToken);
PHP_METHOD(OAuth_V1_Token, setRequestToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_token_setaccesstokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_token_setrequesttokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_token_setrequesttoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_token_method_entry) {
	PHP_ME(OAuth_V1_Token, getAccessTokenSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Token, setAccessTokenSecret, arginfo_oauth_v1_token_setaccesstokensecret, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Token, getRequestTokenSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Token, setRequestTokenSecret, arginfo_oauth_v1_token_setrequesttokensecret, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Token, getRequestToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Token, setRequestToken, arginfo_oauth_v1_token_setrequesttoken, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
