
extern zend_class_entry *oauth_v1_unsupportedhashalgorithmexception_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_UnsupportedHashAlgorithmException);

PHP_METHOD(OAuth_V1_UnsupportedHashAlgorithmException, __construct);
PHP_METHOD(OAuth_V1_UnsupportedHashAlgorithmException, getAlgorithm);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_unsupportedhashalgorithmexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_unsupportedhashalgorithmexception_method_entry) {
	PHP_ME(OAuth_V1_UnsupportedHashAlgorithmException, __construct, arginfo_oauth_v1_unsupportedhashalgorithmexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_V1_UnsupportedHashAlgorithmException, getAlgorithm, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
