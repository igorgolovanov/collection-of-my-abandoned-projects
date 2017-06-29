
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_Token) {

	ZEPHIR_REGISTER_CLASS(OAuth, Token, oauth, token, oauth_token_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(oauth_token_ce, SL("accessToken"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_token_ce, SL("refreshToken"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_token_ce, SL("endOfLife"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_token_ce TSRMLS_CC, 1, oauth_tokeninterface_ce);

	return SUCCESS;

}

PHP_METHOD(OAuth_Token, __construct) {

	int lifetime;
	zval *accessToken_param = NULL, *refreshToken_param = NULL, *lifetime_param = NULL, *_0;
	zval *accessToken = NULL, *refreshToken = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &accessToken_param, &refreshToken_param, &lifetime_param);

	if (Z_TYPE_P(accessToken_param) != IS_STRING && Z_TYPE_P(accessToken_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'accessToken' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(accessToken_param) == IS_STRING) {
		accessToken = accessToken_param;
	} else {
		ZEPHIR_INIT_VAR(accessToken);
		ZVAL_EMPTY_STRING(accessToken);
	}
	if (Z_TYPE_P(refreshToken_param) != IS_STRING && Z_TYPE_P(refreshToken_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'refreshToken' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(refreshToken_param) == IS_STRING) {
		refreshToken = refreshToken_param;
	} else {
		ZEPHIR_INIT_VAR(refreshToken);
		ZVAL_EMPTY_STRING(refreshToken);
	}
		lifetime = zephir_get_intval(lifetime_param);


	zephir_call_method_p1_noret(this_ptr, "setaccesstoken", accessToken);
	zephir_call_method_p1_noret(this_ptr, "setrefreshtoken", refreshToken);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, lifetime);
	zephir_call_method_p1_noret(this_ptr, "setlifetime", _0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the access token.
 *
 * @return string
 */
PHP_METHOD(OAuth_Token, getAccessToken) {


	RETURN_MEMBER(this_ptr, "accessToken");

}

/**
 * Sets the access token.
 *
 * @param string token
 * @return OAuth\Token
 */
PHP_METHOD(OAuth_Token, setAccessToken) {

	zval *token_param = NULL;
	zval *token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);

	if (Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(token_param) == IS_STRING) {
		token = token_param;
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}


	zephir_update_property_this(this_ptr, SL("accessToken"), token TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the refresh token.
 *
 * @return string
 */
PHP_METHOD(OAuth_Token, getRefreshToken) {


	RETURN_MEMBER(this_ptr, "refreshToken");

}

/**
 * Sets the refresh token.
 *
 * @param string token
 * @return OAuth\Token
 */
PHP_METHOD(OAuth_Token, setRefreshToken) {

	zval *token_param = NULL;
	zval *token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);

	if (Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(token_param) == IS_STRING) {
		token = token_param;
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}


	zephir_update_property_this(this_ptr, SL("refreshToken"), token TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the end of token life
 *
 * @return int
 */
PHP_METHOD(OAuth_Token, getEndOfLife) {


	RETURN_MEMBER(this_ptr, "endOfLife");

}

/**
 * Sets the end of token life
 *
 * @param int endOfLife
 * @return OAuth\Token
 */
PHP_METHOD(OAuth_Token, setEndOfLife) {

	zval *endOfLife_param = NULL, *_0;
	int endOfLife;

	zephir_fetch_params(0, 1, 0, &endOfLife_param);

		endOfLife = zephir_get_intval(endOfLife_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, endOfLife);
	zephir_update_property_zval(this_ptr, SL("endOfLife"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the token lifetime.
 *
 * @param int lifetime
 * @return OAuth\Token
 */
PHP_METHOD(OAuth_Token, setLifetime) {

	zval *lifetime_param = NULL;
	int lifetime;

	zephir_fetch_params(0, 1, 0, &lifetime_param);

		lifetime = zephir_get_intval(lifetime_param);


	RETURN_THISW();

}

