
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_directory.h"
#include "kernel/iterator.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Loader_ModuleAutoloader) {

	ZEPHIR_REGISTER_CLASS(Zend\\Loader, ModuleAutoloader, zendframework, loader_moduleautoloader, zendframework_loader_moduleautoloader_method_entry, 0);

	/**
	 * @var array An array of module paths to scan
	 */
	zend_declare_property_null(zendframework_loader_moduleautoloader_ce, SL("paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array An array of modulename => path
	 */
	zend_declare_property_null(zendframework_loader_moduleautoloader_ce, SL("explicitPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array An array of namespaceName => namespacePath
	 */
	zend_declare_property_null(zendframework_loader_moduleautoloader_ce, SL("namespacedPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array An array of supported phar extensions (filled on constructor)
	 */
	zend_declare_property_null(zendframework_loader_moduleautoloader_ce, SL("pharExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array An array of module classes to their containing files
	 */
	zend_declare_property_null(zendframework_loader_moduleautoloader_ce, SL("moduleClassMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_loader_moduleautoloader_ce TSRMLS_CC, 1, zendframework_loader_splautoloader_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * Allow configuration of the autoloader via the constructor.
 *
 * @param  null|array|Traversable $options
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, __construct) {

	zval *_9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zval *options = NULL, *_0, *_1 = NULL, *_2, *_3, *_4, *_5, _6 = zval_used_for_init, *_7 = NULL, *_10 = NULL, *_11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("paths"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("paths"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("explicitPaths"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("explicitPaths"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("namespacedPaths"), PH_NOISY_CC);
	if (Z_TYPE_P(_3) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("namespacedPaths"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("pharExtensions"), PH_NOISY_CC);
	if (Z_TYPE_P(_4) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("pharExtensions"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("moduleClassMap"), PH_NOISY_CC);
	if (Z_TYPE_P(_5) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("moduleClassMap"), _1 TSRMLS_CC);
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "phar", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "extension_loaded", &_8, &_6);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		ZEPHIR_INIT_VAR(_9);
		array_init_size(_9, 4);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "phar", 1);
		zephir_array_fast_append(_9, _1);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "phar.tar", 1);
		zephir_array_fast_append(_9, _1);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "tar", 1);
		zephir_array_fast_append(_9, _1);
		zephir_update_property_this(this_ptr, SL("pharExtensions"), _9 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "zlib", 0);
		ZEPHIR_CALL_FUNCTION(&_10, "extension_loaded", &_8, &_6);
		zephir_check_call_status();
		if (zephir_is_true(_10)) {
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "phar.gz", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "phar.tar.gz", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "tar.gz", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "phar.zip", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "zip", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
		}
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "bzip2", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "extension_loaded", &_8, &_6);
		zephir_check_call_status();
		if (zephir_is_true(_12)) {
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "phar.bz2", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "phar.tar.bz2", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11);
			ZVAL_STRING(_11, "tar.bz2", 1);
			zephir_update_property_array_append(this_ptr, SL("pharExtensions"), _11 TSRMLS_CC);
		}
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
 * In most cases, $options should be either an associative array or
 * Traversable object.
 *
 * @param  array|Traversable $options
 * @return ModuleAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, setOptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerpaths", NULL, options);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Retrieves the class map for all loaded modules.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, getModuleClassMap) {


	RETURN_MEMBER(this_ptr, "moduleClassMap");

}

/**
 * Sets the class map used to speed up the module autoloading.
 *
 * @param  array $classmap
 * @return ModuleAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, setModuleClassMap) {

	zval *classmap_param = NULL;
	zval *classmap = NULL;

	zephir_fetch_params(0, 1, 0, &classmap_param);

	if (unlikely(Z_TYPE_P(classmap_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'classmap' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		classmap = classmap_param;



	zephir_update_property_this(this_ptr, SL("moduleClassMap"), classmap TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Autoload a class
 *
 * @param   $class
 * @return  mixed
 *          False [if unable to load $class]
 *          get_class($class) [if $class is successfully loaded]
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, autoload) {

	zend_object_iterator *_28;
	zend_bool _22, _23;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_27 = NULL;
	HashTable *_7, *_19;
	HashPosition _6, _18;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_15 = NULL, *_24 = NULL, *_25 = NULL, *_31 = NULL;
	zval *class_param = NULL, *str = NULL, *classLoaded = NULL, *className = NULL, *pos = NULL, *basePath = NULL, *entry = NULL, *glob = NULL, *moduleClassFile = NULL, *moduleName = NULL, *ns = NULL, *path = NULL, *moduleNameBuffer = NULL, *moduleClassPath, *pharSuffixPattern = NULL, *namespacedPaths = NULL, *exts = NULL, *paths = NULL, *pharExtensions = NULL, _0 = zval_used_for_init, *_2, _3 = zval_used_for_init, *_4, *_5, **_8, *_9 = NULL, *_10 = NULL, _13, _14 = zval_used_for_init, *_16 = NULL, *_17, **_20, _21 = zval_used_for_init, *_26 = NULL, *_29 = NULL, *_30 = NULL, *_32 = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);
	ZEPHIR_INIT_VAR(pharSuffixPattern);
	ZVAL_NULL(pharSuffixPattern);


	ZEPHIR_CPY_WRT(className, class);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -7);
	ZEPHIR_CALL_FUNCTION(&str, "substr", &_1, className, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(str, "\\Module")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(moduleClassFile);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("moduleClassMap"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&moduleClassFile, _2, className, 0 TSRMLS_CC)) {
		if (zephir_require_zval(moduleClassFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(moduleClassFile);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -7);
	ZEPHIR_CALL_FUNCTION(&moduleName, "substr", &_1, className, &_0, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(moduleClassFile);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("explicitPaths"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&moduleClassFile, _4, moduleName, 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromdir", NULL, moduleClassFile, className);
		zephir_check_call_status();
		if (zephir_is_true(classLoaded)) {
			RETURN_CCTOR(classLoaded);
		}
		ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromphar", NULL, moduleClassFile, className);
		zephir_check_call_status();
		if (zephir_is_true(classLoaded)) {
			RETURN_CCTOR(classLoaded);
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("namespacedPaths"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(namespacedPaths, _5);
	if (Z_TYPE_P(namespacedPaths) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(namespacedPaths);
		array_init(namespacedPaths);
		zephir_update_property_this(this_ptr, SL("namespacedPaths"), namespacedPaths TSRMLS_CC);
	}
	if (zephir_fast_count_int(namespacedPaths TSRMLS_CC) >= 1) {
		zephir_is_iterable(namespacedPaths, &_7, &_6, 0, 0, "zendframework/loader/moduleautoloader.zep", 193);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(ns, _7, _6);
			ZEPHIR_GET_HVALUE(path, _8);
			ZEPHIR_INIT_NVAR(pos);
			zephir_fast_strpos(pos, moduleName, ns, 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(moduleNameBuffer);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VS(_9, ns, "\\");
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_STRING(&_0, "", 0);
			zephir_fast_str_replace(moduleNameBuffer, _9, &_0, moduleName TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VSVS(_10, path, "/", moduleNameBuffer, "/");
			ZEPHIR_CPY_WRT(path, _10);
			ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromdir", &_11, path, className);
			zephir_check_call_status();
			if (zephir_is_true(classLoaded)) {
				RETURN_CCTOR(classLoaded);
			}
			ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromphar", &_12, path, className);
			zephir_check_call_status();
			if (zephir_is_true(classLoaded)) {
				RETURN_CCTOR(classLoaded);
			}
		}
	}
	ZEPHIR_INIT_VAR(moduleClassPath);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "\\", 0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "/", 0);
	zephir_fast_str_replace(moduleClassPath, &_3, &_13, moduleName TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("pharExtensions"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pharExtensions, _5);
	if (Z_TYPE_P(pharExtensions) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(pharExtensions);
		array_init(pharExtensions);
		zephir_update_property_this(this_ptr, SL("pharExtensions"), pharExtensions TSRMLS_CC);
	}
	if (zephir_fast_count_int(pharExtensions TSRMLS_CC) > 0) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("pharExtensions"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_14);
		ZVAL_STRING(&_14, "preg_quote", 0);
		ZEPHIR_CALL_FUNCTION(&exts, "array_map", &_15, &_14, _5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_16);
		zephir_fast_join_str(_16, SL("|"), exts TSRMLS_CC);
		ZEPHIR_INIT_NVAR(pharSuffixPattern);
		ZEPHIR_CONCAT_SVS(pharSuffixPattern, "(", _16, ")");
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "#.+\\.", pharSuffixPattern, "$#");
		ZEPHIR_CPY_WRT(pharSuffixPattern, _9);
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(paths, _17);
	if (Z_TYPE_P(paths) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(paths);
		array_init(paths);
		zephir_update_property_this(this_ptr, SL("paths"), paths TSRMLS_CC);
	}
	zephir_is_iterable(paths, &_19, &_18, 0, 0, "zendframework/loader/moduleautoloader.zep", 248);
	for (
	  ; zephir_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
	  ; zephir_hash_move_forward_ex(_19, &_18)
	) {
		ZEPHIR_GET_HVALUE(path, _20);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_VV(_9, path, moduleClassPath);
		ZEPHIR_CPY_WRT(path, _9);
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_LONG(&_14, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 2);
		ZEPHIR_CALL_FUNCTION(&str, "substr", &_1, path, &_14, &_21);
		zephir_check_call_status();
		_22 = ZEPHIR_IS_STRING(path, ".");
		if (!(_22)) {
			_22 = ZEPHIR_IS_STRING(str, "./");
		}
		_23 = _22;
		if (!(_23)) {
			_23 = ZEPHIR_IS_STRING(str, ".\\");
		}
		if (_23) {
			ZEPHIR_SINIT_NVAR(_14);
			ZVAL_STRING(&_14, ".", 0);
			ZEPHIR_CALL_FUNCTION(&basePath, "realpath", &_24, &_14);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(basePath)) {
				ZEPHIR_CALL_FUNCTION(&basePath, "getcwd", &_25);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_16);
			ZEPHIR_SINIT_NVAR(_14);
			ZVAL_STRING(&_14, "\\/\\", 0);
			zephir_fast_trim(_16, basePath, &_14, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_21);
			ZVAL_LONG(&_21, 1);
			ZEPHIR_CALL_FUNCTION(&_26, "substr", &_1, path, &_21);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VV(_9, _16, _26);
			ZEPHIR_CPY_WRT(path, _9);
		}
		ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromdir", &_11, path, className);
		zephir_check_call_status();
		if (zephir_is_true(classLoaded)) {
			RETURN_CCTOR(classLoaded);
		}
		if (Z_TYPE_P(pharSuffixPattern) != IS_NULL) {
			ZEPHIR_INIT_NVAR(glob);
			object_init_ex(glob, spl_ce_GlobIterator);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VS(_9, path, ".*");
			ZEPHIR_CALL_METHOD(NULL, glob, "__construct", &_27, _9);
			zephir_check_call_status();
			_28 = zephir_get_iterator(glob TSRMLS_CC);
			_28->funcs->rewind(_28 TSRMLS_CC);
			for (;_28->funcs->valid(_28 TSRMLS_CC) == SUCCESS && !EG(exception); _28->funcs->move_forward(_28 TSRMLS_CC)) {
				{ zval **tmp; 
				_28->funcs->get_current_data(_28, &tmp TSRMLS_CC);
				entry = *tmp;
				}
				ZEPHIR_CALL_METHOD(&_26, entry, "isdir", NULL);
				zephir_check_call_status();
				if (zephir_is_true(_26)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_29, entry, "getpathname", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_30, "preg_match", &_31, pharSuffixPattern, _29);
				zephir_check_call_status();
				if (!(zephir_is_true(_30))) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_32, entry, "getpathname", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromphar", &_12, _32, className);
				zephir_check_call_status();
				if (zephir_is_true(classLoaded)) {
					RETURN_CCTOR(classLoaded);
				}
			}
			_28->funcs->dtor(_28 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * loadModuleFromDir
 *
 * @param  string $dirPath
 * @param  string $class
 * @return  mixed
 *          False [if unable to load $class]
 *          get_class($class) [if $class is successfully loaded]
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, loadModuleFromDir) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dirPath_param = NULL, *class_param = NULL, *file, *filePath = NULL, *_1 = NULL, *_3 = NULL;
	zval *dirPath = NULL, *class = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dirPath_param, &class_param);

	zephir_get_strval(dirPath, dirPath_param);
	zephir_get_strval(class, class_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, dirPath, "/Module.php");
	ZEPHIR_CPY_WRT(filePath, _0);
	ZEPHIR_INIT_VAR(file);
	object_init_ex(file, spl_ce_SplFileInfo);
	ZEPHIR_CALL_METHOD(NULL, file, "__construct", NULL, filePath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, file, "isreadable", NULL);
	zephir_check_call_status();
	_2 = zephir_is_true(_1);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, file, "isfile", NULL);
		zephir_check_call_status();
		_2 = zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&filePath, file, "getrealpath", NULL);
		zephir_check_call_status();
		if (zephir_require_zval(filePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		if (zephir_class_exists(class, 1 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("moduleClassMap"), class, filePath TSRMLS_CC);
			RETURN_CTOR(class);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * loadModuleFromPhar
 *
 * @param  string $pharPath
 * @param  string $class
 * @return  mixed
 *          False [if unable to load $class]
 *          get_class($class) [if $class is successfully loaded]
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, loadModuleFromPhar) {

	zend_bool _3, _7, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pharPath_param = NULL, *class_param = NULL, *file, *pos, *moduleFile = NULL, *fileRealPath = NULL, *moduleClassFile = NULL, *pharBaseName = NULL, *_0 = NULL, *_1, *_2 = NULL, *_4 = NULL, _5, *_6 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL;
	zval *pharPath = NULL, *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pharPath_param, &class_param);

	zephir_get_strval(pharPath, pharPath_param);
	zephir_get_strval(class, class_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 0);
	ZEPHIR_CALL_STATIC(&_0, "normalizepath", NULL, pharPath, _1);
	zephir_check_call_status();
	zephir_get_strval(pharPath, _0);
	ZEPHIR_INIT_VAR(file);
	object_init_ex(file, spl_ce_SplFileInfo);
	ZEPHIR_CALL_METHOD(NULL, file, "__construct", NULL, pharPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, file, "isreadable", NULL);
	zephir_check_call_status();
	_3 = !zephir_is_true(_2);
	if (!(_3)) {
		ZEPHIR_CALL_METHOD(&_4, file, "isfile", NULL);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&fileRealPath, file, "getrealpath", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, ".phar", 0);
	ZEPHIR_INIT_VAR(pos);
	zephir_fast_strpos(pos, fileRealPath, &_5, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		if (zephir_require_zval(fileRealPath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		if (zephir_class_exists(class, 1 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("moduleClassMap"), class, fileRealPath TSRMLS_CC);
			RETURN_CTOR(class);
		}
	}
	ZEPHIR_INIT_VAR(moduleClassFile);
	ZEPHIR_CONCAT_SVS(moduleClassFile, "phar://", fileRealPath, "/Module.php");
	ZEPHIR_INIT_VAR(moduleFile);
	object_init_ex(moduleFile, spl_ce_SplFileInfo);
	ZEPHIR_CALL_METHOD(NULL, moduleFile, "__construct", NULL, moduleClassFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, moduleFile, "isreadable", NULL);
	zephir_check_call_status();
	_7 = zephir_is_true(_6);
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8, moduleFile, "isfile", NULL);
		zephir_check_call_status();
		_7 = zephir_is_true(_8);
	}
	if (_7) {
		if (zephir_require_zval(moduleClassFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		if (zephir_class_exists(class, 1 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("moduleClassMap"), class, fileRealPath TSRMLS_CC);
			RETURN_CTOR(class);
		}
	}
	ZEPHIR_CALL_METHOD(&pharBaseName, this_ptr, "pharfiletomodulename", NULL, fileRealPath);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(moduleClassFile);
	ZEPHIR_CONCAT_SVSVS(moduleClassFile, "phar://", fileRealPath, "/", pharBaseName, "/Module.php");
	ZEPHIR_INIT_NVAR(moduleFile);
	object_init_ex(moduleFile, spl_ce_SplFileInfo);
	ZEPHIR_CALL_METHOD(NULL, moduleFile, "__construct", NULL, moduleClassFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, moduleFile, "isreadable", NULL);
	zephir_check_call_status();
	_10 = zephir_is_true(_9);
	if (_10) {
		ZEPHIR_CALL_METHOD(&_11, moduleFile, "isfile", NULL);
		zephir_check_call_status();
		_10 = zephir_is_true(_11);
	}
	if (_10) {
		if (zephir_require_zval(moduleClassFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		if (zephir_class_exists(class, 1 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("moduleClassMap"), class, fileRealPath TSRMLS_CC);
			RETURN_CTOR(class);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Register the autoloader with spl_autoload registry
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, register) {

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
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Unregister the autoloader with spl_autoload registry
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, unregister) {

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
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * registerPaths
 *
 * @param  array|Traversable $paths
 * @throws \InvalidArgumentException
 * @return ModuleAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, registerPaths) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *paths = NULL, *module = NULL, *path = NULL, _0, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths);

	ZEPHIR_SEPARATE_PARAM(paths);


	if (Z_TYPE_P(paths) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, paths, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Parameter to \\Zend\\Loader\\ModuleAutoloader's registerPaths method must be an array or implement the Traversable interface", "zendframework/loader/moduleautoloader.zep", 378);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, paths);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(paths, _3);
	}
	zephir_is_iterable(paths, &_5, &_4, 0, 0, "zendframework/loader/moduleautoloader.zep", 391);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(module, _5, _4);
		ZEPHIR_GET_HVALUE(path, _6);
		if (Z_TYPE_P(module) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerpath", &_7, path, module);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerpath", &_7, path);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

/**
 * registerPath
 *
 * @param  string $path
 * @param  bool|string $moduleName
 * @throws \InvalidArgumentException
 * @return ModuleAutoloader
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, registerPath) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *path, *moduleName = NULL, *moduleNamePart = NULL, *normalizedPath = NULL, *patterns = NULL, *_0 = NULL, *_1, *_2, _3 = zval_used_for_init, _5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &moduleName);

	if (!moduleName) {
		moduleName = ZEPHIR_GLOBAL(global_false);
	}
	ZEPHIR_INIT_VAR(patterns);
	array_init(patterns);


	ZEPHIR_INIT_NVAR(patterns);
	array_init_size(patterns, 3);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "\\*", 1);
	zephir_array_fast_append(patterns, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "\\%", 1);
	zephir_array_fast_append(patterns, _0);
	if (unlikely(Z_TYPE_P(path) != IS_STRING)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_gettype(_0, path TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Invalid path provided; must be a string, received ", _0);
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/loader/moduleautoloader.zep", 409 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_STATIC(&normalizedPath, "normalizepath", NULL, path);
	zephir_check_call_status();
	if (zephir_is_true(moduleName)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, -2);
		ZEPHIR_CALL_FUNCTION(&moduleNamePart, "substr", &_4, moduleName, &_3);
		zephir_check_call_status();
		if (zephir_fast_in_array(moduleNamePart, patterns TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, 0);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_LONG(&_5, -2);
			ZEPHIR_CALL_FUNCTION(&moduleNamePart, "substr", &_4, moduleName, &_3, &_5);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("namespacedPaths"), moduleNamePart, normalizedPath TSRMLS_CC);
		} else {
			zephir_update_property_array(this_ptr, SL("explicitPaths"), moduleName, normalizedPath TSRMLS_CC);
		}
	} else {
		zephir_update_property_array_append(this_ptr, SL("paths"), normalizedPath TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * getPaths
 *
 * This is primarily for unit testing, but could have other uses.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, getPaths) {


	RETURN_MEMBER(this_ptr, "paths");

}

/**
 * Returns the base module name from the path to a phar
 *
 * @param  string $pharPath
 * @return string
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, pharFileToModuleName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *pharPath_param = NULL, *info = NULL, *path = NULL, *_1;
	zval *pharPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pharPath_param);

	zephir_get_strval(pharPath, pharPath_param);


	ZEPHIR_CPY_WRT(path, pharPath);
	do {
		ZEPHIR_CALL_FUNCTION(&info, "pathinfo", &_0, path);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(path);
		zephir_array_fetch_string(&path, info, SL("filename"), PH_NOISY, "zendframework/loader/moduleautoloader.zep", 454 TSRMLS_CC);
	} while (zephir_array_isset_string(info, SS("extension")));
	zephir_array_fetch_string(&_1, info, SL("filename"), PH_NOISY | PH_READONLY, "zendframework/loader/moduleautoloader.zep", 457 TSRMLS_CC);
	RETURN_CTOR(_1);

}

/**
 * Normalize a path for insertion in the stack
 *
 * @param  string $path
 * @param  bool   $trailingSlash Whether trailing slash should be included
 * @return string
 */
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, normalizePath) {

	zend_bool trailingSlash;
	zval *path_param = NULL, *trailingSlash_param = NULL, *_0, _1, *_2, _3;
	zval *path = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &trailingSlash_param);

	zephir_get_strval(path, path_param);
	if (!trailingSlash_param) {
		trailingSlash = 1;
	} else {
		trailingSlash = zephir_get_boolval(trailingSlash_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	zephir_fast_trim(_0, path, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(path, _0);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\\", 0);
	zephir_fast_trim(_2, path, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(path, _2);
	if (trailingSlash) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, path, "/");
		ZEPHIR_CPY_WRT(path, _4);
	}
	RETURN_CTOR(path);

}

