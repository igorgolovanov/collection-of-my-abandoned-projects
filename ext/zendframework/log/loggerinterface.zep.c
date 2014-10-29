
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Log_LoggerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log, LoggerInterface, zendframework, log_loggerinterface, zendframework_log_loggerinterface_method_entry);

	return SUCCESS;

}

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, emerg);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, alert);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, crit);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, err);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, warn);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, notice);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, info);

/**
 * @param string $message
 * @param array|Traversable $extra
 * @return LoggerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_LoggerInterface, debug);

