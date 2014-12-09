
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


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * PSR-0 compliant autoloader
 *
 * Allows autoloading both namespaced and vendor-prefixed classes. Class
 * lookups are performed on the filesystem. If a class file for the referenced
 * class is not found, a PHP warning will be raised by include().
 */
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
	zval *options = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("namespaces"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("namespaces"), _1 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("prefixes"), PH_NOISY_CC);
	if (Z_TYPE_P(_2) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_this(this_ptr, SL("prefixes"), _1 TSRMLS_CC);
	}
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

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zend_bool _7;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *options = NULL, *type = NULL, *pairs = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options);

	ZEPHIR_SEPARATE_PARAM(options);


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, options, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Options must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 92);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, options);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(options, _3);
	}
	zephir_is_iterable(options, &_5, &_4, 0, 0, "zendframework/loader/standardautoloader.zep", 121);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HKEY(type, _5, _4);
		ZEPHIR_GET_HVALUE(pairs, _6);
		do {
			if (ZEPHIR_IS_STRING(type, "autoregister_zf")) {
				break;
			}
			if (ZEPHIR_IS_STRING(type, "namespaces")) {
				_7 = Z_TYPE_P(pairs) == IS_ARRAY;
				if (!(_7)) {
					ZEPHIR_SINIT_NVAR(_0);
					ZVAL_STRING(&_0, "Traversable", 0);
					ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, pairs, &_0);
					zephir_check_call_status();
					_7 = zephir_is_true(_1);
				}
				if (_7) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "registernamespaces", &_8, pairs);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(type, "prefixes")) {
				_7 = Z_TYPE_P(pairs) == IS_ARRAY;
				if (!(_7)) {
					ZEPHIR_SINIT_NVAR(_0);
					ZVAL_STRING(&_0, "Traversable", 0);
					ZEPHIR_CALL_FUNCTION(&_3, "is_subclass_of", &_2, pairs, &_0);
					zephir_check_call_status();
					_7 = zephir_is_true(_3);
				}
				if (_7) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprefixes", &_9, pairs);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_STRING(type, "fallback_autoloader")) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfallbackautoloader", &_10, pairs);
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

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *namespaces = NULL, *ns = NULL, *dir = NULL, _0, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces);

	ZEPHIR_SEPARATE_PARAM(namespaces);


	if (Z_TYPE_P(namespaces) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, namespaces, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Namespace pairs must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 180);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, namespaces);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(namespaces, _3);
	}
	zephir_is_iterable(namespaces, &_5, &_4, 0, 0, "zendframework/loader/standardautoloader.zep", 187);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(ns, _5, _4);
		ZEPHIR_GET_HVALUE(dir, _6);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registernamespace", &_7, ns, dir);
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

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *prefixes = NULL, *prefix = NULL, *dir = NULL, _0, *_1 = NULL, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefixes);

	ZEPHIR_SEPARATE_PARAM(prefixes);


	if (Z_TYPE_P(prefixes) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "is_subclass_of", &_2, prefixes, &_0);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Prefix pairs must be either an array or Traversable", "zendframework/loader/standardautoloader.zep", 223);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, prefixes);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(prefixes, _3);
	}
	zephir_is_iterable(prefixes, &_5, &_4, 0, 0, "zendframework/loader/standardautoloader.zep", 230);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(prefix, _5, _4);
		ZEPHIR_GET_HVALUE(dir, _6);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerprefix", &_7, prefix, dir);
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
	zval *class_param = NULL, *pos = NULL, *_0 = NULL, _1, *_2 = NULL, _3, *_4 = NULL;
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
	ZEPHIR_CPY_WRT(pos, _2);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "namespaces", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "loadclass", NULL, class, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			RETURN_CTOR(class);
		} else if (isFallback) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "_", 0);
	ZEPHIR_INIT_NVAR(_2);
	zephir_fast_strpos(_2, class, &_3, 0 );
	ZEPHIR_CPY_WRT(pos, _2);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "prefixes", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "loadclass", NULL, class, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			RETURN_CTOR(class);
		} else if (isFallback) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	if (isFallback) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "fallback_autoloader", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "loadclass", NULL, class, _2);
		zephir_check_temp_parameter(_2);
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
	if (zephir_array_isset_string_fetch(&ns, matches, SS("namespace"), 0 TSRMLS_CC)) {
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

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_4;
	HashPosition _3;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *class_param = NULL, *type_param = NULL, *fileName = NULL, *resolvedName = NULL, *paths = NULL, *leader = NULL, *path = NULL, *trimmedClass = NULL, *_1 = NULL, **_5, *_6 = NULL, _7 = zval_used_for_init;
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
		zephir_throw_exception_debug(_1, "zendframework/loader/standardautoloader.zep", 326 TSRMLS_CC);
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
			if (zephir_require_zval(resolvedName TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			RETURN_CTOR(class);
		}
		RETURN_MM_BOOL(0);
	}
	do {
		if (ZEPHIR_IS_STRING(type, "namespaces")) {
			ZEPHIR_OBS_VAR(paths);
			zephir_read_property_this(&paths, this_ptr, SL("namespaces"), PH_NOISY_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "prefixes")) {
			ZEPHIR_OBS_NVAR(paths);
			zephir_read_property_this(&paths, this_ptr, SL("prefixes"), PH_NOISY_CC);
			break;
		}
	} while(0);

	if (Z_TYPE_P(paths) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(paths);
		array_init(paths);
	}
	zephir_is_iterable(paths, &_4, &_3, 0, 0, "zendframework/loader/standardautoloader.zep", 367);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(leader, _4, _3);
		ZEPHIR_GET_HVALUE(path, _5);
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_strpos(_1, class, leader, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, zephir_fast_strlen_ev(leader));
			ZEPHIR_CALL_FUNCTION(&trimmedClass, "substr", &_8, class, &_7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&fileName, this_ptr, "transformclassnametofilename", &_9, trimmedClass, path);
			zephir_check_call_status();
			if ((zephir_file_exists(fileName TSRMLS_CC) == SUCCESS)) {
				if (zephir_require_zval(fileName TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				RETURN_CTOR(class);
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

