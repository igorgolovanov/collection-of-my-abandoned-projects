
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
#include "kernel/operators.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(ZendFramework_Http_HeaderLoader) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Http, HeaderLoader, zendframework, http_headerloader, zendframework_loader_pluginclassloader_ce, zendframework_http_headerloader_method_entry, 0);

	/**
	 * @var array Pre-aliased Header plugins
	 */
	zend_declare_property_null(zendframework_http_headerloader_ce, SL("plugins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param null|array|Traversable map If provided, seeds the loader with a map
 */
PHP_METHOD(ZendFramework_Http_HeaderLoader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *map = NULL, *staticMap = NULL, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &map);

	if (!map) {
		map = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(staticMap);
	ZVAL_NULL(staticMap);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 69);
	add_assoc_stringl_ex(_0, SS("accept"), SL("Zend\\Http\\Header\\Accept"), 1);
	add_assoc_stringl_ex(_0, SS("acceptcharset"), SL("Zend\\Http\\Header\\AcceptCharset"), 1);
	add_assoc_stringl_ex(_0, SS("acceptencoding"), SL("Zend\\Http\\Header\\AcceptEncoding"), 1);
	add_assoc_stringl_ex(_0, SS("acceptlanguage"), SL("Zend\\Http\\Header\\AcceptLanguage"), 1);
	add_assoc_stringl_ex(_0, SS("acceptranges"), SL("Zend\\Http\\Header\\AcceptRanges"), 1);
	add_assoc_stringl_ex(_0, SS("age"), SL("Zend\\Http\\Header\\Age"), 1);
	add_assoc_stringl_ex(_0, SS("allow"), SL("Zend\\Http\\Header\\Allow"), 1);
	add_assoc_stringl_ex(_0, SS("authenticationinfo"), SL("Zend\\Http\\Header\\AuthenticationInfo"), 1);
	add_assoc_stringl_ex(_0, SS("authorization"), SL("Zend\\Http\\Header\\Authorization"), 1);
	add_assoc_stringl_ex(_0, SS("cachecontrol"), SL("Zend\\Http\\Header\\CacheControl"), 1);
	add_assoc_stringl_ex(_0, SS("connection"), SL("Zend\\Http\\Header\\Connection"), 1);
	add_assoc_stringl_ex(_0, SS("contentdisposition"), SL("Zend\\Http\\Header\\ContentDisposition"), 1);
	add_assoc_stringl_ex(_0, SS("contentencoding"), SL("Zend\\Http\\Header\\ContentEncoding"), 1);
	add_assoc_stringl_ex(_0, SS("contentlanguage"), SL("Zend\\Http\\Header\\ContentLanguage"), 1);
	add_assoc_stringl_ex(_0, SS("contentlength"), SL("Zend\\Http\\Header\\ContentLength"), 1);
	add_assoc_stringl_ex(_0, SS("contentlocation"), SL("Zend\\Http\\Header\\ContentLocation"), 1);
	add_assoc_stringl_ex(_0, SS("contentmd5"), SL("Zend\\Http\\Header\\ContentMD5"), 1);
	add_assoc_stringl_ex(_0, SS("contentrange"), SL("Zend\\Http\\Header\\ContentRange"), 1);
	add_assoc_stringl_ex(_0, SS("contenttransferencoding"), SL("Zend\\Http\\Header\\ContentTransferEncoding"), 1);
	add_assoc_stringl_ex(_0, SS("contenttype"), SL("Zend\\Http\\Header\\ContentType"), 1);
	add_assoc_stringl_ex(_0, SS("cookie"), SL("Zend\\Http\\Header\\Cookie"), 1);
	add_assoc_stringl_ex(_0, SS("date"), SL("Zend\\Http\\Header\\Date"), 1);
	add_assoc_stringl_ex(_0, SS("etag"), SL("Zend\\Http\\Header\\Etag"), 1);
	add_assoc_stringl_ex(_0, SS("expect"), SL("Zend\\Http\\Header\\Expect"), 1);
	add_assoc_stringl_ex(_0, SS("expires"), SL("Zend\\Http\\Header\\Expires"), 1);
	add_assoc_stringl_ex(_0, SS("from"), SL("Zend\\Http\\Header\\From"), 1);
	add_assoc_stringl_ex(_0, SS("host"), SL("Zend\\Http\\Header\\Host"), 1);
	add_assoc_stringl_ex(_0, SS("ifmatch"), SL("Zend\\Http\\Header\\IfMatch"), 1);
	add_assoc_stringl_ex(_0, SS("ifmodifiedsince"), SL("Zend\\Http\\Header\\IfModifiedSince"), 1);
	add_assoc_stringl_ex(_0, SS("ifnonematch"), SL("Zend\\Http\\Header\\IfNoneMatch"), 1);
	add_assoc_stringl_ex(_0, SS("ifrange"), SL("Zend\\Http\\Header\\IfRange"), 1);
	add_assoc_stringl_ex(_0, SS("ifunmodifiedsince"), SL("Zend\\Http\\Header\\IfUnmodifiedSince"), 1);
	add_assoc_stringl_ex(_0, SS("keepalive"), SL("Zend\\Http\\Header\\KeepAlive"), 1);
	add_assoc_stringl_ex(_0, SS("lastmodified"), SL("Zend\\Http\\Header\\LastModified"), 1);
	add_assoc_stringl_ex(_0, SS("location"), SL("Zend\\Http\\Header\\Location"), 1);
	add_assoc_stringl_ex(_0, SS("maxforwards"), SL("Zend\\Http\\Header\\MaxForwards"), 1);
	add_assoc_stringl_ex(_0, SS("origin"), SL("Zend\\Http\\Header\\Origin"), 1);
	add_assoc_stringl_ex(_0, SS("pragma"), SL("Zend\\Http\\Header\\Pragma"), 1);
	add_assoc_stringl_ex(_0, SS("proxyauthenticate"), SL("Zend\\Http\\Header\\ProxyAuthenticate"), 1);
	add_assoc_stringl_ex(_0, SS("proxyauthorization"), SL("Zend\\Http\\Header\\ProxyAuthorization"), 1);
	add_assoc_stringl_ex(_0, SS("range"), SL("Zend\\Http\\Header\\Range"), 1);
	add_assoc_stringl_ex(_0, SS("referer"), SL("Zend\\Http\\Header\\Referer"), 1);
	add_assoc_stringl_ex(_0, SS("refresh"), SL("Zend\\Http\\Header\\Refresh"), 1);
	add_assoc_stringl_ex(_0, SS("retryafter"), SL("Zend\\Http\\Header\\RetryAfter"), 1);
	add_assoc_stringl_ex(_0, SS("server"), SL("Zend\\Http\\Header\\Server"), 1);
	add_assoc_stringl_ex(_0, SS("setcookie"), SL("Zend\\Http\\Header\\SetCookie"), 1);
	add_assoc_stringl_ex(_0, SS("te"), SL("Zend\\Http\\Header\\TE"), 1);
	add_assoc_stringl_ex(_0, SS("trailer"), SL("Zend\\Http\\Header\\Trailer"), 1);
	add_assoc_stringl_ex(_0, SS("transferencoding"), SL("Zend\\Http\\Header\\TransferEncoding"), 1);
	add_assoc_stringl_ex(_0, SS("upgrade"), SL("Zend\\Http\\Header\\Upgrade"), 1);
	add_assoc_stringl_ex(_0, SS("useragent"), SL("Zend\\Http\\Header\\UserAgent"), 1);
	add_assoc_stringl_ex(_0, SS("vary"), SL("Zend\\Http\\Header\\Vary"), 1);
	add_assoc_stringl_ex(_0, SS("via"), SL("Zend\\Http\\Header\\Via"), 1);
	add_assoc_stringl_ex(_0, SS("warning"), SL("Zend\\Http\\Header\\Warning"), 1);
	add_assoc_stringl_ex(_0, SS("wwwauthenticate"), SL("Zend\\Http\\Header\\WWWAuthenticate"), 1);
	zephir_update_property_this(this_ptr, SL("plugins"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&staticMap, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("staticMap") TSRMLS_CC);
        
	if (!(ZEPHIR_IS_EMPTY(staticMap))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", NULL, staticMap);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(map) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerplugins", NULL, map);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

