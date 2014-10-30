
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
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_ResponseSender_ResponseSenderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc\\ResponseSender, ResponseSenderInterface, zendframework, mvc_responsesender_responsesenderinterface, zendframework_mvc_responsesender_responsesenderinterface_method_entry);

	return SUCCESS;

}

/**
 * Send the response
 *
 * @param SendResponseEvent $event
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_ResponseSender_ResponseSenderInterface, __invoke);

