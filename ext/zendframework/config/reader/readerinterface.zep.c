
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
ZEPHIR_INIT_CLASS(ZendFramework_Config_Reader_ReaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Config\\Reader, ReaderInterface, zendframework, config_reader_readerinterface, zendframework_config_reader_readerinterface_method_entry);

	return SUCCESS;

}

/**
 * Read from a file and create an array
 *
 * @param  string $filename
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Reader_ReaderInterface, fromFile);

/**
 * Read from a string and create an array
 *
 * @param  string $string
 * @return array|bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Config_Reader_ReaderInterface, fromString);

