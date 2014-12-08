
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/file.h"

ZEPHIR_INIT_CLASS(ZendFramework_Loader_StandardAutoloader) {

	ZEPHIR_REGISTER_CLASS(Zend\\Loader, StandardAutoloader, zendframework, loader_standardautoloader, zendframework_loader_standardautoloader_method_entry, 0);

	/**
	 * @var array Namespace/directory pairs to search; ZF library added by default
	 */
	zend_declare_property_null(zendframework_loader_standardautoloader_ce, SL("namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array Prefix/directory pairs to search
	 */
	zend_declare_property_null(zendframework_loader_standardautoloader_ce, SL("prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool Whether or not the autoloader should also act as a fallback autoloader
	 */
	zend_declare_property_bool(zendframework_loader_standardautoloader_ce, SL("fallbackAutoloaderFlag"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("NS_SEPARATOR"), "\\" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("PREFIX_SEPARATOR"), "_" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("LOAD_NS"), "namespaces" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("LOAD_PREFIX"), "prefixes" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("ACT_AS_FALLBACK"), "fallback_autoloader" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_standardautoloader_ce, SL("AUTOREGISTER_ZF"), "autoregister_zf" TSRMLS_CC);

	zend_class_implements(zendframework_loader_standardautoloader_ce TSRMLS_CC, 1, zendframework_loader_splautoloader_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param  null|array|\Traversable $options
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("prefixes"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("namespaces"), _1 TSRMLS_CC);
	if (Z_TYPE_P(options) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Configure autoloader
 *
 * Allows specifying both "namespace" and "prefix" pairs, using the
 * following structure:
 * <code>
 * array(
 *     'namespaces' => array(
 *         'Zend'     => '/path/to/Zend/library',
 *         'Doctrine' => '/path/to/Doctrine/library',
 *     ),
 *     'prefixes' => array(
 *         'Phly_'     => '/path/to/Phly/library',
 *     ),
 *     'fallback_autoloader' => true,
 * )
 * </code>
 *
 * @param  array|\Traversable $options
 * @throws Exception\InvalidArgumentException
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, setOptions) {

	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_8 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _5;
	zval *options = NULL, *type = NULL, *pairs = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);

	ZEPHIR_SEPARATE_PARAM(options);


	_0 = Z_TYPE_P(options) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(options, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Options must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 84);
		return;
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_1, "iterator_to_array", NULL, options);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(options, _1);
	}
	zephir_is_iterable(options, &_3, &_2, 0, 0, "zendframework/loader/standardautoloader.zep", 115);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HKEY(type, _3, _2);
		ZEPHIR_GET_HVALUE(pairs, _4);
		do {
			if (ZEPHIR_IS_STRING(type, "autoregister_zf")) {
				break;
			}
			if (ZEPHIR_IS_STRING(type, "namespaces")) {
				_5 = Z_TYPE_P(pairs) == IS_ARRAY;
				if (!(_5)) {
					_5 = zephir_is_instance_of(pairs, SL("Traversable") TSRMLS_CC);
				}
				if (_5) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "registernamespaces", &_6, pairs);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(type, "prefixes")) {
				_5 = Z_TYPE_P(pairs) == IS_ARRAY;
				if (!(_5)) {
					_5 = zephir_is_instance_of(pairs, SL("Traversable") TSRMLS_CC);
				}
				if (_5) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprefixes", &_7, pairs);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(type, "fallback_autoloader")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfallbackautoloader", &_8, pairs);
				zephir_check_call_status();
				break;
			}
			break;
		} while(0);

	}
	RETURN_THIS();

}

/**
 * Set flag indicating fallback autoloader status
 *
 * @param  bool $flag
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, setFallbackAutoloader) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 1, 0, &flag_param);

	flag = zephir_get_boolval(flag_param);


	zephir_update_property_this(this_ptr, SL("fallbackAutoloaderFlag"), flag ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Is this autoloader acting as a fallback autoloader?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, isFallbackAutoloader) {


	RETURN_MEMBER(this_ptr, "fallbackAutoloaderFlag");

}

/**
 * Register a namespace/directory pair
 *
 * @param  string $namespace
 * @param  string $directory
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, registerNamespace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *directory_param = NULL, *normalized = NULL, *_0, _1;
	zval *namespace = NULL, *directory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &directory_param);

	zephir_get_strval(namespace, namespace_param);
	zephir_get_strval(directory, directory_param);


	ZEPHIR_CALL_METHOD(&normalized, this_ptr, "normalizedirectory", NULL, directory);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, namespace, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(namespace, _0);
	zephir_concat_self_str(&namespace, "\\", sizeof("\\")-1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("namespaces"), namespace, normalized TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register many namespace/directory pairs at once
 *
 * @param  array $namespaces
 * @throws Exception\InvalidArgumentException
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, registerNamespaces) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *namespaces = NULL, *ns = NULL, *dir = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces);

	ZEPHIR_SEPARATE_PARAM(namespaces);


	_0 = Z_TYPE_P(namespaces) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(namespaces, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Namespace pairs must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 173);
		return;
	}
	if (Z_TYPE_P(namespaces) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_1, "iterator_to_array", NULL, namespaces);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(namespaces, _1);
	}
	zephir_is_iterable(namespaces, &_3, &_2, 0, 0, "zendframework/loader/standardautoloader.zep", 183);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(ns, _3, _2);
		ZEPHIR_GET_HVALUE(dir, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registernamespace", &_5, ns, dir);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Register a prefix/directory pair
 *
 * @param  string $prefix
 * @param  string $directory
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, registerPrefix) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *directory_param = NULL, *normalized = NULL, *_0, _1;
	zval *prefix = NULL, *directory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &directory_param);

	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(directory, directory_param);


	ZEPHIR_CALL_METHOD(&normalized, this_ptr, "normalizedirectory", NULL, directory);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "_", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(prefix, _0);
	zephir_concat_self_str(&prefix, "_", sizeof("_")-1 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("prefixes"), prefix, normalized TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register many namespace/directory pairs at once
 *
 * @param  array $prefixes
 * @throws Exception\InvalidArgumentException
 * @return StandardAutoloader
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, registerPrefixes) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *prefixes = NULL, *prefix = NULL, *dir = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefixes);

	ZEPHIR_SEPARATE_PARAM(prefixes);


	_0 = Z_TYPE_P(prefixes) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(prefixes, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Prefix pairs must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 218);
		return;
	}
	if (Z_TYPE_P(prefixes) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_1, "iterator_to_array", NULL, prefixes);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(prefixes, _1);
	}
	zephir_is_iterable(prefixes, &_3, &_2, 0, 0, "zendframework/loader/standardautoloader.zep", 228);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(prefix, _3, _2);
		ZEPHIR_GET_HVALUE(dir, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprefix", &_5, prefix, dir);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Defined by Autoloadable; autoload a class
 *
 * @param  string $class
 * @return false|string
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, autoload) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool isFallback;
	zval *class_param = NULL, *_0 = NULL, _1, *_2, *_3 = NULL, *_4 = NULL, _5, *_6 = NULL, *_7 = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isfallbackautoloader", NULL);
	zephir_check_call_status();
	isFallback = zephir_get_boolval(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strpos(_2, class, &_1, 0 );
	if (ZEPHIR_IS_BOOL(_2, 0)) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "namespaces", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "loadclass", NULL, class, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			RETURN_CTOR(class);
		} else if (isFallback) {
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _4);
			zephir_check_temp_parameter(_4);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "_", 0);
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_strpos(_4, class, &_5, 0 );
	if (ZEPHIR_IS_BOOL(_4, 0)) {
		ZEPHIR_INIT_VAR(_7);
		ZVAL_STRING(_7, "prefixes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "loadclass", NULL, class, _7);
		zephir_check_temp_parameter(_7);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			RETURN_CTOR(class);
		} else if (isFallback) {
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _7);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	if (isFallback) {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Register the autoloader with spl_autoload
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, register) {

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
 * Transform the class name to a filename
 *
 * @param  string $class
 * @param  string $directory
 * @return string
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, transformClassNameToFilename) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *class_param = NULL, *directory_param = NULL, *matches, *cl = NULL, *ns = NULL, *_0 = NULL, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4;
	zval *class = NULL, *directory = NULL, *fileName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_param, &directory_param);

	zephir_get_strval(class, class_param);
	zephir_get_strval(directory, directory_param);
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/(?P<namespace>.+\\\\)?(?P<class>[^\\\\]+$)/", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(NULL, "preg_match", &_1, _0, class, matches);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(cl);
	if (zephir_array_isset_string_fetch(&cl, matches, SS("class"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "_", 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "/", 0);
		zephir_fast_str_replace(_0, &_2, &_3, cl TSRMLS_CC);
		ZEPHIR_CPY_WRT(cl, _0);
	} else {
		ZEPHIR_INIT_NVAR(cl);
		ZVAL_STRING(cl, "", 1);
	}
	ZEPHIR_OBS_VAR(ns);
	if (!(zephir_array_isset_string_fetch(&ns, matches, SS("namespace"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "\\", 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "/", 0);
		zephir_fast_str_replace(_0, &_2, &_3, ns TSRMLS_CC);
		ZEPHIR_CPY_WRT(ns, _0);
	} else {
		ZEPHIR_INIT_NVAR(ns);
		ZVAL_STRING(ns, "", 1);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VVVS(_4, directory, ns, cl, ".php");
	zephir_get_strval(fileName, _4);
	RETURN_CTOR(fileName);

}

/**
 * Load a class, based on its type (namespaced or prefixed)
 *
 * @param  string $class
 * @param  string $type
 * @return bool|string
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, loadClass) {

	zephir_fcall_cache_entry *_11 = NULL;
	HashTable *_7;
	HashPosition _6;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_5 = NULL;
	zval *class_param = NULL, *type_param = NULL, *fileName = NULL, *resolvedName = NULL, *paths = NULL, *leader = NULL, *path = NULL, *trimmedClass = NULL, *_1 = NULL, *_3 = NULL, *_4, **_8, _9 = zval_used_for_init, *_12 = NULL;
	zval *class = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &class_param, &type_param);

	zephir_get_strval(class, class_param);
	zephir_get_strval(type, type_param);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 4);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "namespaces", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "prefixes", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fallback_autoloader", 1);
	zephir_array_fast_append(_0, _1);
	if (unlikely(!zephir_fast_in_array(type, _0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, zendframework_loader_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/loader/standardautoloader.zep", 321 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(type, "fallback_autoloader")) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&fileName, this_ptr, "transformclassnametofilename", NULL, class, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&resolvedName, "stream_resolve_include_path", &_2, fileName);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(resolvedName)) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
			if (zephir_require_zval_ret(&_3, resolvedName TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			RETURN_CCTOR(_3);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_zval(&_4, this_ptr, type, PH_NOISY_CC);
	zephir_get_arrval(_5, _4);
	ZEPHIR_CPY_WRT(paths, _5);
	zephir_is_iterable(paths, &_7, &_6, 0, 0, "zendframework/loader/standardautoloader.zep", 348);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(leader, _7, _6);
		ZEPHIR_GET_HVALUE(path, _8);
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_strpos(_1, class, leader, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_LONG(&_9, zephir_fast_strlen_ev(leader));
			ZEPHIR_CALL_FUNCTION(&trimmedClass, "substr", &_10, class, &_9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fileName, this_ptr, "transformclassnametofilename", &_11, trimmedClass, path);
			zephir_check_call_status();
			if ((zephir_file_exists(fileName TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_12);
				if (zephir_require_zval_ret(&_12, fileName TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				RETURN_CCTOR(_12);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Normalize the directory to include a trailing directory separator
 *
 * @param  string $directory
 * @return string
 */
PHP_METHOD(ZendFramework_Loader_StandardAutoloader, normalizeDirectory) {

	zval *directory_param = NULL, *_0 = NULL, *_1, _2;
	zval *directory = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);

	zephir_get_strval(directory, directory_param);


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/\\", 0);
	zephir_fast_trim(_1, directory, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, _1, "/");
	RETURN_MM();

}

