
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
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_ServiceLocatorAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, ServiceLocatorAwareInterface, zendframework, servicemanager_servicelocatorawareinterface, zendframework_servicemanager_servicelocatorawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Set service locator
 *
 * @param ServiceLocatorInterface $serviceLocator
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ServiceLocatorAwareInterface, setServiceLocator);

/**
 * Get service locator
 *
 * @return ServiceLocatorInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ServiceLocatorAwareInterface, getServiceLocator);

