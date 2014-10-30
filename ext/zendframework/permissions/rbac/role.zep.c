
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_Role) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Permissions\\Rbac, Role, zendframework, permissions_rbac_role, zendframework_permissions_rbac_abstractrole_ce, zendframework_permissions_rbac_role_method_entry, 0);

	zend_class_implements(zendframework_permissions_rbac_role_ce TSRMLS_CC, 1, zendframework_permissions_rbac_roleinterface_ce);
	return SUCCESS;

}

/**
 * @param string $name
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Role, __construct) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

