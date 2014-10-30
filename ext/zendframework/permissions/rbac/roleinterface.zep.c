
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_RoleInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Permissions\\Rbac, RoleInterface, zendframework, permissions_rbac_roleinterface, zendframework_permissions_rbac_roleinterface_method_entry);

	zend_class_implements(zendframework_permissions_rbac_roleinterface_ce TSRMLS_CC, 1, spl_ce_RecursiveIterator);
	return SUCCESS;

}

/**
 * Get the name of the role.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, getName);

/**
 * Add permission to the role.
 *
 * @param $name
 * @return RoleInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, addPermission);

/**
 * Checks if a permission exists for this role or any child roles.
 *
 * @param  string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, hasPermission);

/**
 * Add a child.
 *
 * @param  RoleInterface|string $child
 * @return Role
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, addChild);

/**
 * @param  RoleInterface $parent
 * @return RoleInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, setParent);

/**
 * @return null|RoleInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_RoleInterface, getParent);

