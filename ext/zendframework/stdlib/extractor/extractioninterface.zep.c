
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Extractor_ExtractionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Extractor, ExtractionInterface, zendframework, stdlib_extractor_extractioninterface, zendframework_stdlib_extractor_extractioninterface_method_entry);

	return SUCCESS;

}

/**
 * Extract values from an object
 *
 * @param  object $object
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Extractor_ExtractionInterface, extract);

