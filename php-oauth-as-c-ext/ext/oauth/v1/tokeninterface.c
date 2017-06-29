
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
ZEPHIR_INIT_CLASS(OAuth_V1_TokenInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(OAuth\\V1, TokenInterface, oauth, v1_tokeninterface, oauth_tokeninterface_ce, oauth_v1_tokeninterface_method_entry);


	return SUCCESS;

}

/**
 * Gets the secret for access token
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, getAccessTokenSecret);

/**
 * Sets the secret for access token
 *
 * @param string tokenSecret Secret for access token
 * @return OAuth\V1\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, setAccessTokenSecret);

/**
 * Gets the secret for request token
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, getRequestTokenSecret);

/**
 * Sets the secret for request token
 *
 * @param string tokenSecret Secret for request token
 * @return OAuth\V1\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, setRequestTokenSecret);

/**
 * Gets the request token.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, getRequestToken);

/**
 * Sets the request token.
 *
 * @param string token
 * @return OAuth\V1\TokenInterface
 */
ZEPHIR_DOC_METHOD(OAuth_V1_TokenInterface, setRequestToken);

