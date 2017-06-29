
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_ZENDXML_H
#define PHP_ZENDXML_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_ZENDXML_NAME        "ZendXml"
#define PHP_ZENDXML_VERSION     "1.0.0"
#define PHP_ZENDXML_EXTNAME     "zendxml"
#define PHP_ZENDXML_AUTHOR      "Igor Golovanov"
#define PHP_ZENDXML_ZEPVERSION  "0.5.9a"
#define PHP_ZENDXML_DESCRIPTION "An utility component for XML usage and best practices in PHP"



ZEND_BEGIN_MODULE_GLOBALS(zendxml)

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
	
ZEND_END_MODULE_GLOBALS(zendxml)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(zendxml)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(zendxml_globals_id, zend_zendxml_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (zendxml_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_zendxml_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(zendxml_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(zendxml_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def zendxml_globals
#define zend_zephir_globals_def zend_zendxml_globals

extern zend_module_entry zendxml_module_entry;
#define phpext_zendxml_ptr &zendxml_module_entry

#endif
