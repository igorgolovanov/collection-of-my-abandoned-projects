
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Utility class for handling strings of different character encodings
 * using available PHP extensions.
 *
 * Declared abstract, as we have no need for instantiation.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_StringUtils) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, StringUtils, zendframework, stdlib_stringutils, zendframework_stdlib_stringutils_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Ordered list of registered string wrapper instances
	 *
	 * @var StringWrapperInterface[]
	 */
	zend_declare_property_null(zendframework_stdlib_stringutils_ce, SL("wrapperRegistry"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * A list of known single-byte character encodings (upper-case)
	 *
	 * @var string[]
	 */
	zend_declare_property_null(zendframework_stdlib_stringutils_ce, SL("singleByteEncodings"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Is PCRE compiled with Unicode support?
	 *
	 * @var bool
	 **/
	zend_declare_property_null(zendframework_stdlib_stringutils_ce, SL("hasPcreUnicodeSupport"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(ZendFramework_Stdlib_StringUtils, _singleByteEncodings) {

	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	array_init_size(return_value, 26);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "ASCII", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "7BIT", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "8BIT", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-1", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-2", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-3", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-4", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-5", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-6", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-7", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-8", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-9", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-10", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-11", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-13", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-14", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-15", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "ISO-8859-16", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "CP-1251", 1);
	zephir_array_fast_append(return_value, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "CP-1252", 1);
	zephir_array_fast_append(return_value, _0);
	RETURN_MM();

}

/**
 * Get registered wrapper classes
 *
 * @return string[]
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getRegisteredWrappers) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *className, *wrapperRegistry = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(wrapperRegistry);
	ZVAL_NULL(wrapperRegistry);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        
	if (Z_TYPE_P(wrapperRegistry) == IS_NULL) {
		ZEPHIR_INIT_NVAR(wrapperRegistry);
		array_init(wrapperRegistry);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "intl", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", &_2, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "Zend\\\\Stdlib\\\\StringWrapper\\\\Intl", 1);
			zephir_array_append(&wrapperRegistry, _3, PH_SEPARATE, "zendframework/stdlib/stringutils.zep", 71);
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "mbstring", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "extension_loaded", &_2, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "Zend\\\\Stdlib\\\\StringWrapper\\\\MbString", 1);
			zephir_array_append(&wrapperRegistry, _3, PH_SEPARATE, "zendframework/stdlib/stringutils.zep", 74);
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "iconv", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "extension_loaded", &_2, &_0);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "Zend\\\\Stdlib\\\\StringWrapper\\\\Iconv", 1);
			zephir_array_append(&wrapperRegistry, _3, PH_SEPARATE, "zendframework/stdlib/stringutils.zep", 77);
		}
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Zend\\\\Stdlib\\\\StringWrapper\\\\Native", 1);
		zephir_array_append(&wrapperRegistry, _3, PH_SEPARATE, "zendframework/stdlib/stringutils.zep", 80);
	}
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        
	RETURN_CCTOR(wrapperRegistry);

}

/**
 * Register a string wrapper class
 *
 * @param string $wrapper
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, registerWrapper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *wrapper_param = NULL, *className, *wrapperRegistry = NULL, *_0 = NULL;
	zval *wrapper = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &wrapper_param);

	zephir_get_strval(wrapper, wrapper_param);
	ZEPHIR_INIT_VAR(wrapperRegistry);
	ZVAL_NULL(wrapperRegistry);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        
	if (Z_TYPE_P(wrapperRegistry) == IS_NULL) {
		ZEPHIR_INIT_NVAR(wrapperRegistry);
		array_init(wrapperRegistry);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "in_array", &_1, wrapper, wrapperRegistry, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		zephir_array_append(&wrapperRegistry, wrapper, PH_SEPARATE, "zendframework/stdlib/stringutils.zep", 107);
	}
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Unregister a string wrapper class
 *
 * @param string $wrapper
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, unregisterWrapper) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *wrapper_param = NULL, *index = NULL, *className, *wrapperRegistry = NULL;
	zval *wrapper = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &wrapper_param);

	zephir_get_strval(wrapper, wrapper_param);
	ZEPHIR_INIT_VAR(wrapperRegistry);
	ZVAL_NULL(wrapperRegistry);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        
	if (Z_TYPE_P(wrapperRegistry) == IS_NULL) {
		ZEPHIR_INIT_NVAR(wrapperRegistry);
		array_init(wrapperRegistry);
	}
	ZEPHIR_CALL_FUNCTION(&index, "array_search", &_0, wrapper, wrapperRegistry, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(index)) {
		zephir_array_unset(&wrapperRegistry, index, PH_SEPARATE);
	}
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Reset all registered wrappers so the default wrappers will be used
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, resetRegisteredWrappers) {

	zval *className, wrapperRegistry;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_SINIT_VAR(wrapperRegistry);
	ZVAL_NULL(&wrapperRegistry);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the first string wrapper supporting the given character encoding
 * and supports to convert into the given convert encoding.
 *
 * @param string      $encoding        Character encoding to support
 * @param string|null $convertEncoding OPTIONAL character encoding to convert in
 * @return StringWrapperInterface
 * @throws Exception\RuntimeException If no wrapper supports given character encodings
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getWrapper) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *encoding_param = NULL, *convertEncoding_param = NULL, *wrappers = NULL, *wrapperClass = NULL, **_2, *_4;
	zval *encoding = NULL, *convertEncoding = NULL, *exceptionMsg = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &encoding_param, &convertEncoding_param);

	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
		zephir_get_strval(encoding, encoding_param);
	}
	if (!convertEncoding_param) {
		ZEPHIR_INIT_VAR(convertEncoding);
		ZVAL_EMPTY_STRING(convertEncoding);
	} else {
		zephir_get_strval(convertEncoding, convertEncoding_param);
	}


	ZEPHIR_CALL_STATIC(&wrappers, "getregisteredwrappers", NULL);
	zephir_check_call_status();
	zephir_is_iterable(wrappers, &_1, &_0, 0, 0, "zendframework/stdlib/stringutils.zep", 184);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(wrapperClass, _2);
	}
	ZEPHIR_INIT_VAR(exceptionMsg);
	ZEPHIR_CONCAT_SVS(exceptionMsg, "No wrapper found supporting \"", encoding, "\"");
	if (!ZEPHIR_IS_STRING_IDENTICAL(convertEncoding, "")) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, exceptionMsg, " and \"", convertEncoding, "\"");
		ZEPHIR_CPY_WRT(exceptionMsg, _3);
	}
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, zendframework_stdlib_exception_runtimeexception_ce);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, exceptionMsg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_4, "zendframework/stdlib/stringutils.zep", 188 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Get a list of all known single-byte character encodings
 *
 * @return string[]
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, getSingleByteEncodings) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *singleByteEncodings = NULL, *className;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(singleByteEncodings);
	ZVAL_NULL(singleByteEncodings);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&singleByteEncodings, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("singleByteEncodings") TSRMLS_CC);
        
	if (Z_TYPE_P(singleByteEncodings) == IS_NULL) {
		ZEPHIR_CALL_STATIC(&singleByteEncodings, "_singlebyteencodings", NULL);
		zephir_check_call_status();
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("singleByteEncodings"), &singleByteEncodings TSRMLS_CC);
            
	}
	RETURN_CCTOR(singleByteEncodings);

}

/**
 * Check if a given encoding is a known single-byte character encoding
 *
 * @param string $encoding
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, isSingleByteEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *encoding_param = NULL, *encodings = NULL, *_0 = NULL, *_1;
	zval *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);

	zephir_get_strval(encoding, encoding_param);


	ZEPHIR_CALL_STATIC(&encodings, "getsinglebyteencodings", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtoupper(_1, encoding);
	RETURN_MM_BOOL(zephir_fast_in_array(_1, encodings TSRMLS_CC));

}

/**
 * Check if a given string is valid UTF-8 encoded
 *
 * @param string $str
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, isValidUtf8) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _0;
	zval *str, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	if (Z_TYPE_P(str) == IS_STRING) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(str, "");
		if (!(_0)) {
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "/^./su", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, str);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			_0 = ZEPHIR_IS_LONG(_2, 1);
		}
		if (_0) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Is PCRE compiled with Unicode support?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Stdlib_StringUtils, hasPcreUnicodeSupport) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_8 = NULL, *_9 = NULL;
	zval *hasPcreUnicodeSupport = NULL, *className, _1, *_2 = NULL, *_5, *_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(hasPcreUnicodeSupport);
	ZVAL_NULL(hasPcreUnicodeSupport);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&hasPcreUnicodeSupport, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("hasPcreUnicodeSupport") TSRMLS_CC);
        
	if (Z_TYPE_P(hasPcreUnicodeSupport) == IS_NULL) {
		ZEPHIR_CALL_CE_STATIC(NULL, zendframework_stdlib_errorhandler_ce, "start", &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "PREG_BAD_UTF8_OFFSET_ERROR", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "defined", &_3, &_1);
		zephir_check_call_status();
		_4 = zephir_is_true(_2);
		if (_4) {
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "/\\pL/u", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_STRING(_6, "a", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_7, "preg_match", &_8, _5, _6);
			zephir_check_temp_parameter(_5);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
			_4 = ZEPHIR_IS_LONG(_7, 1);
		}
		ZEPHIR_INIT_NVAR(hasPcreUnicodeSupport);
		if (_4) {
			ZVAL_BOOL(hasPcreUnicodeSupport, 1);
		} else {
			ZVAL_BOOL(hasPcreUnicodeSupport, 0);
		}
		ZEPHIR_CALL_CE_STATIC(NULL, zendframework_stdlib_errorhandler_ce, "stop", &_9);
		zephir_check_call_status();
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("hasPcreUnicodeSupport"), &hasPcreUnicodeSupport TSRMLS_CC);
            
	}
	RETURN_CCTOR(hasPcreUnicodeSupport);

}

