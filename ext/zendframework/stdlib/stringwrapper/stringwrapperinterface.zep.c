
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\StringWrapper, StringWrapperInterface, zendframework, stdlib_stringwrapper_stringwrapperinterface, zendframework_stdlib_stringwrapper_stringwrapperinterface_method_entry);

	return SUCCESS;

}

/**
 * Check if the given character encoding is supported by this wrapper
 * and the character encoding to convert to is also supported.
 *
 * @param string      $encoding
 * @param string|null $convertEncoding
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, isSupported);

/**
 * Get a list of supported character encodings
 *
 * @return string[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, getSupportedEncodings);

/**
 * Set character encoding working with and convert to
 *
 * @param string      $encoding         The character encoding to work with
 * @param string|null $convertEncoding  The character encoding to convert to
 * @return StringWrapperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, setEncoding);

/**
 * Get the defined character encoding to work with (upper case)
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, getEncoding);

/**
 * Get the defined character encoding to convert to (upper case)
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, getConvertEncoding);

/**
 * Returns the length of the given string
 *
 * @param string $str
 * @return int|false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strlen);

/**
 * Returns the portion of string specified by the start and length parameters
 *
 * @param string   $str
 * @param int      $offset
 * @param int|null $length
 * @return string|false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, substr);

/**
 * Find the position of the first occurrence of a substring in a string
 *
 * @param string $haystack
 * @param string $needle
 * @param int    $offset
 * @return int|false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strpos);

/**
 * Convert a string from defined encoding to the defined convert encoding
 *
 * @param string  $str
 * @param bool $reverse
 * @return string|false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, convert);

/**
 * Wraps a string to a given number of characters
 *
 * @param  string  $str
 * @param  int $width
 * @param  string  $break
 * @param  bool $cut
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, wordWrap);

/**
 * Pad a string to a certain length with another string
 *
 * @param  string  $input
 * @param  int $padLength
 * @param  string  $padString
 * @param  int $padType
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_StringWrapper_StringWrapperInterface, strPad);

