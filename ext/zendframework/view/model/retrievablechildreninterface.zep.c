
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
 * Interface describing a Retrievable Child Model
 *
 * Models implementing this interface provide a way to get there children by capture
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Model_RetrievableChildrenInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Model, RetrievableChildrenInterface, zendframework, view_model_retrievablechildreninterface, zendframework_view_model_retrievablechildreninterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an array of Viewmodels with captureTo value $capture
 *
 * @param string $capture
 * @param bool $recursive search recursive through children, default true
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_RetrievableChildrenInterface, getChildrenByCaptureTo);

