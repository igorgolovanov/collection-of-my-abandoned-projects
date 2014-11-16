
extern zend_class_entry *zendframework_http_client_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Http_Client);

PHP_METHOD(ZendFramework_Http_Client, __construct);
PHP_METHOD(ZendFramework_Http_Client, setOptions);
PHP_METHOD(ZendFramework_Http_Client, setAdapter);
PHP_METHOD(ZendFramework_Http_Client, getAdapter);
PHP_METHOD(ZendFramework_Http_Client, setRequest);
PHP_METHOD(ZendFramework_Http_Client, getRequest);
PHP_METHOD(ZendFramework_Http_Client, setResponse);
PHP_METHOD(ZendFramework_Http_Client, getResponse);
PHP_METHOD(ZendFramework_Http_Client, getLastRawRequest);
PHP_METHOD(ZendFramework_Http_Client, getLastRawResponse);
PHP_METHOD(ZendFramework_Http_Client, getRedirectionsCount);
PHP_METHOD(ZendFramework_Http_Client, setUri);
PHP_METHOD(ZendFramework_Http_Client, getUri);
PHP_METHOD(ZendFramework_Http_Client, setMethod);
PHP_METHOD(ZendFramework_Http_Client, getMethod);
PHP_METHOD(ZendFramework_Http_Client, setArgSeparator);
PHP_METHOD(ZendFramework_Http_Client, getArgSeparator);
PHP_METHOD(ZendFramework_Http_Client, setEncType);
PHP_METHOD(ZendFramework_Http_Client, getEncType);
PHP_METHOD(ZendFramework_Http_Client, setRawBody);
PHP_METHOD(ZendFramework_Http_Client, setParameterPost);
PHP_METHOD(ZendFramework_Http_Client, setParameterGet);
PHP_METHOD(ZendFramework_Http_Client, resetParameters);
PHP_METHOD(ZendFramework_Http_Client, getCookies);
PHP_METHOD(ZendFramework_Http_Client, getCookieId);
PHP_METHOD(ZendFramework_Http_Client, addCookie);
PHP_METHOD(ZendFramework_Http_Client, setCookies);
PHP_METHOD(ZendFramework_Http_Client, clearCookies);
PHP_METHOD(ZendFramework_Http_Client, setHeaders);
PHP_METHOD(ZendFramework_Http_Client, hasHeader);
PHP_METHOD(ZendFramework_Http_Client, getHeader);
PHP_METHOD(ZendFramework_Http_Client, setStream);
PHP_METHOD(ZendFramework_Http_Client, getStream);
PHP_METHOD(ZendFramework_Http_Client, openTempStream);
PHP_METHOD(ZendFramework_Http_Client, setAuth);
PHP_METHOD(ZendFramework_Http_Client, clearAuth);
PHP_METHOD(ZendFramework_Http_Client, calcAuthDigest);
PHP_METHOD(ZendFramework_Http_Client, dispatch);
PHP_METHOD(ZendFramework_Http_Client, send);
PHP_METHOD(ZendFramework_Http_Client, reset);
PHP_METHOD(ZendFramework_Http_Client, setFileUpload);
PHP_METHOD(ZendFramework_Http_Client, removeFileUpload);
PHP_METHOD(ZendFramework_Http_Client, prepareCookies);
PHP_METHOD(ZendFramework_Http_Client, prepareHeaders);
PHP_METHOD(ZendFramework_Http_Client, prepareBody);
PHP_METHOD(ZendFramework_Http_Client, detectFileMimeType);
PHP_METHOD(ZendFramework_Http_Client, encodeFormData);
PHP_METHOD(ZendFramework_Http_Client, flattenParametersArray);
PHP_METHOD(ZendFramework_Http_Client, doRequest);
PHP_METHOD(ZendFramework_Http_Client, encodeAuthHeader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setadapter, 0, 0, 1)
	ZEND_ARG_INFO(0, adapter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, ZendFramework\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, ZendFramework\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setargseparator, 0, 0, 1)
	ZEND_ARG_INFO(0, argSeparator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setenctype, 0, 0, 1)
	ZEND_ARG_INFO(0, encType)
	ZEND_ARG_INFO(0, boundary)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setrawbody, 0, 0, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setparameterpost, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, post, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setparameterget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_resetparameters, 0, 0, 0)
	ZEND_ARG_INFO(0, clearCookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_getcookieid, 0, 0, 1)
	ZEND_ARG_INFO(0, cookie)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_addcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, cookie)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, httponly)
	ZEND_ARG_INFO(0, maxAge)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setcookies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setstream, 0, 0, 0)
	ZEND_ARG_INFO(0, streamfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setauth, 0, 0, 2)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_calcauthdigest, 0, 0, 2)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_ARRAY_INFO(0, digest, 1)
	ZEND_ARG_INFO(0, entityBody)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_dispatch, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_send, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, request, ZendFramework\\Http\\Request, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_setfileupload, 0, 0, 2)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, formname)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, ctype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_removefileupload, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_preparecookies, 0, 0, 3)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_prepareheaders, 0, 0, 2)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_detectfilemimetype, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_encodeformdata, 0, 0, 3)
	ZEND_ARG_INFO(0, boundary)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_flattenparametersarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, parray, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_dorequest, 0, 0, 2)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_http_client_encodeauthheader, 0, 0, 2)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_http_client_method_entry) {
	PHP_ME(ZendFramework_Http_Client, __construct, arginfo_zendframework_http_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Http_Client, setOptions, arginfo_zendframework_http_client_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setAdapter, arginfo_zendframework_http_client_setadapter, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setRequest, arginfo_zendframework_http_client_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setResponse, arginfo_zendframework_http_client_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getLastRawRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getLastRawResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getRedirectionsCount, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setUri, arginfo_zendframework_http_client_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setMethod, arginfo_zendframework_http_client_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setArgSeparator, arginfo_zendframework_http_client_setargseparator, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getArgSeparator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setEncType, arginfo_zendframework_http_client_setenctype, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getEncType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setRawBody, arginfo_zendframework_http_client_setrawbody, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setParameterPost, arginfo_zendframework_http_client_setparameterpost, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setParameterGet, arginfo_zendframework_http_client_setparameterget, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, resetParameters, arginfo_zendframework_http_client_resetparameters, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getCookieId, arginfo_zendframework_http_client_getcookieid, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, addCookie, arginfo_zendframework_http_client_addcookie, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setCookies, arginfo_zendframework_http_client_setcookies, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, clearCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setHeaders, arginfo_zendframework_http_client_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, hasHeader, arginfo_zendframework_http_client_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getHeader, arginfo_zendframework_http_client_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setStream, arginfo_zendframework_http_client_setstream, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, getStream, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, openTempStream, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, setAuth, arginfo_zendframework_http_client_setauth, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, clearAuth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, calcAuthDigest, arginfo_zendframework_http_client_calcauthdigest, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, dispatch, arginfo_zendframework_http_client_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, send, arginfo_zendframework_http_client_send, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, setFileUpload, arginfo_zendframework_http_client_setfileupload, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, removeFileUpload, arginfo_zendframework_http_client_removefileupload, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, prepareCookies, arginfo_zendframework_http_client_preparecookies, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, prepareHeaders, arginfo_zendframework_http_client_prepareheaders, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, prepareBody, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, detectFileMimeType, arginfo_zendframework_http_client_detectfilemimetype, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, encodeFormData, arginfo_zendframework_http_client_encodeformdata, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Http_Client, flattenParametersArray, arginfo_zendframework_http_client_flattenparametersarray, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, doRequest, arginfo_zendframework_http_client_dorequest, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Http_Client, encodeAuthHeader, arginfo_zendframework_http_client_encodeauthheader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
