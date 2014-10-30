
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Form_ElementPrepareAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, ElementPrepareAwareInterface, zendframework, form_elementprepareawareinterface, zendframework_form_elementprepareawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Prepare the form element (mostly used for rendering purposes)
 *
 * @param FormInterface $form
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementPrepareAwareInterface, prepareElement);

