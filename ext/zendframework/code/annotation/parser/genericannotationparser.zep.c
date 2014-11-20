
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser) {

	ZEPHIR_REGISTER_CLASS(Zend\\Code\\Annotation\\Parser, GenericAnnotationParser, zendframework, code_annotation_parser_genericannotationparser, zendframework_code_annotation_parser_genericannotationparser_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_code_annotation_parser_genericannotationparser_ce, SL("aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_code_annotation_parser_genericannotationparser_ce, SL("annotationNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var AnnotationInterface[]
	 */
	zend_declare_property_null(zendframework_code_annotation_parser_genericannotationparser_ce, SL("annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_code_annotation_parser_genericannotationparser_ce TSRMLS_CC, 1, zendframework_code_annotation_parser_parserinterface_ce);
	return SUCCESS;

}

/**
 * Listen to onCreateAnnotation, and attempt to return an annotation object
 * instance.
 *
 * If the annotation class or alias is not registered, immediately returns
 * false. Otherwise, resolves the class, clones it, and, if any content is
 * present, calls {@link AnnotationInterface::initialize()} with the
 * content.
 *
 * @param  EventInterface $e
 * @return false|AnnotationInterface
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, onCreateAnnotation) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *e, *className = NULL, *content = NULL, *index = NULL, *annotation = NULL, *annotationNew, *_0 = NULL, *_1 = NULL, *_3 = NULL, _4, *_5 = NULL, *_6 = NULL, *_7, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	if (!(zephir_instance_of_ev(e, zendframework_eventmanager_eventinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'e' must be an instance of 'ZendFramework\\EventManager\\EventInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "class", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 0);
	ZEPHIR_CALL_METHOD(&className, e, "getparam", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_2 = !zephir_is_true(className);
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "hasannotation", NULL, className);
		zephir_check_call_status();
		_2 = !zephir_is_true(_3);
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "content", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&content, e, "getparam", NULL, _0, _1);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "()", 0);
	zephir_fast_trim(_0, content, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(content, _0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "hasalias", NULL, className);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "resolvealias", NULL, className);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(className, _6);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("annotationNames"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&index, "array_search", &_8, className, _7);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("annotations"), PH_NOISY_CC);
	zephir_array_fetch(&_10, _9, index, PH_NOISY | PH_READONLY, "zendframework/code/annotation/parser/genericannotationparser.zep", 70 TSRMLS_CC);
	ZEPHIR_CPY_WRT(annotation, _10);
	ZEPHIR_INIT_VAR(annotationNew);
	if (zephir_clone(annotationNew, annotation TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	if (zephir_is_true(content)) {
		ZEPHIR_CALL_METHOD(NULL, annotationNew, "initialize", NULL, content);
		zephir_check_call_status();
	}
	RETURN_CCTOR(annotationNew);

}

/**
 * Register annotations
 *
 * @param  string|AnnotationInterface $annotation String class name of an
 *         AnnotationInterface implementation, or actual instance
 * @return GenericAnnotationParser
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, registerAnnotation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_2;
	zend_bool _0;
	zval *exceptionMsg = NULL, *type = NULL;
	zval *annotation = NULL, *className = NULL, *_1 = NULL, *_3 = NULL, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &annotation);

	ZEPHIR_SEPARATE_PARAM(annotation);
	ZEPHIR_INIT_VAR(className);
	ZVAL_NULL(className);


	_0 = Z_TYPE_P(annotation) == IS_STRING;
	if (_0) {
		_0 = zephir_class_exists(annotation, 1 TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(className, annotation);
		ZEPHIR_INIT_NVAR(annotation);
		zephir_fetch_safe_class(_1, annotation);
		_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(annotation, _2);
		if (zephir_has_constructor(annotation TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, annotation, "__construct", NULL);
			zephir_check_call_status();
		}
	}
	if (unlikely(!(zephir_instance_of_ev(annotation, zendframework_code_annotation_annotationinterface_ce TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_3);
		zephir_gettype(_3, annotation TSRMLS_CC);
		zephir_get_strval(type, _3);
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_INIT_VAR(type);
			zephir_get_class(type, annotation, 0 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SSSSVS(exceptionMsg, "GenericAnnotationParser:registerAnnotation", ": expects an instance of ", "ZendFramework_Code_Annotation_Parser", "\\AnnotationInterface; received \"", type, "\"");
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zendframework_code_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "zendframework/code/annotation/parser/genericannotationparser.zep", 105 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(className))) {
		ZEPHIR_INIT_NVAR(className);
		zephir_get_class(className, annotation, 0 TSRMLS_CC);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("annotationNames"), PH_NOISY_CC);
	if (unlikely(zephir_fast_in_array(className, _5 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "An annotation for this class ", className, " already exists");
		zephir_get_strval(exceptionMsg, _6);
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zendframework_code_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/code/annotation/parser/genericannotationparser.zep", 114 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("annotation"), annotation TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("annotationNames"), className TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register many annotations at once
 *
 * @param  array|Traversable $annotations
 * @throws Exception\InvalidArgumentException
 * @return GenericAnnotationParser
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, registerAnnotations) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *exceptionMsg = NULL, *type = NULL;
	zval *annotations, *annotation = NULL, *_0, *_2, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &annotations);



	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, annotations TSRMLS_CC);
	zephir_get_strval(type, _0);
	_1 = !ZEPHIR_IS_STRING(type, "array");
	if (_1) {
		_1 = !(zephir_is_instance_of(annotations, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_1)) {
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_INIT_VAR(type);
			zephir_get_class(type, annotations, 0 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SSVS(exceptionMsg, "GenericAnnotationParser:registerAnnotations", ": expects an array or Traversable; received \"", type, "\"");
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_code_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/code/annotation/parser/genericannotationparser.zep", 142 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(annotations, &_4, &_3, 0, 0, "zendframework/code/annotation/parser/genericannotationparser.zep", 149);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(annotation, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerannotation", &_6, annotation);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Checks if the manager has annotations for a class
 *
 * @param  string $class
 * @return bool
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, hasAnnotation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *class_param = NULL, *_0;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("annotationNames"), PH_NOISY_CC);
	if (zephir_fast_in_array(class, _0 TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasalias", NULL, class);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias an annotation name
 *
 * @param  string $alias
 * @param  string $class May be either a registered annotation name or another alias
 * @throws Exception\InvalidArgumentException
 * @return GenericAnnotationParser
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, setAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1;
	zval *alias_param = NULL, *class_param = NULL, *normilized = NULL, *_0, *_2 = NULL, *_3;
	zval *alias = NULL, *class = NULL, *exceptionMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &alias_param, &class_param);

	zephir_get_strval(alias, alias_param);
	zephir_get_strval(class, class_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("annotationNames"), PH_NOISY_CC);
	_1 = !zephir_fast_in_array(class, _0 TSRMLS_CC);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasalias", NULL, class);
		zephir_check_call_status();
		_1 = !zephir_is_true(_2);
	}
	if (unlikely(_1)) {
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SSVSVSVS(exceptionMsg, "GenericAnnotationParser:setAlias", ": Cannot alias \"", alias, "\" to \"", class, "\", as class \"", class, "\" is not currently a registered annotation or alias");
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zendframework_code_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "zendframework/code/annotation/parser/genericannotationparser.zep", 182 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&normilized, this_ptr, "normalizealias", NULL, alias);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("aliases"), normilized, class TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Normalize an alias name
 *
 * @param  string $alias
 * @return string
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, normalizeAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *chars;
	zval *alias_param = NULL, *replaced, _0;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	zephir_get_strval(alias, alias_param);
	ZEPHIR_INIT_VAR(chars);
	array_init(chars);


	ZEPHIR_INIT_VAR(replaced);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "", 0);
	zephir_fast_str_replace(replaced, chars, &_0, alias TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(replaced, "lower", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Do we have an alias by the provided name?
 *
 * @param  string $alias
 * @return bool
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, hasAlias) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *normilized = NULL, *_0;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	zephir_get_strval(alias, alias_param);


	ZEPHIR_CALL_METHOD(&normilized, this_ptr, "normalizealias", NULL, alias);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("aliases"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, normilized));

}

/**
 * Resolve an alias to a class name
 *
 * @param  string $alias
 * @return string
 */
PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, resolveAlias) {

	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *normilized = NULL, *className, *_1, *_2 = NULL;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	zephir_get_strval(alias, alias_param);


	do {
		ZEPHIR_CALL_METHOD(&normilized, this_ptr, "normalizealias", &_0, alias);
		zephir_check_call_status();
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("aliases"), PH_NOISY_CC);
		zephir_array_fetch(&className, _1, normilized, PH_NOISY | PH_READONLY, "zendframework/code/annotation/parser/genericannotationparser.zep", 235 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasalias", &_3, className);
		zephir_check_call_status();
	} while (zephir_is_true(_2));
	RETURN_CTOR(className);

}

PHP_METHOD(ZendFramework_Code_Annotation_Parser_GenericAnnotationParser, __construct) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("annotations"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("annotationNames"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("aliases"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

