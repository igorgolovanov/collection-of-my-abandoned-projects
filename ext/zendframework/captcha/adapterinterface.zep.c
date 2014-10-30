
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
 * Generic Captcha adapter interface
 *
 * Each specific captcha implementation should implement this interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Captcha_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Captcha, AdapterInterface, zendframework, captcha_adapterinterface, zendframework_captcha_adapterinterface_method_entry);

	zend_class_implements(zendframework_captcha_adapterinterface_ce TSRMLS_CC, 1, zendframework_validator_validatorinterface_ce);
	return SUCCESS;

}

/**
 * Generate a new captcha
 *
 * @return string new captcha ID
 */
ZEPHIR_DOC_METHOD(ZendFramework_Captcha_AdapterInterface, generate);

/**
 * Set captcha name
 *
 * @param  string $name
 * @return AdapterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Captcha_AdapterInterface, setName);

/**
 * Get captcha name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Captcha_AdapterInterface, getName);

/**
 * Get helper name to use when rendering this captcha type
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Captcha_AdapterInterface, getHelperName);

