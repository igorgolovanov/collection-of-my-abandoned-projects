
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_StorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, StorageInterface, zendframework, cache_storage_storageinterface, zendframework_cache_storage_storageinterface_method_entry);

	return SUCCESS;

}

/**
 * Set options.
 *
 * @param array|Traversable|Adapter\AdapterOptions $options
 * @return StorageInterface Fluent interface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, setOptions);

/**
 * Get options
 *
 * @return Adapter\AdapterOptions
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getOptions);

/**
 * Get an item.
 *
 * @param  string  $key
 * @param  bool $success
 * @param  mixed   $casToken
 * @return mixed Data on success, null on failure
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getItem);

/**
 * Get multiple items.
 *
 * @param  array $keys
 * @return array Associative array of keys and values
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getItems);

/**
 * Test if an item exists.
 *
 * @param  string $key
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, hasItem);

/**
 * Test multiple items.
 *
 * @param  array $keys
 * @return array Array of found keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, hasItems);

/**
 * Get metadata of an item.
 *
 * @param  string $key
 * @return array|bool Metadata on success, false on failure
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getMetadata);

/**
 * Get multiple metadata
 *
 * @param  array $keys
 * @return array Associative array of keys and metadata
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getMetadatas);

/**
 * Store an item.
 *
 * @param  string $key
 * @param  mixed  $value
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, setItem);

/**
 * Store multiple items.
 *
 * @param  array $keyValuePairs
 * @return array Array of not stored keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, setItems);

/**
 * Add an item.
 *
 * @param  string $key
 * @param  mixed  $value
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, addItem);

/**
 * Add multiple items.
 *
 * @param  array $keyValuePairs
 * @return array Array of not stored keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, addItems);

/**
 * Replace an existing item.
 *
 * @param  string $key
 * @param  mixed  $value
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, replaceItem);

/**
 * Replace multiple existing items.
 *
 * @param  array $keyValuePairs
 * @return array Array of not stored keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, replaceItems);

/**
 * Set an item only if token matches
 *
 * It uses the token received from getItem() to check if the item has
 * changed before overwriting it.
 *
 * @param  mixed  $token
 * @param  string $key
 * @param  mixed  $value
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 * @see    getItem()
 * @see    setItem()
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, checkAndSetItem);

/**
 * Reset lifetime of an item
 *
 * @param  string $key
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, touchItem);

/**
 * Reset lifetime of multiple items.
 *
 * @param  array $keys
 * @return array Array of not updated keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, touchItems);

/**
 * Remove an item.
 *
 * @param  string $key
 * @return bool
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, removeItem);

/**
 * Remove multiple items.
 *
 * @param  array $keys
 * @return array Array of not removed keys
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, removeItems);

/**
 * Increment an item.
 *
 * @param  string $key
 * @param  int    $value
 * @return int|bool The new value on success, false on failure
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, incrementItem);

/**
 * Increment multiple items.
 *
 * @param  array $keyValuePairs
 * @return array Associative array of keys and new values
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, incrementItems);

/**
 * Decrement an item.
 *
 * @param  string $key
 * @param  int    $value
 * @return int|bool The new value on success, false on failure
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, decrementItem);

/**
 * Decrement multiple items.
 *
 * @param  array $keyValuePairs
 * @return array Associative array of keys and new values
 * @throws \Zend\Cache\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, decrementItems);

/**
 * Capabilities of this storage
 *
 * @return Capabilities
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_StorageInterface, getCapabilities);

