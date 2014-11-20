
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(ZendFramework_Http_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http, Response, zendframework, http_response, zendframework_http_abstractmessage_ce, zendframework_http_response_method_entry, 0);

	/**
	 * @var array Recommended Reason Phrases
	 */
	zend_declare_property_null(zendframework_http_response_ce, SL("recommendedReasonPhrases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int Status code
	 */
	zend_declare_property_long(zendframework_http_response_ce, SL("statusCode"), 200, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|null Null means it will be looked up from the $reasonPhrase list above
	 */
	zend_declare_property_null(zendframework_http_response_ce, SL("reasonPhrase"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**#@+
	 * @const int Status codes
	 */
	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_CUSTOM"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_100"), 100 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_101"), 101 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_102"), 102 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_200"), 200 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_201"), 201 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_202"), 202 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_203"), 203 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_204"), 204 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_205"), 205 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_206"), 206 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_207"), 207 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_208"), 208 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_300"), 300 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_301"), 301 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_302"), 302 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_303"), 303 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_304"), 304 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_305"), 305 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_306"), 306 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_307"), 307 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_400"), 400 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_401"), 401 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_402"), 402 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_403"), 403 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_404"), 404 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_405"), 405 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_406"), 406 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_407"), 407 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_408"), 408 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_409"), 409 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_410"), 410 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_411"), 411 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_412"), 412 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_413"), 413 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_414"), 414 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_415"), 415 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_416"), 416 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_417"), 417 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_418"), 418 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_422"), 422 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_423"), 423 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_424"), 424 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_425"), 425 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_426"), 426 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_428"), 428 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_429"), 429 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_431"), 431 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_500"), 500 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_501"), 501 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_502"), 502 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_503"), 503 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_504"), 504 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_505"), 505 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_506"), 506 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_507"), 507 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_508"), 508 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_http_response_ce, SL("STATUS_CODE_511"), 511 TSRMLS_CC);

	zend_class_implements(zendframework_http_response_ce TSRMLS_CC, 1, zendframework_stdlib_responseinterface_ce);
	return SUCCESS;

}

/**
 * Populate object from string
 *
 * @param  string $string
 * @return self
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Response, fromString) {

	HashTable *_10;
	HashPosition _9;
	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zend_bool isHeader = 1, _0, _12;
	zval *string_param = NULL, *lines = NULL, *firstLine = NULL, *response, *className, *matches, *reason, *content = NULL, *headers, *line = NULL, *_2 = NULL, *_4 = NULL, *_6, *_7, *_8 = NULL, **_11;
	zval *string = NULL, *regex;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &string_param);

	zephir_get_strval(string, string_param);
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	ZEPHIR_INIT_VAR(lines);
	zephir_fast_explode_str(lines, SL("\r\n"), string, LONG_MAX TSRMLS_CC);
	_0 = Z_TYPE_P(lines) != IS_ARRAY;
	if (!(_0)) {
		_0 = zephir_fast_count_int(lines TSRMLS_CC) == 1;
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(lines);
		zephir_fast_explode_str(lines, SL("n"), string, LONG_MAX TSRMLS_CC);
	}
	Z_SET_ISREF_P(lines);
	ZEPHIR_CALL_FUNCTION(&firstLine, "array_shift", &_1, lines);
	Z_UNSET_ISREF_P(lines);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(response);
	zephir_fetch_safe_class(_2, className);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(response, _3);
	if (zephir_has_constructor(response TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, response, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(regex);
	ZVAL_STRING(regex, "/^HTTP\/(?P<version>1\.[01]) (?P<status>\d{3})(?:[ ]+(?P<reason>.*))?$/", 1);
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_match", &_5, regex, firstLine, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "A valid response status line was not found in the provided string", "zendframework/http/response.zep", 191);
		return;
	}
	zephir_array_fetch_string(&_6, matches, SL("version"), PH_NOISY | PH_READONLY, "zendframework/http/response.zep", 194 TSRMLS_CC);
	zephir_update_property_zval(response, SL("version"), _6 TSRMLS_CC);
	zephir_array_fetch_string(&_7, matches, SL("status"), PH_NOISY | PH_READONLY, "zendframework/http/response.zep", 196 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(reason);
	if (zephir_array_isset_string_fetch(&reason, matches, SS("reason"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, reason);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_8);
		ZVAL_STRING(_8, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, response, "setstatuscode", NULL, _8);
		zephir_check_temp_parameter(_8);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(lines TSRMLS_CC) == 0) {
		RETURN_CCTOR(response);
	}
	ZEPHIR_INIT_VAR(content);
	array_init(content);
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	zephir_is_iterable(lines, &_10, &_9, 0, 0, "zendframework/http/response.zep", 223);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(line, _11);
		_12 = isHeader;
		if (_12) {
			_12 = ZEPHIR_IS_STRING(line, "");
		}
		if (_12) {
			isHeader = 0;
			continue;
		}
		if (isHeader) {
			zephir_array_append(&headers, line, PH_SEPARATE, "zendframework/http/response.zep", 217);
		} else {
			zephir_array_append(&content, line, PH_SEPARATE, "zendframework/http/response.zep", 219);
		}
	}
	if (zephir_is_true(headers)) {
		ZEPHIR_INIT_NVAR(_8);
		zephir_fast_join_str(_8, SL("\r\n"), headers TSRMLS_CC);
		zephir_update_property_zval(response, SL("headers"), _8 TSRMLS_CC);
	}
	if (zephir_is_true(content)) {
		ZEPHIR_INIT_NVAR(_8);
		zephir_fast_join_str(_8, SL("\r\n"), content TSRMLS_CC);
		ZEPHIR_CPY_WRT(content, _8);
		ZEPHIR_CALL_METHOD(NULL, response, "setcontent", NULL, content);
		zephir_check_call_status();
	}
	RETURN_CCTOR(response);

}

/**
 * @return Header\SetCookie[]
 */
PHP_METHOD(ZendFramework_Http_Response, getCookie) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL, *cookie = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Set-Cookie", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&cookie, headers, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_CCTOR(cookie);

}

/**
 * Set HTTP status code and (optionally) message
 *
 * @param  int $code
 * @throws Exception\InvalidArgumentException
 * @return self
 */
PHP_METHOD(ZendFramework_Http_Response, setStatusCode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zend_bool _0;
	zval *exceptionMsg;
	zval *code, *className, *constName, *_1 = NULL, *_3 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(constName);
	ZEPHIR_CONCAT_VSV(constName, className, "::STATUS_CODE_", code);
	_0 = !zephir_is_numeric(code);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, constName);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZVAL_STRING(exceptionMsg, "Invalid status code provided: \"", 1);
		ZEPHIR_CALL_FUNCTION(&_3, "is_scalar", &_4, code);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_INIT_VAR(_5);
			zephir_gettype(_5, code TSRMLS_CC);
			zephir_concat_self(&exceptionMsg, _5 TSRMLS_CC);
		} else {
			zephir_concat_self(&exceptionMsg, code TSRMLS_CC);
		}
		zephir_concat_self_str(&exceptionMsg, "\"", sizeof("\"")-1 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		object_init_ex(_5, zendframework_http_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "zendframework/http/response.zep", 269 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, zephir_get_intval(code));
	zephir_update_property_this(this_ptr, SL("statusCode"), _6 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Retrieve HTTP status code
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Http_Response, getStatusCode) {


	RETURN_MEMBER(this_ptr, "statusCode");

}

/**
 * Set custom HTTP status code
 *
 * @param  int $code
 * @throws Exception\InvalidArgumentException
 * @return self
 */
PHP_METHOD(ZendFramework_Http_Response, setCustomStatusCode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *exceptionMsg;
	zval *code, *_0 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	if (unlikely(!zephir_is_numeric(code))) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZVAL_STRING(exceptionMsg, "Invalid status code provided: \"", 1);
		ZEPHIR_CALL_FUNCTION(&_0, "is_scalar", &_1, code);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			ZEPHIR_INIT_VAR(_2);
			zephir_gettype(_2, code TSRMLS_CC);
			zephir_concat_self(&exceptionMsg, _2 TSRMLS_CC);
		} else {
			zephir_concat_self(&exceptionMsg, code TSRMLS_CC);
		}
		zephir_concat_self_str(&exceptionMsg, "\"", sizeof("\"")-1 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_2);
		object_init_ex(_2, zendframework_http_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/http/response.zep", 306 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, zephir_get_intval(code));
	zephir_update_property_this(this_ptr, SL("statusCode"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param string $reasonPhrase
 * @return self
 */
PHP_METHOD(ZendFramework_Http_Response, setReasonPhrase) {

	zval *reasonPhrase_param = NULL, *_0 = NULL, *_1;
	zval *reasonPhrase = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reasonPhrase_param);

	zephir_get_strval(reasonPhrase, reasonPhrase_param);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_trim(_1, reasonPhrase, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("reasonPhrase"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get HTTP status message
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Response, getReasonPhrase) {

	zval *reasonPhrase, *statusCode = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("reasonPhrase"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("statusCode"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(statusCode, _1);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("recommendedReasonPhrases"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&reasonPhrase, _1, statusCode, 1 TSRMLS_CC)) {
			RETURN_CTOR(reasonPhrase);
		}
	}
	RETURN_MM_MEMBER(this_ptr, "reasonPhrase");

}

/**
 * Get the body of the response
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Response, getBody) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *body = NULL, *headers = NULL, *transferEncoding = NULL, *transferEncodingValue = NULL, *contentEncoding = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontent", NULL);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(body, _1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "Transfer-Encoding", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&transferEncoding, headers, "get", NULL, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(transferEncoding))) {
		ZEPHIR_CALL_METHOD(&transferEncodingValue, transferEncoding, "getfieldvalue", NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		zephir_fast_strtolower(_3, transferEncodingValue);
		if (ZEPHIR_IS_STRING(_3, "chunked")) {
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "decodechunkedbody", NULL, body);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(body, _2);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Content-Encoding", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&contentEncoding, headers, "get", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(contentEncoding))) {
		ZEPHIR_CALL_METHOD(&contentEncoding, contentEncoding, "getfieldvalue", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(contentEncoding, "gzip")) {
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "decodegzip", NULL, body);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(body, _2);
		} else if (ZEPHIR_IS_STRING(contentEncoding, "deflate")) {
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "decodedeflate", NULL, body);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(body, _2);
		}
	}
	RETURN_CCTOR(body);

}

/**
 * Does the status code indicate a client error?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isClientError) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	_0 = ZEPHIR_LT_LONG(code, 500);
	if (_0) {
		_0 = ZEPHIR_GE_LONG(code, 400);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Is the request forbidden due to ACLs?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isForbidden) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(code, 403));

}

/**
 * Is the current status "informational"?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isInformational) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	_0 = ZEPHIR_GE_LONG(code, 100);
	if (_0) {
		_0 = ZEPHIR_LT_LONG(code, 200);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Does the status code indicate the resource is not found?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isNotFound) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(code, 404));

}

/**
 * Do we have a normal, OK response?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isOk) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(code, 200));

}

/**
 * Does the status code reflect a server error?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isServerError) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	_0 = ZEPHIR_GE_LONG(code, 500);
	if (_0) {
		_0 = ZEPHIR_LT_LONG(code, 600);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Do we have a redirect?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isRedirect) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	_0 = ZEPHIR_GE_LONG(code, 300);
	if (_0) {
		_0 = ZEPHIR_LT_LONG(code, 400);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Was the response successful?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Response, isSuccess) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	_0 = ZEPHIR_GE_LONG(code, 200);
	if (_0) {
		_0 = ZEPHIR_LT_LONG(code, 300);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Render the status line header
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Response, renderStatusLine) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *status = NULL, *_3 = NULL;
	zval *version = NULL, *code = NULL, *phrase = NULL, _0, *_1 = NULL, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&version, this_ptr, "getversion", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getstatuscode", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&phrase, this_ptr, "getreasonphrase", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "HTTP/%s %d %s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", &_2, &_0, version, code, phrase);
	zephir_check_call_status();
	zephir_get_strval(_3, _1);
	ZEPHIR_CPY_WRT(status, _3);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_trim(_4, status, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	RETURN_CCTOR(_4);

}

/**
 * Render entire response as HTTP response string
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Response, toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str = NULL;
	zval *statusLine = NULL, *headers = NULL, *headersStr = NULL, *content = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&statusLine, this_ptr, "renderstatusline", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&content, this_ptr, "getcontent", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_CALL_METHOD(&headersStr, headers, "tostring", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSVSV(_1, statusLine, "\r\n", headersStr, "\r\n", content);
	zephir_get_strval(str, _1);
	RETURN_CTOR(str);

}

/**
 * Decode a "chunked" transfer-encoded body and return the decoded text
 *
 * @param  string $body
 * @return string
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Response, decodeChunkedBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_9 = NULL;
	zval *body_param = NULL, *m, *lengthHex = NULL, *length = NULL, *cut = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5, *_7, *_8 = NULL, _10 = zval_used_for_init, _11 = zval_used_for_init, *_12 = NULL;
	zval *body = NULL, *decBody;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body_param);

	zephir_get_strval(body, body_param);
	ZEPHIR_INIT_VAR(m);
	array_init(m);
	ZEPHIR_INIT_VAR(decBody);
	ZVAL_STRING(decBody, "", 1);


	while (1) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_fast_trim(_1, body, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		if (!(zephir_is_true(_1))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "/^([\\da-fA-F]+)[^\r\n]*\r\n/sm", ZEPHIR_TEMP_PARAM_COPY);
		Z_SET_ISREF_P(m);
		ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, _2, body, m);
		zephir_check_temp_parameter(_2);
		Z_UNSET_ISREF_P(m);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_runtimeexception_ce, "Error parsing body - doesn't seem to be a chunked message", "zendframework/http/response.zep", 541);
			return;
		}
		ZEPHIR_INIT_NVAR(lengthHex);
		zephir_array_fetch_long(&_5, m, 1, PH_NOISY | PH_READONLY, "zendframework/http/response.zep", 543 TSRMLS_CC);
		zephir_fast_trim(lengthHex, _5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&length, "hexdec", &_6, lengthHex);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7, m, 0, PH_NOISY | PH_READONLY, "zendframework/http/response.zep", 545 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(cut);
		ZVAL_LONG(cut, zephir_fast_strlen_ev(_7));
		ZEPHIR_CALL_FUNCTION(&_8, "substr", &_9, body, cut, length);
		zephir_check_call_status();
		zephir_concat_self(&decBody, _8 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_10);
		zephir_add_function(&_10, cut, length TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_11);
		ZVAL_LONG(&_11, (zephir_get_numberval(&_10) + 2));
		ZEPHIR_CALL_FUNCTION(&_12, "substr", &_9, body, &_11);
		zephir_check_call_status();
		zephir_get_strval(body, _12);
	}
	RETURN_CTOR(decBody);

}

/**
 * Decode a gzip encoded message (when Content-encoding = gzip)
 *
 * Currently requires PHP with zlib support
 *
 * @param  string $body
 * @return string
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Response, decodeGzip) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *body_param = NULL, *test = NULL, *bodyCut = NULL, *result = NULL, _1, *_4, *_5, *_6;
	zval *body = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body_param);

	zephir_get_strval(body, body_param);


	if (unlikely(!(zephir_function_exists_ex(SS("gzinflate") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_runtimeexception_ce, "zlib extension is required in order to decode \"gzip\" encoding", "zendframework/http/response.zep", 567);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(NULL, zendframework_stdlib_errorhandler_ce, "start", &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 10);
	ZEPHIR_CALL_FUNCTION(&bodyCut, "substr", &_2, body, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "gzinflate", NULL, bodyCut);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&test, zendframework_stdlib_errorhandler_ce, "stop", &_3);
	zephir_check_call_status();
	if (unlikely(!ZEPHIR_IS_EMPTY(test))) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zendframework_http_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "Error occurred during gzip inflation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5, _6, test);
		zephir_check_temp_parameter(_5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "zendframework/http/response.zep", 576 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(result);

}

/**
 * Decode a zlib deflated message (when Content-encoding = deflate)
 *
 * Currently requires PHP with zlib support
 *
 * @param  string $body
 * @return string
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Response, decodeDeflate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zval *body_param = NULL, *result = NULL, *zlibHeader = NULL, *zlibHeaderFirst, *bodyCut = NULL, _0 = zval_used_for_init, _1;
	zval *body = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body_param);

	zephir_get_strval(body, body_param);


	if (unlikely(!(zephir_function_exists_ex(SS("gzuncompress") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_runtimeexception_ce, "zlib extension is required in order to decode \"deflate\" encoding", "zendframework/http/response.zep", 595);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&bodyCut, "substr", &_2, body, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "n", 0);
	ZEPHIR_CALL_FUNCTION(&zlibHeader, "unpack", &_3, &_0, bodyCut);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(zlibHeaderFirst);
	zephir_array_fetch_long(&zlibHeaderFirst, zlibHeader, 1, PH_NOISY, "zendframework/http/response.zep", 610 TSRMLS_CC);
	if ((zephir_get_numberval(zlibHeaderFirst) % 31) == 0) {
		ZEPHIR_CALL_FUNCTION(&result, "gzuncompress", NULL, body);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&result, "gzinflate", NULL, body);
		zephir_check_call_status();
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(ZendFramework_Http_Response, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 72);
	add_index_stringl(_0, 100, SL("Continue"), 1);
	add_index_stringl(_0, 101, SL("Switching Protocols"), 1);
	add_index_stringl(_0, 102, SL("Processing"), 1);
	add_index_stringl(_0, 200, SL("OK"), 1);
	add_index_stringl(_0, 201, SL("Created"), 1);
	add_index_stringl(_0, 202, SL("Accepted"), 1);
	add_index_stringl(_0, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(_0, 204, SL("No Content"), 1);
	add_index_stringl(_0, 205, SL("Reset Content"), 1);
	add_index_stringl(_0, 206, SL("Partial Content"), 1);
	add_index_stringl(_0, 207, SL("Multi-status"), 1);
	add_index_stringl(_0, 208, SL("Already Reported"), 1);
	add_index_stringl(_0, 300, SL("Multiple Choices"), 1);
	add_index_stringl(_0, 301, SL("Moved Permanently"), 1);
	add_index_stringl(_0, 302, SL("Found"), 1);
	add_index_stringl(_0, 303, SL("See Other"), 1);
	add_index_stringl(_0, 304, SL("Not Modified"), 1);
	add_index_stringl(_0, 305, SL("Use Proxy"), 1);
	add_index_stringl(_0, 306, SL("Switch Proxy"), 1);
	add_index_stringl(_0, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(_0, 400, SL("Bad Request"), 1);
	add_index_stringl(_0, 401, SL("Unauthorized"), 1);
	add_index_stringl(_0, 402, SL("Payment Required"), 1);
	add_index_stringl(_0, 403, SL("Forbidden"), 1);
	add_index_stringl(_0, 404, SL("Not Found"), 1);
	add_index_stringl(_0, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(_0, 406, SL("Not Acceptable"), 1);
	add_index_stringl(_0, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(_0, 408, SL("Request Time-out"), 1);
	add_index_stringl(_0, 409, SL("Conflict"), 1);
	add_index_stringl(_0, 410, SL("Gone"), 1);
	add_index_stringl(_0, 411, SL("Length Required"), 1);
	add_index_stringl(_0, 412, SL("Precondition Failed"), 1);
	add_index_stringl(_0, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(_0, 414, SL("Request-URI Too Large"), 1);
	add_index_stringl(_0, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(_0, 416, SL("Requested range not satisfiable"), 1);
	add_index_stringl(_0, 417, SL("Expectation Failed"), 1);
	add_index_stringl(_0, 418, SL("I\"m a teapot"), 1);
	add_index_stringl(_0, 422, SL("Unprocessable Entity"), 1);
	add_index_stringl(_0, 423, SL("Locked"), 1);
	add_index_stringl(_0, 424, SL("Failed Dependency"), 1);
	add_index_stringl(_0, 425, SL("Unordered Collection"), 1);
	add_index_stringl(_0, 426, SL("Upgrade Required"), 1);
	add_index_stringl(_0, 428, SL("Precondition Required"), 1);
	add_index_stringl(_0, 429, SL("Too Many Requests"), 1);
	add_index_stringl(_0, 431, SL("Request Header Fields Too Large"), 1);
	add_index_stringl(_0, 500, SL("Internal Server Error"), 1);
	add_index_stringl(_0, 501, SL("Not Implemented"), 1);
	add_index_stringl(_0, 502, SL("Bad Gateway"), 1);
	add_index_stringl(_0, 503, SL("Service Unavailable"), 1);
	add_index_stringl(_0, 504, SL("Gateway Time-out"), 1);
	add_index_stringl(_0, 505, SL("HTTP Version not supported"), 1);
	add_index_stringl(_0, 506, SL("Variant Also Negotiates"), 1);
	add_index_stringl(_0, 507, SL("Insufficient Storage"), 1);
	add_index_stringl(_0, 508, SL("Loop Detected"), 1);
	add_index_stringl(_0, 511, SL("Network Authentication Required"), 1);
	zephir_update_property_this(this_ptr, SL("recommendedReasonPhrases"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

