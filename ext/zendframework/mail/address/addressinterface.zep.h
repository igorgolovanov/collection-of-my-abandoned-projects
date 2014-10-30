
extern zend_class_entry *zendframework_mail_address_addressinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mail_Address_AddressInterface);

ZEPHIR_INIT_FUNCS(zendframework_mail_address_addressinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Mail_Address_AddressInterface, getEmail, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Address_AddressInterface, getName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Address_AddressInterface, toString, NULL)
  PHP_FE_END
};
