
extern zend_class_entry *zendframework_filter_encrypt_encryptionalgorithminterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_filter_encrypt_encryptionalgorithminterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_filter_encrypt_encryptionalgorithminterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_filter_encrypt_encryptionalgorithminterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, encrypt, arginfo_zendframework_filter_encrypt_encryptionalgorithminterface_encrypt)
	PHP_ABSTRACT_ME(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, decrypt, arginfo_zendframework_filter_encrypt_encryptionalgorithminterface_decrypt)
	PHP_ABSTRACT_ME(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, toString, NULL)
  PHP_FE_END
};