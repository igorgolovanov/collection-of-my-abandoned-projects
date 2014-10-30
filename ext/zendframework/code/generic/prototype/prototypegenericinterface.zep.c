
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
ZEPHIR_INIT_CLASS(ZendFramework_Code_Generic_Prototype_PrototypeGenericInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Generic\\Prototype, PrototypeGenericInterface, zendframework, code_generic_prototype_prototypegenericinterface, zendframework_code_generic_prototype_prototypegenericinterface_method_entry);

	zend_class_implements(zendframework_code_generic_prototype_prototypegenericinterface_ce TSRMLS_CC, 1, zendframework_code_generic_prototype_prototypeinterface_ce);
	return SUCCESS;

}

/**
 * @param string $name
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Generic_Prototype_PrototypeGenericInterface, setName);

