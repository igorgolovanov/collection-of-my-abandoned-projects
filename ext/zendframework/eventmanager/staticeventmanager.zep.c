
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Static version of EventManager
 */
ZEPHIR_INIT_CLASS(ZendFramework_EventManager_StaticEventManager) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\EventManager, StaticEventManager, zendframework, eventmanager_staticeventmanager, zendframework_eventmanager_sharedeventmanager_ce, zendframework_eventmanager_staticeventmanager_method_entry, 0);

	/**
	 * @var StaticEventManager
	 */
	zend_declare_property_null(zendframework_eventmanager_staticeventmanager_ce, SL("instance"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(zendframework_eventmanager_staticeventmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_sharedeventmanagerinterface_ce);
	zend_class_implements(zendframework_eventmanager_staticeventmanager_ce TSRMLS_CC, 1, zendframework_eventmanager_sharedeventaggregateawareinterface_ce);
	return SUCCESS;

}

/**
 * Singleton
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, __construct) {

	zval *className, *instance = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);

	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        
	if (Z_TYPE_P(instance) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Can't create new instance of StaticEventManager", "zendframework/eventmanager/staticeventmanager.zep", 34);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Singleton
 *
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, __clone) {



}

/**
 * Retrieve instance
 *
 * @return StaticEventManager
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, getInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_0;
	zval *className, *instance = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        
	if (Z_TYPE_P(instance) == IS_NULL) {
		ZEPHIR_INIT_NVAR(instance);
		_0 = zend_fetch_class(Z_STRVAL_P(className), Z_STRLEN_P(className), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(instance, _0);
		if (zephir_has_constructor(instance TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, instance, "__construct", NULL);
			zephir_check_call_status();
		}
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
            
	}
	RETURN_CCTOR(instance);

}

/**
 * Set the singleton to a specific SharedEventManagerInterface instance
 *
 * @param SharedEventManagerInterface $instance
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, setInstance) {

	zval *instance, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &instance);



	if (!(zephir_instance_of_ev(instance, zendframework_eventmanager_sharedeventmanagerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'instance' must be an instance of 'ZendFramework\\\\EventManager\\\\SharedEventManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

/**
 * Is a singleton instance defined?
 *
 * @return bool
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, hasInstance) {

	zval *className, *instance = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(instance);
	ZVAL_NULL(instance);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        
	RETURN_MM_BOOL(zephir_instance_of_ev(instance, zendframework_eventmanager_sharedeventmanagerinterface_ce TSRMLS_CC));

}

/**
 * Reset the singleton instance
 *
 * @return void
 */
PHP_METHOD(ZendFramework_EventManager_StaticEventManager, resetInstance) {

	zval *className, instance;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_SINIT_VAR(instance);
	ZVAL_NULL(&instance);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
        
	ZEPHIR_MM_RESTORE();

}

