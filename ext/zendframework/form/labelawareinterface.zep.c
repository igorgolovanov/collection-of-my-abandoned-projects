
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
ZEPHIR_INIT_CLASS(ZendFramework_Form_LabelAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, LabelAwareInterface, zendframework, form_labelawareinterface, zendframework_form_labelawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the label (if any) used for this element
 *
 * @param  $label
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, setLabel);

/**
 * Retrieve the label (if any) used for this element
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, getLabel);

/**
 * Set the attributes to use with the label
 *
 * @param array $labelAttributes
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, setLabelAttributes);

/**
 * Get the attributes to use with the label
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, getLabelAttributes);

/**
 * Set many label options at once
 *
 * Implementation will decide if this will overwrite or merge.
 *
 * @param  array|\Traversable $arrayOrTraversable
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, setLabelOptions);

/**
 * Get label specific options
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, getLabelOptions);

/**
 * Set a single label optionn
 *
 * @param  string $key
 * @param  mixed  $value
 * @return Element|ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, setLabelOption);

/**
 * Retrieve a single label option
 *
 * @param  $key
 * @return mixed|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, getLabelOption);

/**
 * Remove a single label option
 *
 * @param string $key
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, removeLabelOption);

/**
 * Does the element has a specific label option ?
 *
 * @param  string $key
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, hasLabelOption);

/**
 * Remove many attributes at once
 *
 * @param array $keys
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, removeLabelOptions);

/**
 * Clear all label options
 *
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_LabelAwareInterface, clearLabelOptions);

