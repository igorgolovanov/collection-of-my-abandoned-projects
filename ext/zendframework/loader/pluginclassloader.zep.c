
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
	zval *map = NULL, *_0, *staticMap = NULL, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &map);

	if (!map) {
		map = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(staticMap);
	ZVAL_NULL(staticMap);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("plugins"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&staticMap, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap") TSRMLS_CC);
        
	if (!(ZEPHIR_IS_EMPTY(staticMap))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", NULL, staticMap);
		zephir_check_call_status();
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

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zval *map, *staticMap = NULL, *className, *key = NULL, *value = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_INIT_VAR(staticMap);
	ZVAL_NULL(staticMap);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	if (Z_TYPE_P(map) == IS_NULL) {
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap"), &staticMap TSRMLS_CC);
            
		RETURN_MM_NULL();
	}
	_0 = Z_TYPE_P(map) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(map, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Expects an array or Traversable object", "zendframework/loader/pluginclassloader.zep", 78);
		return;
	}
	
            zephir_read_static_property(&staticMap, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap") TSRMLS_CC);
        
	if (Z_TYPE_P(staticMap) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(staticMap);
		array_init(staticMap);
	}
	zephir_is_iterable(map, &_2, &_1, 0, 0, "zendframework/loader/pluginclassloader.zep", 92);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
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

	zval *shortName_param = NULL, *className_param = NULL, *_0;
	zval *shortName = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &shortName_param, &className_param);

	zephir_get_strval(shortName, shortName_param);
	zephir_get_strval(className, className_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, shortName);
	zephir_get_strval(shortName, _0);
	zephir_update_property_array(this_ptr, SL("plugins"), shortName, className TSRMLS_CC);
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

	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_bool _3, _4;
	zend_object_iterator *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1, *_6;
	zval *map = NULL, *name = NULL, *className = NULL, *_0 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_SEPARATE_PARAM(map);


	if (Z_TYPE_P(map) == IS_STRING) {
		if (unlikely(!zephir_class_exists(map, 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map class provided is invalid", "zendframework/loader/pluginclassloader.zep", 133);
			return;
		}
		ZEPHIR_INIT_NVAR(map);
		zephir_fetch_safe_class(_0, map);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(map, _1);
		if (zephir_has_constructor(map TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, map, "__construct", NULL);
			zephir_check_call_status();
		}
	} else if (Z_TYPE_P(map) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(map);
		object_init_ex(map, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, map, "__construct", NULL, map);
		zephir_check_call_status();
	}
	if (unlikely(!(zephir_is_instance_of(map, SL("Traversable") TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map provided is invalid; must be traversable", "zendframework/loader/pluginclassloader.zep", 141);
		return;
	}
	_2 = zephir_get_iterator(map TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(name, _2);
		{ zval **tmp; 
		_2->funcs->get_current_data(_2, &tmp TSRMLS_CC);
		className = *tmp;
		}
		_3 = Z_TYPE_P(name) == IS_LONG;
		if (!(_3)) {
			_3 = zephir_is_numeric(name);
		}
		if (_3) {
			_4 = Z_TYPE_P(className) != IS_OBJECT;
			if (_4) {
				_4 = zephir_class_exists(className, 1 TSRMLS_CC);
			}
			if (_4) {
				ZEPHIR_INIT_NVAR(className);
				zephir_fetch_safe_class(_5, className);
				_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(className, _6);
				if (zephir_has_constructor(className TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, className, "__construct", NULL);
					zephir_check_call_status();
				}
			}
			if (zephir_is_instance_of(className, SL("Traversable") TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", &_7, className);
				zephir_check_call_status();
				continue;
			}
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugin", &_8, name, className);
		zephir_check_call_status();
	}
	_2->funcs->dtor(_2 TSRMLS_CC);
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
	if (zephir_array_key_exists(plugins, lookup TSRMLS_CC)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
		zephir_array_unset(&_0, lookup, PH_SEPARATE);
	}
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

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL, *lookup = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, name);
	zephir_get_strval(lookup, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("plugins"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_1, lookup));

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
	zval *name_param = NULL, *className, *lookup = NULL, *_0 = NULL, *_1, *_2;
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
	if (zephir_array_isset_fetch(&className, _2, lookup, 1 TSRMLS_CC)) {
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
	ZEPHIR_INIT_VAR(iterator);
	object_init_ex(iterator, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, plugins);
	zephir_check_call_status();
	RETURN_CCTOR(iterator);

}

