
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
 * An interface description for Zend\Http\Client\Adapter\Stream classes.
 *
 * This interface describes Zend\Http\Client\Adapter which supports streaming.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_Client_Adapter_StreamInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Http\\Client\\Adapter, StreamInterface, zendframework, http_client_adapter_streaminterface, zendframework_http_client_adapter_streaminterface_method_entry);

	return SUCCESS;

}

/**
 * Set output stream
 *
 * This function sets output stream where the result will be stored.
 *
 * @param resource $stream Stream to write the output to
 *
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Client_Adapter_StreamInterface, setOutputStream);

