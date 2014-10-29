
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
ZEPHIR_INIT_CLASS(ZendFramework_View_Helper_HelperInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Helper, HelperInterface, zendframework, view_helper_helperinterface, zendframework_view_helper_helperinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the View object
 *
 * @param  Renderer $view
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_HelperInterface, setView);

/**
 * Get the View object
 *
 * @return Renderer
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_HelperInterface, getView);

