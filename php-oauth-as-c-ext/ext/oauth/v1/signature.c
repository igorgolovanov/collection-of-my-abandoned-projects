
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_V1_Signature) {

	ZEPHIR_REGISTER_CLASS(OAuth\\V1, Signature, oauth, v1_signature, oauth_v1_signature_method_entry, 0);

/**
* @var Credentials
*/
	zend_declare_property_null(oauth_v1_signature_ce, SL("credentials"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
* @var string
*/
	zend_declare_property_null(oauth_v1_signature_ce, SL("algorithm"), ZEND_ACC_PRIVATE TSRMLS_CC);
/**
* @var string
*/
	zend_declare_property_null(oauth_v1_signature_ce, SL("tokenSecret"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(oauth_v1_signature_ce TSRMLS_CC, 1, oauth_v1_signatureinterface_ce);

	return SUCCESS;

}

/**
 * @param OAuth\CredentialsInterface credentials
 */
PHP_METHOD(OAuth_V1_Signature, __construct) {

	zval *credentials;

	zephir_fetch_params(0, 1, 0, &credentials);



	zephir_update_property_this(this_ptr, SL("credentials"), credentials TSRMLS_CC);

}

/**
 * Sets the algorithm for hashing
 * 
 * @param string algorithm
 */
PHP_METHOD(OAuth_V1_Signature, setHashingAlgorithm) {

	zval *algorithm_param = NULL;
	zval *algorithm = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &algorithm_param);

		zephir_get_strval(algorithm, algorithm_param);


	zephir_update_property_this(this_ptr, SL("algorithm"), algorithm TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the secret for token
 * 
 * @param string tokenSecret
 */
PHP_METHOD(OAuth_V1_Signature, setTokenSecret) {

	zval *tokenSecret_param = NULL;
	zval *tokenSecret = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tokenSecret_param);

		zephir_get_strval(tokenSecret, tokenSecret_param);


	zephir_update_property_this(this_ptr, SL("tokenSecret"), tokenSecret TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Gets the secret for token
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, getTokenSecret) {


	RETURN_MEMBER(this_ptr, "tokenSecret");

}

/**
 * Gets the signature
 *
 * @param OAuth\UriInterface uri
 * @param array params
 * @param string method
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, getSignature) {

	HashTable *_4;
	HashPosition _3;
	zend_class_entry *_1;
	zval *method = NULL;
	zval *uri, *params, *method_param = NULL, *signature, *signatureData, *signatureString, *signatureStringEncoded, *query, *queryStringData = NULL, *queryStringKey = NULL, *queryStringValue = NULL, *queryStringKeyEncoded = NULL, *queryStringValueEncoded = NULL, *scheme, *authority, *path, *hasExplicitTrailingHostSlash, *baseUri, *baseUriEncoded, *dataString, *dataHash, *_0 = NULL, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &uri, &params, &method_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(method);
		ZVAL_STRING(method, "POST", 1);
	} else {
		zephir_get_strval(method, method_param);
	}


	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, uri, "getquery");
	ZEPHIR_INIT_VAR(queryStringData);
	array_init(queryStringData);
	ZEPHIR_INIT_VAR(signatureData);
	array_init(signatureData);
	if ((Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "The params must be an Array", 1);
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_array_merge(_0, &(queryStringData), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(queryStringData, _0);
	Z_SET_ISREF_P(queryStringData);
	zephir_call_func_p2_noret("parse_str", query, queryStringData);
	Z_UNSET_ISREF_P(queryStringData);
	zephir_is_iterable(queryStringData, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(queryStringKey, _4, _3);
		ZEPHIR_GET_HVALUE(queryStringValue, _5);
		ZEPHIR_INIT_NVAR(queryStringKeyEncoded);
		zephir_call_func_p1(queryStringKeyEncoded, "rawurlencode", queryStringKey);
		ZEPHIR_INIT_NVAR(queryStringValueEncoded);
		zephir_call_func_p1(queryStringValueEncoded, "rawurlencode", queryStringValue);
		zephir_array_update_zval(&signatureData, queryStringKeyEncoded, &queryStringValueEncoded, PH_COPY | PH_SEPARATE);
	}
	Z_SET_ISREF_P(signatureData);
	zephir_call_func_p1_noret("ksort", signatureData);
	Z_UNSET_ISREF_P(signatureData);
	ZEPHIR_INIT_VAR(scheme);
	zephir_call_method(scheme, uri, "getscheme");
	ZEPHIR_INIT_VAR(authority);
	zephir_call_method(authority, uri, "getrawauthority");
	ZEPHIR_INIT_VAR(path);
	zephir_call_method(path, uri, "getpath");
	ZEPHIR_INIT_VAR(hasExplicitTrailingHostSlash);
	zephir_call_method(hasExplicitTrailingHostSlash, uri, "hasexplicittrailinghostslash");
	ZEPHIR_INIT_VAR(baseUri);
	ZEPHIR_CONCAT_VSV(baseUri, scheme, "://", authority);
	if (ZEPHIR_IS_STRING(path, "/")) {
		if (zephir_is_true(hasExplicitTrailingHostSlash)) {
			zephir_concat_self_str(&baseUri, SL("/") TSRMLS_CC);
		}
	} else {
		zephir_concat_self(&baseUri, path TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(baseUriEncoded);
	zephir_call_func_p1(baseUriEncoded, "rawurlencode", baseUri);
	ZEPHIR_INIT_VAR(signatureString);
	zephir_call_method_p1(signatureString, this_ptr, "buildsignaturestring", signatureData);
	ZEPHIR_INIT_VAR(signatureStringEncoded);
	zephir_call_func_p1(signatureStringEncoded, "rawurlencode", signatureString);
	ZEPHIR_INIT_VAR(dataString);
	zephir_fast_strtoupper(dataString, method);
	ZEPHIR_INIT_BNVAR(dataString);
	ZEPHIR_CONCAT_VSVSV(dataString, dataString, "&", baseUriEncoded, "&", signatureStringEncoded);
	ZEPHIR_INIT_VAR(dataHash);
	zephir_call_method_p1(dataHash, this_ptr, "hash", dataString);
	ZEPHIR_INIT_VAR(signature);
	zephir_call_func_p1(signature, "base64_encode", dataHash);
	RETURN_CCTOR(signature);

}

/**
 * Build signature string from array.
 *
 * @param array signatureData
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, buildSignatureString) {

	HashTable *_4;
	HashPosition _3;
	zend_class_entry *_1;
	zval *signatureData, *signatureString = NULL, *delimiter = NULL, *key = NULL, *value = NULL, *_0, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &signatureData);



	if ((Z_TYPE_P(signatureData) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "The signatureData must be an Array", 1);
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(signatureString);
	ZVAL_STRING(signatureString, "", 1);
	ZEPHIR_INIT_VAR(delimiter);
	ZVAL_STRING(delimiter, "", 1);
	zephir_is_iterable(signatureData, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_INIT_NVAR(signatureString);
		ZEPHIR_CONCAT_VVSV(signatureString, delimiter, key, "=", value);
		ZEPHIR_INIT_NVAR(delimiter);
		ZVAL_STRING(delimiter, "&", 1);
	}
	RETURN_CCTOR(signatureString);

}

/**
 * Get hashing algorithm
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, getHashingAlgorithm) {


	RETURN_MEMBER(this_ptr, "algorithm");

}

/**
 * @return OAuth\CredentialsInterface
 */
PHP_METHOD(OAuth_V1_Signature, getCredentials) {


	RETURN_MEMBER(this_ptr, "credentials");

}

/**
 * Gets the signing key
 *
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, getSigningKey) {

	zval *signingKey, *credentials = NULL, *consumerSecret, *tokenSecret, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "getcredentials");
	ZEPHIR_CPY_WRT(credentials, _0);
	ZEPHIR_INIT_VAR(consumerSecret);
	zephir_call_method(consumerSecret, credentials, "getconsumersecret");
	ZEPHIR_INIT_VAR(tokenSecret);
	zephir_call_method(tokenSecret, this_ptr, "gettokensecret");
	ZEPHIR_INIT_BNVAR(_0);
	zephir_call_func_p1(_0, "rawurlencode", consumerSecret);
	ZEPHIR_INIT_VAR(signingKey);
	ZEPHIR_CONCAT_VS(signingKey, _0, "&");
	if (!(ZEPHIR_IS_EMPTY(tokenSecret))) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "rawurlencode", tokenSecret);
		zephir_concat_self(&signingKey, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(signingKey);

}

/**
 * Hash
 *
 * @param string data 
 * @return string
 */
PHP_METHOD(OAuth_V1_Signature, hash) {

	zval *data_param = NULL, *algorithm = NULL, *hash, *signingKey, *_0, _1, *_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

		zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(algorithm);
	zephir_call_method(algorithm, this_ptr, "gethashingalgorithm");
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, algorithm);
	ZEPHIR_CPY_WRT(algorithm, _0);
	do {
		if (ZEPHIR_IS_STRING(algorithm, "HMAC-SHA1")) {
			ZEPHIR_INIT_VAR(signingKey);
			zephir_call_method(signingKey, this_ptr, "getsigningkey");
			ZEPHIR_SINIT_VAR(_1);
			ZVAL_STRING(&_1, "sha1", 0);
			ZEPHIR_INIT_VAR(hash);
			zephir_call_func_p4(hash, "hash_hmac", &_1, data, signingKey, ZEPHIR_GLOBAL(global_true));
			break;
		}
		ZEPHIR_INIT_BNVAR(_0);
		object_init_ex(_0, oauth_v1_unsupportedhashalgorithmexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Unsupported hashing algorithm (", algorithm, ") used.");
		zephir_call_method_p2_noret(_0, "__construct", algorithm, _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_CCTOR(hash);

}

