
extern zend_class_entry *zendframework_ldap_exception_ldapexception_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Ldap_Exception_LdapException);

PHP_METHOD(ZendFramework_Ldap_Exception_LdapException, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_ldap_exception_ldapexception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, ldap)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_ldap_exception_ldapexception_method_entry) {
	PHP_ME(ZendFramework_Ldap_Exception_LdapException, __construct, arginfo_zendframework_ldap_exception_ldapexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
