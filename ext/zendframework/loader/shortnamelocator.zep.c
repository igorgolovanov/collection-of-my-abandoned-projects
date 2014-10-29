
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
 * Short name locator interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Loader_ShortNameLocator) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Loader, ShortNameLocator, zendframework, loader_shortnamelocator, zendframework_loader_shortnamelocator_method_entry);

	return SUCCESS;

}

/**
 * Whether or not a Helper by a specific name
 *
 * @param  string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_ShortNameLocator, isLoaded);

/**
 * Return full class name for a named helper
 *
 * @param  string $name
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_ShortNameLocator, getClassName);

/**
 * Load a helper via the name provided
 *
 * @param  string $name
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_ShortNameLocator, load);

