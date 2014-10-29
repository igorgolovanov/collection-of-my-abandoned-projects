
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
ZEPHIR_INIT_CLASS(ZendFramework_Validator_Translator_TranslatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Validator\\Translator, TranslatorInterface, zendframework, validator_translator_translatorinterface, zendframework_validator_translator_translatorinterface_method_entry);

	return SUCCESS;

}

/**
 * @param  string $message
 * @param  string $textDomain
 * @param  string $locale
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorInterface, translate);

