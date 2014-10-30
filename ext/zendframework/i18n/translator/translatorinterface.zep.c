
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
 * Translator interface.
 */
ZEPHIR_INIT_CLASS(ZendFramework_I18n_Translator_TranslatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\I18n\\Translator, TranslatorInterface, zendframework, i18n_translator_translatorinterface, zendframework_i18n_translator_translatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Translate a message.
 *
 * @param  string $message
 * @param  string $textDomain
 * @param  string $locale
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_I18n_Translator_TranslatorInterface, translate);

/**
 * Translate a plural message.
 *
 * @param  string      $singular
 * @param  string      $plural
 * @param  int         $number
 * @param  string      $textDomain
 * @param  string|null $locale
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_I18n_Translator_TranslatorInterface, translatePlural);

