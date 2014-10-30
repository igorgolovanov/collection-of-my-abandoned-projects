
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
ZEPHIR_INIT_CLASS(ZendFramework_Session_Storage_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session\\Storage, StorageInterface, zendframework, session_storage_storageinterface, zendframework_session_storage_storageinterface_method_entry);

	zend_class_implements(zendframework_session_storage_storageinterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(zendframework_session_storage_storageinterface_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(zendframework_session_storage_storageinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, getRequestAccessTime);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, lock);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, isLocked);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, unlock);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, markImmutable);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, isImmutable);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, setMetadata);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, getMetadata);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, clear);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, fromArray);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Storage_StorageInterface, toArray);

