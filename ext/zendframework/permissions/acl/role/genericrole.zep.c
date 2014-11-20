
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Role_GenericRole) {

	ZEPHIR_REGISTER_CLASS(Zend\\Permissions\\Acl\\Role, GenericRole, zendframework, permissions_acl_role_genericrole, zendframework_permissions_acl_role_genericrole_method_entry, 0);

	/**
	 * Unique id of Role
	 *
	 * @var string
	 */
	zend_declare_property_null(zendframework_permissions_acl_role_genericrole_ce, SL("roleId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_permissions_acl_role_genericrole_ce TSRMLS_CC, 1, zendframework_permissions_acl_role_roleinterface_ce);
	return SUCCESS;

}

/**
 * Sets the Role identifier
 *
 * @param string $roleId
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_GenericRole, __construct) {

	zval *roleId_param = NULL;
	zval *roleId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleId_param);

	zephir_get_strval(roleId, roleId_param);


	zephir_update_property_this(this_ptr, SL("roleId"), roleId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Defined by RoleInterface; returns the Role identifier
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_GenericRole, getRoleId) {


	RETURN_MEMBER(this_ptr, "roleId");

}

/**
 * Defined by RoleInterface; returns the Role identifier
 * Proxies to getRoleId()
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_GenericRole, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&id, this_ptr, "getroleid", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(id);

}

