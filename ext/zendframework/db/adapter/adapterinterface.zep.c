
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
 *
 * @property Driver\DriverInterface $driver
 * @property Platform\PlatformInterface $platform
 */
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter, AdapterInterface, zendframework, db_adapter_adapterinterface, zendframework_db_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * @return Driver\DriverInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_AdapterInterface, getDriver);

/**
 * @return Platform\PlatformInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_AdapterInterface, getPlatform);

