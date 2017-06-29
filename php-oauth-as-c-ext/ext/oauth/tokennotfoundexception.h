
extern zend_class_entry *oauth_tokennotfoundexception_ce;

ZEPHIR_INIT_CLASS(OAuth_TokenNotFoundException);

PHP_METHOD(OAuth_TokenNotFoundException, __construct);
PHP_METHOD(OAuth_TokenNotFoundException, getToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokennotfoundexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_tokennotfoundexception_method_entry) {
	PHP_ME(OAuth_TokenNotFoundException, __construct, arginfo_oauth_tokennotfoundexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_TokenNotFoundException, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
