
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_Uri) {

	ZEPHIR_REGISTER_CLASS(OAuth, Uri, oauth, uri, oauth_uri_method_entry, 0);

/**
     * @var string
     */
	zend_declare_property_string(oauth_uri_ce, SL("scheme"), "http", ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_null(oauth_uri_ce, SL("userInfo"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_null(oauth_uri_ce, SL("rawUserInfo"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_null(oauth_uri_ce, SL("host"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var int
     */
	zend_declare_property_long(oauth_uri_ce, SL("port"), 80, ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_string(oauth_uri_ce, SL("path"), "/", ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_null(oauth_uri_ce, SL("query"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var string
     */
	zend_declare_property_null(oauth_uri_ce, SL("fragment"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var boolean
     */
	zend_declare_property_bool(oauth_uri_ce, SL("explicitPortSpecified"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var boolean
     */
	zend_declare_property_bool(oauth_uri_ce, SL("explicitTrailingHostSlash"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_uri_ce TSRMLS_CC, 1, oauth_uriinterface_ce);

	return SUCCESS;

}

PHP_METHOD(OAuth_Uri, __construct) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
	if (Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(uri_param) == IS_STRING) {
		uri = uri_param;
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(uri))) {
		zephir_call_method_p1_noret(this_ptr, "parseuri", uri);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse URI and setup object vars.
 *
 * @param string uri URI.
 * @return OAuth\Uri
 */
PHP_METHOD(OAuth_Uri, parseUri) {

	zend_class_entry *_1, *_5;
	zval *uri_param = NULL, *parts, *userInfo, *scheme, *port, *path, *query, *fragment, *user, *pass, *_0 = NULL, *_2 = NULL, *_3, *_4, *_6;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

		zephir_get_strval(uri, uri_param);


	ZEPHIR_INIT_VAR(parts);
	zephir_call_func_p1(parts, "parse_url", uri);
	if (ZEPHIR_IS_FALSE(parts)) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Invalid URI: ", uri);
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_string_fetch(&scheme, parts, SS("scheme"), 1 TSRMLS_CC)) {
		zephir_array_fetch_string(&_3, parts, SL("scheme"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("scheme"), _3 TSRMLS_CC);
		zephir_array_fetch_string(&_4, parts, SL("host"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("host"), _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_0);
		_5 = zend_fetch_class(SL("InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _5);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "Invalid URI: http|https scheme required", 1);
		zephir_call_method_p1_noret(_0, "__construct", _6);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_array_isset_string_fetch(&port, parts, SS("port"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("port"), port TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("explicitPortSpecified"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		zephir_array_fetch_string(&_3, parts, SL("scheme"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_3, "https")) {
			ZEPHIR_INIT_ZVAL_NREF(_4);
			ZVAL_LONG(_4, 443);
			zephir_update_property_this(this_ptr, SL("port"), _4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_4);
			ZVAL_LONG(_4, 80);
			zephir_update_property_this(this_ptr, SL("port"), _4 TSRMLS_CC);
		}
		zephir_update_property_this(this_ptr, SL("explicitPortSpecified"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&path, parts, SS("path"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
		if (ZEPHIR_IS_STRING(path, "/")) {
			zephir_update_property_this(this_ptr, SL("explicitTrailingHostSlash"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_STRING(_3, "/", 1);
		zephir_update_property_this(this_ptr, SL("path"), _3 TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&query, parts, SS("query"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("query"), query TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_STRING(_3, "", 1);
		zephir_update_property_this(this_ptr, SL("query"), _3 TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&fragment, parts, SS("fragment"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("fragment"), fragment TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_STRING(_3, "", 1);
		zephir_update_property_this(this_ptr, SL("fragment"), _3 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(userInfo);
	ZVAL_STRING(userInfo, "", 1);
	if (zephir_array_isset_string_fetch(&user, parts, SS("user"), 1 TSRMLS_CC)) {
		zephir_concat_self(&userInfo, user TSRMLS_CC);
	}
	if (zephir_is_true(userInfo) && zephir_array_isset_string_fetch(&pass, parts, SS("pass"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SV(_2, ":", pass);
		zephir_concat_self(&userInfo, _2 TSRMLS_CC);
	}
	zephir_call_method_p1_noret(this_ptr, "setuserinfo", userInfo);
	RETURN_THIS();

}

/**
 * Gets the schema
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getScheme) {


	RETURN_MEMBER(this_ptr, "scheme");

}

/**
 * Sets the schema
 *
 * @param string scheme
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setScheme) {

	zval *scheme_param = NULL;
	zval *scheme = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	if (Z_TYPE_P(scheme_param) != IS_STRING && Z_TYPE_P(scheme_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(scheme_param) == IS_STRING) {
		scheme = scheme_param;
	} else {
		ZEPHIR_INIT_VAR(scheme);
		ZVAL_EMPTY_STRING(scheme);
	}


	zephir_update_property_this(this_ptr, SL("scheme"), scheme TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the host
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getHost) {


	RETURN_MEMBER(this_ptr, "host");

}

/**
 * Sets the host
 *
 * @param string host
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setHost) {

	zval *host_param = NULL;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);

	if (Z_TYPE_P(host_param) != IS_STRING && Z_TYPE_P(host_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'host' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(host_param) == IS_STRING) {
		host = host_param;
	} else {
		ZEPHIR_INIT_VAR(host);
		ZVAL_EMPTY_STRING(host);
	}


	zephir_update_property_this(this_ptr, SL("host"), host TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the port
 *
 * @return int
 */
PHP_METHOD(OAuth_Uri, getPort) {


	RETURN_MEMBER(this_ptr, "port");

}

/**
 * Sets the port
 *
 * @param int port
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setPort) {

	zval *port_param = NULL, *scheme, *_0;
	int port;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port_param);

		port = zephir_get_intval(port_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, port);
	zephir_update_property_zval(this_ptr, SL("port"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(scheme);
	zephir_call_method(scheme, this_ptr, "getscheme");
	if ((((ZEPHIR_IS_STRING(scheme, "https") && (port == 443))) || ((ZEPHIR_IS_STRING(scheme, "http") && (port == 80))))) {
		zephir_update_property_this(this_ptr, SL("explicitPortSpecified"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("explicitPortSpecified"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Gets the path 
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getPath) {


	RETURN_MEMBER(this_ptr, "path");

}

/**
 * Sets the path
 *
 * @param string path
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setPath) {

	zval *path_param = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

		zephir_get_strval(path, path_param);


	if (ZEPHIR_IS_EMPTY(path)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_STRING(_0, "/", 1);
		zephir_update_property_this(this_ptr, SL("path"), _0 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("explicitTrailingHostSlash"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
		if (ZEPHIR_IS_STRING(path, "/")) {
			zephir_update_property_this(this_ptr, SL("explicitTrailingHostSlash"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Gets the query
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getQuery) {


	RETURN_MEMBER(this_ptr, "query");

}

/**
 * Sets the query
 *
 * @param string query
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setQuery) {

	zval *query_param = NULL;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	if (Z_TYPE_P(query_param) != IS_STRING && Z_TYPE_P(query_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'query' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(query_param) == IS_STRING) {
		query = query_param;
	} else {
		ZEPHIR_INIT_VAR(query);
		ZVAL_EMPTY_STRING(query);
	}


	zephir_update_property_this(this_ptr, SL("query"), query TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a param to the query string.
 *
 * @param string name
 * @param string value
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, addToQuery) {

	zval *name_param = NULL, *value, *query, *params, *paramsPacked, *prefix, *separator;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(separator);
	ZVAL_STRING(separator, "&", 1);
	ZEPHIR_INIT_VAR(prefix);
	ZVAL_STRING(prefix, "", 1);
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, this_ptr, "getquery");
	if (!(ZEPHIR_IS_EMPTY(query))) {
		zephir_concat_self(&query, separator TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_array_update_zval(&params, name, &value, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(paramsPacked);
	zephir_call_func_p3(paramsPacked, "http_build_query", params, prefix, separator);
	zephir_concat_self(&query, paramsPacked TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("query"), query TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the fragment.
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getFragment) {


	RETURN_MEMBER(this_ptr, "fragment");

}

/**
 * Should return URI user info, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getUserInfo) {


	RETURN_MEMBER(this_ptr, "userInfo");

}

/**
 * Sets the user info.
 *
 * @param string userInfo
 * @return OAuth\UriInterface
 */
PHP_METHOD(OAuth_Uri, setUserInfo) {

	zval *userInfo_param = NULL;
	zval *userInfo = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &userInfo_param);

		zephir_get_strval(userInfo, userInfo_param);


	zephir_update_property_this(this_ptr, SL("userInfo"), userInfo TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("rawUserInfo"), userInfo TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Should return the URI Authority, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getAuthority) {

	zval *authority, *userInfo, *host, *postSpecified, *port, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(userInfo);
	zephir_call_method(userInfo, this_ptr, "getuserinfo");
	ZEPHIR_INIT_VAR(host);
	zephir_call_method(host, this_ptr, "gethost");
	ZEPHIR_INIT_VAR(postSpecified);
	zephir_call_method(postSpecified, this_ptr, "hasexplicitportspecified");
	ZEPHIR_INIT_VAR(authority);
	if (zephir_is_true(userInfo)) {
		ZEPHIR_CONCAT_VS(authority, userInfo, "@");
	} else {
		ZVAL_STRING(authority, "", 1);
	}
	zephir_concat_self(&authority, host TSRMLS_CC);
	if (zephir_is_true(postSpecified)) {
		ZEPHIR_INIT_VAR(port);
		zephir_call_method(port, this_ptr, "getport");
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, ":", port);
		zephir_concat_self(&authority, _0 TSRMLS_CC);
	}
	RETURN_CCTOR(authority);

}

/**
 * Should return the URI string, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string the URI string with user protected info masked
 */
PHP_METHOD(OAuth_Uri, __toString) {

	zval *uri, *scheme, *authority, *path, *explicitTrailingHostSlash, *query, *fragment;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(scheme);
	zephir_call_method(scheme, this_ptr, "getscheme");
	ZEPHIR_INIT_VAR(authority);
	zephir_call_method(authority, this_ptr, "getauthority");
	ZEPHIR_INIT_VAR(path);
	zephir_call_method(path, this_ptr, "getpath");
	ZEPHIR_INIT_VAR(explicitTrailingHostSlash);
	zephir_call_method(explicitTrailingHostSlash, this_ptr, "hasexplicittrailinghostslash");
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, this_ptr, "getquery");
	ZEPHIR_INIT_VAR(fragment);
	zephir_call_method(fragment, this_ptr, "getfragment");
	ZEPHIR_INIT_VAR(uri);
	ZEPHIR_CONCAT_VSV(uri, scheme, "://", authority);
	if (ZEPHIR_IS_STRING(path, "/")) {
		if (zephir_is_true(explicitTrailingHostSlash)) {
			zephir_concat_self_str(&uri, SL("/") TSRMLS_CC);
		}
	} else {
		zephir_concat_self(&uri, path TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(query))) {
		ZEPHIR_INIT_BNVAR(uri);
		ZEPHIR_CONCAT_VSV(uri, uri, "?", query);
	}
	if (!(ZEPHIR_IS_EMPTY(fragment))) {
		ZEPHIR_INIT_BNVAR(uri);
		ZEPHIR_CONCAT_VSV(uri, uri, "#", fragment);
	}
	RETURN_CCTOR(uri);

}

/**
 * Should return the URI Authority without masking protected user info data
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getRawAuthority) {

	zval *authority, *rawUserInfo, *host, *explicitPortSpecified, *port;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(authority);
	ZVAL_STRING(authority, "", 1);
	ZEPHIR_INIT_VAR(rawUserInfo);
	zephir_call_method(rawUserInfo, this_ptr, "getrawuserinfo");
	ZEPHIR_INIT_VAR(host);
	zephir_call_method(host, this_ptr, "gethost");
	ZEPHIR_INIT_VAR(explicitPortSpecified);
	zephir_call_method(explicitPortSpecified, this_ptr, "hasexplicitportspecified");
	if (zephir_is_true(rawUserInfo)) {
		ZEPHIR_INIT_BNVAR(authority);
		ZEPHIR_CONCAT_VVS(authority, authority, rawUserInfo, "@");
	}
	if (zephir_is_true(explicitPortSpecified)) {
		ZEPHIR_INIT_VAR(port);
		zephir_call_method(port, this_ptr, "getport");
		ZEPHIR_INIT_BNVAR(authority);
		ZEPHIR_CONCAT_VSV(authority, authority, ":", port);
	}
	RETURN_CCTOR(authority);

}

/**
 * Should return the URI user info without masking protected user info data
 *
 * @return string
 */
PHP_METHOD(OAuth_Uri, getRawUserInfo) {


	RETURN_MEMBER(this_ptr, "rawUserInfo");

}

/**
 * Build the full URI based on all the properties
 *
 * @return string The full URI without masking user info
 */
PHP_METHOD(OAuth_Uri, getAbsoluteUri) {

	zval *uri, *scheme, *authority, *path, *query, *fragment, *explicitTrailingHostSlash;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(scheme);
	zephir_call_method(scheme, this_ptr, "getscheme");
	ZEPHIR_INIT_VAR(authority);
	zephir_call_method(authority, this_ptr, "getrawauthority");
	ZEPHIR_INIT_VAR(path);
	zephir_call_method(path, this_ptr, "getpath");
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, this_ptr, "getquery");
	ZEPHIR_INIT_VAR(fragment);
	zephir_call_method(fragment, this_ptr, "getfragment");
	ZEPHIR_INIT_VAR(uri);
	ZEPHIR_CONCAT_VSV(uri, scheme, "://", authority);
	if (ZEPHIR_IS_STRING(path, "/")) {
		ZEPHIR_INIT_VAR(explicitTrailingHostSlash);
		zephir_call_method(explicitTrailingHostSlash, this_ptr, "hasexplicittrailinghostslash");
		if (zephir_is_true(explicitTrailingHostSlash)) {
			zephir_concat_self_str(&uri, SL("/") TSRMLS_CC);
		}
	} else {
		zephir_concat_self(&uri, path TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(query))) {
		ZEPHIR_INIT_BNVAR(uri);
		ZEPHIR_CONCAT_VSV(uri, uri, "?", query);
	}
	if (!(ZEPHIR_IS_EMPTY(fragment))) {
		ZEPHIR_INIT_BNVAR(uri);
		ZEPHIR_CONCAT_VSV(uri, uri, "#", fragment);
	}
	RETURN_CCTOR(uri);

}

/**
 * Build the relative URI based on all the properties
 *
 * @return string The relative URI
 */
PHP_METHOD(OAuth_Uri, getRelativeUri) {

	zval *uri = NULL, *path, *explicitTrailingHostSlash;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(path);
	zephir_call_method(path, this_ptr, "getpath");
	ZEPHIR_INIT_VAR(explicitTrailingHostSlash);
	zephir_call_method(explicitTrailingHostSlash, this_ptr, "hasexplicittrailinghostslash");
	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "", 1);
	if (ZEPHIR_IS_STRING(path, "/")) {
		if (zephir_is_true(explicitTrailingHostSlash)) {
			ZEPHIR_INIT_BNVAR(uri);
			ZVAL_STRING(uri, "/", 1);
		}
	} else {
		ZEPHIR_CPY_WRT(uri, path);
	}
	RETURN_CCTOR(uri);

}

/**
 * @return bool
 */
PHP_METHOD(OAuth_Uri, hasExplicitTrailingHostSlash) {


	RETURN_MEMBER(this_ptr, "explicitTrailingHostSlash");

}

/**
 * @return bool
 */
PHP_METHOD(OAuth_Uri, hasExplicitPortSpecified) {


	RETURN_MEMBER(this_ptr, "explicitPortSpecified");

}

PHP_METHOD(OAuth_Uri, createFromSuperGlobals) {

	zval *params = NULL, *uri, *_SERVER;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		ZEPHIR_CPY_WRT(params, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(params);
	}


	ZEPHIR_INIT_VAR(uri);
	object_init_ex(uri, oauth_uri_ce);
	zephir_call_method_noret(uri, "__construct");
	if (!(ZEPHIR_IS_EMPTY(params))) {
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		ZEPHIR_CPY_WRT(params, _SERVER);
	}
	ZEPHIR_MM_RESTORE();

}

