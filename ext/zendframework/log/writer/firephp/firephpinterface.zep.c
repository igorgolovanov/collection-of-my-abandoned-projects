
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Writer_FirePhp_FirePhpInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Writer\\FirePhp, FirePhpInterface, zendframework, log_writer_firephp_firephpinterface, zendframework_log_writer_firephp_firephpinterface_method_entry);

	return SUCCESS;

}

/**
 * Determine whether or not FirePHP is enabled
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, getEnabled);

/**
 * Log an error message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, error);

/**
 * Log a warning
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, warn);

/**
 * Log informational message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, info);

/**
 * Log a trace
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, trace);

/**
 * Log a message
 *
 * @param string $line
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, log);

