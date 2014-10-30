
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
 * LocatorRegistered
 *
 * By implementing this interface in a Module class, the instance of the Module
 * class will be automatically injected into any DI-configured object which has
 * a constructor or setter parameter which is type hinted with the Module class
 * name. Implementing this interface obviously does not require adding any
 * methods to your class.
 */
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_LocatorRegisteredInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, LocatorRegisteredInterface, zendframework, modulemanager_feature_locatorregisteredinterface, NULL);

	return SUCCESS;

}

