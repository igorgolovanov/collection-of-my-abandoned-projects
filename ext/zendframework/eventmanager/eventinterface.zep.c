
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
 * Representation of an event
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, EventInterface, zendframework, eventmanager_eventinterface, zendframework_eventmanager_eventinterface_method_entry);

	return SUCCESS;

}

/**
 * Get event name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, getName);

/**
 * Get target/context from which event was triggered
 *
 * @return null|string|object
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, getTarget);

/**
 * Get parameters passed to the event
 *
 * @return array|ArrayAccess
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, getParams);

/**
 * Get a single parameter by name
 *
 * @param  string $name
 * @param  mixed $default Default value to return if parameter does not exist
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, getParam);

/**
 * Set the event name
 *
 * @param  string $name
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, setName);

/**
 * Set the event target/context
 *
 * @param  null|string|object $target
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, setTarget);

/**
 * Set event parameters
 *
 * @param  string $params
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, setParams);

/**
 * Set a single parameter by key
 *
 * @param  string $name
 * @param  mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, setParam);

/**
 * Indicate whether or not the parent EventManagerInterface should stop propagating events
 *
 * @param  bool $flag
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, stopPropagation);

/**
 * Has this event indicated event propagation should stop?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventInterface, propagationIsStopped);

