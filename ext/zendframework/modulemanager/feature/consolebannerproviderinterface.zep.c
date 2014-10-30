
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_ConsoleBannerProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, ConsoleBannerProviderInterface, zendframework, modulemanager_feature_consolebannerproviderinterface, zendframework_modulemanager_feature_consolebannerproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns a string containing a banner text, that describes the module and/or the application.
 * The banner is shown in the console window, when the user supplies invalid command-line parameters or invokes
 * the application with no parameters.
 *
 * The method is called with active Zend\Console\Adapter\AdapterInterface that can be used to directly access Console and send
 * output.
 *
 * @param AdapterInterface $console
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_ConsoleBannerProviderInterface, getConsoleBanner);

