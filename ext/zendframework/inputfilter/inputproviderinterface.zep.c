
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
ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_InputProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\InputFilter, InputProviderInterface, zendframework, inputfilter_inputproviderinterface, zendframework_inputfilter_inputproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Should return an array specification compatible with
 * {@link Zend\InputFilter\Factory::createInput()}.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_InputProviderInterface, getInputSpecification);

