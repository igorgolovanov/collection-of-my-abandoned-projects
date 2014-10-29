
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
 * Interface to automate setter injection for an EventManager instance
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_EventManagerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, EventManagerAwareInterface, zendframework, eventmanager_eventmanagerawareinterface, zendframework_eventmanager_eventmanagerawareinterface_method_entry);

	zend_class_implements(zendframework_eventmanager_eventmanagerawareinterface_ce TSRMLS_CC, 1, zendframework_eventmanager_eventscapableinterface_ce);
	return SUCCESS;

}

/**
 * Inject an EventManager instance
 *
 * @param  EventManagerInterface $eventManager
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_EventManagerAwareInterface, setEventManager);

