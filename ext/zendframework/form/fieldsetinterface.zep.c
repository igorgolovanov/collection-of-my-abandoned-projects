
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
ZEPHIR_INIT_CLASS(ZendFramework_Form_FieldsetInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, FieldsetInterface, zendframework, form_fieldsetinterface, zendframework_form_fieldsetinterface_method_entry);

	zend_class_implements(zendframework_form_fieldsetinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_form_fieldsetinterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(zendframework_form_fieldsetinterface_ce TSRMLS_CC, 1, zendframework_form_elementinterface_ce);
	zend_class_implements(zendframework_form_fieldsetinterface_ce TSRMLS_CC, 1, zendframework_form_elementprepareawareinterface_ce);
	zend_class_implements(zendframework_form_fieldsetinterface_ce TSRMLS_CC, 1, zendframework_form_formfactoryawareinterface_ce);
	return SUCCESS;

}

/**
 * Add an element or fieldset
 *
 * $flags could contain metadata such as the alias under which to register
 * the element or fieldset, order in which to prioritize it, etc.
 *
 * @param  array|\Traversable|ElementInterface $elementOrFieldset Typically, only allow objects implementing ElementInterface;
 *                                                                however, keeping it flexible to allow a factory-based form
 *                                                                implementation as well
 * @param  array $flags
 * @return FieldsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, add);

/**
 * Does the fieldset have an element/fieldset by the given name?
 *
 * @param  string $elementOrFieldset
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, has);

/**
 * Retrieve a named element or fieldset
 *
 * @param  string $elementOrFieldset
 * @return ElementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, get);

/**
 * Remove a named element or fieldset
 *
 * @param  string $elementOrFieldset
 * @return FieldsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, remove);

/**
 * Set/change the priority of an element or fieldset
 *
 * @param string $elementOrFieldset
 * @param int $priority
 * @return FieldsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, setPriority);

/**
 * Retrieve all attached elements
 *
 * Storage is an implementation detail of the concrete class.
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, getElements);

/**
 * Retrieve all attached fieldsets
 *
 * Storage is an implementation detail of the concrete class.
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, getFieldsets);

/**
 * Recursively populate value attributes of elements
 *
 * @param  array|\Traversable $data
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, populateValues);

/**
 * Set the object used by the hydrator
 *
 * @param  $object
 * @return FieldsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, setObject);

/**
 * Get the object used by the hydrator
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, getObject);

/**
 * Checks if the object can be set in this fieldset
 *
 * @param $object
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, allowObjectBinding);

/**
 * Set the hydrator to use when binding an object to the element
 *
 * @param  HydratorInterface $hydrator
 * @return FieldsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, setHydrator);

/**
 * Get the hydrator used when binding an object to the element
 *
 * @return null|HydratorInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, getHydrator);

/**
 * Bind values to the bound object
 *
 * @param  array $values
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, bindValues);

/**
 * Checks if this fieldset can bind data
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetInterface, allowValueBinding);

