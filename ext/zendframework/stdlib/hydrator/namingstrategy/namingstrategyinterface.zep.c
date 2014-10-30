
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
 * Allow property extraction / hydration for hydrator
 *
 * Interface PropertyStrategyInterface
 * @package Zend\Stdlib\Hydrator\NamingStrategy
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator\\NamingStrategy, NamingStrategyInterface, zendframework, stdlib_hydrator_namingstrategy_namingstrategyinterface, zendframework_stdlib_hydrator_namingstrategy_namingstrategyinterface_method_entry);

	return SUCCESS;

}

/**
 * Converts the given name so that it can be extracted by the hydrator.
 *
 * @param string $name   The original name
 * @param object $object (optional) The original object for context.
 * @return mixed         The hydrated name
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface, hydrate);

/**
 * Converts the given name so that it can be hydrated by the hydrator.
 *
 * @param string $name The original name
 * @param array  $data (optional) The original data for context.
 * @return mixed The extracted name
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_NamingStrategy_NamingStrategyInterface, extract);

