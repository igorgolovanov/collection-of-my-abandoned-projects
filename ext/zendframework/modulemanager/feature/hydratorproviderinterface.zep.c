
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_HydratorProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, HydratorProviderInterface, zendframework, modulemanager_feature_hydratorproviderinterface, zendframework_modulemanager_feature_hydratorproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Expected to return \Zend\ServiceManager\Config object or array to
 * seed such an object.
 *
 * @return array|\Zend\ServiceManager\Config
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_HydratorProviderInterface, getHydratorConfig);

