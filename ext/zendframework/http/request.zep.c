
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * HTTP Request
 *
 * @link      http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html#sec5
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http, Request, zendframework, http_request, zendframework_http_abstractmessage_ce, zendframework_http_request_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(zendframework_http_request_ce, SL("method"), "GET", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string|HttpUri
	 */
	zend_declare_property_null(zendframework_http_request_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var ParametersInterface
	 */
	zend_declare_property_null(zendframework_http_request_ce, SL("queryParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var ParametersInterface
	 */
	zend_declare_property_null(zendframework_http_request_ce, SL("postParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var ParametersInterface
	 */
	zend_declare_property_null(zendframework_http_request_ce, SL("fileParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**#@+
	 * @const string METHOD constant names
	 */
	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_OPTIONS"), "OPTIONS" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_GET"), "GET" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_HEAD"), "HEAD" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_POST"), "POST" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_PUT"), "PUT" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_DELETE"), "DELETE" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_TRACE"), "TRACE" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_CONNECT"), "CONNECT" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_PATCH"), "PATCH" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_request_ce, SL("METHOD_PROPFIND"), "PROPFIND" TSRMLS_CC);

	zend_class_implements(zendframework_http_request_ce TSRMLS_CC, 1, zendframework_stdlib_requestinterface_ce);
	return SUCCESS;

}

/**
 * A factory that produces a Request object from a well-formed Http Request string
 *
 * @param  string $string
 * @return Request
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Request, fromString) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zend_bool isHeader = 1;
	zval *string_param = NULL, *className, *request, *lines, *matches = NULL, *methods, *firstLine = NULL, *version, *headers, *rawBody, *nextLine = NULL, *_2 = NULL, *_3, *_5 = NULL, *_7, *_8, *_9;
	zval *string = NULL, *regex = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &string_param);

	zephir_get_strval(string, string_param);
	ZEPHIR_INIT_VAR(matches);
	ZVAL_NULL(matches);
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	ZEPHIR_INIT_VAR(rawBody);
	array_init(rawBody);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(request);
	_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(request, _0);
	if (zephir_has_constructor(request TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(lines);
	zephir_fast_explode_str(lines, SL("\r\n"), string, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_VAR(methods);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 12);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "OPTIONS", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "GET", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "HEAD", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "POST", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "PUT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "DELETE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "TRACE", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "CONNECT", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_BNVAR(_2);
	ZVAL_STRING(_2, "PATCH", 1);
	zephir_array_fast_append(_1, _2);
	zephir_fast_join_str(methods, SL("|"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "#^(?P<method>", methods, ")\s(?P<uri>[^ ]*)(?:\sHTTP\/(?P<version>\d+\.\d+)){0,1}#");
	zephir_get_strval(regex, _3);
	Z_SET_ISREF_P(lines);
	ZEPHIR_CALL_FUNCTION(&firstLine, "array_shift", &_4, lines);
	Z_UNSET_ISREF_P(lines);
	zephir_check_call_status();
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_match", &_6, regex, firstLine, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "A valid request line was not found in the provided string", "zendframework/http/request.zep", 93);
		return;
	}
	zephir_array_fetch_string(&_7, matches, SL("method"), PH_NOISY | PH_READONLY, "zendframework/http/request.zep", 96 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, request, "setmethod", NULL, _7);
	zephir_check_call_status();
	zephir_array_fetch_string(&_8, matches, SL("uri"), PH_NOISY | PH_READONLY, "zendframework/http/request.zep", 97 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, request, "seturi", NULL, _8);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(version);
	if (zephir_array_isset_string_fetch(&version, matches, SS("version"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, request, "setversion", NULL, version);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(lines TSRMLS_CC) == 0) {
		RETURN_CCTOR(request);
	}
	while (1) {
		if (!(zephir_is_true(lines))) {
			break;
		}
		Z_SET_ISREF_P(lines);
		ZEPHIR_CALL_FUNCTION(&nextLine, "array_shift", &_4, lines);
		Z_UNSET_ISREF_P(lines);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(nextLine, "")) {
			isHeader = 0;
			continue;
		}
		if (isHeader) {
			zephir_array_append(&headers, nextLine, PH_SEPARATE, "zendframework/http/request.zep", 114);
		} else {
			zephir_array_append(&rawBody, nextLine, PH_SEPARATE, "zendframework/http/request.zep", 116);
		}
	}
	if (zephir_is_true(headers)) {
		ZEPHIR_INIT_BNVAR(_2);
		zephir_fast_join_str(_2, SL("\r\n"), headers TSRMLS_CC);
		zephir_update_property_zval(request, SL("headers"), _2 TSRMLS_CC);
	}
	if (zephir_is_true(rawBody)) {
		ZEPHIR_INIT_VAR(_9);
		zephir_fast_join_str(_9, SL("\r\n"), rawBody TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, request, "setcontent", NULL, _9);
		zephir_check_call_status();
	}
	RETURN_CCTOR(request);

}

/**
 * Set the method for this request
 *
 * @param  string $method
 * @return Request
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Request, setMethod) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *method_param = NULL, *_0, *_1 = NULL;
	zval *method = NULL, *constName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, method);
	zephir_get_strval(method, _0);
	ZEPHIR_INIT_VAR(constName);
	ZEPHIR_CONCAT_SV(constName, "static::METHOD_", method);
	ZEPHIR_CALL_FUNCTION(&_1, "defined", &_2, constName);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "Invalid HTTP method passed", "zendframework/http/request.zep", 145);
		return;
	}
	zephir_update_property_this(this_ptr, SL("method"), method TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the method for this request
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Request, getMethod) {


	RETURN_MEMBER(this_ptr, "method");

}

/**
 * Set the URI/URL for this request, this can be a string or an instance of Zend\Uri\Http
 *
 * @throws Exception\InvalidArgumentException
 * @param string|HttpUri $uri
 * @return Request
 */
PHP_METHOD(ZendFramework_Http_Request, setUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *exceptionMsg = NULL, *uriStr = NULL, *_1 = NULL;
	zval *uri = NULL, *e = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri);

	ZEPHIR_SEPARATE_PARAM(uri);


	if (Z_TYPE_P(uri) == IS_STRING) {

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(uri);
			_0 = zend_fetch_class(SL("ZendFramework\\Uri\\Http"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(uri, _0);
			if (zephir_has_constructor(uri TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, uri, "__construct", NULL, uri);
				zephir_check_call_status_or_jump(try_end_1);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_is_instance_of(e, SL("UriException\\InvalidUriPartException") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				zephir_get_strval(_1, uri);
				ZEPHIR_CPY_WRT(uriStr, _1);
				ZEPHIR_INIT_VAR(exceptionMsg);
				ZEPHIR_CONCAT_SVS(exceptionMsg, "Invalid URI passed as string (", uriStr, ")");
				ZEPHIR_INIT_VAR(_2);
				object_init_ex(_2, zendframework_http_exception_invalidargumentexception_ce);
				ZEPHIR_CALL_METHOD(&_3, e, "getcode",  NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg, _3, e);
				zephir_check_call_status();
				zephir_throw_exception_debug(_2, "zendframework/http/request.zep", 180 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else if (unlikely(!(zephir_is_instance_of(uri, SL("ZendFramework\\Uri\\Http") TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "URI must be an instance of Zend\\\\Uri\\\\Http or a string", "zendframework/http/request.zep", 184);
		return;
	}
	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the URI for this request object
 *
 * @return HttpUri
 */
PHP_METHOD(ZendFramework_Http_Request, getUri) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zend_bool _1;
	zval *uri = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(uri, _0);
	_1 = Z_TYPE_P(uri) == IS_NULL;
	if (!(_1)) {
		_1 = Z_TYPE_P(uri) == IS_STRING;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(uri);
		_2 = zend_fetch_class(SL("ZendFramework\\Uri\\Http"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(uri, _2);
		if (zephir_has_constructor(uri TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, uri, "__construct", NULL, uri);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	}
	RETURN_CCTOR(uri);

}

/**
 * Return the URI for this request object as a string
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Request, getUriString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(uri, _0);
	if (zephir_is_instance_of(uri, SL("ZendFramework\\Uri\\Http") TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(uri, "tostring", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(uri);

}

/**
 * Provide an alternate Parameter Container implementation for query parameters in this object,
 * (this is NOT the primary API for value setting, for that see getQuery())
 *
 * @param \Zend\Stdlib\ParametersInterface $query
 * @return Request
 */
PHP_METHOD(ZendFramework_Http_Request, setQuery) {

	zval *query;

	zephir_fetch_params(0, 1, 0, &query);



	if (!(zephir_instance_of_ev(query, zendframework_stdlib_parametersinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'query' must be an instance of 'ZendFramework\\\\Stdlib\\\\ParametersInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("queryParams"), query TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the parameter container responsible for query parameters or a single query parameter
 *
 * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
 * @param mixed|null            $default         Default value to use when the parameter is missing.
 * @return \Zend\Stdlib\ParametersInterface|mixed
 */
PHP_METHOD(ZendFramework_Http_Request, getQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL, *queryParams = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &defaultVal);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queryParams"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(queryParams, _0);
	if (Z_TYPE_P(queryParams) == IS_NULL) {
		ZEPHIR_INIT_VAR(queryParams);
		object_init_ex(queryParams, zendframework_stdlib_parameters_ce);
		ZEPHIR_CALL_METHOD(NULL, queryParams, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("queryParams"), queryParams TSRMLS_CC);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		RETURN_CCTOR(queryParams);
	}
	ZEPHIR_RETURN_CALL_METHOD(queryParams, "get", NULL, name, defaultVal);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Provide an alternate Parameter Container implementation for post parameters in this object,
 * (this is NOT the primary API for value setting, for that see getPost())
 *
 * @param \Zend\Stdlib\ParametersInterface $post
 * @return Request
 */
PHP_METHOD(ZendFramework_Http_Request, setPost) {

	zval *post;

	zephir_fetch_params(0, 1, 0, &post);



	if (!(zephir_instance_of_ev(post, zendframework_stdlib_parametersinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'post' must be an instance of 'ZendFramework\\\\Stdlib\\\\ParametersInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("postParams"), post TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the parameter container responsible for post parameters or a single post parameter.
 *
 * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
 * @param mixed|null            $default         Default value to use when the parameter is missing.
 * @return \Zend\Stdlib\ParametersInterface|mixed
 */
PHP_METHOD(ZendFramework_Http_Request, getPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL, *postParams = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &defaultVal);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("postParams"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(postParams, _0);
	if (Z_TYPE_P(postParams) == IS_NULL) {
		ZEPHIR_INIT_VAR(postParams);
		object_init_ex(postParams, zendframework_stdlib_parameters_ce);
		ZEPHIR_CALL_METHOD(NULL, postParams, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("postParams"), postParams TSRMLS_CC);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		RETURN_CCTOR(postParams);
	}
	ZEPHIR_RETURN_CALL_METHOD(postParams, "get", NULL, name, defaultVal);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the Cookie header, this is the same as calling $request->getHeaders()->get('Cookie');
 *
 * @convenience $request->getHeaders()->get('Cookie');
 * @return Header\Cookie
 */
PHP_METHOD(ZendFramework_Http_Request, getCookie) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Cookie", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(headers, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Provide an alternate Parameter Container implementation for file parameters in this object,
 * (this is NOT the primary API for value setting, for that see getFiles())
 *
 * @param  ParametersInterface $files
 * @return Request
 */
PHP_METHOD(ZendFramework_Http_Request, setFiles) {

	zval *files;

	zephir_fetch_params(0, 1, 0, &files);



	if (!(zephir_instance_of_ev(files, zendframework_stdlib_parametersinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'files' must be an instance of 'ZendFramework\\\\Stdlib\\\\ParametersInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("fileParams"), files TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the parameter container responsible for file parameters or a single file.
 *
 * @param string|null           $name            Parameter name to retrieve, or null to get the whole container.
 * @param mixed|null            $default         Default value to use when the parameter is missing.
 * @return ParametersInterface|mixed
 */
PHP_METHOD(ZendFramework_Http_Request, getFiles) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL, *fileParams = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &defaultVal);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("fileParams"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(fileParams, _0);
	if (Z_TYPE_P(fileParams) == IS_NULL) {
		ZEPHIR_INIT_VAR(fileParams);
		object_init_ex(fileParams, zendframework_stdlib_parameters_ce);
		ZEPHIR_CALL_METHOD(NULL, fileParams, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("fileParams"), fileParams TSRMLS_CC);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(name, "")) {
		RETURN_CCTOR(fileParams);
	}
	ZEPHIR_RETURN_CALL_METHOD(fileParams, "get", NULL, name, defaultVal);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the header container responsible for headers or all headers of a certain name/type
 *
 * @see \Zend\Http\Headers::get()
 * @param string|null           $name            Header name to retrieve, or null to get the whole container.
 * @param mixed|null            $default         Default value to use when the requested header is missing.
 * @return \Zend\Http\Headers|bool|\Zend\Http\Header\HeaderInterface|\ArrayIterator
 */
PHP_METHOD(ZendFramework_Http_Request, getHeaders) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL, *headers = NULL, *_0, *_1 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &defaultVal);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_false);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(headers, _0);
	if (Z_TYPE_P(headers) == IS_NULL) {
		ZEPHIR_INIT_VAR(headers);
		object_init_ex(headers, zendframework_http_headers_ce);
		ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("headers"), headers TSRMLS_CC);
	} else if (Z_TYPE_P(headers) == IS_STRING) {
		ZEPHIR_CALL_CE_STATIC(&_1, zendframework_http_headers_ce, "fromstring", &_2, headers);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(headers, _1);
		zephir_update_property_this(this_ptr, SL("headers"), headers TSRMLS_CC);
	}
	if (ZEPHIR_IS_EMPTY(name)) {
		RETURN_CCTOR(headers);
	}
	ZEPHIR_CALL_METHOD(&_1, headers, "has", NULL, name);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_RETURN_CALL_METHOD(headers, "get", NULL, name);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(defaultVal, 1, 0);
	RETURN_MM();

}

/**
 * Get all headers of a certain name/type.
 *
 * @see Request::getHeaders()
 * @param string|null           $name            Header name to retrieve, or null to get the whole container.
 * @param mixed|null            $default         Default value to use when the requested header is missing.
 * @return \Zend\Http\Headers|bool|\Zend\Http\Header\HeaderInterface|\ArrayIterator
 */
PHP_METHOD(ZendFramework_Http_Request, getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultVal = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultVal);

	zephir_get_strval(name, name_param);
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getheaders", NULL, name, defaultVal);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Is this an OPTIONS method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isOptions) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "OPTIONS"));

}

/**
 * Is this a PROPFIND method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isPropFind) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PROPFIND"));

}

/**
 * Is this a GET method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isGet) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "GET"));

}

/**
 * Is this a HEAD method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isHead) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "HEAD"));

}

/**
 * Is this a POST method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isPost) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "POST"));

}

/**
 * Is this a PUT method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isPut) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PUT"));

}

/**
 * Is this a DELETE method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isDelete) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "DELETE"));

}

/**
 * Is this a TRACE method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isTrace) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "TRACE"));

}

/**
 * Is this a CONNECT method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isConnect) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "CONNECT"));

}

/**
 * Is this a PATCH method request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isPatch) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "PATCH"));

}

/**
 * Is the request a Javascript XMLHttpRequest?
 *
 * Should work with Prototype/Script.aculo.us, possibly others.
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isXmlHttpRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL, *header = NULL, *fieldValue = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "X_REQUESTED_WITH", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, headers, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(header, _0);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(header)) {
		ZEPHIR_CALL_METHOD(&fieldValue, header, "getfieldvalue",  NULL);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_IS_STRING(fieldValue, "XMLHttpRequest"));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Is this a Flash request?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Request, isFlashRequest) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL, *header = NULL, *fieldValue = NULL, *_0 = NULL, *_1, _2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "USER_AGENT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, headers, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(header, _0);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(header)) {
		ZEPHIR_CALL_METHOD(&fieldValue, header, "getfieldvalue",  NULL);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, " flash", 0);
		ZEPHIR_CALL_FUNCTION(&_0, "stristr", &_3, fieldValue, &_2);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(_0));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Return the formatted request line (first line) for this http request
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Request, renderRequestLine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *method = NULL, *uri = NULL, *version = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("method"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(method, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uri"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(uri, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("version"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(version, _0);
	if (Z_TYPE_P(uri) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&uri, uri, "__tostring",  NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CONCAT_VSVSV(return_value, method, " ", uri, "HTTP/", version);
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Request, toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *line = NULL, *headers = NULL, *headersStr = NULL, *content = NULL, *_0 = NULL, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&line, this_ptr, "renderrequestline",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getheaders",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_CALL_METHOD(&headersStr, headers, "tostring",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&content, this_ptr, "getcontent",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSVSV(_1, line, "\r\n", headersStr, "\r\n", content);
	zephir_get_strval(str, _1);
	RETURN_CTOR(str);

}

