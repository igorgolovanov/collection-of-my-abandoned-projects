
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
 * with a SharedEventManager, without an event name. The {@link attach()} method will
 * then be called with the current SharedEventManager instance, allowing the class to
 * wire up one or more listeners.
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedListenerAggregateInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, SharedListenerAggregateInterface, zendframework, eventmanager_sharedlisteneraggregateinterface, zendframework_eventmanager_sharedlisteneraggregateinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach one or more listeners
 *
 * Implementors may add an optional $priority argument; the SharedEventManager
 * implementation will pass this to the aggregate.
 *
 * @param SharedEventManagerInterface $events
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedListenerAggregateInterface, attachShared);

/**
 * Detach all previously attached listeners
 *
 * @param SharedEventManagerInterface $events
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedListenerAggregateInterface, detachShared);

