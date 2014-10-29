
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
/**
 * Service locator interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_ServiceLocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, ServiceLocatorInterface, zendframework, servicemanager_servicelocatorinterface, zendframework_servicemanager_servicelocatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Retrieve a registered instance
 *
 * @param  string  $name
 * @throws Exception\ServiceNotFoundException
 * @return object|array
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ServiceLocatorInterface, get);

/**
 * Check for a registered instance
 *
 * @param  string|array  $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ServiceLocatorInterface, has);

