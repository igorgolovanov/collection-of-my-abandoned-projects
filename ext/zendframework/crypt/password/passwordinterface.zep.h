
extern zend_class_entry *zendframework_crypt_password_passwordinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Crypt_Password_PasswordInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_crypt_password_passwordinterface_create, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_crypt_password_passwordinterface_verify, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, hash)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_crypt_password_passwordinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Crypt_Password_PasswordInterface, create, arginfo_zendframework_crypt_password_passwordinterface_create)
	PHP_ABSTRACT_ME(ZendFramework_Crypt_Password_PasswordInterface, verify, arginfo_zendframework_crypt_password_passwordinterface_verify)
  PHP_FE_END
};
