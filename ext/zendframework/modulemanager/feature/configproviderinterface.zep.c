
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_ConfigProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, ConfigProviderInterface, zendframework, modulemanager_feature_configproviderinterface, zendframework_modulemanager_feature_configproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns configuration to merge with application configuration
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_ConfigProviderInterface, getConfig);

