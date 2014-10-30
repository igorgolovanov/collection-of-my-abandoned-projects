
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/memory.h"

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_AbstractListenerAggregate) {

	ZEPHIR_REGISTER_CLASS(Zend\\EventManager, AbstractListenerAggregate, zendframework, eventmanager_abstractlisteneraggregate, zendframework_eventmanager_abstractlisteneraggregate_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var \Zend\Stdlib\CallbackHandler[]
	 */
	zend_declare_property_null(zendframework_eventmanager_abstractlisteneraggregate_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_abstractlisteneraggregate_ce TSRMLS_CC, 1, zendframework_eventmanager_listeneraggregateinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_EventManager_AbstractListenerAggregate, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *events, *index = NULL, *callback = NULL, *detached = NULL, *_0, **_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &events);



	if (!(zephir_instance_of_ev(events, zendframework_eventmanager_eventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'events' must be an instance of 'ZendFramework\\\\EventManager\\\\EventManagerInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "zendframework/eventmanager/abstractlisteneraggregate.zep", 35);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(index, _2, _1);
		ZEPHIR_GET_HVALUE(callback, _3);
		ZEPHIR_CALL_METHOD(&detached, events, "detach", NULL, callback);
		zephir_check_call_status();
		if (zephir_is_true(detached)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
			zephir_array_unset(&_4, index, PH_SEPARATE);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(ZendFramework_EventManager_AbstractListenerAggregate, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("listeners"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

