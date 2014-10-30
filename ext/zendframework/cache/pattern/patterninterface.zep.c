
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Pattern_PatternInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Pattern, PatternInterface, zendframework, cache_pattern_patterninterface, zendframework_cache_pattern_patterninterface_method_entry);

	return SUCCESS;

}

/**
 * Set pattern options
 *
 * @param  PatternOptions $options
 * @return PatternInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Pattern_PatternInterface, setOptions);

/**
 * Get all pattern options
 *
 * @return PatternOptions
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Pattern_PatternInterface, getOptions);

