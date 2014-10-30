
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
 * Session validator interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Session_Validator_ValidatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session\\Validator, ValidatorInterface, zendframework, session_validator_validatorinterface, zendframework_session_validator_validatorinterface_method_entry);

	return SUCCESS;

}

/**
 * This method will be called at the beginning of
 * every session to determine if the current environment matches
 * that which was store in the setup() procedure.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_Validator_ValidatorInterface, isValid);

/**
 * Get data from validator to be used for validation comparisons
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_Validator_ValidatorInterface, getData);

/**
 * Get validator name for use with storing validators between requests
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_Validator_ValidatorInterface, getName);

