

#ifndef PHP_OAUTH_H
#define PHP_OAUTH_H 1

#include "kernel/globals.h"

#define PHP_OAUTH_NAME    "oauth"
#define PHP_OAUTH_VERSION "0.0.1"
#define PHP_OAUTH_EXTNAME "oauth"



ZEND_BEGIN_MODULE_GLOBALS(oauth)

	/* Memory */
	zephir_memory_entry *start_memory;
	zephir_memory_entry *active_memory;

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/* Function cache */
	HashTable *function_cache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(oauth)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(oauth)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(oauth_globals_id, zend_oauth_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (oauth_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_oauth_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(oauth_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(oauth_globals)
#endif

#define zephir_globals oauth_globals
#define zend_zephir_globals zend_oauth_globals

extern zend_module_entry oauth_module_entry;
#define phpext_oauth_ptr &oauth_module_entry

#endif
