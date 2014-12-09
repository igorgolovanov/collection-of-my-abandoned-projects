
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
#include "kernel/memory.h"
#include "kernel/operators.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Ldap_Exception_LdapException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Ldap\\Exception, LdapException, zendframework, ldap_exception_ldapexception, zend_exception_get_default(TSRMLS_C), zendframework_ldap_exception_ldapexception_method_entry, 0);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SUCCESS"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OPERATIONS_ERROR"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PROTOCOL_ERROR"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TIMELIMIT_EXCEEDED"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SIZELIMIT_EXCEEDED"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_COMPARE_FALSE"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_COMPARE_TRUE"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AUTH_METHOD_NOT_SUPPORTED"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_STRONG_AUTH_REQUIRED"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PARTIAL_RESULTS"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_REFERRAL"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ADMINLIMIT_EXCEEDED"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNAVAILABLE_CRITICAL_EXTENSION"), 12 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONFIDENTIALITY_REQUIRED"), 13 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SASL_BIND_IN_PROGRESS"), 14 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_ATTRIBUTE"), 16 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNDEFINED_TYPE"), 17 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INAPPROPRIATE_MATCHING"), 18 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONSTRAINT_VIOLATION"), 19 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TYPE_OR_VALUE_EXISTS"), 20 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_SYNTAX"), 21 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_OBJECT"), 32 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALIAS_PROBLEM"), 33 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_DN_SYNTAX"), 34 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_IS_LEAF"), 35 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALIAS_DEREF_PROBLEM"), 36 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PROXY_AUTHZ_FAILURE"), 47 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INAPPROPRIATE_AUTH"), 48 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INVALID_CREDENTIALS"), 49 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_INSUFFICIENT_ACCESS"), 50 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_BUSY"), 51 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNAVAILABLE"), 52 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_UNWILLING_TO_PERFORM"), 53 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_LOOP_DETECT"), 54 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NAMING_VIOLATION"), 64 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OBJECT_CLASS_VIOLATION"), 65 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_ALLOWED_ON_NONLEAF"), 66 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_ALLOWED_ON_RDN"), 67 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ALREADY_EXISTS"), 68 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_OBJECT_CLASS_MODS"), 69 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_RESULTS_TOO_LARGE"), 70 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AFFECTS_MULTIPLE_DSAS"), 71 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_OTHER"), 80 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SERVER_DOWN"), 81 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_LOCAL_ERROR"), 82 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ENCODING_ERROR"), 83 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_DECODING_ERROR"), 84 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TIMEOUT"), 85 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_AUTH_UNKNOWN"), 86 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_FILTER_ERROR"), 87 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_USER_CANCELLED"), 88 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_PARAM_ERROR"), 89 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_MEMORY"), 90 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONNECT_ERROR"), 91 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NOT_SUPPORTED"), 92 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CONTROL_NOT_FOUND"), 93 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_RESULTS_RETURNED"), 94 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_MORE_RESULTS_TO_RETURN"), 95 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CLIENT_LOOP"), 96 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_REFERRAL_LIMIT_EXCEEDED"), 97 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_RESOURCES_EXHAUSTED"), 113 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_SECURITY_VIOLATION"), 114 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_INVALID_DATA"), 115 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_UNSUPPORTED_SCHEME"), 116 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CUP_RELOAD_REQUIRED"), 117 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CANCELLED"), 118 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_NO_SUCH_OPERATION"), 119 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_TOO_LATE"), 120 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_CANNOT_CANCEL"), 121 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_ASSERTION_FAILED"), 122 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_SYNC_REFRESH_REQUIRED"), 4096 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_SYNC_REFRESH_REQUIRED"), 16640 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_NO_OPERATION"), 16654 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_ASSERTION_FAILED"), 16655 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_NO_REFERRALS_FOUND"), 16656 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_CANNOT_CHAIN"), 16657 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_DOMAIN_MISMATCH"), 28673 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_ldap_exception_ldapexception_ce, SL("LDAP_X_EXTENSION_NOT_LOADED"), 28674 TSRMLS_CC);

	zend_class_implements(zendframework_ldap_exception_ldapexception_ce TSRMLS_CC, 1, zendframework_ldap_exception_exceptioninterface_ce);
	return SUCCESS;

}

/**
 * @param Ldap   $ldap Zend\Ldap\Ldap object
 * @param string $str  Informative exception message
 * @param int    $code LDAP error code
 */
PHP_METHOD(ZendFramework_Ldap_Exception_LdapException, __construct) {

	int code;
	zval *str = NULL;
	zval *ldap = NULL, *str_param = NULL, *code_param = NULL;

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



}

