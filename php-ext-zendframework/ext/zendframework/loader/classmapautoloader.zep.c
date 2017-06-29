
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/require.h"
#include "kernel/file.h"
#include "kernel/string.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Class-map autoloader
 *
 * Utilizes class-map files to lookup classfile locations.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Loader_ClassMapAutoloader) {

	ZEPHIR_REGISTER_CLASS(Zend\\Loader, ClassMapAutoloader, zendframework, loader_classmapautoloader, zendframework_loader_classmapautoloader_method_entry, 0);

	/**
	 * Registry of map files that have already been loaded
	 * @var array
	 */
	zend_declare_property_null(zendframework_loader_classmapautoloader_ce, SL("mapsLoaded"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Class name/filename map
	 * @var array
	 */
	zend_declare_property_null(zendframework_loader_classmapautoloader_ce, SL("map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_loader_classmapautoloader_ce TSRMLS_CC, 1, zendframework_loader_splautoloader_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Create a new instance, and optionally configure the autoloader.
 *
 * @param  null|array|Traversable $options
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("mapsLoaded"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("mapsLoaded"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("map"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("map"), _1 TSRMLS_CC);
	}
	if (Z_TYPE_P(options) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Configure the autoloader
 *
 * Proxies to {@link registerAutoloadMaps()}.
 *
 * @param  array|Traversable $options
 * @return ClassMapAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, setOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerautoloadmaps", NULL, options);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Register an autoload map
 *
 * An autoload map may be either an associative array, or a file returning
 * an associative array.
 *
 * An autoload map should be an associative array containing
 * classname/file pairs.
 *
 * @param  string|array $map
 * @throws Exception\InvalidArgumentException
 * @return ClassMapAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, registerAutoloadMap) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *map = NULL, *exceptionMsg = NULL, *location = NULL, *merged, *baseMap = NULL, *mapsLoaded = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_SEPARATE_PARAM(map);
	ZEPHIR_INIT_VAR(location);
	ZVAL_NULL(location);


	if (Z_TYPE_P(map) == IS_STRING) {
		ZEPHIR_CPY_WRT(location, map);
		ZEPHIR_CALL_METHOD(&map, this_ptr, "loadmapfromfile", NULL, location);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(map, this_ptr)) {
			RETURN_THIS();
		}
	}
	if (unlikely(Z_TYPE_P(map) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZVAL_STRING(exceptionMsg, "Map file provided does not return a map. Map file: \"", 1);
		if (ZEPHIR_IS_EMPTY(location)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_gettype(_0, map TSRMLS_CC);
			ZEPHIR_INIT_NVAR(location);
			ZEPHIR_CONCAT_SV(location, "unexpected type: ", _0);
		}
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VVS(_1, exceptionMsg, location, "\"");
		ZEPHIR_CPY_WRT(exceptionMsg, _1);
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "zendframework/loader/classmapautoloader.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(baseMap);
	zephir_read_property_this(&baseMap, this_ptr, SL("map"), PH_NOISY_CC);
	if (Z_TYPE_P(baseMap) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(baseMap);
		array_init(baseMap);
	}
	ZEPHIR_INIT_VAR(merged);
	zephir_fast_array_merge(merged, &(baseMap), &(map) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("map"), merged TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(location))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("mapsLoaded"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(mapsLoaded, _2);
		if (Z_TYPE_P(mapsLoaded) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(mapsLoaded);
			array_init(mapsLoaded);
		}
		zephir_array_append(&mapsLoaded, location, PH_SEPARATE, "zendframework/loader/classmapautoloader.zep", 114);
		zephir_update_property_this(this_ptr, SL("mapsLoaded"), mapsLoaded TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Register many autoload maps at once
 *
 * @param  array $locations
 * @throws Exception\InvalidArgumentException
 * @return ClassMapAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, registerAutoloadMaps) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *locations = NULL, *location = NULL, _0, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &locations);

	ZEPHIR_SEPARATE_PARAM(locations);


	if (Z_TYPE_P(locations) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, locations, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map list must be an array or implement Traversable", "zendframework/loader/classmapautoloader.zep", 133);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, locations);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(locations, _3);
	}
	zephir_is_iterable(locations, &_5, &_4, 0, 0, "zendframework/loader/classmapautoloader.zep", 141);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(location, _6);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerautoloadmap", &_7, location);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Retrieve current autoload map
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, getAutoloadMap) {


	RETURN_MEMBER(this_ptr, "map");

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, autoload) {

	zval *class_param = NULL, *path, *map = NULL, *_0, *_1;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(map, _0);
	if (Z_TYPE_P(map) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("map"), _1 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(path);
	if (zephir_array_isset_fetch(&path, map, class, 0 TSRMLS_CC)) {
		if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CTOR(class);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Register the autoloader with spl_autoload registry
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "autoload", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _0, ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Load a map from a file
 *
 * If the map has been previously loaded, returns the current instance;
 * otherwise, returns whatever was returned by calling include() on the
 * location.
 *
 * @param  string $location
 * @return ClassMapAutoloader|mixed
 * @throws Exception\InvalidArgumentException for nonexistent locations
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, loadMapFromFile) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *location = NULL, *path = NULL, *map = NULL, *mapsLoaded = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);

	ZEPHIR_SEPARATE_PARAM(location);


	if (unlikely(!(zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		if (Z_TYPE_P(location) != IS_STRING) {
			ZEPHIR_INIT_VAR(_0);
			zephir_gettype(_0, location TSRMLS_CC);
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "unexpected type: ", _0);
			ZEPHIR_CPY_WRT(location, _1);
		}
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Map file provided does not exist. Map file: \"", location, "\"");
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "zendframework/loader/classmapautoloader.zep", 205 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_STATIC(&path, "realpharpath", NULL, location);
	zephir_check_call_status();
	if (!(zephir_is_true(path))) {
		ZEPHIR_CALL_FUNCTION(&path, "realpath", &_2, location);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("mapsLoaded"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(mapsLoaded, _3);
	if (Z_TYPE_P(mapsLoaded) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(mapsLoaded);
		array_init(mapsLoaded);
		zephir_update_property_this(this_ptr, SL("mapsLoaded"), mapsLoaded TSRMLS_CC);
	}
	if (zephir_fast_in_array(path, mapsLoaded TSRMLS_CC)) {
		RETURN_THIS();
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(map, _4);
	RETURN_CCTOR(map);

}

/**
 * Resolve the real_path() to a file within a phar.
 *
 * @see https://bugs.php.net/bug.php?id=52769
 * @param  string $path
 * @return string
 */
PHP_METHOD(ZendFramework_Loader_ClassMapAutoloader, realPharPath) {

	zend_bool _11;
	HashTable *_9, *_14;
	HashPosition _8, _13;
	zval *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_12 = NULL, *_19 = NULL;
	zval *path_param = NULL, *match, *value = NULL, *key = NULL, *parts = NULL, *partsFiltered, *realPath = NULL, *prefixLength, *_0 = NULL, *_1 = NULL, *_3, *_6 = NULL, _7, **_10, **_15, *_16 = NULL, _17, _18, *_20;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);
	ZEPHIR_INIT_VAR(match);
	array_init(match);
	ZEPHIR_INIT_VAR(partsFiltered);
	array_init(partsFiltered);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "|^phar:(/{2,3})|", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(match);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, path, match);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(match);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_STRING("", 1);
	}
	zephir_array_fetch_long(&_3, match, 1, PH_NOISY | PH_READONLY, "zendframework/loader/classmapautoloader.zep", 242 TSRMLS_CC);
	ZEPHIR_INIT_VAR(prefixLength);
	ZVAL_LONG(prefixLength, (5 + zephir_fast_strlen_ev(_3)));
	ZEPHIR_CALL_FUNCTION(&parts, "substr", &_4, path, prefixLength);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 3);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "/", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "\\", 1);
	zephir_array_fast_append(_5, _6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_str_replace(_0, _5, &_7, parts TSRMLS_CC);
	ZEPHIR_CPY_WRT(parts, _0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_explode_str(_0, SL("/"), parts, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(parts, _0);
	zephir_is_iterable(parts, &_9, &_8, 0, 0, "zendframework/loader/classmapautoloader.zep", 251);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(value, _10);
		_11 = !ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (_11) {
			_11 = !ZEPHIR_IS_STRING_IDENTICAL(value, ".");
		}
		if (_11) {
			zephir_array_append(&partsFiltered, value, PH_SEPARATE, "zendframework/loader/classmapautoloader.zep", 248);
		}
	}
	ZEPHIR_CALL_FUNCTION(&parts, "array_values", &_12, partsFiltered);
	zephir_check_call_status();
	zephir_is_iterable(parts, &_14, &_13, 1, 0, "zendframework/loader/classmapautoloader.zep", 260);
	for (
	  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
	  ; zephir_hash_move_forward_ex(_14, &_13)
	) {
		ZEPHIR_GET_HKEY(key, _14, _13);
		ZEPHIR_GET_HVALUE(value, _15);
		if (ZEPHIR_IS_STRING_IDENTICAL(value, "..")) {
			zephir_array_unset(&parts, key, PH_SEPARATE);
			zephir_array_unset_long(&parts, (zephir_get_numberval(key) - 1), PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_16, "array_values", &_12, parts);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(parts, _16);
		}
	}
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_STRING(&_17, "phar:", 0);
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_STRING(&_18, "/", 0);
	ZEPHIR_CALL_FUNCTION(&realPath, "str_pad", &_19, &_17, prefixLength, &_18);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_join_str(_0, SL("/"), parts TSRMLS_CC);
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_VV(_20, realPath, _0);
	ZEPHIR_CPY_WRT(realPath, _20);
	if ((zephir_file_exists(realPath TSRMLS_CC) == SUCCESS)) {
		RETURN_CCTOR(realPath);
	}
	RETURN_MM_STRING("", 1);

}

