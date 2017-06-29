
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
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_TokenExpiredException) {

	ZEPHIR_REGISTER_CLASS_EX(OAuth, TokenExpiredException, oauth, tokenexpiredexception, zend_exception_get_default(TSRMLS_C), oauth_tokenexpiredexception_method_entry, 0);

/**
	 * Token
	 *
	 * @var string
	 */
	zend_declare_property_null(oauth_tokenexpiredexception_ce, SL("token"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_tokenexpiredexception_ce TSRMLS_CC, 1, oauth_exceptioninterface_ce);

	return SUCCESS;

}

/**
 * @param string token Expired token
 * @param string message
 * @param int code
 * @param Exception previous
 */
PHP_METHOD(OAuth_TokenExpiredException, __construct) {

	int code;
	zval *token_param = NULL, *message_param = NULL, *code_param = NULL, *previous = NULL, *_0;
	zval *token = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &token_param, &message_param, &code_param, &previous);

		zephir_get_strval(token, token_param);
	if (!message_param) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
		zephir_get_strval(message, message_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!previous) {
		previous = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, code);
	zephir_call_parent_p3_noret(this_ptr, oauth_tokenexpiredexception_ce, "__construct", message, _0, previous);
	zephir_update_property_this(this_ptr, SL("token"), token TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the expired token
 *
 * @return string
 */
PHP_METHOD(OAuth_TokenExpiredException, getToken) {


	RETURN_MEMBER(this_ptr, "token");

}

