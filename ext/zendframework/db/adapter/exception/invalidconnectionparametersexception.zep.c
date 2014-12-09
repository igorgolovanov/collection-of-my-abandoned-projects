
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Exception_InvalidConnectionParametersException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Db\\Adapter\\Exception, InvalidConnectionParametersException, zendframework, db_adapter_exception_invalidconnectionparametersexception, zendframework_db_adapter_exception_runtimeexception_ce, zendframework_db_adapter_exception_invalidconnectionparametersexception_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_null(zendframework_db_adapter_exception_invalidconnectionparametersexception_ce, SL("parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param string $message
 * @param int $parameters
 */
PHP_METHOD(ZendFramework_Db_Adapter_Exception_InvalidConnectionParametersException, __construct) {

	int parameters;
	zval *message_param = NULL, *parameters_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &message_param, &parameters_param);

	zephir_get_strval(message, message_param);
	parameters = zephir_get_intval(parameters_param);



}

