
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
ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_InputFilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\InputFilter, InputFilterInterface, zendframework, inputfilter_inputfilterinterface, zendframework_inputfilter_inputfilterinterface_method_entry);

	zend_declare_class_constant_string(zendframework_inputfilter_inputfilterinterface_ce, SL("VALIDATE_ALL"), "INPUT_FILTER_ALL" TSRMLS_CC);

	zend_class_implements(zendframework_inputfilter_inputfilterinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Add an input to the input filter
 *
 * @param  InputInterface|InputFilterInterface|array $input
 * @param  null|string $name Name used to retrieve this input
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, add);

/**
 * Retrieve a named input
 *
 * @param  string $name
 * @return InputInterface|InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, get);

/**
 * Test if an input or input filter by the given name is attached
 *
 * @param  string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, has);

/**
 * Remove a named input
 *
 * @param  string $name
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, remove);

/**
 * Set data to use when validating and filtering
 *
 * @param  array|Traversable $data
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, setData);

/**
 * Is the data set valid?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, isValid);

/**
 * Provide a list of one or more elements indicating the complete set to validate
 *
 * When provided, calls to {@link isValid()} will only validate the provided set.
 *
 * If the initial value is {@link VALIDATE_ALL}, the current validation group, if
 * any, should be cleared.
 *
 * Implementations should allow passing a single array value, or multiple arguments,
 * each specifying a single input.
 *
 * @param  mixed $name
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, setValidationGroup);

/**
 * Return a list of inputs that were invalid.
 *
 * Implementations should return an associative array of name/input pairs
 * that failed validation.
 *
 * @return InputInterface[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getInvalidInput);

/**
 * Return a list of inputs that were valid.
 *
 * Implementations should return an associative array of name/input pairs
 * that passed validation.
 *
 * @return InputInterface[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getValidInput);

/**
 * Retrieve a value from a named input
 *
 * @param  string $name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getValue);

/**
 * Return a list of filtered values
 *
 * List should be an associative array, with the values filtered. If
 * validation failed, this should raise an exception.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getValues);

/**
 * Retrieve a raw (unfiltered) value from a named input
 *
 * @param  string $name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getRawValue);

/**
 * Return a list of unfiltered values
 *
 * List should be an associative array of named input/value pairs,
 * with the values unfiltered.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getRawValues);

/**
 * Return a list of validation failure messages
 *
 * Should return an associative array of named input/message list pairs.
 * Pairs should only be returned for inputs that failed validation.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterInterface, getMessages);

