
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Writer_WriterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Writer, WriterInterface, zendframework, log_writer_writerinterface, zendframework_log_writer_writerinterface_method_entry);

	return SUCCESS;

}

/**
 * Add a log filter to the writer
 *
 * @param  int|string|Filter $filter
 * @return WriterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_WriterInterface, addFilter);

/**
 * Set a message formatter for the writer
 *
 * @param string|Formatter $formatter
 * @return WriterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_WriterInterface, setFormatter);

/**
 * Write a log message
 *
 * @param  array $event
 * @return WriterInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_WriterInterface, write);

/**
 * Perform shutdown activities
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_WriterInterface, shutdown);

