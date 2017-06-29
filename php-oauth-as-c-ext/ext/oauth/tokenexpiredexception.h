
extern zend_class_entry *oauth_tokenexpiredexception_ce;

ZEPHIR_INIT_CLASS(OAuth_TokenExpiredException);

PHP_METHOD(OAuth_TokenExpiredException, __construct);
PHP_METHOD(OAuth_TokenExpiredException, getToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_tokenexpiredexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_tokenexpiredexception_method_entry) {
	PHP_ME(OAuth_TokenExpiredException, __construct, arginfo_oauth_tokenexpiredexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_TokenExpiredException, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
