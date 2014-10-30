
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
/**
 * @todo v3.0, add optional object/data to extract/hydrate.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_Strategy_StrategyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator\\Strategy, StrategyInterface, zendframework, stdlib_hydrator_strategy_strategyinterface, zendframework_stdlib_hydrator_strategy_strategyinterface_method_entry);

	return SUCCESS;

}

/**
 * Converts the given value so that it can be extracted by the hydrator.
 *
 * @param mixed   $value The original value.
 * @param object $object (optional) The original object for context.
 * @return mixed Returns the value that should be extracted.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_Strategy_StrategyInterface, extract);

/**
 * Converts the given value so that it can be hydrated by the hydrator.
 *
 * @param mixed $value The original value.
 * @param array  $data (optional) The original data for context.
 * @return mixed Returns the value that should be hydrated.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_Strategy_StrategyInterface, hydrate);

