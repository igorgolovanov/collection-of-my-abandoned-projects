
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * File loader interface.
 */
ZEPHIR_INIT_CLASS(ZendFramework_I18n_Translator_Loader_FileLoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\I18n\\Translator\\Loader, FileLoaderInterface, zendframework, i18n_translator_loader_fileloaderinterface, zendframework_i18n_translator_loader_fileloaderinterface_method_entry);

	return SUCCESS;

}

/**
 * Load translations from a file.
 *
 * @param  string $locale
 * @param  string $filename
 * @return \Zend\I18n\Translator\TextDomain|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_I18n_Translator_Loader_FileLoaderInterface, load);

