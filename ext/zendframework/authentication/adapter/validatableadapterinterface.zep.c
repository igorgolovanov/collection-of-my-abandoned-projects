
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
ZEPHIR_INIT_CLASS(ZendFramework_Authentication_Adapter_ValidatableAdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication\\Adapter, ValidatableAdapterInterface, zendframework, authentication_adapter_validatableadapterinterface, zendframework_authentication_adapter_validatableadapterinterface_method_entry);

	zend_class_implements(zendframework_authentication_adapter_validatableadapterinterface_ce TSRMLS_CC, 1, zendframework_authentication_adapter_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Returns the identity of the account being authenticated, or
 * NULL if none is set.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_ValidatableAdapterInterface, getIdentity);

/**
 * Sets the identity for binding
 *
 * @param  mixed                       $identity
 * @return ValidatableAdapterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_ValidatableAdapterInterface, setIdentity);

/**
 * Returns the credential of the account being authenticated, or
 * NULL if none is set.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_ValidatableAdapterInterface, getCredential);

/**
 * Sets the credential for binding
 *
 * @param  mixed                       $credential
 * @return ValidatableAdapterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_ValidatableAdapterInterface, setCredential);

