
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
ZEPHIR_INIT_CLASS(ZendFramework_Di_LocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Di, LocatorInterface, zendframework, di_locatorinterface, zendframework_di_locatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Retrieve a class instance
 *
 * @param  string      $name   Class name or service name
 * @param  null|array  $params Parameters to be used when instantiating a new instance of $name
 * @return object|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_LocatorInterface, get);

