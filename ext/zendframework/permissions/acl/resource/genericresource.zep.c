
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
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Resource_GenericResource) {

	ZEPHIR_REGISTER_CLASS(Zend\\Permissions\\Acl\\Resource, GenericResource, zendframework, permissions_acl_resource_genericresource, zendframework_permissions_acl_resource_genericresource_method_entry, 0);

	/**
	 * Unique id of Resource
	 *
	 * @var string
	 */
	zend_declare_property_null(zendframework_permissions_acl_resource_genericresource_ce, SL("resourceId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_permissions_acl_resource_genericresource_ce TSRMLS_CC, 1, zendframework_permissions_acl_resource_resourceinterface_ce);
	return SUCCESS;

}

/**
 * Sets the Resource identifier
 *
 * @param  string $resourceId
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Resource_GenericResource, __construct) {

	zval *resourceId_param = NULL;
	zval *resourceId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resourceId_param);

	zephir_get_strval(resourceId, resourceId_param);


	zephir_update_property_this(this_ptr, SL("resourceId"), resourceId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Defined by ResourceInterface; returns the Resource identifier
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Resource_GenericResource, getResourceId) {


	RETURN_MEMBER(this_ptr, "resourceId");

}

/**
 * Defined by ResourceInterface; returns the Resource identifier
 * Proxies to getResourceId()
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Resource_GenericResource, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&id, this_ptr, "getresourceid",  NULL);
	zephir_check_call_status();
	RETURN_CCTOR(id);

}

