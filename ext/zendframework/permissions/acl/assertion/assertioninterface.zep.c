
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Assertion_AssertionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Permissions\\Acl\\Assertion, AssertionInterface, zendframework, permissions_acl_assertion_assertioninterface, zendframework_permissions_acl_assertion_assertioninterface_method_entry);

	return SUCCESS;

}

/**
 * Returns true if and only if the assertion conditions are met
 *
 * This method is passed the ACL, Role, Resource, and privilege to which the authorization query applies. If the
 * $role, $resource, or $privilege parameters are null, it means that the query applies to all Roles, Resources, or
 * privileges, respectively.
 *
 * @param  AclInterface         $acl
 * @param  RoleInterface        $role
 * @param  ResourceInterface    $resource
 * @param  string               $privilege
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Acl_Assertion_AssertionInterface, assert);

