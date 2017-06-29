
extern zend_class_entry *oauth_v1_signature_ce;

ZEPHIR_INIT_CLASS(OAuth_V1_Signature);

PHP_METHOD(OAuth_V1_Signature, __construct);
PHP_METHOD(OAuth_V1_Signature, setHashingAlgorithm);
PHP_METHOD(OAuth_V1_Signature, setTokenSecret);
PHP_METHOD(OAuth_V1_Signature, getTokenSecret);
PHP_METHOD(OAuth_V1_Signature, getSignature);
PHP_METHOD(OAuth_V1_Signature, buildSignatureString);
PHP_METHOD(OAuth_V1_Signature, getHashingAlgorithm);
PHP_METHOD(OAuth_V1_Signature, getCredentials);
PHP_METHOD(OAuth_V1_Signature, getSigningKey);
PHP_METHOD(OAuth_V1_Signature, hash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, credentials)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature_sethashingalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, algorithm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature_settokensecret, 0, 0, 1)
	ZEND_ARG_INFO(0, tokenSecret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature_getsignature, 0, 0, 2)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature_buildsignaturestring, 0, 0, 1)
	ZEND_ARG_INFO(0, signatureData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_v1_signature_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_v1_signature_method_entry) {
	PHP_ME(OAuth_V1_Signature, __construct, arginfo_oauth_v1_signature___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(OAuth_V1_Signature, setHashingAlgorithm, arginfo_oauth_v1_signature_sethashingalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Signature, setTokenSecret, arginfo_oauth_v1_signature_settokensecret, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Signature, getTokenSecret, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Signature, getSignature, arginfo_oauth_v1_signature_getsignature, ZEND_ACC_PUBLIC)
	PHP_ME(OAuth_V1_Signature, buildSignatureString, arginfo_oauth_v1_signature_buildsignaturestring, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Signature, getHashingAlgorithm, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Signature, getCredentials, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Signature, getSigningKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(OAuth_V1_Signature, hash, arginfo_oauth_v1_signature_hash, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
