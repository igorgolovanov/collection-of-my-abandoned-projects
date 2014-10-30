
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
ZEPHIR_INIT_CLASS(ZendFramework_Form_FormInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, FormInterface, zendframework, form_forminterface, zendframework_form_forminterface_method_entry);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("BIND_ON_VALIDATE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("BIND_MANUAL"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("VALIDATE_ALL"), 16 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("VALUES_NORMALIZED"), 17 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("VALUES_RAW"), 18 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_form_forminterface_ce, SL("VALUES_AS_ARRAY"), 19 TSRMLS_CC);

	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, zendframework_form_fieldsetinterface_ce);
	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, zendframework_form_formfactoryawareinterface_ce);
	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, zendframework_form_elementprepareawareinterface_ce);
	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, zendframework_form_elementinterface_ce);
	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(zendframework_form_forminterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Set data to validate and/or populate elements
 *
 * Typically, also passes data on to the composed input filter.
 *
 * @param  array|\ArrayAccess $data
 * @return FormInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, setData);

/**
 * Bind an object to the element
 *
 * Allows populating the object with validated values.
 *
 * @param  object $object
 * @param  int $flags
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, bind);

/**
 * Whether or not to bind values to the bound object when validation succeeds
 *
 * @param  int $bindOnValidateFlag
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, setBindOnValidate);

/**
 * Set input filter
 *
 * @param  InputFilterInterface $inputFilter
 * @return FormInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, setInputFilter);

/**
 * Retrieve input filter
 *
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, getInputFilter);

/**
 * Validate the form
 *
 * Typically, will proxy to the composed input filter.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, isValid);

/**
 * Retrieve the validated data
 *
 * By default, retrieves normalized values; pass one of the VALUES_*
 * constants to shape the behavior.
 *
 * @param  int $flag
 * @return array|object
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, getData);

/**
 * Set the validation group (set of values to validate)
 *
 * Typically, proxies to the composed input filter
 *
 * @return FormInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FormInterface, setValidationGroup);

