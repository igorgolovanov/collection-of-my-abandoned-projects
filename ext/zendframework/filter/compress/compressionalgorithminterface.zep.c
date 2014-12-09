
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
/**
 * Compression interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Filter_Compress_CompressionAlgorithmInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Filter\\Compress, CompressionAlgorithmInterface, zendframework, filter_compress_compressionalgorithminterface, zendframework_filter_compress_compressionalgorithminterface_method_entry);

	return SUCCESS;

}

/**
 * Compresses $value with the defined settings
 *
 * @param  string $value Data to compress
 * @return string The compressed data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Compress_CompressionAlgorithmInterface, compress);

/**
 * Decompresses $value with the defined settings
 *
 * @param  string $value Data to decompress
 * @return string The decompressed data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Compress_CompressionAlgorithmInterface, decompress);

/**
 * Return the adapter name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_Compress_CompressionAlgorithmInterface, toString);

