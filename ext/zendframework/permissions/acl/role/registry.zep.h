
extern zend_class_entry *zendframework_permissions_acl_role_registry_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Role_Registry);

PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, add);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, get);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, has);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, getParents);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, inherits);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, remove);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, removeAll);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, getRoles);
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, role, ZendFramework\\Permissions\\Acl\\Role\\RoleInterface, 0)
	ZEND_ARG_INFO(0, parents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_get, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_has, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_getparents, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_inherits, 0, 0, 2)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, inherit)
	ZEND_ARG_INFO(0, onlyParents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_role_registry_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_acl_role_registry_method_entry) {
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, add, arginfo_zendframework_permissions_acl_role_registry_add, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, get, arginfo_zendframework_permissions_acl_role_registry_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, has, arginfo_zendframework_permissions_acl_role_registry_has, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, getParents, arginfo_zendframework_permissions_acl_role_registry_getparents, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, inherits, arginfo_zendframework_permissions_acl_role_registry_inherits, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, remove, arginfo_zendframework_permissions_acl_role_registry_remove, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, removeAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, getRoles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Permissions_Acl_Role_Registry, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
