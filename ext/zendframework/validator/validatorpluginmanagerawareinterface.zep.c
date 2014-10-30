
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
ZEPHIR_INIT_CLASS(ZendFramework_Validator_ValidatorPluginManagerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Validator, ValidatorPluginManagerAwareInterface, zendframework, validator_validatorpluginmanagerawareinterface, zendframework_validator_validatorpluginmanagerawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Set validator plugin manager
 *
 * @param ValidatorPluginManager $pluginManager
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_ValidatorPluginManagerAwareInterface, setValidatorPluginManager);

/**
 * Get validator plugin manager
 *
 * @return ValidatorPluginManager
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_ValidatorPluginManagerAwareInterface, getValidatorPluginManager);

