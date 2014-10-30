
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_DependencyIndicatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, DependencyIndicatorInterface, zendframework, modulemanager_feature_dependencyindicatorinterface, zendframework_modulemanager_feature_dependencyindicatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Expected to return an array of modules on which the current one depends on
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_DependencyIndicatorInterface, getModuleDependencies);

