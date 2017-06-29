
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_V1_Service) {

	ZEPHIR_REGISTER_CLASS_EX(OAuth\\V1, Service, oauth, v1_service, oauth_service_ce, oauth_v1_service_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(oauth_v1_service_ce, SL("signature"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_v1_service_ce, SL("baseApiUri"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(OAuth_V1_Service, __construct) {

	zval *credentials, *client, *storage, *signature, *baseApiUri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &credentials, &client, &storage, &signature, &baseApiUri);

	if (!baseApiUri) {
		baseApiUri = ZEPHIR_GLOBAL(global_null);
	}


	zephir_call_parent_p3_noret(this_ptr, oauth_v1_service_ce, "__construct", credentials, client, storage);
	zephir_update_property_this(this_ptr, SL("signature"), signature TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("baseApiUri"), baseApiUri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(OAuth_V1_Service, getSignature) {


	RETURN_MEMBER(this_ptr, "signature");

}

PHP_METHOD(OAuth_V1_Service, getAuthorizationUri) {

	zend_function *_6 = NULL;
	HashTable *_4;
	HashPosition _3;
	zend_class_entry *_1;
	zval *params = NULL, *uri, *endpoint, *key = NULL, *value = NULL, *_0, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	if (((Z_TYPE_P(params) != IS_ARRAY) && (Z_TYPE_P(params) != IS_NULL))) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "The params must be an Array", 1);
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(endpoint);
	object_init_ex(endpoint, oauth_uri_ce);
	zephir_call_method_noret(endpoint, "__construct");
	ZEPHIR_INIT_VAR(uri);
	if (zephir_clone(uri, endpoint TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	if ((Z_TYPE_P(params) != IS_ARRAY)) {
		zephir_is_iterable(params, &_4, &_3, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			; zend_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(key, _4, _3);
			ZEPHIR_GET_HVALUE(value, _5);
			zephir_call_method_p2_cache_noret(uri, "addtoquery", &_6, key, value);
		}
	}
	RETURN_CCTOR(uri);

}

PHP_METHOD(OAuth_V1_Service, request) {

	zval *path_param = NULL, *method_param = NULL, *body = NULL, *headers = NULL;
	zval *path = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &method_param, &body, &headers);

	if (Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(path_param) == IS_STRING) {
		path = path_param;
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "GET", 1);
	} else {
	if (Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(method_param) == IS_STRING) {
		method = method_param;
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	}
	if (!body) {
		body = ZEPHIR_GLOBAL(global_null);
	}
	if (!headers) {
		headers = ZEPHIR_GLOBAL(global_null);
	}



}

