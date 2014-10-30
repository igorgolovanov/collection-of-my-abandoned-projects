
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_StrategyEnabledInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator, StrategyEnabledInterface, zendframework, stdlib_hydrator_strategyenabledinterface, zendframework_stdlib_hydrator_strategyenabledinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds the given strategy under the given name.
 *
 * @param string $name The name of the strategy to register.
 * @param StrategyInterface $strategy The strategy to register.
 * @return StrategyEnabledInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_StrategyEnabledInterface, addStrategy);

/**
 * Gets the strategy with the given name.
 *
 * @param string $name The name of the strategy to get.
 * @return StrategyInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_StrategyEnabledInterface, getStrategy);

/**
 * Checks if the strategy with the given name exists.
 *
 * @param string $name The name of the strategy to check for.
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_StrategyEnabledInterface, hasStrategy);

/**
 * Removes the strategy with the given name.
 *
 * @param string $name The name of the strategy to remove.
 * @return StrategyEnabledInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_StrategyEnabledInterface, removeStrategy);

