
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_NamingStrategyEnabledInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator, NamingStrategyEnabledInterface, zendframework, stdlib_hydrator_namingstrategyenabledinterface, zendframework_stdlib_hydrator_namingstrategyenabledinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds the given naming strategy
 *
 * @param NamingStrategyInterface $strategy The naming to register.
 * @return NamingStrategyEnabledInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategyEnabledInterface, setNamingStrategy);

/**
 * Gets the naming strategy.
 *
 * @return NamingStrategyInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategyEnabledInterface, getNamingStrategy);

/**
 * Checks if a naming strategy exists.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategyEnabledInterface, hasNamingStrategy);

/**
 * Removes the naming with the given name.
 *
 * @return NamingStrategyEnabledInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategyEnabledInterface, removeNamingStrategy);

