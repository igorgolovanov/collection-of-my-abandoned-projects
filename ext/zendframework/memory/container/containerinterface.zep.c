
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
/**
 * Memory value container interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Memory_Container_ContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Memory\\Container, ContainerInterface, zendframework, memory_container_containerinterface, zendframework_memory_container_containerinterface_method_entry);

	return SUCCESS;

}

/**
 * Get string value reference
 *
 * _Must_ be used for value access before PHP v 5.2
 * or _may_ be used for performance considerations
 *
 * @return &string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Memory_Container_ContainerInterface, getRef);

/**
 * Signal, that value is updated by external code.
 *
 * Should be used together with getRef()
 */
ZEPHIR_DOC_METHOD(ZendFramework_Memory_Container_ContainerInterface, touch);

/**
 * Lock object in memory.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Memory_Container_ContainerInterface, lock);

/**
 * Unlock object
 */
ZEPHIR_DOC_METHOD(ZendFramework_Memory_Container_ContainerInterface, unlock);

/**
 * Return true if object is locked
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Memory_Container_ContainerInterface, isLocked);

