
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
 * Interface class for Zend\View\Renderer\* compatible template engine implementations
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Renderer_RendererInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Renderer, RendererInterface, zendframework, view_renderer_rendererinterface, zendframework_view_renderer_rendererinterface_method_entry);

	return SUCCESS;

}

/**
 * Return the template engine object, if any
 *
 * If using a third-party template engine, such as Smarty, patTemplate,
 * phplib, etc, return the template engine object. Useful for calling
 * methods on these objects, such as for setting filters, modifiers, etc.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Renderer_RendererInterface, getEngine);

/**
 * Set the resolver used to map a template name to a resource the renderer may consume.
 *
 * @param  ResolverInterface $resolver
 * @return RendererInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Renderer_RendererInterface, setResolver);

/**
 * Processes a view script and returns the output.
 *
 * @param  string|ModelInterface   $nameOrModel The script/resource process, or a view model
 * @param  null|array|\ArrayAccess $values      Values to use during rendering
 * @return string The script output.
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Renderer_RendererInterface, render);

