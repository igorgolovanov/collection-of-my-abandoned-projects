
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
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"

ZEPHIR_INIT_CLASS(ZendFramework_Http_Client) {

	ZEPHIR_REGISTER_CLASS(Zend\\Http, Client, zendframework, http_client, zendframework_http_client_method_entry, 0);

	/**
	 * @var Response
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("response"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Request
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Client/Adapter
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("auth"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("streamName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array of Header\SetCookie
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(zendframework_http_client_ce, SL("encType"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Request
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("lastRawRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Response
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("lastRawResponse"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(zendframework_http_client_ce, SL("redirectCounter"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Configuration array, set using the constructor or using ::setOptions()
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Fileinfo magic database resource
	 *
	 * This variable is populated the first time _detectFileMimeType is called
	 * and is then reused on every call to this method
	 *
	 * @var resource
	 */
	zend_declare_property_null(zendframework_http_client_ce, SL("fileInfoDb"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @const string Supported HTTP Authentication methods
	 */
	zend_declare_class_constant_string(zendframework_http_client_ce, SL("AUTH_BASIC"), "basic" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("AUTH_DIGEST"), "digest" TSRMLS_CC);

	/**
	 * @const string POST data encoding methods
	 */
	zend_declare_class_constant_string(zendframework_http_client_ce, SL("ENC_URLENCODED"), "application/x-www-form-urlencoded" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("ENC_FORMDATA"), "multipart/form-data" TSRMLS_CC);

	/**
	 * @const string DIGEST Authentication
	 */
	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_REALM"), "realm" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_QOP"), "qop" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_NONCE"), "nonce" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_OPAQUE"), "opaque" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_NC"), "nc" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_client_ce, SL("DIGEST_CNONCE"), "cnonce" TSRMLS_CC);

	zend_class_implements(zendframework_http_client_ce TSRMLS_CC, 1, zendframework_stdlib_dispatchableinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string $uri
 * @param array|Traversable $options
 */
PHP_METHOD(ZendFramework_Http_Client, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *uri_param = NULL, *options = NULL, *_1, *_2;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uri_param, &options);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
		zephir_get_strval(uri, uri_param);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 16);
	add_assoc_long_ex(_0, SS("maxredirects"), 5);
	zephir_array_update_string(&_0, SL("strictredirects"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("useragent"), SL("Zend\\Http\\Client"), 1);
	add_assoc_long_ex(_0, SS("timeout"), 10);
	add_assoc_stringl_ex(_0, SS("adapter"), SL("Zend\\Http\\Client\\Adapter\\Socket"), 1);
	add_assoc_stringl_ex(_0, SS("httpversion"), SL("1.1"), 1);
	zephir_array_update_string(&_0, SL("storeresponse"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("keepalive"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("outputstream"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("encodecookies"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("argseparator"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("rfc3986strict"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("cookies"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("auth"), _2 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING_IDENTICAL(uri, "")) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturi", NULL, uri);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(options) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Set configuration parameters for this HTTP client
 *
 * @param  array|Traversable $options
 * @return Client
 * @throws Client\Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Client, setOptions) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *wildcards;
	zval *options = NULL, *k = NULL, *v = NULL, *key = NULL, *_0 = NULL, **_4, *_5 = NULL, _6 = zval_used_for_init, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}
	ZEPHIR_INIT_VAR(wildcards);
	array_init(wildcards);


	if (zephir_is_instance_of(options, SL("Traversable") TSRMLS_CC)) {
		ZEPHIR_CALL_CE_STATIC(&_0, zendframework_stdlib_arrayutils_ce, "iteratortoarray", &_1, options);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(options, _0);
	}
	if (unlikely(Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_client_exception_invalidargumentexception_ce, "Config parameter is not valid", "zendframework/http/client.zep", 157);
		return;
	}
	zephir_is_iterable(options, &_3, &_2, 0, 0, "zendframework/http/client.zep", 166);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(k, _3, _2);
		ZEPHIR_GET_HVALUE(v, _4);
		ZEPHIR_INIT_NVAR(key);
		ZEPHIR_INIT_NVAR(_5);
		zephir_fast_strtolower(_5, k);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "", 0);
		zephir_fast_str_replace(key, wildcards, &_6, _5 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("config"), key, v TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_this(&_7, this_ptr, SL("adapter"), PH_NOISY_CC);
	if (zephir_instance_of_ev(_7, zendframework_http_client_adapter_adapterinterface_ce TSRMLS_CC)) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("adapter"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _8, "setoptions", NULL, options);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Load the connection adapter
 *
 * While this method is not called more than one for a client, it is
 * separated from ->request() to preserve logic and readability
 *
 * @param  Client\Adapter\AdapterInterface|string $adapter
 * @return Client
 * @throws Client\Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Client, setAdapter) {

	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *adapter = NULL, *config = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &adapter);

	ZEPHIR_SEPARATE_PARAM(adapter);


	if (Z_TYPE_P(adapter) == IS_STRING) {
		if (unlikely(!zephir_class_exists(adapter, 1 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_CONCAT_SVS(_0, "Unable to locate adapter class \"", adapter, "\"");
			zephir_get_strval(exceptionMsg, _0);
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, zendframework_http_client_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "zendframework/http/client.zep", 191 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(adapter);
		zephir_fetch_safe_class(_2, adapter);
		_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(adapter, _3);
		if (zephir_has_constructor(adapter TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, adapter, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (unlikely(!(zephir_instance_of_ev(adapter, zendframework_http_client_adapter_adapterinterface_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZVAL_STRING(exceptionMsg, "Passed adapter is not a HTTP connection adapter", 1);
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, zendframework_http_client_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/http/client.zep", 198 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("adapter"), adapter TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(config, _4);
	zephir_array_unset_string(&config, SS("adapter"), PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, adapter, "setoptions", NULL, config);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Load the connection adapter
 *
 * @return Client\Adapter\AdapterInterface $adapter
 */
PHP_METHOD(ZendFramework_Http_Client, getAdapter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("adapter"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("adapter"), PH_NOISY | PH_READONLY, "zendframework/http/client.zep", 220 TSRMLS_CC);
		ZEPHIR_CPY_WRT(config, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setadapter", NULL, config);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "adapter");

}

/**
 * Set request
 *
 * @param Request $request
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setRequest) {

	zval *request;

	zephir_fetch_params(0, 1, 0, &request);



	if (!(zephir_instance_of_ev(request, zendframework_http_request_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'ZendFramework\\Http\\Request'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get Request
 *
 * @return Request
 */
PHP_METHOD(ZendFramework_Http_Client, getRequest) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(request, _0);
	if (ZEPHIR_IS_EMPTY(request)) {
		ZEPHIR_INIT_NVAR(request);
		object_init_ex(request, zendframework_http_request_ce);
		if (zephir_has_constructor(request TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);
	}
	RETURN_CCTOR(request);

}

/**
 * Set response
 *
 * @param Response $response
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setResponse) {

	zval *response;

	zephir_fetch_params(0, 1, 0, &response);



	if (!(zephir_instance_of_ev(response, zendframework_http_response_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'ZendFramework\\Http\\Response'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("response"), response TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get Response
 *
 * @return Response
 */
PHP_METHOD(ZendFramework_Http_Client, getResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("response"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(response, _0);
	if (ZEPHIR_IS_EMPTY(response)) {
		ZEPHIR_INIT_NVAR(response);
		object_init_ex(response, zendframework_http_response_ce);
		if (zephir_has_constructor(response TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, response, "__construct", NULL);
			zephir_check_call_status();
		}
		zephir_update_property_this(this_ptr, SL("response"), response TSRMLS_CC);
	}
	RETURN_CCTOR(response);

}

/**
 * Get the last request (as a string)
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, getLastRawRequest) {


	RETURN_MEMBER(this_ptr, "lastRawRequest");

}

/**
 * Get the last response (as a string)
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, getLastRawResponse) {


	RETURN_MEMBER(this_ptr, "lastRawResponse");

}

/**
 * Get the redirections count
 *
 * @return int
 */
PHP_METHOD(ZendFramework_Http_Client, getRedirectionsCount) {


	RETURN_MEMBER(this_ptr, "redirectCounter");

}

/**
 * Set Uri (to the request)
 *
 * @param string|Http $uri
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setUri) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	if (!(ZEPHIR_IS_EMPTY(uri))) {
	}
	RETURN_THIS();

}

/**
 * Get uri (from the request)
 *
 * @return Http
 */
PHP_METHOD(ZendFramework_Http_Client, getUri) {



}

/**
 * Set the HTTP method (to the request)
 *
 * @param string $method
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setMethod) {

	zval *method_param = NULL;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(method, method_param);


	RETURN_THIS();

}

/**
 * Get the HTTP method
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, getMethod) {


	RETURN_STRING("", 1);

}

/**
 * Set the query string argument separator
 *
 * @param string $argSeparator
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setArgSeparator) {

	zval *argSeparator_param = NULL;
	zval *argSeparator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argSeparator_param);

	zephir_get_strval(argSeparator, argSeparator_param);


	RETURN_THIS();

}

/**
 * Get the query string argument separator
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, getArgSeparator) {



}

/**
 * Set the encoding type and the boundary (if any)
 *
 * @param string $encType
 * @param string $boundary
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setEncType) {

	zval *encType_param = NULL, *boundary_param = NULL;
	zval *encType = NULL, *boundary = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &encType_param, &boundary_param);

	zephir_get_strval(encType, encType_param);
	if (!boundary_param) {
		ZEPHIR_INIT_VAR(boundary);
		ZVAL_EMPTY_STRING(boundary);
	} else {
		zephir_get_strval(boundary, boundary_param);
	}


	RETURN_THIS();

}

/**
 * Get the encoding type
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, getEncType) {



}

/**
 * Set raw body (for advanced use cases)
 *
 * @param string $body
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setRawBody) {

	zval *body_param = NULL;
	zval *body = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body_param);

	zephir_get_strval(body, body_param);


	RETURN_THIS();

}

/**
 * Set the POST parameters
 *
 * @param array $post
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setParameterPost) {

	zval *post_param = NULL;
	zval *post = NULL;

	zephir_fetch_params(0, 1, 0, &post_param);

	if (unlikely(Z_TYPE_P(post_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'post' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		post = post_param;



	RETURN_THISW();

}

/**
 * Set the GET parameters
 *
 * @param array $query
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setParameterGet) {

	zval *query_param = NULL;
	zval *query = NULL;

	zephir_fetch_params(0, 1, 0, &query_param);

	if (unlikely(Z_TYPE_P(query_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'query' must be an array") TSRMLS_CC);
		RETURN_NULL();
	}

		query = query_param;



	RETURN_THISW();

}

/**
 * Reset all the HTTP parameters (request, response, etc)
 *
 * @param  bool   $clearCookies  Also clear all valid cookies? (defaults to false)
 * @param  bool   $clearAuth     Also clear http authentication? (defaults to true)
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, resetParameters) {

	zval *clearCookies_param = NULL;
	zend_bool clearCookies;

	zephir_fetch_params(0, 0, 1, &clearCookies_param);

	if (!clearCookies_param) {
		clearCookies = 0;
	} else {
		clearCookies = zephir_get_boolval(clearCookies_param);
	}


	RETURN_THISW();

}

/**
 * Return the current cookies
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Client, getCookies) {


	array_init(return_value);
	return;

}

/**
 * Get the cookie Id (name+domain+path)
 *
 * @param  Header\SetCookie|Header\Cookie $cookie
 * @return string|bool
 */
PHP_METHOD(ZendFramework_Http_Client, getCookieId) {

	zval *cookie;

	zephir_fetch_params(0, 1, 0, &cookie);



	RETURN_STRING("", 1);

}

/**
 * Add a cookie
 *
 * @param array|ArrayIterator|Header\SetCookie|string $cookie
 * @param string  $value
 * @param string  $expire
 * @param string  $path
 * @param string  $domain
 * @param  bool $secure
 * @param  bool $httponly
 * @param string  $maxAge
 * @param string  $version
 * @throws Exception\InvalidArgumentException
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, addCookie) {

	zend_bool secure, httponly;
	zval *value = NULL, *expire = NULL, *path = NULL, *domain = NULL, *maxAge = NULL, *version = NULL;
	zval *cookie, *value_param = NULL, *expire_param = NULL, *path_param = NULL, *domain_param = NULL, *secure_param = NULL, *httponly_param = NULL, *maxAge_param = NULL, *version_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 8, &cookie, &value_param, &expire_param, &path_param, &domain_param, &secure_param, &httponly_param, &maxAge_param, &version_param);

	if (!value_param) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	} else {
		zephir_get_strval(value, value_param);
	}
	if (!expire_param) {
		ZEPHIR_INIT_VAR(expire);
		ZVAL_EMPTY_STRING(expire);
	} else {
		zephir_get_strval(expire, expire_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	} else {
		zephir_get_strval(path, path_param);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
		zephir_get_strval(domain, domain_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!httponly_param) {
		httponly = 1;
	} else {
		httponly = zephir_get_boolval(httponly_param);
	}
	if (!maxAge_param) {
		ZEPHIR_INIT_VAR(maxAge);
		ZVAL_EMPTY_STRING(maxAge);
	} else {
		zephir_get_strval(maxAge, maxAge_param);
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	} else {
		zephir_get_strval(version, version_param);
	}


	RETURN_THIS();

}

/**
 * Set an array of cookies
 *
 * @param  array $cookies
 * @throws Exception\InvalidArgumentException
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setCookies) {

	zval *cookies_param = NULL;
	zval *cookies = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(cookies, cookies_param);


	RETURN_THIS();

}

/**
 * Clear all the cookies
 */
PHP_METHOD(ZendFramework_Http_Client, clearCookies) {



}

/**
 * Set the headers (for the request)
 *
 * @param  Headers|array $headers
 * @throws Exception\InvalidArgumentException
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setHeaders) {

	zval *headers;

	zephir_fetch_params(0, 1, 0, &headers);



	RETURN_THISW();

}

/**
 * Check if exists the header type specified
 *
 * @param  string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Client, hasHeader) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	RETURN_MM_BOOL(1);

}

/**
 * Get the header value of the request
 *
 * @param  string $name
 * @return string|bool
 */
PHP_METHOD(ZendFramework_Http_Client, getHeader) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	RETURN_MM_STRING("", 1);

}

/**
 * Set streaming for received data
 *
 * @param string|bool $streamfile Stream file, true for temp file, false/null for no streaming
 * @return \Zend\Http\Client
 */
PHP_METHOD(ZendFramework_Http_Client, setStream) {

	zval *streamfile = NULL;

	zephir_fetch_params(0, 0, 1, &streamfile);

	if (!streamfile) {
		streamfile = ZEPHIR_GLOBAL(global_true);
	}


	RETURN_THISW();

}

/**
 * Get status of streaming for received data
 * @return bool|string
 */
PHP_METHOD(ZendFramework_Http_Client, getStream) {


	RETURN_STRING("", 1);

}

/**
 * Create temporary stream
 *
 * @throws Exception\RuntimeException
 * @return resource
 */
PHP_METHOD(ZendFramework_Http_Client, openTempStream) {



}

/**
 * Create a HTTP authentication "Authorization:" header according to the
 * specified user, password and authentication method.
 *
 * @param string $user
 * @param string $password
 * @param string $type
 * @throws Exception\InvalidArgumentException
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, setAuth) {

	zval *user_param = NULL, *password_param = NULL, *type = NULL;
	zval *user = NULL, *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &user_param, &password_param, &type);

	zephir_get_strval(user, user_param);
	zephir_get_strval(password, password_param);
	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "basic", 1);
	}


	RETURN_THIS();

}

/**
 * Clear http authentication
 */
PHP_METHOD(ZendFramework_Http_Client, clearAuth) {



}

/**
 * Calculate the response value according to the HTTP authentication type
 *
 * @see http://www.faqs.org/rfcs/rfc2617.html
 * @param string $user
 * @param string $password
 * @param string $type
 * @param array $digest
 * @param null|string $entityBody
 * @throws Exception\InvalidArgumentException
 * @return string|bool
 */
PHP_METHOD(ZendFramework_Http_Client, calcAuthDigest) {

	zval *digest = NULL;
	zval *user_param = NULL, *password_param = NULL, *type = NULL, *digest_param = NULL, *entityBody_param = NULL;
	zval *user = NULL, *password = NULL, *entityBody = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &user_param, &password_param, &type, &digest_param, &entityBody_param);

	zephir_get_strval(user, user_param);
	zephir_get_strval(password, password_param);
	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "basic", 1);
	}
	if (!digest_param) {
		ZEPHIR_INIT_VAR(digest);
		array_init(digest);
	} else {
		zephir_get_arrval(digest, digest_param);
	}
	if (!entityBody_param) {
		ZEPHIR_INIT_VAR(entityBody);
		ZVAL_EMPTY_STRING(entityBody);
	} else {
		zephir_get_strval(entityBody, entityBody_param);
	}


	RETURN_MM_STRING("", 1);

}

/**
 * Dispatch
 *
 * @param Stdlib\RequestInterface $request
 * @param Stdlib\ResponseInterface $response
 * @return Stdlib\ResponseInterface
 */
PHP_METHOD(ZendFramework_Http_Client, dispatch) {

	zval *request, *response = NULL;

	zephir_fetch_params(0, 1, 1, &request, &response);

	if (!response) {
		response = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * Send HTTP request
 *
 * @param  Request $request
 * @return Response
 * @throws Exception\RuntimeException
 * @throws Client\Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Client, send) {

	zend_bool _0;
	zval *request = NULL;

	zephir_fetch_params(0, 0, 1, &request);

	if (!request) {
		request = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(request) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(request, zendframework_http_request_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'request' must be an instance of 'ZendFramework\\Http\\Request'", "", 0);
		return;
	}

}

/**
 * Fully reset the HTTP client (auth, cookies, request, response, etc.)
 *
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_Client, reset) {


	RETURN_THISW();

}

/**
 * Set a file to upload (using a POST request)
 *
 * Can be used in two ways:
 *
 * 1. $data is null (default): $filename is treated as the name if a local file which
 * will be read and sent. Will try to guess the content type using mime_content_type().
 * 2. $data is set - $filename is sent as the file name, but $data is sent as the file
 * contents and no file is read from the file system. In this case, you need to
 * manually set the Content-Type ($ctype) or it will default to
 * application/octet-stream.
 *
 * @param  string $filename Name of file to upload, or name to save as
 * @param  string $formname Name of form element to send as
 * @param  string $data Data to send (if null, $filename is read and sent)
 * @param  string $ctype Content type to use (if $data is set and $ctype is
 *                null, will be application/octet-stream)
 * @return Client
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Client, setFileUpload) {

	zval *filename_param = NULL, *formname_param = NULL, *data_param = NULL, *ctype_param = NULL;
	zval *filename = NULL, *formname = NULL, *data = NULL, *ctype = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &filename_param, &formname_param, &data_param, &ctype_param);

	zephir_get_strval(filename, filename_param);
	zephir_get_strval(formname, formname_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	} else {
		zephir_get_strval(data, data_param);
	}
	if (!ctype_param) {
		ZEPHIR_INIT_VAR(ctype);
		ZVAL_EMPTY_STRING(ctype);
	} else {
		zephir_get_strval(ctype, ctype_param);
	}


	RETURN_THIS();

}

/**
 * Remove a file to upload
 *
 * @param  string $filename
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Client, removeFileUpload) {

	zval *filename_param = NULL;
	zval *filename = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);

	zephir_get_strval(filename, filename_param);


	RETURN_MM_BOOL(1);

}

/**
 * Prepare Cookies
 *
 * @param   string $domain
 * @param   string $path
 * @param   bool $secure
 * @return  Header\Cookie|bool
 */
PHP_METHOD(ZendFramework_Http_Client, prepareCookies) {

	zend_bool secure;
	zval *domain_param = NULL, *path_param = NULL, *secure_param = NULL;
	zval *domain = NULL, *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &domain_param, &path_param, &secure_param);

	zephir_get_strval(domain, domain_param);
	zephir_get_strval(path, path_param);
	secure = zephir_get_boolval(secure_param);


	RETURN_MM_BOOL(1);

}

/**
 * Prepare the request headers
 *
 * @param resource|string $body
 * @param Http $uri
 * @throws Exception\RuntimeException
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Client, prepareHeaders) {

	zval *body, *uri;

	zephir_fetch_params(0, 2, 0, &body, &uri);



	array_init(return_value);
	return;

}

/**
 * Prepare the request body (for PATCH, POST and PUT requests)
 *
 * @return string
 * @throws \Zend\Http\Client\Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Client, prepareBody) {


	RETURN_STRING("", 1);

}

/**
 * Attempt to detect the MIME type of a file using available extensions
 *
 * This method will try to detect the MIME type of a file. If the fileinfo
 * extension is available, it will be used. If not, the mime_magic
 * extension which is deprecated but is still available in many PHP setups
 * will be tried.
 *
 * If neither extension is available, the default application/octet-stream
 * MIME type will be returned
 *
 * @param string $file File path
 * @return string MIME type
 */
PHP_METHOD(ZendFramework_Http_Client, detectFileMimeType) {

	zval *file_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(file, file_param);


	RETURN_MM_STRING("", 1);

}

/**
 * Encode data to a multipart/form-data part suitable for a POST request.
 *
 * @param string $boundary
 * @param string $name
 * @param mixed $value
 * @param string $filename
 * @param array $headers Associative array of optional headers @example ("Content-Transfer-Encoding" => "binary")
 * @return string
 */
PHP_METHOD(ZendFramework_Http_Client, encodeFormData) {

	zval *headers = NULL;
	zval *boundary_param = NULL, *name_param = NULL, *value, *filename_param = NULL, *headers_param = NULL;
	zval *boundary = NULL, *name = NULL, *filename = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &boundary_param, &name_param, &value, &filename_param, &headers_param);

	zephir_get_strval(boundary, boundary_param);
	zephir_get_strval(name, name_param);
	if (!filename_param) {
		ZEPHIR_INIT_VAR(filename);
		ZVAL_EMPTY_STRING(filename);
	} else {
		zephir_get_strval(filename, filename_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}


	RETURN_MM_STRING("", 1);

}

/**
 * Convert an array of parameters into a flat array of (key, value) pairs
 *
 * Will flatten a potentially multi-dimentional array of parameters (such
 * as POST parameters) into a flat array of (key, value) paris. In case
 * of multi-dimentional arrays, square brackets ([]) will be added to the
 * key to indicate an array.
 *
 * @since 1.9
 *
 * @param array $parray
 * @param string $prefix
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Client, flattenParametersArray) {

	zval *prefix = NULL;
	zval *parray_param = NULL, *prefix_param = NULL;
	zval *parray = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parray_param, &prefix_param);

	zephir_get_arrval(parray, parray_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	array_init(return_value);
	RETURN_MM();

}

/**
 * Separating this from send method allows subclasses to wrap
 * the interaction with the adapter
 *
 * @param Http $uri
 * @param string $method
 * @param  bool $secure
 * @param array $headers
 * @param string $body
 * @return string the raw response
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendFramework_Http_Client, doRequest) {

	zval *headers = NULL;
	zend_bool secure;
	zval *method = NULL, *body = NULL;
	zval *uri, *method_param = NULL, *secure_param = NULL, *headers_param = NULL, *body_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &uri, &method_param, &secure_param, &headers_param, &body_param);

	zephir_get_strval(method, method_param);
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}
	if (!body_param) {
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "", 1);
	} else {
		zephir_get_strval(body, body_param);
	}


	RETURN_MM_STRING("", 1);

}

/**
 * Create a HTTP authentication "Authorization:" header according to the
 * specified user, password and authentication method.
 *
 * @see http://www.faqs.org/rfcs/rfc2617.html
 * @param string $user
 * @param string $password
 * @param string $type
 * @return string
 * @throws Client\Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Client, encodeAuthHeader) {

	zval *user_param = NULL, *password_param = NULL, *type = NULL;
	zval *user = NULL, *password = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &user_param, &password_param, &type);

	zephir_get_strval(user, user_param);
	zephir_get_strval(password, password_param);
	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "basic", 1);
	}


	RETURN_MM_STRING("", 1);

}

