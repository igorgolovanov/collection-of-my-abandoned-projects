
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/file.h"
#include "kernel/string.h"

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
	zval *options = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("map"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("mapsLoaded"), _1 TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *map = NULL, *exceptionMsg = NULL, *location = NULL, *merged = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &map);

	ZEPHIR_SEPARATE_PARAM(map);


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
		zephir_throw_exception_debug(_0, "zendframework/loader/classmapautoloader.zep", 90 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&merged, "array_map", &_3, _2, map);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("map"), merged TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(location))) {
		zephir_update_property_array_append(this_ptr, SL("mapsLoaded"), location TSRMLS_CC);
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

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zval *locations, *location = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &locations);



	_0 = Z_TYPE_P(locations) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(locations, SL("ZendFramework\\Loader\\Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Map list must be an array or implement Traversable", "zendframework/loader/classmapautoloader.zep", 114);
		return;
	}
	zephir_is_iterable(locations, &_2, &_1, 0, 0, "zendframework/loader/classmapautoloader.zep", 120);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(location, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerautoloadmap", &_4, location);
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

	zval *class_param = NULL, *path, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	ZEPHIR_OBS_VAR(path);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&path, _0, class, 0 TSRMLS_CC)) {
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
	zval *_0;
	zval *autoload;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(autoload);
	array_init_size(autoload, 3);
	zephir_array_fast_append(autoload, this_ptr);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "autoload", 1);
	zephir_array_fast_append(autoload, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, autoload, ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_true));
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
	zval *location_param = NULL, *path = NULL, *map = NULL, *_0 = NULL, *_1, *_3, *_4 = NULL;
	zval *location = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location_param);

	zephir_get_strval(location, location_param);


	if (unlikely(!(zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		if (1 != 1) {
			ZEPHIR_INIT_VAR(_0);
			zephir_gettype(_0, location TSRMLS_CC);
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "unexpected type: ", _0);
			zephir_get_strval(location, _1);
		}
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Map file provided does not exist. Map file: \"", location, "\"");
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "zendframework/loader/classmapautoloader.zep", 182 TSRMLS_CC);
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
	if (zephir_fast_in_array(path, _3 TSRMLS_CC)) {
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

	zend_bool _12;
	HashTable *_10, *_15;
	HashPosition _9, _14;
	zval *_4;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_13 = NULL, *_21 = NULL;
	int prefixLength, ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *match = NULL, *value = NULL, *key = NULL, *parts = NULL, *partsFiltered, *realPath, *_0 = NULL, *_1 = NULL, *_3, *_5 = NULL, _6 = zval_used_for_init, *_7 = NULL, **_11, **_16, *_17 = NULL, _18, _19, _20;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);
	ZEPHIR_INIT_VAR(match);
	ZVAL_NULL(match);
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
	zephir_array_fetch_long(&_3, match, 1, PH_NOISY | PH_READONLY, "zendframework/loader/classmapautoloader.zep", 214 TSRMLS_CC);
	prefixLength = (5 + zephir_fast_strlen_ev(_3));
	ZEPHIR_INIT_VAR(parts);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "/", 1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "\\", 1);
	zephir_array_fast_append(_4, _5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, prefixLength);
	ZEPHIR_CALL_FUNCTION(&_7, "substr", &_8, path, &_6);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "/", 0);
	zephir_fast_str_replace(_0, _4, &_6, _7 TSRMLS_CC);
	zephir_fast_explode_str(parts, SL("/"), _0, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(parts, &_10, &_9, 0, 0, "zendframework/loader/classmapautoloader.zep", 221);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(value, _11);
		_12 = !ZEPHIR_IS_STRING_IDENTICAL(value, "");
		if (_12) {
			_12 = !ZEPHIR_IS_STRING_IDENTICAL(value, ".");
		}
		if (_12) {
			zephir_array_append(&partsFiltered, value, PH_SEPARATE, "zendframework/loader/classmapautoloader.zep", 218);
		}
	}
	ZEPHIR_CALL_FUNCTION(&parts, "array_values", &_13, partsFiltered);
	zephir_check_call_status();
	zephir_is_iterable(parts, &_15, &_14, 1, 0, "zendframework/loader/classmapautoloader.zep", 230);
	for (
	  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zephir_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HKEY(key, _15, _14);
		ZEPHIR_GET_HVALUE(value, _16);
		if (ZEPHIR_IS_STRING_IDENTICAL(value, "..")) {
			zephir_array_unset(&parts, key, PH_SEPARATE);
			zephir_array_unset_long(&parts, (zephir_get_numberval(key) - 1), PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_17, "array_values", &_13, parts);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(parts, _17);
		}
	}
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_STRING(&_18, "phar:", 0);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_LONG(&_19, prefixLength);
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_STRING(&_20, "/", 0);
	ZEPHIR_CALL_FUNCTION(&_17, "str_pad", &_21, &_18, &_19, &_20);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	zephir_fast_join_str(_5, SL("/"), parts TSRMLS_CC);
	ZEPHIR_INIT_VAR(realPath);
	ZEPHIR_CONCAT_VV(realPath, _17, _5);
	if ((zephir_file_exists(realPath TSRMLS_CC) == SUCCESS)) {
		RETURN_CCTOR(realPath);
	}
	RETURN_MM_STRING("", 1);

}

