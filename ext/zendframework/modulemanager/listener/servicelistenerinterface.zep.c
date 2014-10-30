
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Listener_ServiceListenerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Listener, ServiceListenerInterface, zendframework, modulemanager_listener_servicelistenerinterface, zendframework_modulemanager_listener_servicelistenerinterface_method_entry);

	zend_class_implements(zendframework_modulemanager_listener_servicelistenerinterface_ce TSRMLS_CC, 1, zendframework_eventmanager_listeneraggregateinterface_ce);
	return SUCCESS;

}

/**
 * @param  ServiceManager|string $serviceManager  Service Manager instance or name
 * @param  string                $key             Configuration key
 * @param  string                $moduleInterface FQCN as string
 * @param  string                $method          Method name
 * @return ServiceListenerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Listener_ServiceListenerInterface, addServiceManager);

/**
 * @param  array $configuration
 * @return ServiceListenerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Listener_ServiceListenerInterface, setDefaultServiceConfig);

