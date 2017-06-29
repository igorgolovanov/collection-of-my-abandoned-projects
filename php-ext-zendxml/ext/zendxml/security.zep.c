
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "kernel/concat.h"


/*

This file is part of the php-ext-zendxml package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendXml_Security) {

	ZEPHIR_REGISTER_CLASS(ZendXml, Security, zendxml, security, zendxml_security_method_entry, 0);

	zend_declare_class_constant_string(zendxml_security_ce, SL("ENTITY_DETECT"), "Detected use of ENTITY in XML, disabled to prevent XXE/XEE attacks" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Heuristic scan to detect entity in XML
 *
 * @param  string xml
 * @throws Exception\RuntimeException
 */
PHP_METHOD(ZendXml_Security, heuristicScan) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *xml_param = NULL, *_0 = NULL, _1, *_2, *_3, *_4;
	zval *xml = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &xml_param);

	zephir_get_strval(xml, xml_param);


	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "<!ENTITY", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strpos(_2, xml, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendxml_exception_runtimeexception_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Detected use of ENTITY in XML, disabled to prevent XXE/XEE attacks", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendxml/security.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Scan XML string for potential XXE and XEE attacks
 *
 * @param   string xml
 * @param   DomDocument dom
 * @throws  Exception\RuntimeException
 * @return  SimpleXMLElement|DomDocument|boolean
 */
PHP_METHOD(ZendXml_Security, scan) {

	HashTable *_11;
	HashPosition _10;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *errorHandler;
	zend_bool _0, simpleXml = 0;
	zval *xml_param = NULL, *dom = NULL, *useInternalXmlErrors = NULL, *loadEntities = NULL, *result = NULL, *child = NULL, *isPhpFpm = NULL, *_1 = NULL, *_4 = NULL, _5, *_8, *_9 = NULL, **_12, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL;
	zval *xml = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &xml_param, &dom);

	zephir_get_strval(xml, xml_param);
	if (!dom) {
		ZEPHIR_CPY_WRT(dom, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dom);
	}


	_0 = Z_TYPE_P(dom) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dom, zephir_get_internal_ce(SS("domdocument") TSRMLS_CC) TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dom' must be an instance of 'DOMDocument'", "", 0);
		return;
	}
	ZEPHIR_CALL_SELF(&_1, "isphpfpm", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_SELF(NULL, "heuristicscan", NULL, xml);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dom) == IS_NULL) {
		simpleXml = 1;
		ZEPHIR_INIT_NVAR(dom);
		object_init_ex(dom, zephir_get_internal_ce(SS("domdocument") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, dom, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_SELF(&isPhpFpm, "isphpfpm", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(isPhpFpm))) {
		ZEPHIR_CALL_FUNCTION(&loadEntities, "libxml_disable_entity_loader", &_2, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&useInternalXmlErrors, "libxml_use_internal_errors", &_3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(errorHandler);
	array_init_size(errorHandler, 3);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "ZendXml\\Security", 1);
	zephir_array_fast_append(errorHandler, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "scanErrorHandler", 1);
	zephir_array_fast_append(errorHandler, _4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", &_6, errorHandler, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_LONG(_4, 2048);
	ZEPHIR_CALL_METHOD(&result, dom, "loadxml", NULL, xml, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", &_7);
	zephir_check_call_status();
	if (!(zephir_is_true(isPhpFpm))) {
		ZEPHIR_CALL_FUNCTION(NULL, "libxml_disable_entity_loader", &_2, loadEntities);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "libxml_use_internal_errors", &_3, useInternalXmlErrors);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(result))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(isPhpFpm))) {
		ZEPHIR_OBS_VAR(_8);
		zephir_read_property(&_8, dom, SL("childNodes"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_9, "iterator_to_array", NULL, _8);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_11, &_10, 0, 0, "zendxml/security.zep", 91);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(child, _12);
			ZEPHIR_OBS_NVAR(_13);
			zephir_read_property(&_13, child, SL("nodeType"), PH_NOISY_CC);
			if (ZEPHIR_IS_LONG_IDENTICAL(_13, 10)) {
				ZEPHIR_OBS_NVAR(_14);
				zephir_read_property(&_14, child, SL("entities"), PH_NOISY_CC);
				ZEPHIR_OBS_NVAR(_15);
				zephir_read_property(&_15, _14, SL("length"), PH_NOISY_CC);
				if (unlikely(ZEPHIR_GT_LONG(_15, 0))) {
					ZEPHIR_INIT_NVAR(_4);
					object_init_ex(_4, zendxml_exception_runtimeexception_ce);
					ZEPHIR_INIT_NVAR(_16);
					ZVAL_STRING(_16, "Detected use of ENTITY in XML, disabled to prevent XXE/XEE attacks", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_17, _16);
					zephir_check_temp_parameter(_16);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4, "zendxml/security.zep", 87 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	if (simpleXml) {
		ZEPHIR_CALL_FUNCTION(&result, "simplexml_import_dom", NULL, dom);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(result, zephir_get_internal_ce(SS("simplexmlelement") TSRMLS_CC) TSRMLS_CC))) {
			RETURN_MM_BOOL(0);
		}
		RETURN_CCTOR(result);
	}
	RETVAL_ZVAL(dom, 1, 0);
	RETURN_MM();

}

PHP_METHOD(ZendXml_Security, scanErrorHandler) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *errstr = NULL;
	zval *errno_param = NULL, *errstr_param = NULL, _0, *_1 = NULL;
	int errno, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &errno_param, &errstr_param);

	errno = zephir_get_intval(errno_param);
	zephir_get_strval(errstr, errstr_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "DOMDocument::loadXML()", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", &_2, errstr, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(_1, 0));

}

/**
 * Scan XML file for potential XXE/XEE attacks
 *
 * @param  string $file
 * @param  DOMDocument $dom
 * @throws Exception\InvalidArgumentException
 * @return SimpleXMLElement|DomDocument
 */
PHP_METHOD(ZendXml_Security, scanFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *file_param = NULL, *dom = NULL, *contents, *_1;
	zval *file = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &dom);

	zephir_get_strval(file, file_param);
	if (!dom) {
		dom = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(dom) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(dom, zephir_get_internal_ce(SS("domdocument") TSRMLS_CC) TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dom' must be an instance of 'DOMDocument'", "", 0);
		return;
	}
	if (unlikely(!(zephir_file_exists(file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendxml_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "The file ", file, " specified doesn't exist");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "zendxml/security.zep", 121 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(contents);
	zephir_file_get_contents(contents, file TSRMLS_CC);
	ZEPHIR_RETURN_CALL_SELF("scan", NULL, contents, dom);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return true if PHP is running with PHP-FPM
 *
 * @return boolean
 */
PHP_METHOD(ZendXml_Security, isPhpFpm) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0 = NULL, *_3 = NULL, _4, *_5;
	zval *sapi = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "php_sapi_name", &_1);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(sapi, _2);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "fpm", 0);
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_strpos(_5, sapi, &_4, 0 );
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_5, 0));

}

