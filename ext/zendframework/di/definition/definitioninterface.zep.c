
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Di_Definition_DefinitionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Di\\Definition, DefinitionInterface, zendframework, di_definition_definitioninterface, zendframework_di_definition_definitioninterface_method_entry);

	return SUCCESS;

}

/**
 * Retrieves classes in this definition
 *
 * @abstract
 * @return string[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, getClasses);

/**
 * Return whether the class exists in this definition
 *
 * @abstract
 * @param  string $class
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, hasClass);

/**
 * Return the supertypes for this class
 *
 * @abstract
 * @param  string   $class
 * @return string[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, getClassSupertypes);

/**
 * @abstract
 * @param  string       $class
 * @return string|array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, getInstantiator);

/**
 * Return if there are injection methods
 *
 * @abstract
 * @param  string $class
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, hasMethods);

/**
 * Return an array of the injection methods for a given class
 *
 * @abstract
 * @param  string   $class
 * @return string[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, getMethods);

/**
 * @abstract
 * @param  string $class
 * @param  string $method
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, hasMethod);

/**
 * @abstract
 * @param $class
 * @param $method
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, hasMethodParameters);

/**
 * getMethodParameters() return information about a methods parameters.
 *
 * Should return an ordered named array of parameters for a given method.
 * Each value should be an array, of length 4 with the following information:
 *
 * array(
 *     0, // string|null: Type Name (if it exists)
 *     1, // bool: whether this param is required
 *     2, // string: fully qualified path to this parameter
 *     3, // mixed: default value
 * );
 *
 *
 * @abstract
 * @param  string $class
 * @param  string $method
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_Definition_DefinitionInterface, getMethodParameters);

