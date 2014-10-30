
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Interface strategies that generate an XSD-Schema for complex data types in WSDL files.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Soap_Wsdl_ComplexTypeStrategy_ComplexTypeStrategyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Soap\\Wsdl\\ComplexTypeStrategy, ComplexTypeStrategyInterface, zendframework, soap_wsdl_complextypestrategy_complextypestrategyinterface, zendframework_soap_wsdl_complextypestrategy_complextypestrategyinterface_method_entry);

	return SUCCESS;

}

/**
 * Method accepts the current WSDL context file.
 *
 * @param Wsdl $context
 */
ZEPHIR_DOC_METHOD(ZendFramework_Soap_Wsdl_ComplexTypeStrategy_ComplexTypeStrategyInterface, setContext);

/**
 * Create a complex type based on a strategy
 *
 * @param  string $type
 * @return string XSD type
 */
ZEPHIR_DOC_METHOD(ZendFramework_Soap_Wsdl_ComplexTypeStrategy_ComplexTypeStrategyInterface, addComplexType);

