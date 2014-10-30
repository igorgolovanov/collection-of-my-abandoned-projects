
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
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_AssertionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Permissions\\Rbac, AssertionInterface, zendframework, permissions_rbac_assertioninterface, zendframework_permissions_rbac_assertioninterface_method_entry);

	return SUCCESS;

}

/**
 * Assertion method - must return a boolean.
 *
 * @param  Rbac    $rbac
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Rbac_AssertionInterface, assert);

