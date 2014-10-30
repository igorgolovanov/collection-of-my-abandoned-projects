
extern zend_class_entry *zendframework_permissions_acl_assertion_assertioninterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Assertion_AssertionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_permissions_acl_assertion_assertioninterface_assert, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, acl, ZendFramework\\Permissions\\Acl\\AclInterface, 0)
	ZEND_ARG_OBJ_INFO(0, role, ZendFramework\\Permissions\\Acl\\Role\\RoleInterface, 1)
	ZEND_ARG_OBJ_INFO(0, resource, ZendFramework\\Permissions\\Acl\\Resource\\ResourceInterface, 1)
	ZEND_ARG_INFO(0, privilege)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_permissions_acl_assertion_assertioninterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Permissions_Acl_Assertion_AssertionInterface, assert, arginfo_zendframework_permissions_acl_assertion_assertioninterface_assert)
  PHP_FE_END
};
