
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
/**
 * Encryption interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Filter\\Encrypt, EncryptionAlgorithmInterface, zendframework, filter_encrypt_encryptionalgorithminterface, zendframework_filter_encrypt_encryptionalgorithminterface_method_entry);

	return SUCCESS;

}

/**
 * Encrypts $value with the defined settings
 *
 * @param  string $value Data to encrypt
 * @return string The encrypted data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, encrypt);

/**
 * Decrypts $value with the defined settings
 *
 * @param  string $value Data to decrypt
 * @return string The decrypted data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, decrypt);

/**
 * Return the adapter name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Encrypt_EncryptionAlgorithmInterface, toString);

