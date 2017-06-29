
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
#include "kernel/memory.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * @author Igor Golovanov
 *
 */
ZEPHIR_INIT_CLASS(OAuth_Service) {

	ZEPHIR_REGISTER_CLASS(OAuth, Service, oauth, service, oauth_service_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

/**
     * @var OAuth\CredentialsInterface
     */
	zend_declare_property_null(oauth_service_ce, SL("credentials"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var OAuth\ClientInterface
     */
	zend_declare_property_null(oauth_service_ce, SL("client"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
     * @var OAuth\TokenStorageInterface
     */
	zend_declare_property_null(oauth_service_ce, SL("storage"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_service_ce TSRMLS_CC, 1, oauth_serviceinterface_ce);

	return SUCCESS;

}

/**
 * @param OAuth\CredentialsInterface credentials
 * @param OAuth\ClientInterface client
 * @param OAuth\TokenStorageInterface storage
 */
PHP_METHOD(OAuth_Service, __construct) {

	zval *credentials, *client, *storage;

	zephir_fetch_params(0, 3, 0, &credentials, &client, &storage);



	zephir_update_property_this(this_ptr, SL("credentials"), credentials TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("client"), client TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

/**
 * Gets the credentials
 *
 * @return OAuth\CredentialsInterface
 */
PHP_METHOD(OAuth_Service, getCredentials) {


	RETURN_MEMBER(this_ptr, "credentials");

}

/**
 * Gets the client
 *
 * @return OAuth\ClientInterface
 */
PHP_METHOD(OAuth_Service, getClient) {


	RETURN_MEMBER(this_ptr, "client");

}

/**
 * Gets the token storage
 *
 * @return OAuth\TokenStorageInterface
 */
PHP_METHOD(OAuth_Service, getTokenStorage) {


	RETURN_MEMBER(this_ptr, "storage");

}

