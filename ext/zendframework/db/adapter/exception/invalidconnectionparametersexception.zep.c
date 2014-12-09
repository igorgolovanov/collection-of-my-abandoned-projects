
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


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

	int parameters, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *parameters_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &message_param, &parameters_param);

	zephir_get_strval(message, message_param);
	parameters = zephir_get_intval(parameters_param);


	ZEPHIR_CALL_PARENT(NULL, zendframework_db_adapter_exception_invalidconnectionparametersexception_ce, this_ptr, "__construct", NULL, message);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, parameters);
	zephir_update_property_this(this_ptr, SL("parameters"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

