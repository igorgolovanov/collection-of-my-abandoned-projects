
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Writer\\ChromePhp, ChromePhpInterface, zendframework, log_writer_chromephp_chromephpinterface, zendframework_log_writer_chromephp_chromephpinterface_method_entry);

	return SUCCESS;

}

/**
 * Log an error message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface, error);

/**
 * Log a warning
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface, warn);

/**
 * Log informational message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface, info);

/**
 * Log a trace
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface, trace);

/**
 * Log a message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_ChromePhp_ChromePhpInterface, log);

