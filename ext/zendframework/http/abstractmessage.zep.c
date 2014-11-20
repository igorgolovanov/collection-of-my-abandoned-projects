
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * HTTP standard message (Request/Response)
 *
 * @link      http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4
 */
ZEPHIR_INIT_CLASS(ZendFramework_Http_AbstractMessage) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http, AbstractMessage, zendframework, http_abstractmessage, zendframework_stdlib_message_ce, zendframework_http_abstractmessage_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(zendframework_http_abstractmessage_ce, SL("version"), "1.1", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var Headers|null
	 */
	zend_declare_property_null(zendframework_http_abstractmessage_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**#@+
	 * @const string Version constant numbers
	 */
	zend_declare_class_constant_string(zendframework_http_abstractmessage_ce, SL("VERSION_10"), "1.0" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_http_abstractmessage_ce, SL("VERSION_11"), "1.1" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set the HTTP version for this object, one of 1.0 or 1.1
 * (AbstractMessage::VERSION_10, AbstractMessage::VERSION_11)
 *
 * @param  string $version (Must be 1.0 or 1.1)
 * @return AbstractMessage
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Http_AbstractMessage, setVersion) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *version_param = NULL, *_1;
	zval *version = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version_param);

	zephir_get_strval(version, version_param);


	_0 = !ZEPHIR_IS_STRING(version, "1.0");
	if (_0) {
		_0 = !ZEPHIR_IS_STRING(version, "1.1");
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SV(exceptionMsg, "Not valid or not supported HTTP version: ", version);
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_http_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendframework/http/abstractmessage.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("version"), version TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return the HTTP version for this request
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_AbstractMessage, getVersion) {


	RETURN_MEMBER(this_ptr, "version");

}

/**
 * Provide an alternate Parameter Container implementation for headers in this object,
 * (this is NOT the primary API for value setting, for that see getHeaders())
 *
 * @see    getHeaders()
 * @param  Headers $headers
 * @return AbstractMessage
 */
PHP_METHOD(ZendFramework_Http_AbstractMessage, setHeaders) {

	zval *headers;

	zephir_fetch_params(0, 1, 0, &headers);



	if (!(zephir_instance_of_ev(headers, zendframework_http_headers_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'headers' must be an instance of 'ZendFramework\\Http\\Headers'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("headers"), headers TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Return the header container responsible for headers
 *
 * @return Headers
 */
PHP_METHOD(ZendFramework_Http_AbstractMessage, getHeaders) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _1;
	zval *headers = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(headers, _0);
	_1 = Z_TYPE_P(headers) == IS_NULL;
	if (!(_1)) {
		_1 = Z_TYPE_P(headers) == IS_STRING;
	}
	if (_1) {
		if (Z_TYPE_P(headers) == IS_STRING) {
			ZEPHIR_CALL_CE_STATIC(&_2, zendframework_http_headers_ce, "fromstring", &_3, headers);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(headers, _2);
		} else {
			ZEPHIR_INIT_NVAR(headers);
			object_init_ex(headers, zendframework_http_headers_ce);
			if (zephir_has_constructor(headers TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, headers, "__construct", NULL);
				zephir_check_call_status();
			}
		}
		zephir_update_property_this(this_ptr, SL("headers"), headers TSRMLS_CC);
	}
	RETURN_CCTOR(headers);

}

/**
 * Allow PHP casting of this object
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Http_AbstractMessage, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tostring", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

