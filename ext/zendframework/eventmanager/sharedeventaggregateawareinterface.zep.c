
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
 * Interface for allowing attachment of shared aggregate listeners.
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_SharedEventAggregateAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\EventManager, SharedEventAggregateAwareInterface, zendframework, eventmanager_sharedeventaggregateawareinterface, zendframework_eventmanager_sharedeventaggregateawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Attach a listener aggregate
 *
 * @param  SharedListenerAggregateInterface $aggregate
 * @param  int $priority If provided, a suggested priority for the aggregate to use
 * @return mixed return value of {@link SharedListenerAggregateInterface::attachShared()}
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventAggregateAwareInterface, attachAggregate);

/**
 * Detach a listener aggregate
 *
 * @param  SharedListenerAggregateInterface $aggregate
 * @return mixed return value of {@link SharedListenerAggregateInterface::detachShared()}
 */
ZEPHIR_DOC_METHOD(ZendFramework_EventManager_SharedEventAggregateAwareInterface, detachAggregate);

