
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
 * Defines an interface for classes that may register with the spl_autoload
 * registry
 */
ZEPHIR_INIT_CLASS(ZendFramework_Loader_SplAutoloader) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Loader, SplAutoloader, zendframework, loader_splautoloader, zendframework_loader_splautoloader_method_entry);

	return SUCCESS;

}

/**
 * Constructor
 *
 * Allow configuration of the autoloader via the constructor.
 *
 * @param  null|array|Traversable $options
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_SplAutoloader, __construct);

/**
 * Configure the autoloader
 *
 * In most cases, options should be either an associative array or
 * Traversable object.
 *
 * @param  array|Traversable $options
 * @return SplAutoloader
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_SplAutoloader, setOptions);

/**
 * Autoload a class
 *
 * @param   $class
 * @return  mixed
 *          False [if unable to load $class]
 *          get_class($class) [if $class is successfully loaded]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_SplAutoloader, autoload);

/**
 * Register the autoloader with spl_autoload registry
 *
 * Typically, the body of this will simply be:
 * <code>
 * spl_autoload_register(array($this, 'autoload'));
 * </code>
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Loader_SplAutoloader, register);

