
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
ZEPHIR_INIT_CLASS(ZendFramework_Code_Reflection_ReflectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Reflection, ReflectionInterface, zendframework, code_reflection_reflectioninterface, zendframework_code_reflection_reflectioninterface_method_entry);

	zend_class_implements(zendframework_code_reflection_reflectioninterface_ce TSRMLS_CC, 1, reflector_ptr);
	return SUCCESS;

}

/**
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Reflection_ReflectionInterface, toString);

