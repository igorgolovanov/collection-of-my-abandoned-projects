
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_ResultInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Driver, ResultInterface, zendframework, db_adapter_driver_resultinterface, zendframework_db_adapter_driver_resultinterface_method_entry);

	zend_class_implements(zendframework_db_adapter_driver_resultinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_db_adapter_driver_resultinterface_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Force buffering
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, buffer);

/**
 * Check if is buffered
 *
 * @return bool|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, isBuffered);

/**
 * Is query result?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, isQueryResult);

/**
 * Get affected rows
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, getAffectedRows);

/**
 * Get generated value
 *
 * @return mixed|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, getGeneratedValue);

/**
 * Get the resource
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, getResource);

/**
 * Get field count
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_ResultInterface, getFieldCount);

