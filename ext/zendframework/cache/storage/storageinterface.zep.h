
extern zend_class_entry *zendframework_cache_storage_storageinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_StorageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_getitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, casToken)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_getitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_hasitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_hasitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_getmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_getmetadatas, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_setitem, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_setitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValuePairs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_additem, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_additems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValuePairs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_replaceitem, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_replaceitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValuePairs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_checkandsetitem, 0, 0, 3)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_touchitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_touchitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_removeitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_removeitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_incrementitem, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_incrementitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValuePairs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_decrementitem, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_cache_storage_storageinterface_decrementitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValuePairs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_cache_storage_storageinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, setOptions, arginfo_zendframework_cache_storage_storageinterface_setoptions)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getItem, arginfo_zendframework_cache_storage_storageinterface_getitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getItems, arginfo_zendframework_cache_storage_storageinterface_getitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, hasItem, arginfo_zendframework_cache_storage_storageinterface_hasitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, hasItems, arginfo_zendframework_cache_storage_storageinterface_hasitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getMetadata, arginfo_zendframework_cache_storage_storageinterface_getmetadata)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getMetadatas, arginfo_zendframework_cache_storage_storageinterface_getmetadatas)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, setItem, arginfo_zendframework_cache_storage_storageinterface_setitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, setItems, arginfo_zendframework_cache_storage_storageinterface_setitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, addItem, arginfo_zendframework_cache_storage_storageinterface_additem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, addItems, arginfo_zendframework_cache_storage_storageinterface_additems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, replaceItem, arginfo_zendframework_cache_storage_storageinterface_replaceitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, replaceItems, arginfo_zendframework_cache_storage_storageinterface_replaceitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, checkAndSetItem, arginfo_zendframework_cache_storage_storageinterface_checkandsetitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, touchItem, arginfo_zendframework_cache_storage_storageinterface_touchitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, touchItems, arginfo_zendframework_cache_storage_storageinterface_touchitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, removeItem, arginfo_zendframework_cache_storage_storageinterface_removeitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, removeItems, arginfo_zendframework_cache_storage_storageinterface_removeitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, incrementItem, arginfo_zendframework_cache_storage_storageinterface_incrementitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, incrementItems, arginfo_zendframework_cache_storage_storageinterface_incrementitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, decrementItem, arginfo_zendframework_cache_storage_storageinterface_decrementitem)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, decrementItems, arginfo_zendframework_cache_storage_storageinterface_decrementitems)
	PHP_ABSTRACT_ME(ZendFramework_Cache_Storage_StorageInterface, getCapabilities, NULL)
  PHP_FE_END
};
