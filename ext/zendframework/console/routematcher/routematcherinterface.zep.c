
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
ZEPHIR_INIT_CLASS(ZendFramework_Console_RouteMatcher_RouteMatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Console\\RouteMatcher, RouteMatcherInterface, zendframework, console_routematcher_routematcherinterface, zendframework_console_routematcher_routematcherinterface_method_entry);

	return SUCCESS;

}

/**
 * Match parameters against route passed to constructor
 *
 * @param array $params
 * @return array|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_RouteMatcher_RouteMatcherInterface, match);

