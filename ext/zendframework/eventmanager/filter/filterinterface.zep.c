
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
* Interface for intercepting filter chains
*/
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager\\Filter, FilterInterface, zendframework, eventmanager_filter_filterinterface, zendframework_eventmanager_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Execute the filter chain
 *
 * @param  string|object $context
 * @param  array $params
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, run);

/**
 * Attach an intercepting filter
 *
 * @param  callable $callback
 * @return CallbackHandler
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, attach);

/**
 * Detach an intercepting filter
 *
 * @param  CallbackHandler $filter
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, detach);

/**
 * Get all intercepting filters
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, getFilters);

/**
 * Clear all filters
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, clearFilters);

/**
 * Get all filter responses
 *
 * @return ResponseCollection
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_Filter_FilterInterface, getResponses);

