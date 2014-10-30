
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/iterator.h"
#include "kernel/hash.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Message) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, Message, zendframework, stdlib_message, zendframework_stdlib_message_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_stdlib_message_ce, SL("metadata"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(zendframework_stdlib_message_ce, SL("content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_stdlib_message_ce TSRMLS_CC, 1, zendframework_stdlib_messageinterface_ce);
	return SUCCESS;

}

/**
 * Set message metadata
 *
 * Non-destructive setting of message metadata; always adds to the metadata, never overwrites
 * the entire metadata container.
 *
 * @param  string|int|array|Traversable $spec
 * @param  mixed $value
 * @throws Exception\InvalidArgumentException
 * @return Message
 */
PHP_METHOD(ZendFramework_Stdlib_Message, setMetadata) {

	HashTable *_7;
	HashPosition _6;
	zend_object_iterator *_5;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *type = NULL, *exceptionMsg = NULL;
	zval *spec, *value = NULL, *key = NULL, *val = NULL, *_0 = NULL, *_3, *_4, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &spec, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_scalar", &_1, spec);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		zephir_update_property_array(this_ptr, SL("metadata"), spec, value TSRMLS_CC);
		RETURN_THIS();
	}
	_2 = Z_TYPE_P(spec) != IS_ARRAY;
	if (_2) {
		_2 = !(zephir_is_instance_of(spec, SL("Traversable") TSRMLS_CC));
	}
	if (unlikely(_2)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_gettype(_3, spec TSRMLS_CC);
		zephir_get_strval(type, _3);
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_INIT_VAR(type);
			zephir_get_class(type, spec, 0 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(exceptionMsg);
		ZEPHIR_CONCAT_SVS(exceptionMsg, "Expected a string, array, or Traversable argument in first position; received \"", type, "\"");
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zendframework_stdlib_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "zendframework/stdlib/message.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(spec) == IS_OBJECT) {
		_5 = zephir_get_iterator(spec TSRMLS_CC);
		_5->funcs->rewind(_5 TSRMLS_CC);
		for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
			ZEPHIR_GET_IMKEY(key, _5);
			{ zval **tmp; 
			_5->funcs->get_current_data(_5, &tmp TSRMLS_CC);
			val = *tmp;
			}
			zephir_update_property_array(this_ptr, SL("metadata"), key, val TSRMLS_CC);
		}
		_5->funcs->dtor(_5 TSRMLS_CC);
	} else {
		zephir_is_iterable(spec, &_7, &_6, 0, 0, "zendframework/stdlib/message.zep", 64);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(val, _8);
			zephir_update_property_array(this_ptr, SL("metadata"), key, val TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Retrieve all metadata or a single metadatum as specified by key
 *
 * @param  null|string|int $key
 * @param  null|mixed $default
 * @throws Exception\InvalidArgumentException
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_Message, getMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *key = NULL, *defaultVal = NULL, *v, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &defaultVal);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultVal) {
		defaultVal = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_MM_MEMBER(this_ptr, "metadata");
	}
	ZEPHIR_CALL_FUNCTION(&_0, "is_scalar", &_1, key);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_stdlib_exception_invalidargumentexception_ce, "Non-scalar argument provided for key", "zendframework/stdlib/message.zep", 87);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("metadata"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&v, _2, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(v);
	}
	RETVAL_ZVAL(defaultVal, 1, 0);
	RETURN_MM();

}

/**
 * Set message content
 *
 * @param  mixed $value
 * @return Message
 */
PHP_METHOD(ZendFramework_Stdlib_Message, setContent) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(this_ptr, SL("content"), value TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Get message content
 *
 * @return mixed
 */
PHP_METHOD(ZendFramework_Stdlib_Message, getContent) {


	RETURN_MEMBER(this_ptr, "content");

}

/**
 * @return string
 */
PHP_METHOD(ZendFramework_Stdlib_Message, toString) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value = NULL, *metadata = NULL, **_2, _3 = zval_used_for_init, *_4 = NULL, *_6 = NULL;
	zval *request = NULL, *content = NULL, *_7 = NULL, *_8;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(request);
	ZVAL_STRING(request, "", 1);

	ZEPHIR_CALL_METHOD(&metadata, this_ptr, "getmetadata",  NULL);
	zephir_check_call_status();
	zephir_is_iterable(metadata, &_1, &_0, 0, 0, "zendframework/stdlib/message.zep", 131);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "%s: %s\r\n", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, &_3, key, value);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_VV(_6, request, _4);
		zephir_get_strval(request, _6);
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcontent",  NULL);
	zephir_check_call_status();
	zephir_get_strval(_7, _4);
	ZEPHIR_CPY_WRT(content, _7);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VSV(_8, request, "\r\n", content);
	ZEPHIR_CPY_WRT(request, _8);
	RETURN_CTOR(request);

}

PHP_METHOD(ZendFramework_Stdlib_Message, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("metadata"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

