
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
 * Interface describing methods for clearing the state of a view model.
 *
 * View models implementing this interface allow clearing children, options,
 * and variables.
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Model_ClearableModelInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Model, ClearableModelInterface, zendframework, view_model_clearablemodelinterface, zendframework_view_model_clearablemodelinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ClearableModelInterface, clearChildren);

ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ClearableModelInterface, clearOptions);

ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ClearableModelInterface, clearVariables);

