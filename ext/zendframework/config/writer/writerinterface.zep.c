
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
ZEPHIR_INIT_CLASS(ZendFramework_Config_Writer_WriterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Config\\Writer, WriterInterface, zendframework, config_writer_writerinterface, zendframework_config_writer_writerinterface_method_entry);

	return SUCCESS;

}

/**
 * Write a config object to a file.
 *
 * @param  string  $filename
 * @param  mixed   $config
 * @param  bool $exclusiveLock
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Writer_WriterInterface, toFile);

/**
 * Write a config object to a string.
 *
 * @param  mixed $config
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Writer_WriterInterface, toString);

