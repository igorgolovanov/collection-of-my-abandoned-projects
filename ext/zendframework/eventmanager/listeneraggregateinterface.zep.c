
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Interface for self-registering event listeners.
 *
 * Classes implementing this interface may be registered by name or instance
 * with an EventManager, without an event name. The {@link attach()} method will
 * then be called with the current EventManager instance, allowing the class to
 * wire up one or more listeners.
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_ListenerAggregateInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, ListenerAggregateInterface, zendframework, eventmanager_listeneraggregateinterface, zendframework_eventmanager_listeneraggregateinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach one or more listeners
 *
 * Implementors may add an optional $priority argument; the EventManager
 * implementation will pass this to the aggregate.
 *
 * @param EventManagerInterface $events
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_ListenerAggregateInterface, attach);

/**
 * Detach all previously attached listeners
 *
 * @param EventManagerInterface $events
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_ListenerAggregateInterface, detach);

