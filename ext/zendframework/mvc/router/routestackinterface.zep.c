
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
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Router_RouteStackInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc\\Router, RouteStackInterface, zendframework, mvc_router_routestackinterface, zendframework_mvc_router_routestackinterface_method_entry);

	zend_class_implements(zendframework_mvc_router_routestackinterface_ce TSRMLS_CC, 1, zendframework_mvc_router_routeinterface_ce);
	return SUCCESS;

}

/**
 * Add a route to the stack.
 *
 * @param  string  $name
 * @param  mixed   $route
 * @param  int $priority
 * @return RouteStackInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteStackInterface, addRoute);

/**
 * Add multiple routes to the stack.
 *
 * @param  array|\Traversable $routes
 * @return RouteStackInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteStackInterface, addRoutes);

/**
 * Remove a route from the stack.
 *
 * @param  string $name
 * @return RouteStackInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteStackInterface, removeRoute);

/**
 * Remove all routes from the stack and set new ones.
 *
 * @param  array|\Traversable $routes
 * @return RouteStackInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteStackInterface, setRoutes);

