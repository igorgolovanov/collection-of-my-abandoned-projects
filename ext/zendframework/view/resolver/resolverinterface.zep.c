
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
ZEPHIR_INIT_CLASS(ZendFramework_View_Resolver_ResolverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Resolver, ResolverInterface, zendframework, view_resolver_resolverinterface, zendframework_view_resolver_resolverinterface_method_entry);

	return SUCCESS;

}

/**
 * Resolve a template/pattern name to a resource the renderer can consume
 *
 * @param  string $name
 * @param  null|Renderer $renderer
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Resolver_ResolverInterface, resolve);

