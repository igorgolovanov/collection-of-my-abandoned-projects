
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
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_AbstractFactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, AbstractFactoryInterface, zendframework, servicemanager_abstractfactoryinterface, zendframework_servicemanager_abstractfactoryinterface_method_entry);

	return SUCCESS;

}

/**
 * Determine if we can create a service with name
 *
 * @param ServiceLocatorInterface $serviceLocator
 * @param $name
 * @param $requestedName
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_AbstractFactoryInterface, canCreateServiceWithName);

/**
 * Create service with name
 *
 * @param ServiceLocatorInterface $serviceLocator
 * @param $name
 * @param $requestedName
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_AbstractFactoryInterface, createServiceWithName);

