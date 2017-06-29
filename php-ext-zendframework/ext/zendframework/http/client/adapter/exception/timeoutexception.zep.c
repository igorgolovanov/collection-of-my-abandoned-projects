
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_Client_Adapter_Exception_TimeoutException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http\\Client\\Adapter\\Exception, TimeoutException, zendframework, http_client_adapter_exception_timeoutexception, zendframework_http_client_adapter_exception_runtimeexception_ce, NULL, 0);

	zend_declare_class_constant_long(zendframework_http_client_adapter_exception_timeoutexception_ce, SL("READ_TIMEOUT"), 1000 TSRMLS_CC);

	return SUCCESS;

}

