
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
ZEPHIR_INIT_CLASS(OAuth_V1_SignatureInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth\\V1, SignatureInterface, oauth, v1_signatureinterface, oauth_v1_signatureinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the algorithm for hashing
 * 
 * @param string algorithm
 */
ZEPHIR_DOC_METHOD(OAuth_V1_SignatureInterface, setHashingAlgorithm);

/**
 * Sets the secret for token
 * 
 * @param string tokenSecret
 */
ZEPHIR_DOC_METHOD(OAuth_V1_SignatureInterface, setTokenSecret);

/**
 * Gets the signature.
 *
 * @param OAuth\UriInterface uri
 * @param array params
 * @param string method
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_V1_SignatureInterface, getSignature);

