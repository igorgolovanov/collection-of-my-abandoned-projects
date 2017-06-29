
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


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Thrown by Zend\Json\Server\Client when an HTTP error occurs during an
 * JSON-RPC method call.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Json_Server_Exception_HttpException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Json\\Server\\Exception, HttpException, zendframework, json_server_exception_httpexception, zendframework_json_server_exception_runtimeexception_ce, NULL, 0);

	return SUCCESS;

}

