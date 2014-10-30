
extern zend_class_entry *zendframework_permissions_acl_aclinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_AclInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_aclinterface_hasresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_aclinterface_isallowed, 0, 0, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, privilege)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_acl_aclinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Permissions_Acl_AclInterface, hasResource, arginfo_zendframework_permissions_acl_aclinterface_hasresource)
	PHP_ABSTRACT_ME(ZendFramework_Permissions_Acl_AclInterface, isAllowed, arginfo_zendframework_permissions_acl_aclinterface_isallowed)
  PHP_FE_END
};
