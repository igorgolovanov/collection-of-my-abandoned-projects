
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
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Storage_Part_PartInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Storage\\Part, PartInterface, zendframework, mail_storage_part_partinterface, zendframework_mail_storage_part_partinterface_method_entry);

	zend_class_implements(zendframework_mail_storage_part_partinterface_ce TSRMLS_CC, 1, spl_ce_RecursiveIterator);
	return SUCCESS;

}

/**
 * Check if part is a multipart message
 *
 * @return bool if part is multipart
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, isMultipart);

/**
 * Body of part
 *
 * If part is multipart the raw content of this part with all sub parts is returned
 *
 * @return string body
 * @throws Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getContent);

/**
 * Return size of part
 *
 * @return int size
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getSize);

/**
 * Get part of multipart message
 *
 * @param  int $num number of part starting with 1 for first part
 * @return PartInterface wanted part
 * @throws Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getPart);

/**
 * Count parts of a multipart part
 *
 * @return int number of sub-parts
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, countParts);

/**
 * Get all headers
 *
 * The returned headers are as saved internally. All names are lowercased. The value is a string or an array
 * if a header with the same name occurs more than once.
 *
 * @return \Zend\Mail\Headers
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getHeaders);

/**
 * Get a header in specified format
 *
 * Internally headers that occur more than once are saved as array, all other as string. If $format
 * is set to string implode is used to concat the values (with Zend\Mime\Mime::LINEEND as delim).
 *
 * @param  string $name   name of header, matches case-insensitive, but camel-case is replaced with dashes
 * @param  string $format change type of return value to 'string' or 'array'
 * @return string|array|\Zend\Mail\Header\HeaderInterface|\ArrayIterator value of header in wanted or internal format
 * @throws Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getHeader);

/**
 * Get a specific field from a header like content type or all fields as array
 *
 * If the header occurs more than once, only the value from the first header
 * is returned.
 *
 * Throws an exception if the requested header does not exist. If
 * the specific header field does not exist, returns null.
 *
 * @param  string $name       name of header, like in getHeader()
 * @param  string $wantedPart the wanted part, default is first, if null an array with all parts is returned
 * @param  string $firstName  key name for the first part
 * @return string|array wanted part or all parts as array($firstName => firstPart, partname => value)
 * @throws Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, getHeaderField);

/**
 * Getter for mail headers - name is matched in lowercase
 *
 * This getter is short for PartInterface::getHeader($name, 'string')
 *
 * @see PartInterface::getHeader()
 *
 * @param  string $name header name
 * @return string value of header
 * @throws Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, __get);

/**
 * magic method to get content of part
 *
 * @return string content
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Part_PartInterface, __toString);

