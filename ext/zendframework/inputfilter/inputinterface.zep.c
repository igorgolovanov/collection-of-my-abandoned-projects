
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
ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_InputInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\InputFilter, InputInterface, zendframework, inputfilter_inputinterface, zendframework_inputfilter_inputinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setAllowEmpty);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setBreakOnFailure);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setErrorMessage);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setFilterChain);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setName);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setRequired);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setValidatorChain);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, setValue);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, merge);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, allowEmpty);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, breakOnFailure);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getErrorMessage);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getFilterChain);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getName);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getRawValue);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, isRequired);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getValidatorChain);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getValue);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, isValid);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputInterface, getMessages);

