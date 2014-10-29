
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
ZEPHIR_INIT_CLASS(ZendFramework_View_Renderer_TreeRendererInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Renderer, TreeRendererInterface, zendframework, view_renderer_treerendererinterface, zendframework_view_renderer_treerendererinterface_method_entry);

	return SUCCESS;

}

/**
 * Indicate whether the renderer is capable of rendering trees of view models
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Renderer_TreeRendererInterface, canRenderTrees);

