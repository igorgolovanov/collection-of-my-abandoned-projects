
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
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_InjectApplicationEventInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc, InjectApplicationEventInterface, zendframework, mvc_injectapplicationeventinterface, zendframework_mvc_injectapplicationeventinterface_method_entry);

	return SUCCESS;

}

/**
 * Compose an Event
 *
 * @param  EventInterface $event
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_InjectApplicationEventInterface, setEvent);

/**
 * Retrieve the composed event
 *
 * @return EventInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_InjectApplicationEventInterface, getEvent);

