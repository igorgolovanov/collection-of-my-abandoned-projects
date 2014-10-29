
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
ZEPHIR_INIT_CLASS(ZendFramework_Validator_ValidatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Validator, ValidatorInterface, zendframework, validator_validatorinterface, zendframework_validator_validatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns true if and only if $value meets the validation requirements
 *
 * If $value fails validation, then this method returns false, and
 * getMessages() will return an array of messages that explain why the
 * validation failed.
 *
 * @param  mixed $value
 * @return bool
 * @throws Exception\RuntimeException If validation of $value is impossible
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_ValidatorInterface, isValid);

/**
 * Returns an array of messages that explain why the most recent isValid()
 * call returned false. The array keys are validation failure message identifiers,
 * and the array values are the corresponding human-readable message strings.
 *
 * If isValid() was never called or if the most recent isValid() call
 * returned true, then this method returns an empty array.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_ValidatorInterface, getMessages);

