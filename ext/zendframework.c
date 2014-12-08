
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "zendframework.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *zendframework_loader_exception_exceptioninterface_ce;
zend_class_entry *zendframework_loader_shortnamelocator_ce;
zend_class_entry *zendframework_loader_splautoloader_ce;
zend_class_entry *zendframework_loader_pluginclasslocator_ce;
zend_class_entry *zendframework_loader_exception_domainexception_ce;
zend_class_entry *zendframework_loader_classmapautoloader_ce;
zend_class_entry *zendframework_loader_exception_badmethodcallexception_ce;
zend_class_entry *zendframework_loader_exception_invalidargumentexception_ce;
zend_class_entry *zendframework_loader_exception_invalidpathexception_ce;
zend_class_entry *zendframework_loader_exception_missingresourcenamespaceexception_ce;
zend_class_entry *zendframework_loader_exception_pluginloaderexception_ce;
zend_class_entry *zendframework_loader_exception_runtimeexception_ce;
zend_class_entry *zendframework_loader_exception_securityexception_ce;
zend_class_entry *zendframework_loader_moduleautoloader_ce;
zend_class_entry *zendframework_loader_pluginclassloader_ce;
zend_class_entry *zendframework_loader_standardautoloader_ce;

ZEND_DECLARE_MODULE_GLOBALS(zendframework)

static PHP_MINIT_FUNCTION(zendframework)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(ZendFramework_Loader_Exception_ExceptionInterface);
	ZEPHIR_INIT(ZendFramework_Loader_ShortNameLocator);
	ZEPHIR_INIT(ZendFramework_Loader_SplAutoloader);
	ZEPHIR_INIT(ZendFramework_Loader_PluginClassLocator);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_DomainException);
	ZEPHIR_INIT(ZendFramework_Loader_ClassMapAutoloader);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_BadMethodCallException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_InvalidArgumentException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_InvalidPathException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_MissingResourceNamespaceException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_PluginLoaderException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_RuntimeException);
	ZEPHIR_INIT(ZendFramework_Loader_Exception_SecurityException);
	ZEPHIR_INIT(ZendFramework_Loader_ModuleAutoloader);
	ZEPHIR_INIT(ZendFramework_Loader_PluginClassLoader);
	ZEPHIR_INIT(ZendFramework_Loader_StandardAutoloader);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(zendframework)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_zendframework_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
#if PHP_VERSION_ID < 50600
	zephir_globals->cache_enabled = 1;
#else
	zephir_globals->cache_enabled = 0;
#endif

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(zendframework)
{

	zend_zendframework_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(zendframework)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(zendframework)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_ZENDFRAMEWORK_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_ZENDFRAMEWORK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_ZENDFRAMEWORK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_ZENDFRAMEWORK_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_ZENDFRAMEWORK_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(zendframework)
{
	php_zephir_init_globals(zendframework_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(zendframework)
{

}

zend_module_entry zendframework_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_ZENDFRAMEWORK_EXTNAME,
	NULL,
	PHP_MINIT(zendframework),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(zendframework),
#else
	NULL,
#endif
	PHP_RINIT(zendframework),
	PHP_RSHUTDOWN(zendframework),
	PHP_MINFO(zendframework),
	PHP_ZENDFRAMEWORK_VERSION,
	ZEND_MODULE_GLOBALS(zendframework),
	PHP_GINIT(zendframework),
	PHP_GSHUTDOWN(zendframework),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_ZENDFRAMEWORK
ZEND_GET_MODULE(zendframework)
#endif
