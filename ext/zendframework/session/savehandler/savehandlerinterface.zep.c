
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
 * SaveHandler Interface
 *
 * @see        http://php.net/session_set_save_handler
 */
ZEPHIR_INIT_CLASS(ZendFramework_Session_SaveHandler_SaveHandlerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session\\SaveHandler, SaveHandlerInterface, zendframework, session_savehandler_savehandlerinterface, zendframework_session_savehandler_savehandlerinterface_method_entry);

	return SUCCESS;

}

/**
 * Open Session - retrieve resources
 *
 * @param string $savePath
 * @param string $name
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, open);

/**
 * Close Session - free resources
 *
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, close);

/**
 * Read session data
 *
 * @param string $id
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, read);

/**
 * Write Session - commit data to resource
 *
 * @param string $id
 * @param mixed $data
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, write);

/**
 * Destroy Session - remove data from resource for
 * given session id
 *
 * @param string $id
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, destroy);

/**
 * Garbage Collection - remove old session data older
 * than $maxlifetime (in seconds)
 *
 * @param int $maxlifetime
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_SaveHandler_SaveHandlerInterface, gc);

