
extern zend_class_entry *zendframework_permissions_rbac_abstractrole_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_AbstractRole);

PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, getName);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, addPermission);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, hasPermission);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, addChild);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, setParent);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, getParent);
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_abstractrole_addpermission, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_abstractrole_haspermission, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_abstractrole_addchild, 0, 0, 1)
	ZEND_ARG_INFO(0, child)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_abstractrole_setparent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parent, ZendFramework\\Permissions\\Rbac\\RoleInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_rbac_abstractrole_method_entry) {
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, addPermission, arginfo_zendframework_permissions_rbac_abstractrole_addpermission, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, hasPermission, arginfo_zendframework_permissions_rbac_abstractrole_haspermission, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, addChild, arginfo_zendframework_permissions_rbac_abstractrole_addchild, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, setParent, arginfo_zendframework_permissions_rbac_abstractrole_setparent, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, getParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_AbstractRole, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
