/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Ldap\Exception;

class LdapException extends \Exception implements ExceptionInterface
{
    const LDAP_SUCCESS = 0;

    const LDAP_OPERATIONS_ERROR = 1;

    const LDAP_PROTOCOL_ERROR = 2;

    const LDAP_TIMELIMIT_EXCEEDED = 3;

    const LDAP_SIZELIMIT_EXCEEDED = 4;

    const LDAP_COMPARE_FALSE = 5;

    const LDAP_COMPARE_TRUE = 6;

    const LDAP_AUTH_METHOD_NOT_SUPPORTED = 7;

    const LDAP_STRONG_AUTH_REQUIRED = 8;

    const LDAP_PARTIAL_RESULTS = 9;

    const LDAP_REFERRAL = 10;

    const LDAP_ADMINLIMIT_EXCEEDED = 11;

    const LDAP_UNAVAILABLE_CRITICAL_EXTENSION = 12;

    const LDAP_CONFIDENTIALITY_REQUIRED = 13;

    const LDAP_SASL_BIND_IN_PROGRESS = 14;

    const LDAP_NO_SUCH_ATTRIBUTE = 16;

    const LDAP_UNDEFINED_TYPE = 17;

    const LDAP_INAPPROPRIATE_MATCHING = 18;

    const LDAP_CONSTRAINT_VIOLATION = 19;

    const LDAP_TYPE_OR_VALUE_EXISTS = 20;

    const LDAP_INVALID_SYNTAX = 21;

    const LDAP_NO_SUCH_OBJECT = 32;

    const LDAP_ALIAS_PROBLEM = 33;

    const LDAP_INVALID_DN_SYNTAX = 34;

    const LDAP_IS_LEAF = 35;

    const LDAP_ALIAS_DEREF_PROBLEM = 36;

    const LDAP_PROXY_AUTHZ_FAILURE = 47;

    const LDAP_INAPPROPRIATE_AUTH = 48;

    const LDAP_INVALID_CREDENTIALS = 49;

    const LDAP_INSUFFICIENT_ACCESS = 50;

    const LDAP_BUSY = 51;

    const LDAP_UNAVAILABLE = 52;

    const LDAP_UNWILLING_TO_PERFORM = 53;

    const LDAP_LOOP_DETECT = 54;

    const LDAP_NAMING_VIOLATION = 64;

    const LDAP_OBJECT_CLASS_VIOLATION = 65;

    const LDAP_NOT_ALLOWED_ON_NONLEAF = 66;

    const LDAP_NOT_ALLOWED_ON_RDN = 67;

    const LDAP_ALREADY_EXISTS = 68;

    const LDAP_NO_OBJECT_CLASS_MODS = 69;

    const LDAP_RESULTS_TOO_LARGE = 70;

    const LDAP_AFFECTS_MULTIPLE_DSAS = 71;

    const LDAP_OTHER = 80;

    const LDAP_SERVER_DOWN = 81;

    const LDAP_LOCAL_ERROR = 82;

    const LDAP_ENCODING_ERROR = 83;

    const LDAP_DECODING_ERROR = 84;

    const LDAP_TIMEOUT = 85;

    const LDAP_AUTH_UNKNOWN = 86;

    const LDAP_FILTER_ERROR = 87;

    const LDAP_USER_CANCELLED = 88;

    const LDAP_PARAM_ERROR = 89;

    const LDAP_NO_MEMORY = 90;

    const LDAP_CONNECT_ERROR = 91;

    const LDAP_NOT_SUPPORTED = 92;

    const LDAP_CONTROL_NOT_FOUND = 93;

    const LDAP_NO_RESULTS_RETURNED = 94;

    const LDAP_MORE_RESULTS_TO_RETURN = 95;

    const LDAP_CLIENT_LOOP = 96;

    const LDAP_REFERRAL_LIMIT_EXCEEDED = 97;

    const LDAP_CUP_RESOURCES_EXHAUSTED = 113;

    const LDAP_CUP_SECURITY_VIOLATION = 114;

    const LDAP_CUP_INVALID_DATA = 115;

    const LDAP_CUP_UNSUPPORTED_SCHEME = 116;

    const LDAP_CUP_RELOAD_REQUIRED = 117;

    const LDAP_CANCELLED = 118;

    const LDAP_NO_SUCH_OPERATION = 119;

    const LDAP_TOO_LATE = 120;

    const LDAP_CANNOT_CANCEL = 121;

    const LDAP_ASSERTION_FAILED = 122;

    const LDAP_SYNC_REFRESH_REQUIRED = 4096;

    const LDAP_X_SYNC_REFRESH_REQUIRED = 16640;

    const LDAP_X_NO_OPERATION = 16654;

    const LDAP_X_ASSERTION_FAILED = 16655;

    const LDAP_X_NO_REFERRALS_FOUND = 16656;

    const LDAP_X_CANNOT_CHAIN = 16657;

    const LDAP_X_DOMAIN_MISMATCH = 28673;

    const LDAP_X_EXTENSION_NOT_LOADED = 28674;

    /**
     * @param Ldap   $ldap Zend\Ldap\Ldap object
     * @param string $str  Informative exception message
     * @param int    $code LDAP error code
     */
    public function __construct(ldap = null, string str = null, int code = 0)
    {

    }

}
