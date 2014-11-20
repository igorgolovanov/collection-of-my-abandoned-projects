
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
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/iterator.h"

ZEPHIR_INIT_CLASS(ZendFramework_Http_Headers) {

	ZEPHIR_REGISTER_CLASS(Zend\\Http, Headers, zendframework, http_headers, zendframework_http_headers_method_entry, 0);

	/**
	 * @var PluginClassLocator
	 */
	zend_declare_property_null(zendframework_http_headers_ce, SL("pluginClassLoader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array key names for $headers array
	 */
	zend_declare_property_null(zendframework_http_headers_ce, SL("headersKeys"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array Array of header array information or Header instances
	 */
	zend_declare_property_null(zendframework_http_headers_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_http_headers_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_http_headers_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Populates headers from string representation
 *
 * Parses a string for headers, and aggregates them, in order, in the
 * current instance, primarily as strings until they are needed (they
 * will be lazy loaded)
 *
 * @param  string $string
 * @return Headers
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Headers, fromString) {

	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *string_param = NULL, *className, *headers, *current = NULL, *lines, *line = NULL, *name = NULL, *matches = NULL, *key = NULL, *_0 = NULL, **_4, *_5 = NULL, *_6 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	zval *string = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &string_param);

	zephir_get_strval(string, string_param);
	ZEPHIR_INIT_VAR(current);
	array_init(current);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(headers);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(headers, _1);
	if (zephir_has_constructor(headers TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(lines);
	zephir_fast_explode_str(lines, SL("\r\n"), string, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(lines, &_3, &_2, 0, 0, "zendframework/http/headers.zep", 90);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(line, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "/^(?P<name>[^()><@,;:\"\\/\\[\\]?=}{ \t]+):.*$/", ZEPHIR_TEMP_PARAM_COPY);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, _5, line, matches);
		zephir_check_temp_parameter(_5);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&name, current, SL("name"), PH_NOISY, "zendframework/http/headers.zep", 65 TSRMLS_CC);
			if (zephir_is_true(current)) {
				ZEPHIR_CALL_STATIC(&key, "createkey", &_8, name);
				zephir_check_call_status();
				zephir_update_property_array_append(this_ptr, SL("headersKeys"), key TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("headers"), current TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(current);
			array_init_size(current, 3);
			zephir_array_update_string(&current, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_5);
			zephir_fast_trim(_5, line, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			zephir_array_update_string(&current, SL("line"), &_5, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_STRING(_5, "/^(?P<ws>\\s+).*$/", ZEPHIR_TEMP_PARAM_COPY);
		Z_SET_ISREF_P(matches);
		ZEPHIR_CALL_FUNCTION(&_9, "preg_match", &_7, _5, line, matches);
		zephir_check_temp_parameter(_5);
		Z_UNSET_ISREF_P(matches);
		zephir_check_call_status();
		if (zephir_is_true(_9)) {
			zephir_array_fetch_string(&_10, matches, SL("ws"), PH_NOISY | PH_READONLY, "zendframework/http/headers.zep", 78 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_5);
			zephir_fast_trim(_5, line, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_SVV(_11, "\r\n", _10, _5);
			zephir_array_update_string(&current, SL("line"), &_11, PH_COPY | PH_SEPARATE);
			continue;
		}
		ZEPHIR_INIT_NVAR(_12);
		ZVAL_STRING(_12, "/^\\s*$/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_13, "preg_match", &_7, _12, line);
		zephir_check_temp_parameter(_12);
		zephir_check_call_status();
		if (zephir_is_true(_13)) {
			break;
		}
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_SVS(_11, "Line \"", line, "\" does not match header format!");
		zephir_get_strval(exceptionMsg, _11);
		ZEPHIR_INIT_NVAR(_12);
		object_init_ex(_12, zendframework_http_exception_runtimeexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _12, "__construct", &_14, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12, "zendframework/http/headers.zep", 87 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(current)) {
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&name, current, SL("name"), PH_NOISY, "zendframework/http/headers.zep", 91 TSRMLS_CC);
		ZEPHIR_CALL_STATIC(&key, "createkey", &_8, name);
		zephir_check_call_status();
		zephir_update_property_array_append(headers, SL("headersKeys"), key TSRMLS_CC);
		zephir_update_property_array_append(headers, SL("headers"), current TSRMLS_CC);
	}
	RETURN_CCTOR(headers);

}

/**
 * Set an alternate implementation for the PluginClassLoader
 *
 * @param \Zend\Loader\PluginClassLocator $pluginClassLoader
 * @return Headers
 */
PHP_METHOD(ZendFramework_Http_Headers, setPluginClassLoader) {

	zval *pluginClassLoader;

	zephir_fetch_params(0, 1, 0, &pluginClassLoader);



	if (!(zephir_instance_of_ev(pluginClassLoader, zendframework_loader_pluginclasslocator_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'pluginClassLoader' must be an instance of 'ZendFramework\\Loader\\PluginClassLocator'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("pluginClassLoader"), pluginClassLoader TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return an instance of a PluginClassLocator, lazyload and inject map if necessary
 *
 * @return PluginClassLocator
 */
PHP_METHOD(ZendFramework_Http_Headers, getPluginClassLoader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *pluginClassLoader = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pluginClassLoader"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pluginClassLoader, _0);
	if (Z_TYPE_P(pluginClassLoader) == IS_NULL) {
		ZEPHIR_INIT_NVAR(pluginClassLoader);
		object_init_ex(pluginClassLoader, zendframework_http_headerloader_ce);
		ZEPHIR_CALL_METHOD(NULL, pluginClassLoader, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("pluginClassLoader"), pluginClassLoader TSRMLS_CC);
	}
	RETURN_MM_MEMBER(this_ptr, "pluginClassLoader");

}

/**
 * Add many headers at once
 *
 * Expects an array (or Traversable object) of type/value pairs.
 *
 * @param  array|Traversable $headers
 * @return Headers
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Headers, addHeaders) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *exceptionMsg = NULL;
	zval *headers = NULL, *type = NULL, *name = NULL, *value = NULL, *count = NULL, *k = NULL, *v = NULL, *_1 = NULL, *_2, *_3 = NULL, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers);

	ZEPHIR_SEPARATE_PARAM(headers);


	_0 = Z_TYPE_P(headers) != IS_ARRAY;
	if (_0) {
		_0 = !(zephir_is_instance_of(headers, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_gettype(_1, headers TSRMLS_CC);
		ZEPHIR_CPY_WRT(type, _1);
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_INIT_NVAR(type);
			zephir_get_class(type, headers, 0 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Expected array or Traversable; received \"", type, "\"");
		zephir_get_strval(exceptionMsg, _2);
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, zendframework_http_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/http/headers.zep", 152 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(headers) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, headers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(headers, _3);
	}
	zephir_is_iterable(headers, &_5, &_4, 0, 0, "zendframework/http/headers.zep", 187);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(name, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		if (Z_TYPE_P(name) == IS_LONG) {
			if (Z_TYPE_P(value) == IS_STRING) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addheaderline", &_7, value);
				zephir_check_call_status();
				continue;
			}
			if (Z_TYPE_P(value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(count);
				ZVAL_LONG(count, zephir_fast_count_int(value TSRMLS_CC));
				if (ZEPHIR_IS_LONG(count, 1)) {
					Z_SET_ISREF_P(value);
					ZEPHIR_CALL_FUNCTION(&k, "key", &_8, value);
					Z_UNSET_ISREF_P(value);
					zephir_check_call_status();
					Z_SET_ISREF_P(value);
					ZEPHIR_CALL_FUNCTION(&v, "current", &_9, value);
					Z_UNSET_ISREF_P(value);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addheaderline", &_7, k, v);
					zephir_check_call_status();
					continue;
				}
				if (ZEPHIR_IS_LONG(count, 2)) {
					ZEPHIR_OBS_NVAR(k);
					zephir_array_fetch_long(&k, value, 0, PH_NOISY, "zendframework/http/headers.zep", 173 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(v);
					zephir_array_fetch_long(&v, value, 1, PH_NOISY, "zendframework/http/headers.zep", 174 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addheaderline", &_7, k, v);
					zephir_check_call_status();
					continue;
				}
			}
			if (zephir_instance_of_ev(value, zendframework_http_header_headerinterface_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addheader", &_10, value);
				zephir_check_call_status();
			}
		}
		if (Z_TYPE_P(name) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addheaderline", &_7, name, value);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

/**
 * Add a raw header line, either in name => value, or as a single string 'name: value'
 *
 * This method allows for lazy-loading in that the parsing and instantiation of Header object
 * will be delayed until they are retrieved by either get() or current()
 *
 * @throws Exception\InvalidArgumentException
 * @param string $headerFieldNameOrLine
 * @param string $fieldValue optional
 * @return Headers
 */
PHP_METHOD(ZendFramework_Http_Headers, addHeaderLine) {

	zval *_4;
	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *headerFieldNameOrLine_param = NULL, *fieldValue = NULL, *matches = NULL, *headerName = NULL, *headerKey = NULL, *line = NULL, *_0 = NULL, *_1 = NULL;
	zval *headerFieldNameOrLine = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &headerFieldNameOrLine_param, &fieldValue);

	zephir_get_strval(headerFieldNameOrLine, headerFieldNameOrLine_param);
	if (!fieldValue) {
		ZEPHIR_CPY_WRT(fieldValue, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(fieldValue);
	}
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, headerFieldNameOrLine, matches);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	_3 = zephir_is_true(_1);
	if (_3) {
		_3 = Z_TYPE_P(fieldValue) == IS_NULL;
	}
	if (_3) {
		ZEPHIR_OBS_VAR(headerName);
		zephir_array_fetch_string(&headerName, matches, SL("name"), PH_NOISY, "zendframework/http/headers.zep", 206 TSRMLS_CC);
		ZEPHIR_CALL_STATIC(&headerKey, "createkey", NULL, headerName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(line, headerFieldNameOrLine);
	} else if (unlikely(Z_TYPE_P(fieldValue) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "A field name was provided without a field value", "zendframework/http/headers.zep", 210);
		return;
	} else {
		ZEPHIR_CPY_WRT(headerName, headerFieldNameOrLine);
		ZEPHIR_CALL_STATIC(&headerKey, "createkey", NULL, headerFieldNameOrLine);
		zephir_check_call_status();
		if (Z_TYPE_P(fieldValue) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), fieldValue TSRMLS_CC);
			ZEPHIR_CPY_WRT(fieldValue, _0);
		}
		ZEPHIR_INIT_NVAR(line);
		ZEPHIR_CONCAT_VSV(line, headerFieldNameOrLine, ": ", fieldValue);
	}
	zephir_update_property_array_append(this_ptr, SL("headersKeys"), headerKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 3);
	zephir_array_update_string(&_4, SL("name"), &headerName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("line"), &line, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("headers"), _4 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Add a Header to this container, for raw values @see addHeaderLine() and addHeaders()
 *
 * @param  Header\HeaderInterface $header
 * @return Headers
 */
PHP_METHOD(ZendFramework_Http_Headers, addHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *header, *key = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header);



	if (!(zephir_instance_of_ev(header, zendframework_http_header_headerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'header' must be an instance of 'ZendFramework\\Http\\Header\\HeaderInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&name, header, "getfieldname", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&key, "createkey", NULL, name);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("headersKeys"), key TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("headers"), header TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Remove a Header from the container
 *
 * @param Header\HeaderInterface $header
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Headers, removeHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *header, *index = NULL, *_0, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header);



	if (!(zephir_instance_of_ev(header, zendframework_http_header_headerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'header' must be an instance of 'ZendFramework\\Http\\Header\\HeaderInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&index, "array_search", &_1, header, _0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(index)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
		zephir_array_unset(&_2, index, PH_SEPARATE);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		zephir_array_unset(&_3, index, PH_SEPARATE);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Clear all headers
 *
 * Removes all headers from queue
 *
 * @return Headers
 */
PHP_METHOD(ZendFramework_Http_Headers, clearHeaders) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("headersKeys"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get all headers of a certain name/type
 *
 * @param  string $name
 * @return bool|Header\HeaderInterface|ArrayIterator
 */
PHP_METHOD(ZendFramework_Http_Headers, get) {

	zephir_fcall_cache_entry *_13 = NULL;
	HashTable *_9, *_15;
	HashPosition _8, _14;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *current, *className = NULL, *headers, *key = NULL, *keys = NULL, *index = NULL, *_0, *_1, *_2 = NULL, _3, *_4 = NULL, *_6, **_10, *_11, *_12 = NULL, **_16, *_17, *_18;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);


	ZEPHIR_CALL_STATIC(&key, "createkey", NULL, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
	if (!(zephir_fast_in_array(key, _0 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(current);
	zephir_array_fetch(&current, _1, name, PH_NOISY, "zendframework/http/headers.zep", 298 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getpluginclassloader", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&className, _2, "load", NULL, key);
	zephir_check_call_status();
	if (!(zephir_is_true(className))) {
		ZEPHIR_INIT_NVAR(className);
		ZVAL_STRING(className, "Zend\\Http\\Header\\GenericHeader", 1);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "Zend\\Http\\Header\\MultipleHeaderInterface", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "is_subclass_of", &_5, className, &_3);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&keys, "array_keys", &_7, _6, key);
		zephir_check_call_status();
		zephir_is_iterable(keys, &_9, &_8, 0, 0, "zendframework/http/headers.zep", 310);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(index, _10);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_12);
			zephir_array_fetch(&_12, _11, index, PH_NOISY, "zendframework/http/headers.zep", 306 TSRMLS_CC);
			if (Z_TYPE_P(_12) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "lazyloadheader", &_13, index);
				zephir_check_call_status();
			}
		}
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&keys, "array_keys", &_7, _11, key);
		zephir_check_call_status();
		zephir_is_iterable(keys, &_15, &_14, 0, 0, "zendframework/http/headers.zep", 314);
		for (
		  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15, &_14)
		) {
			ZEPHIR_GET_HVALUE(index, _16);
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
			zephir_array_fetch(&_18, _17, index, PH_NOISY | PH_READONLY, "zendframework/http/headers.zep", 312 TSRMLS_CC);
			zephir_array_append(&headers, _18, PH_SEPARATE, "zendframework/http/headers.zep", 312);
		}
		object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, headers);
		zephir_check_call_status();
		RETURN_MM();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&index, "array_search", &_19, key, _6);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(index)) {
		RETURN_MM_BOOL(0);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(_12);
	zephir_array_fetch(&_12, _6, index, PH_NOISY, "zendframework/http/headers.zep", 321 TSRMLS_CC);
	if (Z_TYPE_P(_12) == IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "lazyloadheader", &_13, index);
		zephir_check_call_status();
		RETURN_MM();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	zephir_array_fetch(&_18, _6, index, PH_NOISY | PH_READONLY, "zendframework/http/headers.zep", 325 TSRMLS_CC);
	RETURN_CTOR(_18);

}

/**
 * Test for existence of a type of header
 *
 * @param  string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Headers, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *key = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_STATIC(&key, "createkey", NULL, name);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headersKeys"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_fast_in_array(key, _0 TSRMLS_CC));

}

/**
 * Advance the pointer for this object as an iterator
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Http_Headers, next) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "next", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the current key for this object as an iterator
 *
 * @return mixed
 */
PHP_METHOD(ZendFramework_Http_Headers, key) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("key", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Is this iterator still valid?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Headers, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *current = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&current, "current", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(current));

}

/**
 * Reset the internal pointer for this object as an iterator
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Http_Headers, rewind) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the current value for this iterator, lazy loading it if need be
 *
 * @return array|Header\HeaderInterface
 */
PHP_METHOD(ZendFramework_Http_Headers, current) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *current = NULL, *key = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&current, "current", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	if (Z_TYPE_P(current) == IS_ARRAY) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		Z_SET_ISREF_P(_2);
		ZEPHIR_CALL_FUNCTION(&key, "key", &_3, _2);
		Z_UNSET_ISREF_P(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&current, this_ptr, "lazyloadheader", NULL, key);
		zephir_check_call_status();
	}
	RETURN_CCTOR(current);

}

/**
 * Return the number of headers in this contain, if all headers have not been parsed, actual count could
 * increase if MultipleHeader objects exist in the Request/Response.  If you need an exact count, iterate
 *
 * @return int count of currently known headers
 */
PHP_METHOD(ZendFramework_Http_Headers, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Render all headers at once
 *
 * This method handles the normal iteration of headers; it is up to the
 * concrete classes to prepend with the appropriate status/request line.
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Headers, toString) {

	HashTable *_2, *_5;
	HashPosition _1, _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName = NULL, *fieldValue = NULL, *value = NULL, *_0 = NULL, **_3, **_6, *_7 = NULL;
	zval *headers;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(headers);
	ZVAL_STRING(headers, "", 1);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/http/headers.zep", 440);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HKEY(fieldName, _2, _1);
		ZEPHIR_GET_HVALUE(fieldValue, _3);
		if (Z_TYPE_P(fieldValue) == IS_ARRAY) {
			zephir_is_iterable(fieldValue, &_5, &_4, 0, 0, "zendframework/http/headers.zep", 435);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HVALUE(value, _6);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_VSVS(_7, fieldName, ": ", value, "\r\n");
				zephir_concat_self(&headers, _7 TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VSVS(_7, fieldName, ": ", fieldValue, "\r\n");
		zephir_concat_self(&headers, _7 TSRMLS_CC);
	}
	RETURN_CTOR(headers);

}

/**
 * Return the headers container as an array
 *
 * @todo determine how to produce single line headers, if they are supported
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Headers, toArray) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *headers, *header = NULL, *matches = NULL, *name = NULL, *value = NULL, *_0, **_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/http/headers.zep", 478);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(header, _3);
		if (zephir_instance_of_ev(header, zendframework_http_header_multipleheaderinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&name, header, "getfieldname", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, header, "getfieldvalue", NULL);
			zephir_check_call_status();
			if (!(zephir_array_isset(headers, name))) {
				ZEPHIR_INIT_NVAR(_4);
				array_init(_4);
				zephir_array_update_zval(&headers, name, &_4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_update_multi(&headers, &value TSRMLS_CC, SL("za"), 2, name);
		} else if (zephir_instance_of_ev(header, zendframework_http_header_headerinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&name, header, "getfieldname", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, header, "getfieldvalue", NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			zephir_array_fetch_string(&_5, header, SL("line"), PH_NOISY | PH_READONLY, "zendframework/http/headers.zep", 468 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "/^(?P<name>[^()><@,;:\"\\/\\[\\]?=}{ \t]+):\\s*(?P<value>.*)$/", ZEPHIR_TEMP_PARAM_COPY);
			Z_SET_ISREF_P(matches);
			ZEPHIR_CALL_FUNCTION(NULL, "preg_match", &_6, _4, _5, matches);
			zephir_check_temp_parameter(_4);
			Z_UNSET_ISREF_P(matches);
			zephir_check_call_status();
			if (zephir_is_true(matches)) {
				ZEPHIR_OBS_NVAR(name);
				zephir_array_fetch_string(&name, matches, SL("name"), PH_NOISY, "zendframework/http/headers.zep", 471 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch_string(&value, matches, SL("value"), PH_NOISY, "zendframework/http/headers.zep", 472 TSRMLS_CC);
				zephir_array_update_zval(&headers, name, &value, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(headers);

}

/**
 * By calling this, it will force parsing and loading of all headers, after this count() will be accurate
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Headers, forceLoading) {

	zend_object_iterator *_0;
	zval *item = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		item = *tmp;
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * @param $index
 * @return mixed|void
 */
PHP_METHOD(ZendFramework_Http_Headers, lazyLoadHeader) {

	HashTable *_8;
	HashPosition _7;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *index, *current = NULL, *className = NULL, *headers = NULL, *header = NULL, *_0, *_1 = NULL, *_3, *_4, **_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(current);
	zephir_array_fetch(&current, _0, index, PH_NOISY, "zendframework/http/headers.zep", 504 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpluginclassloader", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&className, _1, "load", NULL, index);
	zephir_check_call_status();
	if (!(zephir_is_true(className))) {
		ZEPHIR_INIT_NVAR(className);
		ZVAL_STRING(className, "Zend\\Http\\Header\\GenericHeader", 1);
	}
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	zephir_array_fast_append(_2, className);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "fromString", 1);
	zephir_array_fast_append(_2, _3);
	zephir_array_fetch_string(&_4, current, SL("line"), PH_NOISY | PH_READONLY, "zendframework/http/headers.zep", 509 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&headers, "call_user_func", &_5, _2, _4);
	zephir_check_call_status();
	if (Z_TYPE_P(headers) == IS_ARRAY) {
		Z_SET_ISREF_P(headers);
		ZEPHIR_CALL_FUNCTION(&current, "array_shift", &_6, headers);
		Z_UNSET_ISREF_P(headers);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("headers"), index, current TSRMLS_CC);
		zephir_is_iterable(headers, &_8, &_7, 0, 0, "zendframework/http/headers.zep", 518);
		for (
		  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8, &_7)
		) {
			ZEPHIR_GET_HVALUE(header, _9);
			zephir_update_property_array_append(this_ptr, SL("headersKeys"), index TSRMLS_CC);
			zephir_update_property_array_append(this_ptr, SL("headers"), header TSRMLS_CC);
		}
		RETURN_CCTOR(current);
	}
	zephir_update_property_array(this_ptr, SL("headers"), index, headers TSRMLS_CC);
	RETURN_CCTOR(headers);

}

/**
 * Create array key from header name
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Headers, createKey) {

	zval *wildcards;
	zval *name_param = NULL, *key, *_0, _1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);
	ZEPHIR_INIT_VAR(wildcards);
	array_init(wildcards);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, name);
	zephir_get_strval(name, _0);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "", 0);
	zephir_fast_str_replace(key, wildcards, &_1, name TSRMLS_CC);
	RETURN_CCTOR(key);

}

PHP_METHOD(ZendFramework_Http_Headers, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("headers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("headersKeys"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

