
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
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_ServiceManagerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, ServiceManagerAwareInterface, zendframework, servicemanager_servicemanagerawareinterface, zendframework_servicemanager_servicemanagerawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Set service manager
 *
 * @param ServiceManager $serviceManager
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ServiceManagerAwareInterface, setServiceManager);

