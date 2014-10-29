
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
/*
* Basically, an ArrayObject. You could simply define something like:
* class QueryParams extends ArrayObject implements Parameters {}
* and have 90% of the functionality
*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ParametersInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, ParametersInterface, zendframework, stdlib_parametersinterface, zendframework_stdlib_parametersinterface_method_entry);

	zend_class_implements(zendframework_stdlib_parametersinterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(zendframework_stdlib_parametersinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_stdlib_parametersinterface_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array $values
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, __construct);

/**
 * From array
 *
 * Allow deserialization from standard array
 *
 * @param array $values
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, fromArray);

/**
 * From string
 *
 * Allow deserialization from raw body; e.g., for PUT requests
 *
 * @param $string
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, fromString);

/**
 * To array
 *
 * Allow serialization back to standard array
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, toArray);

/**
 * To string
 *
 * Allow serialization to query format; e.g., for PUT or POST requests
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, toString);

/**
 * Get
 *
 * @param string $name
 * @param mixed|null $default
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, get);

/**
 * Set
 *
 * @param string $name
 * @param mixed $value
 * @return ParametersInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParametersInterface, set);

