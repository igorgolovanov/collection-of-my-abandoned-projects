
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
 * Interface to automate setter injection for a SharedEventManagerInterface instance
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventManagerAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, SharedEventManagerAwareInterface, zendframework, eventmanager_sharedeventmanagerawareinterface, zendframework_eventmanager_sharedeventmanagerawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Inject a SharedEventManager instance
 *
 * @param  SharedEventManagerInterface $sharedEventManager
 * @return SharedEventManagerAwareInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerAwareInterface, setSharedManager);

/**
 * Get shared collections container
 *
 * @return SharedEventManagerInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerAwareInterface, getSharedManager);

/**
 * Remove any shared collections
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventManagerAwareInterface, unsetSharedManager);

