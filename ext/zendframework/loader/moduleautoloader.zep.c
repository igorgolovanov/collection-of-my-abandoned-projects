
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

	zval *_8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zval *options = NULL, *_0, *_1, *_2, *_3, *_4, _5 = zval_used_for_init, *_6 = NULL, *_9 = NULL, *_10 = NULL, *_11, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("moduleClassMap"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("pharExtensions"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("namespacedPaths"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("explicitPaths"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("paths"), _4 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "phar", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "extension_loaded", &_7, &_5);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_VAR(_8);
		array_init_size(_8, 4);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "phar", 1);
		zephir_array_fast_append(_8, _9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "phar.tar", 1);
		zephir_array_fast_append(_8, _9);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "tar", 1);
		zephir_array_fast_append(_8, _9);
		zephir_update_property_this(this_ptr, SL("pharExtensions"), _8 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "zlib", 0);
		ZEPHIR_CALL_FUNCTION(&_10, "extension_loaded", &_7, &_5);
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
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "bzip2", 0);
		ZEPHIR_CALL_FUNCTION(&_12, "extension_loaded", &_7, &_5);
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

	zend_bool _22, _23;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_27 = NULL;
	HashTable *_7, *_19, *_29;
	HashPosition _6, _18, _28;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_16 = NULL, *_24 = NULL, *_25 = NULL;
	zval *class_param = NULL, *str = NULL, *classLoaded = NULL, *className = NULL, *pos = NULL, *basePath = NULL, *entry = NULL, *glob = NULL, *moduleClassFile = NULL, *moduleName = NULL, *ns = NULL, *path = NULL, *moduleNameBuffer = NULL, *moduleClassPath, *pharSuffixPattern = NULL, *namespacedPaths = NULL, *exts = NULL, _0 = zval_used_for_init, *_2, _3 = zval_used_for_init, *_4, *_5, **_8, *_9 = NULL, *_10 = NULL, _13, *_14, _15 = zval_used_for_init, *_17 = NULL, **_20, _21 = zval_used_for_init, *_26 = NULL, **_30, *_31 = NULL, *_32 = NULL, *_33 = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


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
	if (zephir_fast_count_int(namespacedPaths TSRMLS_CC) >= 1) {
		zephir_is_iterable(namespacedPaths, &_7, &_6, 0, 0, "zendframework/loader/moduleautoloader.zep", 172);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(path, _7, _6);
			ZEPHIR_GET_HVALUE(ns, _8);
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
			zephir_fast_str_replace(moduleNameBuffer, _9, &_0, moduleName);
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
	zephir_fast_str_replace(moduleClassPath, &_3, &_13, moduleName);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("pharExtensions"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_5))) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("pharExtensions"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_15);
		ZVAL_STRING(&_15, "preg_quote", 0);
		ZEPHIR_CALL_FUNCTION(&exts, "array_map", &_16, &_15, _14);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_17);
		zephir_fast_join_str(_17, SL("|"), exts TSRMLS_CC);
		ZEPHIR_INIT_VAR(pharSuffixPattern);
		ZEPHIR_CONCAT_SVS(pharSuffixPattern, "(", _17, ")");
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "#.+\\.", pharSuffixPattern, "$#");
		ZEPHIR_CPY_WRT(pharSuffixPattern, _9);
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_is_iterable(_14, &_19, &_18, 0, 0, "zendframework/loader/moduleautoloader.zep", 218);
	for (
	  ; zephir_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
	  ; zephir_hash_move_forward_ex(_19, &_18)
	) {
		ZEPHIR_GET_HVALUE(path, _20);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_VV(_9, path, moduleClassPath);
		ZEPHIR_CPY_WRT(path, _9);
		ZEPHIR_SINIT_NVAR(_15);
		ZVAL_LONG(&_15, 0);
		ZEPHIR_SINIT_NVAR(_21);
		ZVAL_LONG(&_21, 2);
		ZEPHIR_CALL_FUNCTION(&str, "substr", &_1, path, &_15, &_21);
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
			ZEPHIR_SINIT_NVAR(_15);
			ZVAL_STRING(&_15, ".", 0);
			ZEPHIR_CALL_FUNCTION(&basePath, "realpath", &_24, &_15);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(basePath)) {
				ZEPHIR_CALL_FUNCTION(&basePath, "getcwd", &_25);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_NVAR(_17);
			ZEPHIR_SINIT_NVAR(_15);
			ZVAL_STRING(&_15, "\\/\\", 0);
			zephir_fast_trim(_17, basePath, &_15, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_21);
			ZVAL_LONG(&_21, 1);
			ZEPHIR_CALL_FUNCTION(&_26, "substr", &_1, path, &_21);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VV(_9, _17, _26);
			ZEPHIR_CPY_WRT(path, _9);
		}
		ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromdir", &_11, path, className);
		zephir_check_call_status();
		if (zephir_is_true(classLoaded)) {
			RETURN_CCTOR(classLoaded);
		}
		if (!(ZEPHIR_IS_EMPTY(pharSuffixPattern))) {
			ZEPHIR_INIT_NVAR(glob);
			object_init_ex(glob, spl_ce_GlobIterator);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VS(_9, path, ".*");
			ZEPHIR_CALL_METHOD(NULL, glob, "__construct", &_27, _9);
			zephir_check_call_status();
			zephir_is_iterable(glob, &_29, &_28, 0, 0, "zendframework/loader/moduleautoloader.zep", 215);
			for (
			  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
			  ; zephir_hash_move_forward_ex(_29, &_28)
			) {
				ZEPHIR_GET_HVALUE(entry, _30);
				ZEPHIR_CALL_METHOD(&_26, entry, "isdir",  NULL);
				zephir_check_call_status();
				if (zephir_is_true(_26)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_31, entry, "getpathname",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_32, "preg_math", NULL, pharSuffixPattern, _31);
				zephir_check_call_status();
				if (!(zephir_is_true(_32))) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&_33, entry, "getpathname",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&classLoaded, this_ptr, "loadmodulefromphar", &_12, _33, className);
				zephir_check_call_status();
				if (zephir_is_true(classLoaded)) {
					RETURN_CCTOR(classLoaded);
				}
			}
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
	ZEPHIR_CALL_METHOD(&_1, file, "isreadable",  NULL);
	zephir_check_call_status();
	_2 = zephir_is_true(_1);
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, file, "isfile",  NULL);
		zephir_check_call_status();
		_2 = zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&filePath, file, "getrealpath",  NULL);
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
	ZEPHIR_CALL_METHOD(&_2, file, "isreadable",  NULL);
	zephir_check_call_status();
	_3 = !zephir_is_true(_2);
	if (!(_3)) {
		ZEPHIR_CALL_METHOD(&_4, file, "isfile",  NULL);
		zephir_check_call_status();
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&fileRealPath, file, "getrealpath",  NULL);
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
	ZEPHIR_CALL_METHOD(&_6, moduleFile, "isreadable",  NULL);
	zephir_check_call_status();
	_7 = zephir_is_true(_6);
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8, moduleFile, "isfile",  NULL);
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
	ZEPHIR_INIT_BNVAR(moduleClassFile);
	ZEPHIR_CONCAT_SVSVS(moduleClassFile, "phar://", fileRealPath, "/", pharBaseName, "/Module.php");
	ZEPHIR_INIT_BNVAR(moduleFile);
	object_init_ex(moduleFile, spl_ce_SplFileInfo);
	ZEPHIR_CALL_METHOD(NULL, moduleFile, "__construct", NULL, moduleClassFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, moduleFile, "isreadable",  NULL);
	zephir_check_call_status();
	_10 = zephir_is_true(_9);
	if (_10) {
		ZEPHIR_CALL_METHOD(&_11, moduleFile, "isfile",  NULL);
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
	zval *_0;
	zval *callback;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(callback);
	array_init_size(callback, 3);
	zephir_array_fast_append(callback, this_ptr);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "autoload", 1);
	zephir_array_fast_append(callback, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, callback);
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
	zval *_0;
	zval *callback;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(callback);
	array_init_size(callback, 3);
	zephir_array_fast_append(callback, this_ptr);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "autoload", 1);
	zephir_array_fast_append(callback, _0);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, callback);
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

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zval *paths, *module = NULL, *path = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths);



	_0 = Z_TYPE_P(paths) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(paths, SL("ZendFramework\\Loader\\Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Parameter to \\\\Zend\\\\Loader\\\\ModuleAutoloader's registerPaths method must be an array or implement the Traversable interface", "zendframework/loader/moduleautoloader.zep", 353);
		return;
	}
	zephir_is_iterable(paths, &_2, &_1, 0, 0, "zendframework/loader/moduleautoloader.zep", 364);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(module, _2, _1);
		ZEPHIR_GET_HVALUE(path, _3);
		if (Z_TYPE_P(module) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerpath", &_4, path, module);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerpath", &_4, path);
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
	zval *patterns;
	zval *exceptionMsg = NULL;
	zval *path, *moduleName = NULL, *moduleNamePart = NULL, *normalizedPath = NULL, *_0, *_1, *_2, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path, &moduleName);

	if (!moduleName) {
		moduleName = ZEPHIR_GLOBAL(global_false);
	}
	ZEPHIR_INIT_VAR(patterns);
	array_init(patterns);


	if (unlikely(Z_TYPE_P(path) != IS_STRING)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_gettype(_0, path TSRMLS_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Invalid path provided; must be a string, received ", _0);
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/loader/moduleautoloader.zep", 383 TSRMLS_CC);
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
		zephir_array_fetch_string(&path, info, SL("filename"), PH_NOISY, "zendframework/loader/moduleautoloader.zep", 427 TSRMLS_CC);
	} while (zephir_array_isset_string(info, SS("extension")));
	zephir_array_fetch_string(&_1, info, SL("filename"), PH_NOISY | PH_READONLY, "zendframework/loader/moduleautoloader.zep", 430 TSRMLS_CC);
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
	ZVAL_STRING(&_3, "\\\\", 0);
	zephir_fast_trim(_2, path, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(path, _2);
	if (trailingSlash) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, path, "/");
		ZEPHIR_CPY_WRT(path, _4);
	}
	RETURN_CTOR(path);

}

