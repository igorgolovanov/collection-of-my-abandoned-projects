
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
ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_InputFilterAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\InputFilter, InputFilterAwareInterface, zendframework, inputfilter_inputfilterawareinterface, zendframework_inputfilter_inputfilterawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Set input filter
 *
 * @param  InputFilterInterface $inputFilter
 * @return InputFilterAwareInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterAwareInterface, setInputFilter);

/**
 * Retrieve input filter
 *
 * @return InputFilterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputFilterAwareInterface, getInputFilter);

