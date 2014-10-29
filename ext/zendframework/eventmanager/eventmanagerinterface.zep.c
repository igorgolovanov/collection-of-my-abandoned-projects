
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
* Interface for messengers
*/
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, EventManagerInterface, zendframework, eventmanager_eventmanagerinterface, zendframework_eventmanager_eventmanagerinterface_method_entry);

	zend_class_implements(zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC, 1, zendframework_eventmanager_sharedeventmanagerawareinterface_ce);
	return SUCCESS;

}

/**
 * Trigger an event
 *
 * Should allow handling the following scenarios:
 * - Passing Event object only
 * - Passing event name and Event object only
 * - Passing event name, target, and Event object
 * - Passing event name, target, and array|ArrayAccess of arguments
 *
 * Can emulate triggerUntil() if the last argument provided is a callback.
 *
 * @param  string $event
 * @param  object|string $target
 * @param  array|object $argv
 * @param  null|callable $callback
 * @return ResponseCollection
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, trigger);

/**
 * Trigger an event until the given callback returns a boolean false
 *
 * Should allow handling the following scenarios:
 * - Passing Event object and callback only
 * - Passing event name, Event object, and callback only
 * - Passing event name, target, Event object, and callback
 * - Passing event name, target, array|ArrayAccess of arguments, and callback
 *
 * @param  string $event
 * @param  object|string $target
 * @param  array|object $argv
 * @param  callable $callback
 * @return ResponseCollection
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, triggerUntil);

/**
 * Attach a listener to an event
 *
 * @param  string $event
 * @param  callable $callback
 * @param  int $priority Priority at which to register listener
 * @return CallbackHandler
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, attach);

/**
 * Detach an event listener
 *
 * @param  CallbackHandler|ListenerAggregateInterface $listener
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, detach);

/**
 * Get a list of events for which this collection has listeners
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, getEvents);

/**
 * Retrieve a list of listeners registered to a given event
 *
 * @param  string $event
 * @return array|object
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, getListeners);

/**
 * Clear all listeners for a given event
 *
 * @param  string $event
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, clearListeners);

/**
 * Set the event class to utilize
 *
 * @param  string $class
 * @return EventManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, setEventClass);

/**
 * Get the identifier(s) for this EventManager
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, getIdentifiers);

/**
 * Set the identifiers (overrides any currently set identifiers)
 *
 * @param string|int|array|Traversable $identifiers
 * @return EventManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, setIdentifiers);

/**
 * Add some identifier(s) (appends to any currently set identifiers)
 *
 * @param string|int|array|Traversable $identifiers
 * @return EventManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, addIdentifiers);

/**
 * Attach a listener aggregate
 *
 * @param  ListenerAggregateInterface $aggregate
 * @param  int $priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link ListenerAggregateInterface::attach()}
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, attachAggregate);

/**
 * Detach a listener aggregate
 *
 * @param  ListenerAggregateInterface $aggregate
 * @return mixed return value of {@link ListenerAggregateInterface::detach()}
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerInterface, detachAggregate);

