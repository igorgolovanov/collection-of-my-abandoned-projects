
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "oauth.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"

zend_class_entry *oauth_serviceinterface_ce;
zend_class_entry *oauth_tokeninterface_ce;
zend_class_entry *oauth_clientinterface_ce;
zend_class_entry *oauth_credentialsinterface_ce;
zend_class_entry *oauth_exceptioninterface_ce;
zend_class_entry *oauth_tokenstorageinterface_ce;
zend_class_entry *oauth_uriinterface_ce;
zend_class_entry *oauth_v1_serviceinterface_ce;
zend_class_entry *oauth_v1_signatureinterface_ce;
zend_class_entry *oauth_v1_tokeninterface_ce;
zend_class_entry *oauth_v2_serviceinterface_ce;
zend_class_entry *oauth_v2_tokeninterface_ce;
zend_class_entry *oauth_service_ce;
zend_class_entry *oauth_token_ce;
zend_class_entry *oauth_client_ce;
zend_class_entry *oauth_credentials_ce;
zend_class_entry *oauth_tokenexpiredexception_ce;
zend_class_entry *oauth_tokennotfoundexception_ce;
zend_class_entry *oauth_tokenstorage_memory_ce;
zend_class_entry *oauth_uri_ce;
zend_class_entry *oauth_v1_service_ce;
zend_class_entry *oauth_v1_signature_ce;
zend_class_entry *oauth_v1_token_ce;
zend_class_entry *oauth_v1_unsupportedhashalgorithmexception_ce;
zend_class_entry *oauth_v2_service_ce;
zend_class_entry *oauth_v2_token_ce;

ZEND_DECLARE_MODULE_GLOBALS(oauth)

PHP_MINIT_FUNCTION(oauth){

	ZEPHIR_INIT(OAuth_ServiceInterface);
	ZEPHIR_INIT(OAuth_TokenInterface);
	ZEPHIR_INIT(OAuth_ClientInterface);
	ZEPHIR_INIT(OAuth_CredentialsInterface);
	ZEPHIR_INIT(OAuth_ExceptionInterface);
	ZEPHIR_INIT(OAuth_TokenStorageInterface);
	ZEPHIR_INIT(OAuth_UriInterface);
	ZEPHIR_INIT(OAuth_V1_ServiceInterface);
	ZEPHIR_INIT(OAuth_V1_SignatureInterface);
	ZEPHIR_INIT(OAuth_V1_TokenInterface);
	ZEPHIR_INIT(OAuth_V2_ServiceInterface);
	ZEPHIR_INIT(OAuth_V2_TokenInterface);
	ZEPHIR_INIT(OAuth_Service);
	ZEPHIR_INIT(OAuth_Token);
	ZEPHIR_INIT(OAuth_Client);
	ZEPHIR_INIT(OAuth_Credentials);
	ZEPHIR_INIT(OAuth_TokenExpiredException);
	ZEPHIR_INIT(OAuth_TokenNotFoundException);
	ZEPHIR_INIT(OAuth_TokenStorage_Memory);
	ZEPHIR_INIT(OAuth_Uri);
	ZEPHIR_INIT(OAuth_V1_Service);
	ZEPHIR_INIT(OAuth_V1_Signature);
	ZEPHIR_INIT(OAuth_V1_Token);
	ZEPHIR_INIT(OAuth_V1_UnsupportedHashAlgorithmException);
	ZEPHIR_INIT(OAuth_V2_Service);
	ZEPHIR_INIT(OAuth_V2_Token);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(oauth){

	assert(ZEPHIR_GLOBAL(function_cache) == NULL);
	//assert(ZEPHIR_GLOBAL(orm).parser_cache == NULL);
	//assert(ZEPHIR_GLOBAL(orm).ast_cache == NULL);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zephir_globals *zephir_globals TSRMLS_DC) {

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache options */
	zephir_globals->function_cache = NULL;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

}

static PHP_RINIT_FUNCTION(oauth){

	php_zephir_init_globals(ZEPHIR_VGLOBAL TSRMLS_CC);
	//oauth_init_interned_strings(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(oauth){

	if (ZEPHIR_GLOBAL(start_memory) != NULL) {
		zephir_clean_restore_stack(TSRMLS_C);
	}

	if (ZEPHIR_GLOBAL(function_cache) != NULL) {
		zend_hash_destroy(ZEPHIR_GLOBAL(function_cache));
		FREE_HASHTABLE(ZEPHIR_GLOBAL(function_cache));
		ZEPHIR_GLOBAL(function_cache) = NULL;
	}

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(oauth)
{
	php_info_print_table_start();
	php_info_print_table_header(2, PHP_OAUTH_NAME, "enabled");
	php_info_print_table_row(2, "Version", PHP_OAUTH_VERSION);
	php_info_print_table_end();
}

static PHP_GINIT_FUNCTION(oauth)
{
	zephir_memory_entry *start;

	php_zephir_init_globals(oauth_globals TSRMLS_CC);

	/* Start Memory Frame */
	start = (zephir_memory_entry *) pecalloc(1, sizeof(zephir_memory_entry), 1);
	start->addresses       = pecalloc(16, sizeof(zval*), 1);
	start->capacity        = 16;
	start->hash_addresses  = pecalloc(4, sizeof(zval*), 1);
	start->hash_capacity   = 4;

	oauth_globals->start_memory = start;

	/* Global Constants */
	ALLOC_PERMANENT_ZVAL(oauth_globals->global_false);
	INIT_PZVAL(oauth_globals->global_false);
	ZVAL_FALSE(oauth_globals->global_false);
	Z_ADDREF_P(oauth_globals->global_false);

	ALLOC_PERMANENT_ZVAL(oauth_globals->global_true);
	INIT_PZVAL(oauth_globals->global_true);
	ZVAL_TRUE(oauth_globals->global_true);
	Z_ADDREF_P(oauth_globals->global_true);

	ALLOC_PERMANENT_ZVAL(oauth_globals->global_null);
	INIT_PZVAL(oauth_globals->global_null);
	ZVAL_NULL(oauth_globals->global_null);
	Z_ADDREF_P(oauth_globals->global_null);

}

static PHP_GSHUTDOWN_FUNCTION(oauth)
{
	assert(oauth_globals->start_memory != NULL);

	pefree(oauth_globals->start_memory->hash_addresses, 1);
	pefree(oauth_globals->start_memory->addresses, 1);
	pefree(oauth_globals->start_memory, 1);
	oauth_globals->start_memory = NULL;
}

zend_module_entry oauth_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_OAUTH_EXTNAME,
	NULL,
	PHP_MINIT(oauth),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(oauth),
#else
	NULL,
#endif
	PHP_RINIT(oauth),
	PHP_RSHUTDOWN(oauth),
	PHP_MINFO(oauth),
	PHP_OAUTH_VERSION,
	ZEND_MODULE_GLOBALS(oauth),
	PHP_GINIT(oauth),
	PHP_GSHUTDOWN(oauth),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_OAUTH
ZEND_GET_MODULE(oauth)
#endif
