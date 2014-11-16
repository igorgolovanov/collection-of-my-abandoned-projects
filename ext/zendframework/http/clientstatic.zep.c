
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
#include "kernel/array.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Http static client
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_ClientStatic) {

	ZEPHIR_REGISTER_CLASS(Zend\\Http, ClientStatic, zendframework, http_clientstatic, zendframework_http_clientstatic_method_entry, 0);

	zend_declare_property_null(zendframework_http_clientstatic_ce, SL("client"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Get the static HTTP client
 *
 * @return Client
 */
PHP_METHOD(ZendFramework_Http_ClientStatic, getStaticClient) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *className, *client = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(client);
	ZVAL_NULL(client);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&client, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("client") TSRMLS_CC);
        
	if (Z_TYPE_P(client) == IS_NULL) {
		ZEPHIR_INIT_NVAR(client);
		_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(client, _0);
		if (zephir_has_constructor(client TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, client, "__construct", NULL);
			zephir_check_call_status();
		}
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("client"), &client TSRMLS_CC);
            
	}
	RETURN_CCTOR(client);

}

/**
 * HTTP GET METHOD (static)
 *
 * @param  string $url
 * @param  array $query
 * @param  array $headers
 * @param  mixed $body
 * @return Response|bool
 */
PHP_METHOD(ZendFramework_Http_ClientStatic, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, *headers = NULL;
	zval *url_param = NULL, *query_param = NULL, *headers_param = NULL, *body = NULL, *request, *response = NULL, *client = NULL, *_0, *_1 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &url_param, &query_param, &headers_param, &body);

	zephir_get_strval(url, url_param);
	if (!query_param) {
		ZEPHIR_INIT_VAR(query);
		array_init(query);
	} else {
		zephir_get_arrval(query, query_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}
	if (!body) {
		body = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(url)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(request);
	object_init_ex(request, zendframework_http_request_ce);
	if (zephir_has_constructor(request TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, request, "seturi", NULL, url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "GET", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, request, "setmethod", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(query TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_1, request, "getquery",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "fromarray", NULL, query);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(headers TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(&_1, request, "getheaders",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "addheaders", NULL, headers);
		zephir_check_call_status();
	}
	if (!(ZEPHIR_IS_EMPTY(body))) {
		ZEPHIR_CALL_METHOD(NULL, request, "setcontent", NULL, body);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_STATIC(&_1, "getstaticclient", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(client, _1);
	ZEPHIR_CALL_METHOD(&response, client, "send", NULL, request);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

/**
 * HTTP POST METHOD (static)
 *
 * @param  string $url
 * @param  array $params
 * @param  array $headers
 * @param  mixed $body
 * @throws Exception\InvalidArgumentException
 * @return Response|bool
 */
PHP_METHOD(ZendFramework_Http_ClientStatic, post) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *headers = NULL;
	zval *url_param = NULL, *params, *headers_param = NULL, *body = NULL, *request, *response = NULL, *client = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &url_param, &params, &headers_param, &body);

	zephir_get_strval(url, url_param);
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}
	if (!body) {
		body = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(url)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(request);
	object_init_ex(request, zendframework_http_request_ce);
	if (zephir_has_constructor(request TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, request, "seturi", NULL, url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "POST", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, request, "setmethod", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_EMPTY(params);
	if (_1) {
		_1 = Z_TYPE_P(params) != IS_ARRAY;
	}
	if (unlikely(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_http_exception_invalidargumentexception_ce, "The array of post parameters is empty", "zendframework/http/clientstatic.zep", 104);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, request, "getpost",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _2, "fromarray", NULL, params);
	zephir_check_call_status();
	if (!(zephir_array_isset_string(headers, SS("Content-Type")))) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "application/x-www-form-urlencoded", 1);
		zephir_array_update_string(&headers, SL("Content-Type"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(headers TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_3, request, "getheaders",  NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _3, "addheaders", NULL, headers);
		zephir_check_call_status();
	}
	if (!(ZEPHIR_IS_EMPTY(body))) {
		ZEPHIR_CALL_METHOD(NULL, request, "setcontent", NULL, body);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_STATIC(&_3, "getstaticclient", NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(client, _3);
	ZEPHIR_CALL_METHOD(&response, client, "send", NULL, request);
	zephir_check_call_status();
	RETURN_CCTOR(response);

}

