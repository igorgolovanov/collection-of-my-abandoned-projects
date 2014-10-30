
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_ConnectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Driver, ConnectionInterface, zendframework, db_adapter_driver_connectioninterface, zendframework_db_adapter_driver_connectioninterface_method_entry);

	return SUCCESS;

}

/**
 * Get current schema
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, getCurrentSchema);

/**
 * Get resource
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, getResource);

/**
 * Connect
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, connect);

/**
 * Is connected
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, isConnected);

/**
 * Disconnect
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, disconnect);

/**
 * Begin transaction
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, beginTransaction);

/**
 * Commit
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, commit);

/**
 * Rollback
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, rollback);

/**
 * Execute
 *
 * @param  string $sql
 * @return ResultInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, execute);

/**
 * Get last generated id
 *
 * @param  null $name Ignored
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ConnectionInterface, getLastGeneratedValue);

