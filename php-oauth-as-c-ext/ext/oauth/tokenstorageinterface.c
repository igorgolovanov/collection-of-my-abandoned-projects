
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
ZEPHIR_INIT_CLASS(OAuth_TokenStorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth, TokenStorageInterface, oauth, tokenstorageinterface, oauth_tokenstorageinterface_method_entry);


	return SUCCESS;

}

/**
 * @param string $service
 *
 * @return TokenInterface
 *
 * @throws TokenNotFoundException
 */
ZEPHIR_DOC_METHOD(OAuth_TokenStorageInterface, retrieveAccessToken);

/**
 * @param string service
 * @param OAuth\TokenInterface token
 *
 * @return TokenStorageInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenStorageInterface, storeAccessToken);

/**
 * @param string service
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(OAuth_TokenStorageInterface, hasAccessToken);

/**
 * Delete the users token. Aka, log out.
 *
 * @param string service
 *
 * @return TokenStorageInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenStorageInterface, clearToken);

/**
 * Delete *ALL* user tokens. Use with care. Most of the time you will likely
 * want to use clearToken() instead.
 *
 * @return TokenStorageInterface
 */
ZEPHIR_DOC_METHOD(OAuth_TokenStorageInterface, clearAllTokens);

