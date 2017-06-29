
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
 * Interface to allow objects to have initialization logic
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_InitializableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, InitializableInterface, zendframework, stdlib_initializableinterface, zendframework_stdlib_initializableinterface_method_entry);

	return SUCCESS;

}

/**
 * Init an object
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_InitializableInterface, init);

