
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
ZEPHIR_INIT_CLASS(ZendFramework_Crypt_Password_PasswordInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Crypt\\Password, PasswordInterface, zendframework, crypt_password_passwordinterface, zendframework_crypt_password_passwordinterface_method_entry);

	return SUCCESS;

}

/**
 * Create a password hash for a given plain text password
 *
 * @param  string $password The password to hash
 * @return string The formatted password hash
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Password_PasswordInterface, create);

/**
 * Verify a password hash against a given plain text password
 *
 * @param  string $password The password to hash
 * @param  string $hash     The supplied hash to validate
 * @return bool Does the password validate against the hash
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Password_PasswordInterface, verify);

