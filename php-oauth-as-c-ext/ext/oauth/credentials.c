
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_Credentials) {

	ZEPHIR_REGISTER_CLASS(OAuth, Credentials, oauth, credentials, oauth_credentials_method_entry, 0);

	zend_declare_property_null(oauth_credentials_ce, SL("consumerId"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_credentials_ce, SL("consumerSecret"), ZEND_ACC_PRIVATE TSRMLS_CC);
	zend_declare_property_null(oauth_credentials_ce, SL("callbackUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_credentials_ce TSRMLS_CC, 1, oauth_credentialsinterface_ce);

	return SUCCESS;

}

/**
 * @param string consumerId
 * @param string consumerSecret
 * @param string callbackUrl
 */
PHP_METHOD(OAuth_Credentials, __construct) {

	zval *consumerId_param = NULL, *consumerSecret_param = NULL, *callbackUrl_param = NULL;
	zval *consumerId = NULL, *consumerSecret = NULL, *callbackUrl = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &consumerId_param, &consumerSecret_param, &callbackUrl_param);

		zephir_get_strval(consumerId, consumerId_param);
		zephir_get_strval(consumerSecret, consumerSecret_param);
	if (Z_TYPE_P(callbackUrl_param) != IS_STRING && Z_TYPE_P(callbackUrl_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'callbackUrl' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(callbackUrl_param) == IS_STRING) {
		callbackUrl = callbackUrl_param;
	} else {
		ZEPHIR_INIT_VAR(callbackUrl);
		ZVAL_EMPTY_STRING(callbackUrl);
	}


	zephir_update_property_this(this_ptr, SL("consumerId"), consumerId TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("consumerSecret"), consumerSecret TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("callbackUrl"), callbackUrl TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the callback url
 *
 * @return string
 */
PHP_METHOD(OAuth_Credentials, getCallbackUrl) {


	RETURN_MEMBER(this_ptr, "callbackUrl");

}

/**
 * Gets the consumer ID
 *
 * @return string
 */
PHP_METHOD(OAuth_Credentials, getConsumerId) {


	RETURN_MEMBER(this_ptr, "consumerId");

}

/**
 * Gets the consumer secret
 *
 * @return string
 */
PHP_METHOD(OAuth_Credentials, getConsumerSecret) {


	RETURN_MEMBER(this_ptr, "consumerSecret");

}

