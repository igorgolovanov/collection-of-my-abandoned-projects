
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
ZEPHIR_INIT_CLASS(ZendFramework_Form_ElementInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, ElementInterface, zendframework, form_elementinterface, zendframework_form_elementinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the name of this element
 *
 * In most cases, this will proxy to the attributes for storage, but is
 * present to indicate that elements are generally named.
 *
 * @param  string $name
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setName);

/**
 * Retrieve the element name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getName);

/**
 * Set options for an element
 *
 * @param  array|\Traversable $options
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setOptions);

/**
 * Set a single option for an element
 *
 * @param  string $key
 * @param  mixed $value
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setOption);

/**
 * get the defined options
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getOptions);

/**
 * return the specified option
 *
 * @param string $option
 * @return null|mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getOption);

/**
 * Set a single element attribute
 *
 * @param  string $key
 * @param  mixed $value
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setAttribute);

/**
 * Retrieve a single element attribute
 *
 * @param  string $key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getAttribute);

/**
 * Return true if a specific attribute is set
 *
 * @param  string $key
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, hasAttribute);

/**
 * Set many attributes at once
 *
 * Implementation will decide if this will overwrite or merge.
 *
 * @param  array|\Traversable $arrayOrTraversable
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setAttributes);

/**
 * Retrieve all attributes at once
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getAttributes);

/**
 * Set the value of the element
 *
 * @param  mixed $value
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setValue);

/**
 * Retrieve the element value
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getValue);

/**
 * Set the label (if any) used for this element
 *
 * @param  $label
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setLabel);

/**
 * Retrieve the label (if any) used for this element
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getLabel);

/**
 * Set a list of messages to report when validation fails
 *
 * @param  array|\Traversable $messages
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, setMessages);

/**
 * Get validation error messages, if any
 *
 * Returns a list of validation failure messages, if any.
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_ElementInterface, getMessages);

