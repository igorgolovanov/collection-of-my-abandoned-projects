
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Formatter_FormatterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Formatter, FormatterInterface, zendframework, log_formatter_formatterinterface, zendframework_log_formatter_formatterinterface_method_entry);

	zend_declare_class_constant_string(zendframework_log_formatter_formatterinterface_ce, SL("DEFAULT_DATETIME_FORMAT"), "c" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Formats data into a single line to be written by the writer.
 *
 * @param array $event event data
 * @return string formatted line to write to the log
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Formatter_FormatterInterface, format);

/**
 * Get the format specifier for DateTime objects
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Formatter_FormatterInterface, getDateTimeFormat);

/**
 * Set the format specifier for DateTime objects
 *
 * @see http://php.net/manual/en/function.date.php
 * @param string $dateTimeFormat DateTime format
 * @return FormatterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Formatter_FormatterInterface, setDateTimeFormat);

