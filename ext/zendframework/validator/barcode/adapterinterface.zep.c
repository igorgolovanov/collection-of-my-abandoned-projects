
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
ZEPHIR_INIT_CLASS(ZendFramework_Validator_Barcode_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Validator\\Barcode, AdapterInterface, zendframework, validator_barcode_adapterinterface, zendframework_validator_barcode_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Checks the length of a barcode
 *
 * @param  string $value  The barcode to check for proper length
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, hasValidLength);

/**
 * Checks for allowed characters within the barcode
 *
 * @param  string $value The barcode to check for allowed characters
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, hasValidCharacters);

/**
 * Validates the checksum
 *
 * @param string $value The barcode to check the checksum for
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, hasValidChecksum);

/**
 * Returns the allowed barcode length
 *
 * @return int|array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, getLength);

/**
 * Returns the allowed characters
 *
 * @return int|string|array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, getCharacters);

/**
 * Returns if barcode uses a checksum
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, getChecksum);

/**
 * Sets the checksum validation, if no value is given, the actual setting is returned
 *
 * @param  bool $check
 * @return AbstractAdapter|bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Barcode_AdapterInterface, useChecksum);

