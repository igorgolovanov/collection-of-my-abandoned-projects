
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_FilterEnabledInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator, FilterEnabledInterface, zendframework, stdlib_hydrator_filterenabledinterface, zendframework_stdlib_hydrator_filterenabledinterface_method_entry);

	zend_class_implements(zendframework_stdlib_hydrator_filterenabledinterface_ce TSRMLS_CC, 1, zendframework_stdlib_hydrator_filter_filterproviderinterface_ce);
	return SUCCESS;

}

/**
 * Add a new filter to take care of what needs to be hydrated.
 * To exclude e.g. the method getServiceLocator:
 *
 * <code>
 * $composite->addFilter(
 *     "servicelocator",
 *     function ($property) {
 *         list($class, $method) = explode('::', $property);
 *         if ($method === 'getServiceLocator') {
 *             return false;
 *         }
 *         return true;
 *     },
 *     FilterComposite::CONDITION_AND
 * );
 * </code>
 *
 * @param string $name Index in the composite
 * @param callable|FilterInterface $filter
 * @param int $condition
 * @return FilterComposite
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_FilterEnabledInterface, addFilter);

/**
 * Check whether a specific filter exists at key $name or not
 *
 * @param string $name Index in the composite
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_FilterEnabledInterface, hasFilter);

/**
 * Remove a filter from the composition.
 * To not extract "has" methods, you simply need to unregister it
 *
 * <code>
 * $filterComposite->removeFilter('has');
 * </code>
 *
 * @param $name
 * @return FilterComposite
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_FilterEnabledInterface, removeFilter);

