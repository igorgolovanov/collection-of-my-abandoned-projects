
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
/**
 * Interface for mail transports
 */
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Transport_TransportInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Transport, TransportInterface, zendframework, mail_transport_transportinterface, zendframework_mail_transport_transportinterface_method_entry);

	return SUCCESS;

}

/**
 * Send a mail message
 *
 * @param \Zend\Mail\Message $message
 * @return
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Transport_TransportInterface, send);

