
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_DriverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Driver, DriverInterface, zendframework, db_adapter_driver_driverinterface, zendframework_db_adapter_driver_driverinterface_method_entry);

	zend_declare_class_constant_string(zendframework_db_adapter_driver_driverinterface_ce, SL("PARAMETERIZATION_POSITIONAL"), "positional" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_adapter_driver_driverinterface_ce, SL("PARAMETERIZATION_NAMED"), "named" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_adapter_driver_driverinterface_ce, SL("NAME_FORMAT_CAMELCASE"), "camelCase" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_adapter_driver_driverinterface_ce, SL("NAME_FORMAT_NATURAL"), "natural" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get database platform name
 *
 * @param string $nameFormat
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, getDatabasePlatformName);

/**
 * Check environment
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, checkEnvironment);

/**
 * Get connection
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, getConnection);

/**
 * Create statement
 *
 * @param string|resource $sqlOrResource
 * @return StatementInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, createStatement);

/**
 * Create result
 *
 * @param resource $resource
 * @return ResultInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, createResult);

/**
 * Get prepare type
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, getPrepareType);

/**
 * Format parameter name
 *
 * @param string $name
 * @param mixed  $type
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, formatParameterName);

/**
 * Get last generated value
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_DriverInterface, getLastGeneratedValue);

