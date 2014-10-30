
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
 * This class provides a contract for schema attribute-types.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Ldap\\Node\\Schema\\AttributeType, AttributeTypeInterface, zendframework, ldap_node_schema_attributetype_attributetypeinterface, zendframework_ldap_node_schema_attributetype_attributetypeinterface_method_entry);

	return SUCCESS;

}

/**
 * Gets the attribute name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, getName);

/**
 * Gets the attribute OID
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, getOid);

/**
 * Gets the attribute syntax
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, getSyntax);

/**
 * Gets the attribute maximum length
 *
 * @return int|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, getMaxLength);

/**
 * Returns if the attribute is single-valued.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, isSingleValued);

/**
 * Gets the attribute description
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Ldap_Node_Schema_AttributeType_AttributeTypeInterface, getDescription);

