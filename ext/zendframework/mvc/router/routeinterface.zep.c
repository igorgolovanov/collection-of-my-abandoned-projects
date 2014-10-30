
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
 * RouteInterface interface.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Router_RouteInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc\\Router, RouteInterface, zendframework, mvc_router_routeinterface, zendframework_mvc_router_routeinterface_method_entry);

	return SUCCESS;

}

/**
 * Create a new route with given options.
 *
 * @param  array|\Traversable $options
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteInterface, factory);

/**
 * Match a given request.
 *
 * @param  RequestInterface $request
 * @return RouteMatch|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteInterface, match);

/**
 * Assemble the route.
 *
 * @param  array $params
 * @param  array $options
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_Router_RouteInterface, assemble);

