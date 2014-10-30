
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_StatementInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Driver, StatementInterface, zendframework, db_adapter_driver_statementinterface, zendframework_db_adapter_driver_statementinterface_method_entry);

	zend_class_implements(zendframework_db_adapter_driver_statementinterface_ce TSRMLS_CC, 1, zendframework_db_adapter_statementcontainerinterface_ce);
	return SUCCESS;

}

/**
 * Get resource
 *
 * @return resource
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_StatementInterface, getResource);

/**
 * Prepare sql
 *
 * @param string $sql
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_StatementInterface, prepare);

/**
 * Check if is prepared
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_StatementInterface, isPrepared);

/**
 * Execute
 *
 * @param null $parameters
 * @return ResultInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_StatementInterface, execute);

