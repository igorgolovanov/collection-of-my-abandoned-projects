
extern zend_class_entry *zendframework_http_response_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Response);

PHP_METHOD(ZendFramework_Http_Response, fromString);
PHP_METHOD(ZendFramework_Http_Response, getCookie);
PHP_METHOD(ZendFramework_Http_Response, setStatusCode);
PHP_METHOD(ZendFramework_Http_Response, getStatusCode);
PHP_METHOD(ZendFramework_Http_Response, setCustomStatusCode);
PHP_METHOD(ZendFramework_Http_Response, setReasonPhrase);
PHP_METHOD(ZendFramework_Http_Response, getReasonPhrase);
PHP_METHOD(ZendFramework_Http_Response, getBody);
PHP_METHOD(ZendFramework_Http_Response, isClientError);
PHP_METHOD(ZendFramework_Http_Response, isForbidden);
PHP_METHOD(ZendFramework_Http_Response, isInformational);
PHP_METHOD(ZendFramework_Http_Response, isNotFound);
PHP_METHOD(ZendFramework_Http_Response, isOk);
PHP_METHOD(ZendFramework_Http_Response, isServerError);
PHP_METHOD(ZendFramework_Http_Response, isRedirect);
PHP_METHOD(ZendFramework_Http_Response, isSuccess);
PHP_METHOD(ZendFramework_Http_Response, renderStatusLine);
PHP_METHOD(ZendFramework_Http_Response, toString);
PHP_METHOD(ZendFramework_Http_Response, decodeChunkedBody);
PHP_METHOD(ZendFramework_Http_Response, decodeGzip);
PHP_METHOD(ZendFramework_Http_Response, decodeDeflate);
PHP_METHOD(ZendFramework_Http_Response, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_setcustomstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_setreasonphrase, 0, 0, 1)
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_decodechunkedbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_decodegzip, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_response_decodedeflate, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_response_method_entry) {
	PHP_ME(ZendFramework_Http_Response, fromString, arginfo_zendframework_http_response_fromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Http_Response, getCookie, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, setStatusCode, arginfo_zendframework_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, setCustomStatusCode, arginfo_zendframework_http_response_setcustomstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, setReasonPhrase, arginfo_zendframework_http_response_setreasonphrase, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, getReasonPhrase, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isClientError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isForbidden, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isInformational, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isNotFound, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isOk, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isServerError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isRedirect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, isSuccess, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, renderStatusLine, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Response, decodeChunkedBody, arginfo_zendframework_http_response_decodechunkedbody, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Response, decodeGzip, arginfo_zendframework_http_response_decodegzip, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Response, decodeDeflate, arginfo_zendframework_http_response_decodedeflate, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Response, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
