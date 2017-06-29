
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ZENDFRAMEWORK_H
#define PHP_ZENDFRAMEWORK_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ZENDFRAMEWORK_NAME        "ZendFramework"
#define PHP_ZENDFRAMEWORK_VERSION     "2.3.3"
#define PHP_ZENDFRAMEWORK_EXTNAME     "zendframework"
#define PHP_ZENDFRAMEWORK_AUTHOR      "Igor Golovanov"
#define PHP_ZENDFRAMEWORK_ZEPVERSION  "0.5.9a"
#define PHP_ZENDFRAMEWORK_DESCRIPTION "Zend Framework 2 delivered as a C-extension (Zephir)"



ZEND_BEGIN_MODULE_GLOBALS(zendframework)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(zendframework)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(zendframework)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(zendframework_globals_id, zend_zendframework_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (zendframework_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_zendframework_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(zendframework_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(zendframework_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def zendframework_globals
#define zend_zephir_globals_def zend_zendframework_globals

extern zend_module_entry zendframework_module_entry;
#define phpext_zendframework_ptr &zendframework_module_entry

#endif
