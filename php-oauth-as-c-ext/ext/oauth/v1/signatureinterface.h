
extern zend_class_entry *oauth_v1_signatureinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_SignatureInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signatureinterface_sethashingalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signatureinterface_settokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signatureinterface_getsignature, 0, 0, 2)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_signatureinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_V1_SignatureInterface, setHashingAlgorithm, arginfo_oauth_v1_signatureinterface_sethashingalgorithm)
	PHP_ABSTRACT_ME(OAuth_V1_SignatureInterface, setTokenSecret, arginfo_oauth_v1_signatureinterface_settokensecret)
	PHP_ABSTRACT_ME(OAuth_V1_SignatureInterface, getSignature, arginfo_oauth_v1_signatureinterface_getsignature)
	PHP_FE_END
};
