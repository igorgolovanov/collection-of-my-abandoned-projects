
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_V1_Token) {

	ZEPHIR_REGISTER_CLASS_EX(OAuth\\V1, Token, oauth, v1_token, oauth_token_ce, oauth_v1_token_method_entry, 0);

	zend_declare_property_null(oauth_v1_token_ce, SL("accessTokenSecret"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_v1_token_ce, SL("requestTokenSecret"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_v1_token_ce, SL("requestToken"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_v1_token_ce TSRMLS_CC, 1, oauth_v1_tokeninterface_ce);

	return SUCCESS;

}

/**
 * Gets the secret for access token
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Token, getAccessTokenSecret) {


	RETURN_MEMBER(this_ptr, "accessTokenSecret");

}

/**
 * Sets the secret for access token
 *
 * @param string tokenSecret Secret for access token
 * @return OAuth\V1\TokenInterface
 */
PHP_METHOD(OAuth_V1_Token, setAccessTokenSecret) {

	zval *tokenSecret_param = NULL;
	zval *tokenSecret = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokenSecret_param);

		zephir_get_strval(tokenSecret, tokenSecret_param);


	zephir_update_property_this(this_ptr, SL("accessTokenSecret"), tokenSecret TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the secret for request token
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Token, getRequestTokenSecret) {


	RETURN_MEMBER(this_ptr, "requestTokenSecret");

}

/**
 * Sets the secret for request token
 *
 * @param string tokenSecret Secret for request token
 * @return OAuth\V1\TokenInterface
 */
PHP_METHOD(OAuth_V1_Token, setRequestTokenSecret) {

	zval *tokenSecret_param = NULL;
	zval *tokenSecret = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokenSecret_param);

		zephir_get_strval(tokenSecret, tokenSecret_param);


	zephir_update_property_this(this_ptr, SL("requestTokenSecret"), tokenSecret TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the request token.
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Token, getRequestToken) {


	RETURN_MEMBER(this_ptr, "requestToken");

}

/**
 * Sets the request token.
 *
 * @param string token
 * @return OAuth\V1\TokenInterface
 */
PHP_METHOD(OAuth_V1_Token, setRequestToken) {

	zval *token_param = NULL;
	zval *token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);

		zephir_get_strval(token, token_param);


	zephir_update_property_this(this_ptr, SL("requestToken"), token TSRMLS_CC);
	RETURN_THIS();

}

