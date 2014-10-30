
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
 * Tree specific route interface.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Router_Console_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc\\Router\\Console, RouteInterface, zendframework, mvc_router_console_routeinterface, zendframework_mvc_router_console_routeinterface_method_entry);

	zend_class_implements(zendframework_mvc_router_console_routeinterface_ce TSRMLS_CC, 1, zendframework_mvc_router_routeinterface_ce);
	return SUCCESS;

}

/**
 * Get a list of parameters used while assembling.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_Console_RouteInterface, getAssembledParams);

