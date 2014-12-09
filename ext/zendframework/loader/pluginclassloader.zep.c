
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Plugin class locator interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Loader_PluginClassLoader) {

	ZEPHIR_REGISTER_CLASS(Zend\\Loader, PluginClassLoader, zendframework, loader_pluginclassloader, zendframework_loader_pluginclassloader_method_entry, 0);

	/**
	 * List of plugin name => class name pairs
	 * @var array
	 */
	zend_declare_property_null(zendframework_loader_pluginclassloader_ce, SL("plugins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Static map allow global seeding of plugin loader
	 * @var array
	 */
	zend_declare_property_null(zendframework_loader_pluginclassloader_ce, SL("staticMap"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(zendframework_loader_pluginclassloader_ce TSRMLS_CC, 1, zendframework_loader_pluginclasslocator_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param null|array|Traversable map If provided, seeds the loader with a map
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *map = NULL, *staticMap = NULL, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &map);

	if (!map) {
		map = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(staticMap);
	ZVAL_NULL(staticMap);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&staticMap, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap") TSRMLS_CC);
        
	if (Z_TYPE_P(staticMap) != IS_NULL) {
		if (Z_TYPE_P(staticMap) == IS_ARRAY) {
			if (zephir_fast_count_int(staticMap TSRMLS_CC) > 0) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", NULL, staticMap);
				zephir_check_call_status();
			}
		}
	}
	if (Z_TYPE_P(map) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", NULL, map);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Add a static map of plugins
 *
 * A null value will clear the static map.
 *
 * @param  null|array|Traversable map
 * @throws Exception\InvalidArgumentException
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, addStaticMap) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *map = NULL, *staticMap = NULL, *className, *key = NULL, *value = NULL, _0, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_SEPARATE_PARAM(map);
	ZEPHIR_INIT_VAR(staticMap);
	ZVAL_NULL(staticMap);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	if (Z_TYPE_P(map) == IS_NULL) {
		ZEPHIR_INIT_NVAR(map);
		array_init(map);
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap"), &staticMap TSRMLS_CC);
            
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(map) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, map, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Expects an array or Traversable object", "zendframework/loader/pluginclassloader.zep", 83);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, map);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(map, _3);
	}
	
            zephir_read_static_property(&staticMap, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap") TSRMLS_CC);
        
	if (Z_TYPE_P(staticMap) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(staticMap);
		array_init(staticMap);
	}
	zephir_is_iterable(map, &_5, &_4, 0, 0, "zendframework/loader/pluginclassloader.zep", 98);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		zephir_array_update_zval(&staticMap, key, &value, PH_COPY | PH_SEPARATE);
	}
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap"), &staticMap TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Register a class to a given short name
 *
 * @param  string shortName
 * @param  string className
 * @return PluginClassLoader
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, registerPlugin) {

	zval *shortName_param = NULL, *className_param = NULL, *plugins = NULL, *_0, *_1;
	zval *shortName = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &shortName_param, &className_param);

	zephir_get_strval(shortName, shortName_param);
	zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, shortName);
	zephir_get_strval(shortName, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(plugins, _1);
	if (Z_TYPE_P(plugins) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(plugins);
		array_init(plugins);
	}
	zephir_array_update_zval(&plugins, shortName, &className, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("plugins"), plugins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register many plugins at once
 *
 * If $map is a string, assumes that the map is the class name of a
 * Traversable object (likely a ShortNameLocator); it will then instantiate
 * this class and use it to register plugins.
 *
 * If $map is an array or Traversable object, it will iterate it to
 * register plugin names/classes.
 *
 * For all other arguments, or if the string $map is not a class or not a
 * Traversable class, an exception will be raised.
 *
 * @param  string|array|Traversable $map
 * @return PluginClassLoader
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, registerPlugins) {

	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL;
	zend_bool _6, _7;
	zend_object_iterator *_5;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1, *_9;
	zval *map = NULL, *name = NULL, *className = NULL, *classNamePlugin = NULL, *_0 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_8 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_SEPARATE_PARAM(map);


	if (Z_TYPE_P(map) == IS_STRING) {
		if (unlikely(!zephir_class_exists(map, 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map class provided is invalid", "zendframework/loader/pluginclassloader.zep", 146);
			return;
		}
		ZEPHIR_CPY_WRT(className, map);
		ZEPHIR_INIT_NVAR(map);
		zephir_fetch_safe_class(_0, className);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(map, _1);
		if (zephir_has_constructor(map TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, map, "__construct", NULL);
			zephir_check_call_status();
		}
	} else if (Z_TYPE_P(map) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(className, map);
		ZEPHIR_INIT_NVAR(map);
		object_init_ex(map, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, map, "__construct", NULL, className);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "Traversable", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "is_subclass_of", &_4, map, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map provided is invalid; must be traversable", "zendframework/loader/pluginclassloader.zep", 156);
		return;
	}
	_5 = zephir_get_iterator(map TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(name, _5);
		{ zval **tmp; 
		_5->funcs->get_current_data(_5, &tmp TSRMLS_CC);
		className = *tmp;
		}
		_6 = Z_TYPE_P(name) == IS_LONG;
		if (!(_6)) {
			_6 = zephir_is_numeric(name);
		}
		if (_6) {
			_7 = Z_TYPE_P(className) != IS_OBJECT;
			if (_7) {
				_7 = zephir_class_exists(className, 1 TSRMLS_CC);
			}
			if (_7) {
				ZEPHIR_INIT_NVAR(classNamePlugin);
				zephir_fetch_safe_class(_8, className);
				_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(classNamePlugin, _9);
				if (zephir_has_constructor(classNamePlugin TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, classNamePlugin, "__construct", NULL);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(classNamePlugin, className);
			}
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_STRING(&_2, "Traversable", 0);
			ZEPHIR_CALL_FUNCTION(&_10, "is_subclass_of", &_4, classNamePlugin, &_2);
			zephir_check_call_status();
			if (zephir_is_true(_10)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", &_11, classNamePlugin);
				zephir_check_call_status();
				continue;
			}
			ZEPHIR_CPY_WRT(className, classNamePlugin);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugin", &_12, name, className);
		zephir_check_call_status();
	}
	_5->funcs->dtor(_5 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Unregister a short name lookup
 *
 * @param  mixed $shortName
 * @return PluginClassLoader
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, unregisterPlugin) {

	zval *shortName, *lookup, *plugins = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &shortName);



	ZEPHIR_INIT_VAR(lookup);
	zephir_fast_strtolower(lookup, shortName);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(plugins, _0);
	if (Z_TYPE_P(plugins) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(plugins);
		array_init(plugins);
	}
	if (zephir_array_key_exists(plugins, lookup TSRMLS_CC)) {
		zephir_array_unset(&plugins, lookup, PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("plugins"), plugins TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get a list of all registered plugins
 *
 * @return array|Traversable
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, getRegisteredPlugins) {


	RETURN_MEMBER(this_ptr, "plugins");

}

/**
 * Whether or not a plugin by a specific name has been registered
 *
 * @param  string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, isLoaded) {

	zval *name_param = NULL, *plugins = NULL, *_0, *_1;
	zval *name = NULL, *lookup = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, name);
	zephir_get_strval(lookup, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(plugins, _1);
	if (Z_TYPE_P(plugins) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(plugins);
		array_init(plugins);
	}
	RETURN_MM_BOOL(zephir_array_isset(plugins, lookup));

}

/**
 * Return full class name for a named helper
 *
 * @param  string $name
 * @return string|false
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, getClassName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *className = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&className, this_ptr, "load", NULL, name);
	zephir_check_call_status();
	RETURN_CCTOR(className);

}

/**
 * Load a helper via the name provided
 *
 * @param  string $name
 * @return string|false
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *className, *lookup = NULL, *plugins = NULL, *_0 = NULL, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isloaded", NULL, name);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, name);
	ZEPHIR_CPY_WRT(lookup, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(plugins, _2);
	if (Z_TYPE_P(plugins) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(plugins);
		array_init(plugins);
	}
	if (zephir_array_isset_fetch(&className, plugins, lookup, 1 TSRMLS_CC)) {
		RETURN_CTOR(className);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Defined by IteratorAggregate
 *
 * Returns an instance of ArrayIterator, containing a map of
 * all plugins
 *
 * @return ArrayIterator
 */
PHP_METHOD(ZendFramework_Loader_PluginClassLoader, getIterator) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plugins = NULL, *iterator, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(plugins, _0);
	if (Z_TYPE_P(plugins) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(plugins);
		array_init(plugins);
	}
	ZEPHIR_INIT_VAR(iterator);
	object_init_ex(iterator, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, plugins);
	zephir_check_call_status();
	RETURN_CCTOR(iterator);

}

