
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
ZEPHIR_INIT_CLASS(ZendFramework_ModuleManager_Feature_ConsoleUsageProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ModuleManager\\Feature, ConsoleUsageProviderInterface, zendframework, modulemanager_feature_consoleusageproviderinterface, zendframework_modulemanager_feature_consoleusageproviderinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns an array or a string containing usage information for this module's Console commands.
 * The method is called with active Zend\Console\Adapter\AdapterInterface that can be used to directly access
 * Console and send output.
 *
 * If the result is a string it will be shown directly in the console window.
 * If the result is an array, its contents will be formatted to console window width. The array must
 * have the following format:
 *
 *     return array(
 *                'Usage information line that should be shown as-is',
 *                'Another line of usage info',
 *
 *                '--parameter'        =>   'A short description of that parameter',
 *                '-another-parameter' =>   'A short description of another parameter',
 *                ...
 *            )
 *
 * @param AdapterInterface $console
 * @return array|string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_ModuleManager_Feature_ConsoleUsageProviderInterface, getConsoleUsage);

