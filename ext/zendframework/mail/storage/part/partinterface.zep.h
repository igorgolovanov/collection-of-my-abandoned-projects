
extern zend_class_entry *zendframework_mail_storage_part_partinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mail_Storage_Part_PartInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mail_storage_part_partinterface_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, num)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mail_storage_part_partinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mail_storage_part_partinterface_getheaderfield, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, wantedPart)
	ZEND_ARG_INFO(0, firstName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mail_storage_part_partinterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_mail_storage_part_partinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, isMultipart, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getContent, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getSize, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getPart, arginfo_zendframework_mail_storage_part_partinterface_getpart)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, countParts, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getHeaders, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getHeader, arginfo_zendframework_mail_storage_part_partinterface_getheader)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, getHeaderField, arginfo_zendframework_mail_storage_part_partinterface_getheaderfield)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, __get, arginfo_zendframework_mail_storage_part_partinterface___get)
	PHP_ABSTRACT_ME(ZendFramework_Mail_Storage_Part_PartInterface, __toString, NULL)
  PHP_FE_END
};
