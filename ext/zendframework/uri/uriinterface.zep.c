
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Interface defining a URI
 */
ZEPHIR_INIT_CLASS(ZendFramework_Uri_UriInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Uri, UriInterface, zendframework, uri_uriinterface, zendframework_uri_uriinterface_method_entry);

	return SUCCESS;

}

/**
 * Create a new URI object
 *
 * @param  Uri|string|null $uri
 * @throws Exception\InvalidArgumentException
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, __construct);

/**
 * Check if the URI is valid
 *
 * Note that a relative URI may still be valid
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, isValid);

/**
 * Check if the URI is a valid relative URI
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, isValidRelative);

/**
 * Check if the URI is an absolute or relative URI
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, isAbsolute);

/**
 * Parse a URI string
 *
 * @param  string $uri
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, parse);

/**
 * Compose the URI into a string
 *
 * @return string
 * @throws Exception\InvalidUriException
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, toString);

/**
 * Normalize the URI
 *
 * Normalizing a URI includes removing any redundant parent directory or
 * current directory references from the path (e.g. foo/bar/../baz becomes
 * foo/baz), normalizing the scheme case, decoding any over-encoded
 * characters etc.
 *
 * Eventually, two normalized URLs pointing to the same resource should be
 * equal even if they were originally represented by two different strings
 *
 * @return Uri
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, normalize);

/**
 * Convert the link to a relative link by substracting a base URI
 *
 *  This is the opposite of resolving a relative link - i.e. creating a
 *  relative reference link from an original URI and a base URI.
 *
 *  If the two URIs do not intersect (e.g. the original URI is not in any
 *  way related to the base URI) the URI will not be modified.
 *
 * @param  UriInterface|string $baseUri
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, makeRelative);

/**
 * Get the scheme part of the URI
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getScheme);

/**
 * Get the User-info (usually user:password) part
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getUserInfo);

/**
 * Get the URI host
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getHost);

/**
 * Get the URI port
 *
 * @return int|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getPort);

/**
 * Get the URI path
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getPath);

/**
 * Get the URI query
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getQuery);

/**
 * Return the query string as an associative array of key => value pairs
 *
 * This is an extension to RFC-3986 but is quite useful when working with
 * most common URI types
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getQueryAsArray);

/**
 * Get the URI fragment
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, getFragment);

/**
 * Set the URI scheme
 *
 * If the scheme is not valid according to the generic scheme syntax or
 * is not acceptable by the specific URI class (e.g. 'http' or 'https' are
 * the only acceptable schemes for the Zend\Uri\Http class) an exception
 * will be thrown.
 *
 * You can check if a scheme is valid before setting it using the
 * validateScheme() method.
 *
 * @param  string $scheme
 * @throws Exception\InvalidUriPartException
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setScheme);

/**
 * Set the URI User-info part (usually user:password)
 *
 * @param  string $userInfo
 * @return UriInterface
 * @throws Exception\InvalidUriPartException If the schema definition
 * does not have this part
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setUserInfo);

/**
 * Set the URI host
 *
 * Note that the generic syntax for URIs allows using host names which
 * are not necessarily IPv4 addresses or valid DNS host names. For example,
 * IPv6 addresses are allowed as well, and also an abstract "registered name"
 * which may be any name composed of a valid set of characters, including,
 * for example, tilda (~) and underscore (_) which are not allowed in DNS
 * names.
 *
 * Subclasses of Uri may impose more strict validation of host names - for
 * example the HTTP RFC clearly states that only IPv4 and valid DNS names
 * are allowed in HTTP URIs.
 *
 * @param  string $host
 * @throws Exception\InvalidUriPartException
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setHost);

/**
 * Set the port part of the URI
 *
 * @param  int $port
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setPort);

/**
 * Set the path
 *
 * @param  string $path
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setPath);

/**
 * Set the query string
 *
 * If an array is provided, will encode this array of parameters into a
 * query string. Array values will be represented in the query string using
 * PHP's common square bracket notation.
 *
 * @param  string|array $query
 * @return UriInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setQuery);

/**
 * Set the URI fragment part
 *
 * @param  string $fragment
 * @return UriInterface
 * @throws Exception\InvalidUriPartException If the schema definition
 * does not have this part
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, setFragment);

/**
 * Magic method to convert the URI to a string
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Uri_UriInterface, __toString);

