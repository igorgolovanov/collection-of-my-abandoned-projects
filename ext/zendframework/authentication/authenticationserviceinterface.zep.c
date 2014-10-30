
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Provides an API for authentication and identity management
 */
ZEPHIR_INIT_CLASS(ZendFramework_Authentication_AuthenticationServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication, AuthenticationServiceInterface, zendframework, authentication_authenticationserviceinterface, zendframework_authentication_authenticationserviceinterface_method_entry);

	return SUCCESS;

}

/**
 * Authenticates and provides an authentication result
 *
 * @return Result
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_AuthenticationServiceInterface, authenticate);

/**
 * Returns true if and only if an identity is available
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_AuthenticationServiceInterface, hasIdentity);

/**
 * Returns the authenticated identity or null if no identity is available
 *
 * @return mixed|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_AuthenticationServiceInterface, getIdentity);

/**
 * Clears the identity
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_AuthenticationServiceInterface, clearIdentity);

