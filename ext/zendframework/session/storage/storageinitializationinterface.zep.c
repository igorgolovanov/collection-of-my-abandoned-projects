
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
 * Session storage interface
 *
 * Defines the minimum requirements for handling userland, in-script session
 * storage (e.g., the $_SESSION superglobal array).
 */
ZEPHIR_INIT_CLASS(ZendFramework_Session_Storage_StorageInitializationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session\\Storage, StorageInitializationInterface, zendframework, session_storage_storageinitializationinterface, zendframework_session_storage_storageinitializationinterface_method_entry);

	return SUCCESS;

}

/**
 * Initialize Session Storage
 *
 * @param  array $input
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInitializationInterface, init);

