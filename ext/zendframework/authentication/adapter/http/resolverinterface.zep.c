
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
/**
 * Auth HTTP Resolver Interface
 *
 * Defines an interface to resolve a username/realm combination into a shared
 * secret usable by HTTP Authentication.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Authentication_Adapter_Http_ResolverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication\\Adapter\\Http, ResolverInterface, zendframework, authentication_adapter_http_resolverinterface, zendframework_authentication_adapter_http_resolverinterface_method_entry);

	return SUCCESS;

}

/**
 * Resolve username/realm to password/hash/etc.
 *
 * @param  string $username Username
 * @param  string $realm    Authentication Realm
 * @param  string $password Password (optional)
 * @return string|array|false User's shared secret as string if found in realm, or User's identity as array
 *         if resolved, false otherwise.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_Http_ResolverInterface, resolve);

