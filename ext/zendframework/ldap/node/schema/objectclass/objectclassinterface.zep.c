
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * This class provides a contract for schema objectClasses.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Ldap\\Node\\Schema\\ObjectClass, ObjectClassInterface, zendframework, ldap_node_schema_objectclass_objectclassinterface, zendframework_ldap_node_schema_objectclass_objectclassinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets the objectClass name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getName);

/**
 * Gets the objectClass OID
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getOid);

/**
 * Gets the attributes that this objectClass must contain
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getMustContain);

/**
 * Gets the attributes that this objectClass may contain
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getMayContain);

/**
 * Gets the objectClass description
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getDescription);

/**
 * Gets the objectClass type
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getType);

/**
 * Returns the parent objectClasses of this class.
 * This includes structural, abstract and auxiliary objectClasses
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_ObjectClass_ObjectClassInterface, getParentClasses);

