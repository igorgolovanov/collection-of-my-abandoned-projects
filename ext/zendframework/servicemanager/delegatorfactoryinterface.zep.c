
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
 * Interface for factories that can create delegates for services
 */
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_DelegatorFactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, DelegatorFactoryInterface, zendframework, servicemanager_delegatorfactoryinterface, zendframework_servicemanager_delegatorfactoryinterface_method_entry);

	return SUCCESS;

}

/**
 * A factory that creates delegates of a given service
 *
 * @param ServiceLocatorInterface $serviceLocator the service locator which requested the service
 * @param string                  $name           the normalized service name
 * @param string                  $requestedName  the requested service name
 * @param callable                $callback       the callback that is responsible for creating the service
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_DelegatorFactoryInterface, createDelegatorWithName);

