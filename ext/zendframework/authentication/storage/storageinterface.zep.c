
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
ZEPHIR_INIT_CLASS(ZendFramework_Authentication_Storage_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication\\Storage, StorageInterface, zendframework, authentication_storage_storageinterface, zendframework_authentication_storage_storageinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns true if and only if storage is empty
 *
 * @throws \Zend\Authentication\Exception\ExceptionInterface If it is impossible to determine whether storage is empty
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Storage_StorageInterface, isEmpty);

/**
 * Returns the contents of storage
 *
 * Behavior is undefined when storage is empty.
 *
 * @throws \Zend\Authentication\Exception\ExceptionInterface If reading contents from storage is impossible
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Storage_StorageInterface, read);

/**
 * Writes $contents to storage
 *
 * @param  mixed $contents
 * @throws \Zend\Authentication\Exception\ExceptionInterface If writing $contents to storage is impossible
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Storage_StorageInterface, write);

/**
 * Clears contents from storage
 *
 * @throws \Zend\Authentication\Exception\ExceptionInterface If clearing contents from storage is impossible
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Storage_StorageInterface, clear);

