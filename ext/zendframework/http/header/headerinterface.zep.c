
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Interface for HTTP Header classes.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_Header_HeaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Http\\Header, HeaderInterface, zendframework, http_header_headerinterface, zendframework_http_header_headerinterface_method_entry);

	return SUCCESS;

}

/**
 * Factory to generate a header object from a string
 *
 * @param string $headerLine
 * @return self
 * @throws Exception\InvalidArgumentException If the header does not match RFC 2616 definition.
 * @see http://tools.ietf.org/html/rfc2616#section-4.2
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Header_HeaderInterface, fromString);

/**
 * Retrieve header name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Header_HeaderInterface, getFieldName);

/**
 * Retrieve header value
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Header_HeaderInterface, getFieldValue);

/**
 * Cast to string
 *
 * Returns in form of "NAME: VALUE"
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Http_Header_HeaderInterface, toString);

