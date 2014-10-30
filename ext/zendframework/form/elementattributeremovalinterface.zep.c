
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
ZEPHIR_INIT_CLASS(ZendFramework_Form_ElementAttributeRemovalInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, ElementAttributeRemovalInterface, zendframework, form_elementattributeremovalinterface, zendframework_form_elementattributeremovalinterface_method_entry);

	return SUCCESS;

}

/**
 * Remove a single element attribute
 *
 * @param  string $key
 * @return ElementAttributeRemovalInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementAttributeRemovalInterface, removeAttribute);

/**
 * Remove many attributes at once
 *
 * @param array $keys
 * @return ElementAttributeRemovalInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementAttributeRemovalInterface, removeAttributes);

/**
 * Remove all attributes at once
 *
 * @return ElementAttributeRemovalInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementAttributeRemovalInterface, clearAttributes);

