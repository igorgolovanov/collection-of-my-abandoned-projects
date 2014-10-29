
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
ZEPHIR_INIT_CLASS(ZendFramework_ServiceManager_ConfigInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ServiceManager, ConfigInterface, zendframework, servicemanager_configinterface, zendframework_servicemanager_configinterface_method_entry);

	return SUCCESS;

}

/**
 * Configure service manager
 *
 * @param ServiceManager $serviceManager
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_ServiceManager_ConfigInterface, configureServiceManager);

