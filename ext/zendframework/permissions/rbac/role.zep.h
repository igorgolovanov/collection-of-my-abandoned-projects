
extern zend_class_entry *zendframework_permissions_rbac_role_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_Role);

PHP_METHOD(ZendFramework_Permissions_Rbac_Role, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_rbac_role___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_rbac_role_method_entry) {
	PHP_ME(ZendFramework_Permissions_Rbac_Role, __construct, arginfo_zendframework_permissions_rbac_role___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
