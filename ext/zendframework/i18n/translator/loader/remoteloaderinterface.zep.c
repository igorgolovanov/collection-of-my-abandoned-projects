
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
 * Remote loader interface.
 */
ZEPHIR_INIT_CLASS(ZendFramework_I18n_Translator_Loader_RemoteLoaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\I18n\\Translator\\Loader, RemoteLoaderInterface, zendframework, i18n_translator_loader_remoteloaderinterface, zendframework_i18n_translator_loader_remoteloaderinterface_method_entry);

	return SUCCESS;

}

/**
 * Load translations from a remote source.
 *
 * @param  string $locale
 * @param  string $textDomain
 * @return \Zend\I18n\Translator\TextDomain|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_I18n_Translator_Loader_RemoteLoaderInterface, load);

