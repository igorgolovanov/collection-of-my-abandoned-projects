
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
/**
 * Interface provides common methods among all OAuth services.
 */
ZEPHIR_INIT_CLASS(OAuth_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth, ServiceInterface, oauth, serviceinterface, oauth_serviceinterface_method_entry);


	return SUCCESS;

}

/**
 * Sends an authenticated API request to the path provided.
 * If the path provided is not an absolute URI, the base API Uri (service-specific) will be used.
 *
 * @param string|UriInterface path
 * @param string              method       HTTP method
 * @param array               body         Request body if applicable (an associative array will
 *                                          automatically be converted into a urlencoded body)
 * @param array               extraHeaders Extra headers if applicable. These will override service-specific
 *                                          any defaults.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_ServiceInterface, request);

/**
 * Returns the url to redirect to for authorization purposes.
 *
 * @param array params
 *
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_ServiceInterface, getAuthorizationUri);

/**
 * Returns the authorization API endpoint.
 *
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_ServiceInterface, getAuthorizationEndpoint);

/**
 * Returns the access token API endpoint.
 *
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_ServiceInterface, getAccessTokenEndpoint);

