
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Processor_ProcessorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Processor, ProcessorInterface, zendframework, log_processor_processorinterface, zendframework_log_processor_processorinterface_method_entry);

	return SUCCESS;

}

/**
 * Processes a log message before it is given to the writers
 *
 * @param  array $event
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Processor_ProcessorInterface, process);

