
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Client Interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Server_Client) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Server, Client, zendframework, server_client, zendframework_server_client_method_entry);

	return SUCCESS;

}

/**
 * Executes remote call
 *
 * Unified interface for calling custom remote methods.
 *
 * @param  string $method Remote call name.
 * @param  array $params Call parameters.
 * @return mixed Remote call results.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Client, call);

