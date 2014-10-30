
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
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Resource_ResourceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Permissions\\Acl\\Resource, ResourceInterface, zendframework, permissions_acl_resource_resourceinterface, zendframework_permissions_acl_resource_resourceinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the string identifier of the Resource
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Permissions_Acl_Resource_ResourceInterface, getResourceId);

