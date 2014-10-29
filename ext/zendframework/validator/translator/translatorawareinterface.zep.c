
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
ZEPHIR_INIT_CLASS(ZendFramework_Validator_Translator_TranslatorAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Validator\\Translator, TranslatorAwareInterface, zendframework, validator_translator_translatorawareinterface, zendframework_validator_translator_translatorawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets translator to use in helper
 *
 * @param  TranslatorInterface $translator  [optional] translator.
 *             Default is null, which sets no translator.
 * @param  string $textDomain  [optional] text domain
 *             Default is null, which skips setTranslatorTextDomain
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, setTranslator);

/**
 * Returns translator used in object
 *
 * @return TranslatorInterface|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, getTranslator);

/**
 * Checks if the object has a translator
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, hasTranslator);

/**
 * Sets whether translator is enabled and should be used
 *
 * @param  bool $enabled [optional] whether translator should be used.
 *                  Default is true.
 * @return TranslatorAwareInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, setTranslatorEnabled);

/**
 * Returns whether translator is enabled and should be used
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, isTranslatorEnabled);

/**
 * Set translation text domain
 *
 * @param  string $textDomain
 * @return TranslatorAwareInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, setTranslatorTextDomain);

/**
 * Return the translation text domain
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Validator_Translator_TranslatorAwareInterface, getTranslatorTextDomain);

