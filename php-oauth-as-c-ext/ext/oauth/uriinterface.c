
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
ZEPHIR_INIT_CLASS(OAuth_UriInterface) {

	ZEPHIR_REGISTER_INTERFACE(OAuth, UriInterface, oauth, uriinterface, oauth_uriinterface_method_entry);


	return SUCCESS;

}

/**
 * Gets the schema
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getScheme);

/**
 * Sets the schema
 *
 * @param string scheme
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setScheme);

/**
 * Gets the host
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getHost);

/**
 * Sets the host
 *
 * @param string host
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setHost);

/**
 * Gets the port
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getPort);

/**
 * Sets the port
 *
 * @param int port
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setPort);

/**
 * Gets the path 
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getPath);

/**
 * Sets the path
 *
 * @param string path
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setPath);

/**
 * Gets the query
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getQuery);

/**
 * Sets the query
 *
 * @param string query
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setQuery);

/**
 * Adds a param to the query string.
 *
 * @param string name
 * @param string value
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, addToQuery);

/**
 * Gets the fragment.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getFragment);

/**
 * Should return URI user info, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getUserInfo);

/**
 * Sets the user info.
 *
 * @param string userInfo
 * @return OAuth\UriInterface
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, setUserInfo);

/**
 * Should return the URI Authority, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getAuthority);

/**
 * Should return the URI string, masking protected user info data according to rfc3986-3.2.1
 *
 * @return string the URI string with user protected info masked
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, __toString);

/**
 * Should return the URI Authority without masking protected user info data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getRawAuthority);

/**
 * Should return the URI user info without masking protected user info data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getRawUserInfo);

/**
 * Build the full URI based on all the properties
 *
 * @return string The full URI without masking user info
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getAbsoluteUri);

/**
 * Build the relative URI based on all the properties
 *
 * @return string The relative URI
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, getRelativeUri);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, hasExplicitTrailingHostSlash);

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(OAuth_UriInterface, hasExplicitPortSpecified);

