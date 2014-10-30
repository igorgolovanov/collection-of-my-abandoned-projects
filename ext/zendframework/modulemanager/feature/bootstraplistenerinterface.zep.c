
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
 * Bootstrap listener provider interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_BootstrapListenerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, BootstrapListenerInterface, zendframework, modulemanager_feature_bootstraplistenerinterface, zendframework_modulemanager_feature_bootstraplistenerinterface_method_entry);

	return SUCCESS;

}

/**
 * Listen to the bootstrap event
 *
 * @param EventInterface $e
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_BootstrapListenerInterface, onBootstrap);

