
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(ZendFramework_Http_Cookies) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http, Cookies, zendframework, http_cookies, zendframework_http_headers_ce, zendframework_http_cookies_method_entry, 0);

	/**
	 * @var \Zend\Http\Cookies
	 */
	zend_declare_property_null(zendframework_http_cookies_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Zend\Http\Headers
	 */
	zend_declare_property_null(zendframework_http_cookies_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_http_cookies_ce, SL("rawCookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Return cookie(s) as a Zend\Http\Cookie object
	 *
	 */
	zend_declare_class_constant_long(zendframework_http_cookies_ce, SL("COOKIE_OBJECT"), 0 TSRMLS_CC);

	/**
	 * Return cookie(s) as a string (suitable for sending in an HTTP request)
	 *
	 */
	zend_declare_class_constant_long(zendframework_http_cookies_ce, SL("COOKIE_STRING_ARRAY"), 1 TSRMLS_CC);

	/**
	 * Return all cookies as one long string (suitable for sending in an HTTP request)
	 *
	 */
	zend_declare_class_constant_long(zendframework_http_cookies_ce, SL("COOKIE_STRING_CONCAT"), 2 TSRMLS_CC);

	/**
	 * Return all cookies as one long string (strict mode)
	 *  - Single space after the semi-colon separating each cookie
	 *  - Remove trailing semi-colon, if any
	 */
	zend_declare_class_constant_long(zendframework_http_cookies_ce, SL("COOKIE_STRING_CONCAT_STRICT"), 3 TSRMLS_CC);

	return SUCCESS;

}

/**
 * @static
 * @throws Exception\RuntimeException
 * @param $string
 * @return void
 */
PHP_METHOD(ZendFramework_Http_Cookies, fromString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *string_param = NULL, *_0;
	zval *string = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &string_param);

	zephir_get_strval(string, string_param);


	ZEPHIR_INIT_VAR(exceptionMsg);
	ZEPHIR_CONCAT_SSSSSS(exceptionMsg, "Cookies", "::", "fromString", " should not be used as a factory, use ", "ZendFramework_Http", "\\Headers::fromtString() instead.");
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zendframework_http_exception_runtimeexception_ce);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, exceptionMsg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "zendframework/http/cookies.zep", 90 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Add a cookie to the class. Cookie should be passed either as a Zend\Http\Header\Cookie object
 * or as a string - in which case an object is created from the string.
 *
 * @param SetCookie|string $cookie
 * @param Uri\Uri|string $refUri Optional reference URI (for domain, path, secure)
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_Cookies, addCookie) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *refUri = NULL;
	zval *cookie, *refUri_param = NULL, *domain = NULL, *path = NULL, *name = NULL, *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cookie, &refUri_param);

	if (!refUri_param) {
		ZEPHIR_INIT_VAR(refUri);
		ZVAL_EMPTY_STRING(refUri);
	} else {
		zephir_get_strval(refUri, refUri_param);
	}


	if (Z_TYPE_P(cookie) == IS_STRING) {
	}
	ZEPHIR_CALL_METHOD(&domain, cookie, "getdomain", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, cookie, "getpath", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&name, cookie, "getname", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, domain))) {
		ZEPHIR_INIT_VAR(_1);
		array_init(_1);
		zephir_update_property_array(this_ptr, SL("cookies"), domain, _1 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, domain, PH_READONLY, "zendframework/http/cookies.zep", 121 TSRMLS_CC);
	if (!(zephir_array_isset(_3, path))) {
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_update_property_array_multi(this_ptr, SL("cookies"), &_1 TSRMLS_CC, SL("zz"), 2, domain, path);
	}
	zephir_update_property_array_multi(this_ptr, SL("cookies"), &cookie TSRMLS_CC, SL("zzz"), 3, domain, path, name);
	zephir_update_property_array_append(this_ptr, SL("rawCookies"), cookie TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse an HTTP response, adding all the cookies set in that response
 *
 * @param Response $response
 * @param Uri\Uri|string $refUri Requested URI
 */
PHP_METHOD(ZendFramework_Http_Cookies, addCookiesFromResponse) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_4;
	HashPosition _3;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *refUri = NULL;
	zval *response, *refUri_param = NULL, *headers = NULL, *cookieHdrs = NULL, *cookie = NULL, *_0 = NULL, *_1, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &response, &refUri_param);

	zephir_get_strval(refUri, refUri_param);


	if (!(zephir_instance_of_ev(response, zendframework_http_response_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'ZendFramework\\Http\\Response'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, response, "getheaders", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(headers, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Set-Cookie", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&cookieHdrs, headers, "get", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(cookieHdrs) == IS_ARRAY;
	if (!(_2)) {
		_2 = zephir_instance_of_ev(cookieHdrs, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC) TSRMLS_CC);
	}
	if (_2) {
		if (zephir_instance_of_ev(cookieHdrs, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC) TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, cookieHdrs);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(cookieHdrs, _0);
		}
		zephir_is_iterable(cookieHdrs, &_4, &_3, 0, 0, "zendframework/http/cookies.zep", 149);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(cookie, _5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcookie", &_6, cookie, refUri);
			zephir_check_call_status();
		}
	} else if (Z_TYPE_P(cookieHdrs) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcookie", &_6, cookieHdrs, refUri);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get all cookies in the cookie jar as an array
 *
 * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\SetCookie or as strings
 * @return array|string
 */
PHP_METHOD(ZendFramework_Http_Cookies, getAllCookies) {

	zval *retAs_param = NULL, *cookies = NULL, *_0, *_1 = NULL, *_2;
	int retAs, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &retAs_param);

	if (!retAs_param) {
		retAs = 0;
	} else {
		retAs = zephir_get_intval(retAs_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(cookies, _0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, retAs);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_flattencookiesarray", NULL, cookies, _2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cookies, _1);
	RETURN_CCTOR(cookies);

}

/**
 * Return an array of all cookies matching a specific request according to the request URI,
 * whether session cookies should be sent or not, and the time to consider as "now" when
 * checking cookie expiry time.
 *
 * @param string|Uri\Uri $uri URI to check against (secure, domain, path)
 * @param bool $matchSessionCookies Whether to send session cookies
 * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\Cookie or as strings
 * @param int $now Override the current time when checking for expiry time
 * @throws Exception\InvalidArgumentException if invalid URI specified
 * @return array|string
 */
PHP_METHOD(ZendFramework_Http_Cookies, getMatchingCookies) {

	HashTable *_3;
	HashPosition _2;
	int retAs, now, ZEPHIR_LAST_CALL_STATUS;
	zend_bool matchSessionCookies;
	zval *uri, *matchSessionCookies_param = NULL, *retAs_param = NULL, *now_param = NULL, *host = NULL, *path = NULL, *cookies = NULL, *result, *cookie = NULL, *_0 = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &uri, &matchSessionCookies_param, &retAs_param, &now_param);

	if (!matchSessionCookies_param) {
		matchSessionCookies = 1;
	} else {
		matchSessionCookies = zephir_get_boolval(matchSessionCookies_param);
	}
	if (!retAs_param) {
		retAs = 0;
	} else {
		retAs = zephir_get_intval(retAs_param);
	}
	if (!now_param) {
		now = 0;
	} else {
		now = zephir_get_intval(now_param);
	}
	ZEPHIR_INIT_VAR(result);
	array_init(result);


	if (Z_TYPE_P(uri) == IS_STRING) {
	}
	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, uri, "getpath", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(host)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "Invalid URI specified; does not contain a host", "zendframework/http/cookies.zep", 197);
		return;
	}
	ZEPHIR_CALL_METHOD(&cookies, this_ptr, "_matchdomain", NULL, host);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_matchpath", NULL, cookies, path);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cookies, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_flattencookiesarray", NULL, cookies, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cookies, _0);
	zephir_is_iterable(cookies, &_3, &_2, 0, 0, "zendframework/http/cookies.zep", 212);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(cookie, _4);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, now);
		ZEPHIR_CALL_METHOD(&_0, cookie, "match", NULL, uri, (matchSessionCookies ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), _1);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			zephir_array_append(&result, cookie, PH_SEPARATE, "zendframework/http/cookies.zep", 208);
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, retAs);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_flattencookiesarray", NULL, result, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get a specific cookie according to a URI and name
 *
 * @param Uri\Uri|string $uri The uri (domain and path) to match
 * @param string $cookieName The cookie's name
 * @param int $retAs Whether to return cookies as objects of \Zend\Http\Header\SetCookie or as strings
 * @throws Exception\InvalidArgumentException if invalid URI specified or invalid $retAs value
 * @return SetCookie|string
 */
PHP_METHOD(ZendFramework_Http_Cookies, getCookie) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	int retAs, ZEPHIR_LAST_CALL_STATUS;
	zval *cookieName = NULL, *exceptionMsg = NULL;
	zval *uri, *cookieName_param = NULL, *retAs_param = NULL, *host = NULL, *path = NULL, *result = NULL, *cookie, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_5, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &uri, &cookieName_param, &retAs_param);

	zephir_get_strval(cookieName, cookieName_param);
	if (!retAs_param) {
		retAs = 0;
	} else {
		retAs = zephir_get_intval(retAs_param);
	}


	if (Z_TYPE_P(uri) == IS_STRING) {
	}
	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, uri, "getpath", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(host)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "Invalid URI specified; host missing", "zendframework/http/cookies.zep", 240);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", &_2, path, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, path, &_0, _1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(path, _3);
	if (!(zephir_is_true(path))) {
		ZEPHIR_INIT_NVAR(path);
		ZVAL_STRING(path, "/", 1);
	}
	ZEPHIR_OBS_VAR(cookie);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	zephir_array_fetch(&_6, _5, host, PH_NOISY | PH_READONLY, "zendframework/http/cookies.zep", 249 TSRMLS_CC);
	zephir_array_fetch(&_7, _6, path, PH_READONLY, "zendframework/http/cookies.zep", 249 TSRMLS_CC);
	if (zephir_array_isset_fetch(&cookie, _7, cookieName, 0 TSRMLS_CC)) {
		do {
			if (retAs == 0) {
				ZEPHIR_CPY_WRT(result, cookie);
				break;
			}
			if (retAs == 2 || retAs == 1) {
				ZEPHIR_CALL_METHOD(&result, cookie, "__tostring", NULL);
				zephir_check_call_status();
				break;
			}
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, retAs);
			ZEPHIR_INIT_VAR(exceptionMsg);
			ZEPHIR_CONCAT_SV(exceptionMsg, "Invalid value passed for $retAs: ", &_0);
			ZEPHIR_INIT_VAR(_8);
			object_init_ex(_8, zendframework_http_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _8, "__construct", NULL, exceptionMsg);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8, "zendframework/http/cookies.zep", 262 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
			break;
		} while(0);

		RETURN_CCTOR(result);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Helper function to recursively flatten an array. Should be used when exporting the
 * cookies array (or parts of it)
 *
 * @param \Zend\Http\Header\SetCookie|array $ptr
 * @param int $retAs What value to return
 * @return array|string
 */
PHP_METHOD(ZendFramework_Http_Cookies, _flattenCookiesArray) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	int retAs, ZEPHIR_LAST_CALL_STATUS;
	zval *ptr, *retAs_param = NULL, *result = NULL, *item = NULL, *cookies = NULL, **_2, _3 = zval_used_for_init, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &ptr, &retAs_param);

	if (!retAs_param) {
		retAs = 0;
	} else {
		retAs = zephir_get_intval(retAs_param);
	}


	if (Z_TYPE_P(ptr) == IS_ARRAY) {
		if (retAs == 2) {
			ZEPHIR_INIT_VAR(result);
			ZVAL_STRING(result, "", 1);
		} else {
			ZEPHIR_INIT_NVAR(result);
			array_init(result);
		}
		zephir_is_iterable(ptr, &_1, &_0, 0, 0, "zendframework/http/cookies.zep", 292);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(item, _2);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, retAs);
			ZEPHIR_CALL_METHOD(&cookies, this_ptr, "_flattencookiesarray", &_4, item, &_3);
			zephir_check_call_status();
			if (retAs == 2) {
				zephir_concat_self(&result, cookies TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				zephir_fast_array_merge(_5, &(result), &(cookies) TSRMLS_CC);
				ZEPHIR_CPY_WRT(result, _5);
			}
		}
		RETURN_CCTOR(result);
	}
	if (zephir_is_instance_of(ptr, SL("ZendFramework\\Http\\Header\\SetCookie") TSRMLS_CC)) {
		do {
			if (retAs == 1) {
				ZEPHIR_INIT_NVAR(result);
				array_init_size(result, 2);
				ZEPHIR_CALL_METHOD(&_6, ptr, "__tostring", NULL);
				zephir_check_call_status();
				zephir_array_fast_append(result, _6);
				break;
			}
			if (retAs == 2) {
				ZEPHIR_CALL_METHOD(&result, ptr, "__tostring", NULL);
				zephir_check_call_status();
				break;
			}
			if (retAs == 0) {
				ZEPHIR_INIT_NVAR(result);
				array_init_size(result, 2);
				zephir_array_fast_append(result, ptr);
				break;
			}
		} while(0);

		RETURN_CCTOR(result);
	}
	RETURN_MM_NULL();

}

/**
 * Return a subset of the cookies array matching a specific domain
 *
 * @param string $domain
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Cookies, _matchDomain) {

	HashTable *_2;
	HashPosition _1;
	zval *domain_param = NULL, *result, *cookiesKeys, *cdom = NULL, *_0, **_3;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	zephir_get_strval(domain, domain_param);
	ZEPHIR_INIT_VAR(result);
	array_init(result);


	ZEPHIR_INIT_VAR(cookiesKeys);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cookies"), PH_NOISY_CC);
	zephir_array_keys(cookiesKeys, _0 TSRMLS_CC);
	zephir_is_iterable(cookiesKeys, &_2, &_1, 0, 0, "zendframework/http/cookies.zep", 331);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(cdom, _3);
	}
	RETURN_CCTOR(result);

}

/**
 * Return a subset of a domain-matching cookies that also match a specified path
 *
 * @param array $domains
 * @param string $path
 * @return array
 */
PHP_METHOD(ZendFramework_Http_Cookies, _matchPath) {

	HashTable *_1, *_4;
	HashPosition _0, _3;
	zval *path = NULL;
	zval *domains_param = NULL, *path_param = NULL, *result, *dom = NULL, *pathsArray = NULL, *pathsArrayKeys = NULL, *cpath = NULL, **_2, **_5, *_6 = NULL, *_7;
	zval *domains = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &domains_param, &path_param);

	zephir_get_arrval(domains, domains_param);
	zephir_get_strval(path, path_param);
	ZEPHIR_INIT_VAR(result);
	array_init(result);


	zephir_is_iterable(domains, &_1, &_0, 0, 0, "zendframework/http/cookies.zep", 357);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HKEY(dom, _1, _0);
		ZEPHIR_GET_HVALUE(pathsArray, _2);
		ZEPHIR_INIT_NVAR(pathsArrayKeys);
		zephir_array_keys(pathsArrayKeys, pathsArray TSRMLS_CC);
		zephir_is_iterable(pathsArrayKeys, &_4, &_3, 0, 0, "zendframework/http/cookies.zep", 355);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(cpath, _5);
			if (!(zephir_array_isset(result, dom))) {
				ZEPHIR_INIT_NVAR(_6);
				array_init(_6);
				zephir_array_update_zval(&result, dom, &_6, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7, pathsArray, cpath, PH_NOISY | PH_READONLY, "zendframework/http/cookies.zep", 352 TSRMLS_CC);
			zephir_array_update_multi(&result, &_7 TSRMLS_CC, SL("zz"), 2, dom, cpath);
		}
	}
	RETURN_CCTOR(result);

}

/**
 * Create a new Cookies object and automatically load into it all the
 * cookies set in a Response object. If $uri is set, it will be
 * considered as the requested URI for setting default domain and path
 * of the cookie.
 *
 * @param Response $response HTTP Response object
 * @param Uri\Uri|string $refUri The requested URI
 * @return Cookies
 * @todo Add the $uri functionality.
 */
PHP_METHOD(ZendFramework_Http_Cookies, fromResponse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *refUri = NULL;
	zval *response, *refUri_param = NULL, *className, *jar, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &response, &refUri_param);

	zephir_get_strval(refUri, refUri_param);


	if (!(zephir_instance_of_ev(response, zendframework_http_response_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'response' must be an instance of 'ZendFramework\\Http\\Response'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(jar);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(jar, _1);
	if (zephir_has_constructor(jar TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, jar, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, jar, "addcookiesfromresponse", NULL, response, refUri);
	zephir_check_call_status();
	RETURN_CCTOR(jar);

}

/**
 * Tells if the array of cookies is empty
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_Http_Cookies, isEmpty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *count = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&count, this_ptr, "count", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(count, 0));

}

/**
 * Empties the cookieJar of any cookie
 *
 * @return Cookies
 */
PHP_METHOD(ZendFramework_Http_Cookies, reset) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("cookies"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("rawCookies"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(ZendFramework_Http_Cookies, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("cookies"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

