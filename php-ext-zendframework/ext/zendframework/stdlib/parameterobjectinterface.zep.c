
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ParameterObjectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, ParameterObjectInterface, zendframework, stdlib_parameterobjectinterface, zendframework_stdlib_parameterobjectinterface_method_entry);

	return SUCCESS;

}

/**
 * @param string $key
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParameterObjectInterface, __set);

/**
 * @param string $key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParameterObjectInterface, __get);

/**
 * @param string $key
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParameterObjectInterface, __isset);

/**
 * @param string $key
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_ParameterObjectInterface, __unset);

