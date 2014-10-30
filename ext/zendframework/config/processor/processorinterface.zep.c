
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
ZEPHIR_INIT_CLASS(ZendFramework_Config_Processor_ProcessorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Config\\Processor, ProcessorInterface, zendframework, config_processor_processorinterface, zendframework_config_processor_processorinterface_method_entry);

	return SUCCESS;

}

/**
 * Process the whole Config structure and recursively parse all its values.
 *
 * @param  Config $value
 * @return Config
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Processor_ProcessorInterface, process);

/**
 * Process a single value
 *
 * @param  mixed $value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Processor_ProcessorInterface, processValue);

