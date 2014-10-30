
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
ZEPHIR_INIT_CLASS(ZendFramework_Console_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Console\\Adapter, AdapterInterface, zendframework, console_adapter_adapterinterface, zendframework_console_adapter_adapterinterface_method_entry);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("LINE_NONE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("LINE_SINGLE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("LINE_DOUBLE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("LINE_BLOCK"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("FILL_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("FILL_SHADE_LIGHT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("FILL_SHADE_MEDIUM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("FILL_SHADE_DARK"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_adapter_adapterinterface_ce, SL("FILL_BLOCK"), 10 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Write a chunk of text to console.
 *
 * @param string                   $text
 * @param null|int $color
 * @param null|int $bgColor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, write);

/**
 * Alias for write()
 *
 * @param string                   $text
 * @param null|int $color
 * @param null|int $bgColor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, writeText);

/**
 * Write a single line of text to console and advance cursor to the next line.
 * If the text is longer than console width it will be truncated.
 *
 * @param string                   $text
 * @param null|int $color
 * @param null|int $bgColor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, writeLine);

/**
 * Write a piece of text at the coordinates of $x and $y
 *
 * @param string                   $text     Text to write
 * @param int                      $x        Console X coordinate (column)
 * @param int                      $y        Console Y coordinate (row)
 * @param null|int $color
 * @param null|int $bgColor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, writeAt);

/**
 * Write a box at the specified coordinates.
 * If X or Y coordinate value is negative, it will be calculated as the distance from far right or bottom edge
 * of the console (respectively).
 *
 * @param int                      $x1           Top-left corner X coordinate (column)
 * @param int                      $y1           Top-left corner Y coordinate (row)
 * @param int                      $x2           Bottom-right corner X coordinate (column)
 * @param int                      $y2           Bottom-right corner Y coordinate (row)
 * @param int                      $lineStyle    (optional) Box border style.
 * @param int                      $fillStyle    (optional) Box fill style or a single character to fill it with.
 * @param int      $color        (optional) Foreground color
 * @param int      $bgColor      (optional) Background color
 * @param null|int $fillColor    (optional) Foreground color of box fill
 * @param null|int $fillBgColor  (optional) Background color of box fill
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, writeBox);

/**
 * Write a block of text at the given coordinates, matching the supplied width and height.
 * In case a line of text does not fit desired width, it will be wrapped to the next line.
 * In case the whole text does not fit in desired height, it will be truncated.
 *
 * @param string                   $text     Text to write
 * @param int                      $width    Maximum block width. Negative value means distance from right edge.
 * @param int|null                 $height   Maximum block height. Negative value means distance from bottom edge.
 * @param int                      $x        Block X coordinate (column)
 * @param int                      $y        Block Y coordinate (row)
 * @param null|int                 $color    (optional) Text color
 * @param null|int $bgColor  (optional) Text background color
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, writeTextBlock);

/**
 * Determine and return current console width.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getWidth);

/**
 * Determine and return current console height.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getHeight);

/**
 * Determine and return current console width and height.
 *
 * @return array        array($width, $height)
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getSize);

/**
 * Check if console is UTF-8 compatible
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, isUtf8);

/**
 * Set cursor position
 *
 * @param int   $x
 * @param int   $y
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, setPos);

/**
 * Hide console cursor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, hideCursor);

/**
 * Show console cursor
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, showCursor);

/**
 * Return current console window title.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getTitle);

/**
 * Prepare a string that will be rendered in color.
 *
 * @param string                     $string
 * @param null|int   $color    Foreground color
 * @param null|int   $bgColor  Background color
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, colorize);

/**
 * Change current drawing color.
 *
 * @param int $color
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, setColor);

/**
 * Change current drawing background color
 *
 * @param int $color
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, setBgColor);

/**
 * Reset color to console default.
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, resetColor);

/**
 * Set Console charset to use.
 *
 * @param CharsetInterface $charset
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, setCharset);

/**
 * Get charset currently in use by this adapter.
 *
 * @return CharsetInterface $charset
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getCharset);

/**
 * @return CharsetInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, getDefaultCharset);

/**
 * Clear console screen
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, clear);

/**
 * Clear line at cursor position
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, clearLine);

/**
 * Clear console screen
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, clearScreen);

/**
 * Read a single line from the console input
 *
 * @param int $maxLength        Maximum response length
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, readLine);

/**
 * Read a single character from the console input
 *
 * @param string|null   $mask   A list of allowed chars
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Adapter_AdapterInterface, readChar);

