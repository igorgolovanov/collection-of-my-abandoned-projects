
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
ZEPHIR_INIT_CLASS(ZendFramework_Crypt_Symmetric_SymmetricInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Crypt\\Symmetric, SymmetricInterface, zendframework, crypt_symmetric_symmetricinterface, zendframework_crypt_symmetric_symmetricinterface_method_entry);

	return SUCCESS;

}

/**
 * @param string $data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, encrypt);

/**
 * @param string $data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, decrypt);

/**
 * @param string $key
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, setKey);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getKey);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getKeySize);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getAlgorithm);

/**
 * @param  string $algo
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, setAlgorithm);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getSupportedAlgorithms);

/**
 * @param string|false $salt
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, setSalt);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getSalt);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getSaltSize);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getBlockSize);

/**
 * @param string $mode
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, setMode);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getMode);

ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_SymmetricInterface, getSupportedModes);

