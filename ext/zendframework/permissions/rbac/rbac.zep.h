
extern zend_class_entry *zendframework_permissions_rbac_rbac_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_Rbac);

PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, setCreateMissingRoles);
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, getCreateMissingRoles);
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, addRole);
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, hasRole);
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, getRole);
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, isGranted);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_rbac_setcreatemissingroles, 0, 0, 1)
	ZEND_ARG_INFO(0, createMissingRoles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_rbac_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, child)
	ZEND_ARG_INFO(0, parents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_rbac_hasrole, 0, 0, 1)
	ZEND_ARG_INFO(0, objectOrName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_rbac_getrole, 0, 0, 1)
	ZEND_ARG_INFO(0, objectOrName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_rbac_isgranted, 0, 0, 2)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, permission)
	ZEND_ARG_INFO(0, assert)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_rbac_rbac_method_entry) {
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, setCreateMissingRoles, arginfo_zendframework_permissions_rbac_rbac_setcreatemissingroles, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, getCreateMissingRoles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, addRole, arginfo_zendframework_permissions_rbac_rbac_addrole, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, hasRole, arginfo_zendframework_permissions_rbac_rbac_hasrole, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, getRole, arginfo_zendframework_permissions_rbac_rbac_getrole, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Rbac_Rbac, isGranted, arginfo_zendframework_permissions_rbac_rbac_isgranted, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
