
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
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Header_HeaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Header, HeaderInterface, zendframework, mail_header_headerinterface, zendframework_mail_header_headerinterface_method_entry);

	zend_declare_class_constant_bool(zendframework_mail_header_headerinterface_ce, SL("FORMAT_ENCODED"), 1 TSRMLS_CC);

	zend_declare_class_constant_bool(zendframework_mail_header_headerinterface_ce, SL("FORMAT_RAW"), 0 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Factory to generate a header object from a string
 *
 * @param string $headerLine
 * @return self
 * @throws Exception\InvalidArgumentException If the header does not match with RFC 2822 definition.
 * @see http://tools.ietf.org/html/rfc2822#section-2.2
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, fromString);

/**
 * Retrieve header name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, getFieldName);

/**
 * Retrieve header value
 *
 * @param  bool $format Return the value in Mime::Encoded or in Raw format
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, getFieldValue);

/**
 * Set header encoding
 *
 * @param  string $encoding
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, setEncoding);

/**
 * Get header encoding
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, getEncoding);

/**
 * Cast to string
 *
 * Returns in form of "NAME: VALUE"
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Header_HeaderInterface, toString);

