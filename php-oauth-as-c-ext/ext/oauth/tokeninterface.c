
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_TokenInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth, TokenInterface, oauth, tokeninterface, oauth_tokeninterface_method_entry);

	zend_declare_class_constant_long(oauth_tokeninterface_ce, SL("LIFETIME_UNKNOWN"), -9001 TSRMLS_CC);
	zend_declare_class_constant_long(oauth_tokeninterface_ce, SL("LIFETIME_NEVER_EXPIRES"), -9002 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the access token.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, getAccessToken);

/**
 * Sets the access token
 *
 * @param string token
 * @return OAuth\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, setAccessToken);

/**
 * Gets the refresh token
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, getRefreshToken);

/**
 * Sets the refresh token
 *
 * @param string token
 * @return OAuth\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, setRefreshToken);

/**
 * Gets the end of token life
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, getEndOfLife);

/**
 * Sets the end of token life
 *
 * @param int endOfLife
 * @return OAuth\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, setEndOfLife);

/**
 * Sets the token lifetime.
 *
 * @param int lifetime
 * @return OAuth\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenInterface, setLifetime);

