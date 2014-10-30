
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
ZEPHIR_INIT_CLASS(ZendFramework_Crypt_Symmetric_Padding_PaddingInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Crypt\\Symmetric\\Padding, PaddingInterface, zendframework, crypt_symmetric_padding_paddinginterface, zendframework_crypt_symmetric_padding_paddinginterface_method_entry);

	return SUCCESS;

}

/**
 * Pad the string to the specified size
 *
 * @param  string $string    The string to pad
 * @param  int    $blockSize The size to pad to
 * @return string The padded string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_Padding_PaddingInterface, pad);

/**
 * Strip the padding from the supplied string
 *
 * @param  string $string The string to trim
 * @return string The unpadded string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Crypt_Symmetric_Padding_PaddingInterface, strip);

