
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
 * Interface for shared event listener collections
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, SharedEventManagerInterface, zendframework, eventmanager_sharedeventmanagerinterface, zendframework_eventmanager_sharedeventmanagerinterface_method_entry);

	return SUCCESS;

}

/**
 * Retrieve all listeners for a given identifier and event
 *
 * @param  string|int $id
 * @param  string|int $event
 * @return false|PriorityQueue
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerInterface, getListeners);

/**
 * Attach a listener to an event
 *
 * @param  string|array $id Identifier(s) for event emitting component(s)
 * @param  string $event
 * @param  callable $callback PHP Callback
 * @param  int $priority Priority at which listener should execute
 * @return CallbackHandler|array Either CallbackHandler or array of CallbackHandlers
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerInterface, attach);

/**
 * Detach a listener from an event offered by a given resource
 *
 * @param  string|int $id
 * @param  CallbackHandler $listener
 * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerInterface, detach);

/**
 * Retrieve all registered events for a given resource
 *
 * @param  string|int $id
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerInterface, getEvents);

/**
 * Clear all listeners for a given identifier, optionally for a specific event
 *
 * @param  string|int $id
 * @param  null|string $event
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerInterface, clearListeners);

