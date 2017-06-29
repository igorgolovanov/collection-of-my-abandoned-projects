
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(OAuth_TokenStorage_Memory) {

	ZEPHIR_REGISTER_CLASS(OAuth\\TokenStorage, Memory, oauth, tokenstorage_memory, oauth_tokenstorage_memory_method_entry, 0);

	zend_declare_property_null(oauth_tokenstorage_memory_ce, SL("tokens"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(oauth_tokenstorage_memory_ce TSRMLS_CC, 1, oauth_tokenstorageinterface_ce);

	return SUCCESS;

}

PHP_METHOD(OAuth_TokenStorage_Memory, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("tokens"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(OAuth_TokenStorage_Memory, retrieveAccessToken) {

	zval *service_param = NULL, *hasAccess, *_0, *_1;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

		zephir_get_strval(service, service_param);


	ZEPHIR_INIT_VAR(hasAccess);
	zephir_call_method_p1(hasAccess, this_ptr, "hasaccesstoken", service);
	if (zephir_is_true(hasAccess)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokens"), PH_NOISY_CC);
		zephir_array_fetch(&_1, _0, service, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_1);
	}
	ZEPHIR_THROW_EXCEPTION_STR(oauth_tokennotfoundexception_ce, "Token not stored");
	return;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(OAuth_TokenStorage_Memory, storeAccessToken) {

	zval *service_param = NULL, *token;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &service_param, &token);

		zephir_get_strval(service, service_param);


	zephir_update_property_array(this_ptr, SL("tokens"), service, token TSRMLS_CC);
	RETURN_THIS();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(OAuth_TokenStorage_Memory, hasAccessToken) {

	zval *service_param = NULL, *token, *_0;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

		zephir_get_strval(service, service_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokens"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&token, _0, service, 1 TSRMLS_CC)) {
		if (zephir_is_instance_of(token, SL("OAuth\\TokenInterface") TSRMLS_CC)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(OAuth_TokenStorage_Memory, clearToken) {

	zval *service, *_0;

	zephir_fetch_params(0, 1, 0, &service);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("tokens"), PH_NOISY_CC);
	if (zephir_array_isset(_0, service)) {
	}
	RETURN_THISW();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(OAuth_TokenStorage_Memory, clearAllTokens) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("tokens"), _0 TSRMLS_CC);
	RETURN_THIS();

}

