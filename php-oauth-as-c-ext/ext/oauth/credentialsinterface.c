
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
ZEPHIR_INIT_CLASS(OAuth_CredentialsInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth, CredentialsInterface, oauth, credentialsinterface, oauth_credentialsinterface_method_entry);


	return SUCCESS;

}

/**
 * Gets the callback url
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_CredentialsInterface, getCallbackUrl);

/**
 * Gets the consumer ID
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_CredentialsInterface, getConsumerId);

/**
 * Gets the consumer secret
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_CredentialsInterface, getConsumerSecret);

