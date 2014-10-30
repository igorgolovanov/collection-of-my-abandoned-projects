
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
/**
 * An interface description for Zend\Http\Client\Adapter classes.
 *
 * These classes are used as connectors for Zend\Http\Client, performing the
 * tasks of connecting, writing, reading and closing connection to the server.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_Client_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Http\\Client\\Adapter, AdapterInterface, zendframework, http_client_adapter_adapterinterface, zendframework_http_client_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the configuration array for the adapter
 *
 * @param array $options
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_AdapterInterface, setOptions);

/**
 * Connect to the remote server
 *
 * @param string  $host
 * @param int     $port
 * @param  bool $secure
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_AdapterInterface, connect);

/**
 * Send request to the remote server
 *
 * @param string        $method
 * @param UriInterface  $url
 * @param string        $httpVer
 * @param array         $headers
 * @param string        $body
 * @return string Request as text
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_AdapterInterface, write);

/**
 * Read response from server
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_AdapterInterface, read);

/**
 * Close the connection to the server
 *
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_AdapterInterface, close);

