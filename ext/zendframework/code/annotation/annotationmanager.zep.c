
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Pluggable annotation manager
 *
 * Simply composes an EventManager. When createAnnotation() is called, it fires
 * off an event of the same name, passing it the resolved annotation class, the
 * annotation content, and the raw annotation string; the first listener to
 * return an object will halt execution of the event, and that object will be
 * returned as the annotation.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Code_Annotation_AnnotationManager) {

	ZEPHIR_REGISTER_CLASS(Zend\\Code\\Annotation, AnnotationManager, zendframework, code_annotation_annotationmanager, zendframework_code_annotation_annotationmanager_method_entry, 0);

	/**
	 * @var EventManagerInterface
	 */
	zend_declare_property_null(zendframework_code_annotation_annotationmanager_ce, SL("events"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_code_annotation_annotationmanager_ce, SL("EVENT_CREATE_ANNOTATION"), "createAnnotation" TSRMLS_CC);

	zend_class_implements(zendframework_code_annotation_annotationmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_eventmanagerawareinterface_ce);
	return SUCCESS;

}

/**
 * Set the event manager instance
 *
 * @param EventManagerInterface $events
 * @return AnnotationManager
 */
PHP_METHOD(ZendFramework_Code_Annotation_AnnotationManager, setEventManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifiers;
	zval *events, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &events);



	if (!(zephir_instance_of_ev(events, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'events' must be an instance of 'ZendFramework\\\\EventManager\\\\EventManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(identifiers);
	array_init_size(identifiers, 3);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AnnotationManager", 1);
	zephir_array_fast_append(identifiers, _0);
	ZEPHIR_INIT_BNVAR(_0);
	zephir_get_class(_0, this_ptr, 0 TSRMLS_CC);
	zephir_array_fast_append(identifiers, _0);
	ZEPHIR_CALL_METHOD(NULL, events, "setidentifiers", NULL, identifiers);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("events"), events TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Retrieve event manager
 *
 * Lazy loads an instance if none registered.
 *
 * @return EventManagerInterface
 */
PHP_METHOD(ZendFramework_Code_Annotation_AnnotationManager, getEventManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("events"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zendframework_eventmanager_eventmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "seteventmanager", NULL, _1);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "events");

}

/**
 * Attach a parser to listen to the createAnnotation event
 *
 * @param  ParserInterface $parser
 * @return AnnotationManager
 */
PHP_METHOD(ZendFramework_Code_Annotation_AnnotationManager, attach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback;
	zval *parser, *events = NULL, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parser);



	if (!(zephir_instance_of_ev(parser, zendframework_code_annotation_parser_parserinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'parser' must be an instance of 'ZendFramework\\\\Code\\\\Annotation\\\\Parser\\\\ParserInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "geteventmanager",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _0);
	ZEPHIR_INIT_VAR(callback);
	array_init_size(callback, 3);
	zephir_array_fast_append(callback, parser);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onCreateAnnotation", 1);
	zephir_array_fast_append(callback, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "createAnnotation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, events, "attach", NULL, _1, callback);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Create Annotation
 *
 * @param  string[] $annotationData
 * @return false|\stdClass
 */
PHP_METHOD(ZendFramework_Code_Annotation_AnnotationManager, createAnnotation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *annotationData_param = NULL, *event, *events = NULL, *results = NULL, *annotation = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *annotationData = NULL, *params, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &annotationData_param);

	if (unlikely(Z_TYPE_P(annotationData_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'annotationData' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		annotationData = annotationData_param;



	ZEPHIR_INIT_VAR(event);
	object_init_ex(event, zendframework_eventmanager_event_ce);
	ZEPHIR_CALL_METHOD(NULL, event, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(params);
	array_init_size(params, 4);
	ZEPHIR_OBS_VAR(_0);
	zephir_array_fetch_long(&_0, annotationData, 0, PH_NOISY, "zendframework/code/annotation/annotationmanager.zep", 102 TSRMLS_CC);
	zephir_array_update_string(&params, SL("class"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_array_fetch_long(&_0, annotationData, 1, PH_NOISY, "zendframework/code/annotation/annotationmanager.zep", 103 TSRMLS_CC);
	zephir_array_update_string(&params, SL("content"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_0);
	zephir_array_fetch_long(&_0, annotationData, 2, PH_NOISY, "zendframework/code/annotation/annotationmanager.zep", 105 TSRMLS_CC);
	zephir_array_update_string(&params, SL("raw"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "createAnnotation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, event, "setname", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, event, "settarget", NULL, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, event, "setparams", NULL, params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "geteventmanager",  NULL);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(events, _2);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 3);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "_eventCallaback", 1);
	zephir_array_fast_append(_3, _1);
	ZEPHIR_CALL_METHOD(&_2, events, "trigger", NULL, event, _3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(results, _2);
	ZEPHIR_CALL_METHOD(&annotation, results, "last",  NULL);
	zephir_check_call_status();
	if (Z_TYPE_P(annotation) == IS_OBJECT) {
		RETURN_CCTOR(annotation);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(ZendFramework_Code_Annotation_AnnotationManager, _eventCallaback) {

	zval *v;

	zephir_fetch_params(0, 1, 0, &v);



	RETURN_BOOL(Z_TYPE_P(v) == IS_OBJECT);

}

