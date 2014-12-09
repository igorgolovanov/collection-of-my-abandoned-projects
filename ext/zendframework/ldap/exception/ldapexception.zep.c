
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Ldap_Exception_LdapException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Ldap\\Exception, LdapException, zendframework, ldap_exception_ldapexception, zend_exception_get_default(TSRMLS_C), zendframework_ldap_exception_ldapexception_method_entry, 0);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SUCCESS"), 0x00 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OPERATIONS_ERROR"), 0x01 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PROTOCOL_ERROR"), 0x02 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TIMELIMIT_EXCEEDED"), 0x03 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SIZELIMIT_EXCEEDED"), 0x04 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_COMPARE_FALSE"), 0x05 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_COMPARE_TRUE"), 0x06 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AUTH_METHOD_NOT_SUPPORTED"), 0x07 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_STRONG_AUTH_REQUIRED"), 0x08 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PARTIAL_RESULTS"), 0x09 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_REFERRAL"), 0x0a TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ADMINLIMIT_EXCEEDED"), 0x0b TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNAVAILABLE_CRITICAL_EXTENSION"), 0x0c TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONFIDENTIALITY_REQUIRED"), 0x0d TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SASL_BIND_IN_PROGRESS"), 0x0e TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_ATTRIBUTE"), 0x10 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNDEFINED_TYPE"), 0x11 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INAPPROPRIATE_MATCHING"), 0x12 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONSTRAINT_VIOLATION"), 0x13 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TYPE_OR_VALUE_EXISTS"), 0x14 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_SYNTAX"), 0x15 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_OBJECT"), 0x20 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALIAS_PROBLEM"), 0x21 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_DN_SYNTAX"), 0x22 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_IS_LEAF"), 0x23 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALIAS_DEREF_PROBLEM"), 0x24 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PROXY_AUTHZ_FAILURE"), 0x2F TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INAPPROPRIATE_AUTH"), 0x30 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_CREDENTIALS"), 0x31 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INSUFFICIENT_ACCESS"), 0x32 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_BUSY"), 0x33 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNAVAILABLE"), 0x34 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNWILLING_TO_PERFORM"), 0x35 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_LOOP_DETECT"), 0x36 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NAMING_VIOLATION"), 0x40 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OBJECT_CLASS_VIOLATION"), 0x41 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_ALLOWED_ON_NONLEAF"), 0x42 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_ALLOWED_ON_RDN"), 0x43 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALREADY_EXISTS"), 0x44 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_OBJECT_CLASS_MODS"), 0x45 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_RESULTS_TOO_LARGE"), 0x46 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AFFECTS_MULTIPLE_DSAS"), 0x47 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OTHER"), 0x50 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SERVER_DOWN"), 0x51 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_LOCAL_ERROR"), 0x52 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ENCODING_ERROR"), 0x53 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_DECODING_ERROR"), 0x54 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TIMEOUT"), 0x55 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AUTH_UNKNOWN"), 0x56 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_FILTER_ERROR"), 0x57 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_USER_CANCELLED"), 0x58 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PARAM_ERROR"), 0x59 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_MEMORY"), 0x5a TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONNECT_ERROR"), 0x5b TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_SUPPORTED"), 0x5c TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONTROL_NOT_FOUND"), 0x5d TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_RESULTS_RETURNED"), 0x5e TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_MORE_RESULTS_TO_RETURN"), 0x5f TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CLIENT_LOOP"), 0x60 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_REFERRAL_LIMIT_EXCEEDED"), 0x61 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_RESOURCES_EXHAUSTED"), 0x71 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_SECURITY_VIOLATION"), 0x72 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_INVALID_DATA"), 0x73 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_UNSUPPORTED_SCHEME"), 0x74 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_RELOAD_REQUIRED"), 0x75 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CANCELLED"), 0x76 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_OPERATION"), 0x77 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TOO_LATE"), 0x78 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CANNOT_CANCEL"), 0x79 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ASSERTION_FAILED"), 0x7A TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SYNC_REFRESH_REQUIRED"), 0x1000 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_SYNC_REFRESH_REQUIRED"), 0x4100 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_NO_OPERATION"), 0x410e TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_ASSERTION_FAILED"), 0x410f TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_NO_REFERRALS_FOUND"), 0x4110 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_CANNOT_CHAIN"), 0x4111 TSRMLS_CC);

	/* internal error code constants */
	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_DOMAIN_MISMATCH"), 0x7001 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_EXTENSION_NOT_LOADED"), 0x7002 TSRMLS_CC);

	zend_class_implements(zendframework_ldap_exception_ldapexception_ce TSRMLS_CC, 1, zendframework_ldap_exception_exceptioninterface_ce);
	return SUCCESS;

}

/**
 * @param Ldap   $ldap Zend\Ldap\Ldap object
 * @param string $str  Informative exception message
 * @param int    $code LDAP error code
 */
PHP_METHOD(ZendFramework_Ldap_Exception_LdapException, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int code, ZEPHIR_LAST_CALL_STATUS;
	zval *str = NULL;
	zval *ldap = NULL, *str_param = NULL, *code_param = NULL, *errors, *message = NULL, *oldCode, *_0 = NULL, *_1 = NULL, _2, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &ldap, &str_param, &code_param);

	if (!ldap) {
		ldap = ZEPHIR_GLOBAL(global_null);
	}
	if (!str_param) {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	} else {
		zephir_get_strval(str, str_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	ZEPHIR_INIT_VAR(errors);
	array_init(errors);
	ZEPHIR_INIT_VAR(message);
	ZVAL_STRING(message, "", 1);


	if (Z_TYPE_P(ldap) != IS_NULL) {
		ZEPHIR_INIT_VAR(oldCode);
		ZVAL_LONG(oldCode, code);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, code);
		ZEPHIR_CALL_METHOD(&_0, ldap, "getlasterror", NULL, _1, errors);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_VS(message, _0, ": ");
		if (code == 0) {
			ZEPHIR_INIT_NVAR(message);
			ZVAL_STRING(message, "", 1);
			code = zephir_get_numberval(oldCode);
		}
	}
	if (ZEPHIR_IS_EMPTY(message)) {
		if (code > 0) {
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_LONG(&_2, code);
			ZEPHIR_CALL_FUNCTION(&_0, "dechex", &_3, &_2);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "0x", _0, ": ");
			zephir_concat_self(&message, _4 TSRMLS_CC);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(str))) {
		zephir_concat_self(&message, str TSRMLS_CC);
	} else {
		zephir_concat_self_str(&message, SL("no exception message") TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, code);
	ZEPHIR_CALL_PARENT(NULL, zendframework_ldap_exception_ldapexception_ce, this_ptr, "__construct", NULL, message, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

