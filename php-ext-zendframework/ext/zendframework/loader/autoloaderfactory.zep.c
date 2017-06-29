
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Loader_AutoloaderFactory) {

	ZEPHIR_REGISTER_CLASS(Zend\\Loader, AutoloaderFactory, zendframework, loader_autoloaderfactory, zendframework_loader_autoloaderfactory_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array All autoloaders registered using the factory
	 */
	zend_declare_property_null(zendframework_loader_autoloaderfactory_ce, SL("loaders"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var StandardAutoloader StandardAutoloader instance for resolving
	 * autoloader classes via the include_path
	 */
	zend_declare_property_null(zendframework_loader_autoloaderfactory_ce, SL("standardAutoloader"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_loader_autoloaderfactory_ce, SL("STANDARD_AUTOLOADER"), "Zend\\Loader\\StandardAutoloader" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Factory for autoloaders
 *
 * Options should be an array or Traversable object of the following structure:
 * <code>
 * array(
 *     '<autoloader class name>' => $autoloaderOptions,
 * )
 * </code>
 *
 * The factory will then loop through and instantiate each autoloader with
 * the specified options, and register each with the spl_autoloader.
 *
 * You may retrieve the concrete autoloader instances later using
 * {@link getRegisteredAutoloaders()}.
 *
 * Note that the class names must be resolvable on the include_path or via
 * the Zend library, using PSR-0 rules (unless the class has already been
 * loaded).
 *
 * @param  array|Traversable $options (optional) options to use. Defaults to Zend\Loader\StandardAutoloader
 * @return void
 * @throws Exception\InvalidArgumentException for invalid options
 * @throws Exception\InvalidArgumentException for unloadable autoloader classes
 * @throws Exception\DomainException for autoloader classes not implementing SplAutoloader
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, factory) {

	zend_class_entry *_15;
	zend_bool _10;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	HashTable *_7;
	HashPosition _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *exceptionMsg = NULL;
	zval *options = NULL, *className, *loaders = NULL, *autoloaderClass = NULL, *autoloader = NULL, *autoloaderOptions = NULL, *autoloaderClassDefault = NULL, *_0 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL, **_8, *_11 = NULL, *_13 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}
	ZEPHIR_INIT_VAR(loaders);
	ZVAL_NULL(loaders);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	if (Z_TYPE_P(options) == IS_NULL) {
		
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            
		if (Z_TYPE_P(loaders) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(loaders);
			array_init(loaders);
		}
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, className, "::STANDARD_AUTOLOADER");
		ZEPHIR_CALL_FUNCTION(&autoloaderClass, "constant", &_1, _0);
		zephir_check_call_status();
		if (!(zephir_array_isset(loaders, autoloaderClass))) {
			ZEPHIR_CALL_STATIC(&autoloader, "getstandardautoloader", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, autoloader, "register", NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&loaders, autoloaderClass, &autoloader, PH_COPY | PH_SEPARATE);
			
                    zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
                
		}
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "Traversable", 0);
		ZEPHIR_CALL_FUNCTION(&_3, "is_subclass_of", &_4, options, &_2);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_loader_exception_invalidargumentexception_ce, "Options provided must be an array or Traversable", "zendframework/loader/autoloaderfactory.zep", 90);
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_5, "iterator_to_array", NULL, options);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(options, _5);
	}
	zephir_is_iterable(options, &_7, &_6, 0, 0, "zendframework/loader/autoloaderfactory.zep", 132);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(autoloaderClass, _7, _6);
		ZEPHIR_GET_HVALUE(autoloaderOptions, _8);
		
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            
		if (Z_TYPE_P(loaders) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(loaders);
			array_init(loaders);
		}
		ZEPHIR_OBS_NVAR(autoloader);
		if (zephir_array_isset_fetch(&autoloader, loaders, autoloaderClass, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, autoloader, "setoptions", NULL, autoloaderOptions);
			zephir_check_call_status();
			continue;
		}
		ZEPHIR_CALL_STATIC(&autoloader, "getstandardautoloader", &_9);
		zephir_check_call_status();
		_10 = !zephir_class_exists(autoloaderClass, 1 TSRMLS_CC);
		if (_10) {
			ZEPHIR_CALL_METHOD(&_3, autoloader, "autoload", NULL, autoloaderClass);
			zephir_check_call_status();
			_10 = !zephir_is_true(_3);
		}
		if (unlikely(_10)) {
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SVS(_0, "Autoloader class \"", autoloaderClass, "\" not loaded");
			zephir_get_strval(exceptionMsg, _0);
			ZEPHIR_INIT_NVAR(_11);
			object_init_ex(_11, zendframework_loader_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, exceptionMsg);
			zephir_check_call_status();
			zephir_throw_exception_debug(_11, "zendframework/loader/autoloaderfactory.zep", 110 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "Zend\\Loader\\SplAutoloader", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "is_subclass_of", &_4, autoloaderClass, &_2);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_5))) {
			ZEPHIR_INIT_LNVAR(_13);
			ZEPHIR_CONCAT_SVS(_13, "Autoloader class ", autoloaderClass, " must implement Zend\\Loader\\SplAutoloader");
			zephir_get_strval(exceptionMsg, _13);
			ZEPHIR_INIT_NVAR(_11);
			object_init_ex(_11, zendframework_loader_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, exceptionMsg);
			zephir_check_call_status();
			zephir_throw_exception_debug(_11, "zendframework/loader/autoloaderfactory.zep", 115 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VS(_13, className, "::STANDARD_AUTOLOADER");
		ZEPHIR_CALL_FUNCTION(&autoloaderClassDefault, "constant", &_1, _13);
		zephir_check_call_status();
		if (ZEPHIR_IS_IDENTICAL(autoloaderClassDefault, autoloaderClass)) {
			ZEPHIR_CALL_METHOD(NULL, autoloader, "setoptions", NULL, autoloaderOptions);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(autoloader);
			zephir_fetch_safe_class(_14, autoloaderClass);
			_15 = zend_fetch_class(Z_STRVAL_P(_14), Z_STRLEN_P(_14), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(autoloader, _15);
			if (zephir_has_constructor(autoloader TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, autoloader, "__construct", NULL, autoloaderOptions);
				zephir_check_call_status();
			}
		}
		ZEPHIR_CALL_METHOD(NULL, autoloader, "register", NULL);
		zephir_check_call_status();
		zephir_array_update_zval(&loaders, autoloaderClass, &autoloader, PH_COPY | PH_SEPARATE);
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
            
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a list of all autoloaders registered with the factory
 *
 * Returns an array of autoloader instances.
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, getRegisteredAutoloaders) {

	zval *loaders = NULL, *className;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(loaders);
	ZVAL_NULL(loaders);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        
	if (Z_TYPE_P(loaders) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(loaders);
		array_init(loaders);
	}
	RETURN_CCTOR(loaders);

}

/**
 * Retrieves an autoloader by class name
 *
 * @param  string $class
 * @return SplAutoloader
 * @throws Exception\InvalidArgumentException for non-registered class
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, getRegisteredAutoloader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *class, *loaders = NULL, *className, *autoloader, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class);

	ZEPHIR_INIT_VAR(loaders);
	ZVAL_NULL(loaders);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        
	if (Z_TYPE_P(loaders) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(loaders);
		array_init(loaders);
	}
	ZEPHIR_OBS_VAR(autoloader);
	if (likely(zephir_array_isset_fetch(&autoloader, loaders, class, 0 TSRMLS_CC))) {
		RETURN_CCTOR(autoloader);
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "Autoloader class \"", class, "\" not loaded");
	zephir_get_strval(exceptionMsg, _0);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zendframework_loader_exception_invalidargumentexception_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "zendframework/loader/autoloaderfactory.zep", 182 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Unregisters all autoloaders that have been registered via the factory.
 * This will NOT unregister autoloaders registered outside of the fctory.
 *
 * @return void
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, unregisterAutoloaders) {

	zephir_fcall_cache_entry *_5 = NULL;
	zval *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *autoloaders = NULL, *className, *autoloader = NULL, *loaders = NULL, *autoloaderClass = NULL, **_2, *_4 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(loaders);
	ZVAL_NULL(loaders);

	ZEPHIR_CALL_STATIC(&autoloaders, "getregisteredautoloaders", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	zephir_is_iterable(autoloaders, &_1, &_0, 0, 0, "zendframework/loader/autoloaderfactory.zep", 210);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HKEY(autoloaderClass, _1, _0);
		ZEPHIR_GET_HVALUE(autoloader, _2);
		ZEPHIR_INIT_NVAR(_3);
		array_init_size(_3, 3);
		zephir_array_fast_append(_3, autoloader);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "autoload", 1);
		zephir_array_fast_append(_3, _4);
		ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", &_5, _3);
		zephir_check_call_status();
		
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            
		zephir_array_unset(&loaders, autoloaderClass, PH_SEPARATE);
		
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
            
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Unregister a single autoloader by class name
 *
 * @param  string $autoloaderClass
 * @return bool
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, unregisterAutoloader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zend_bool _0;
	zval *autoloaderClass_param = NULL, *className, *loaders = NULL, *autoloader, *_2;
	zval *autoloaderClass = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &autoloaderClass_param);

	zephir_get_strval(autoloaderClass, autoloaderClass_param);
	ZEPHIR_INIT_VAR(loaders);
	ZVAL_NULL(loaders);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        
	_0 = Z_TYPE_P(loaders) != IS_ARRAY;
	if (!(_0)) {
		ZEPHIR_OBS_VAR(autoloader);
		_0 = !zephir_array_isset_fetch(&autoloader, loaders, autoloaderClass, 0 TSRMLS_CC);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 3);
	zephir_array_fast_append(_1, autoloader);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "autoload", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, _1);
	zephir_check_call_status();
	zephir_array_unset(&loaders, autoloaderClass, PH_SEPARATE);
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
        
	RETURN_MM_BOOL(1);

}

/**
 * Get an instance of the standard autoloader
 *
 * Used to attempt to resolve autoloader classes, using the
 * StandardAutoloader. The instance is marked as a fallback autoloader, to
 * allow resolving autoloaders not under the "Zend" namespace.
 *
 * @return SplAutoloader
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, getStandardAutoloader) {

	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *className, *standardAutoloader = NULL, *autoloaderClass = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(standardAutoloader);
	ZVAL_NULL(standardAutoloader);

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	
            zephir_read_static_property(&standardAutoloader, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("standardAutoloader") TSRMLS_CC);
        
	if (Z_TYPE_P(standardAutoloader) != IS_NULL) {
		RETURN_CCTOR(standardAutoloader);
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, className, "::STANDARD_AUTOLOADER");
	ZEPHIR_CALL_FUNCTION(&autoloaderClass, "constant", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(standardAutoloader);
	zephir_fetch_safe_class(_2, autoloaderClass);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(standardAutoloader, _3);
	if (zephir_has_constructor(standardAutoloader TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, standardAutoloader, "__construct", NULL);
		zephir_check_call_status();
	}
	
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("standardAutoloader"), &standardAutoloader TSRMLS_CC);
        
	RETURN_CCTOR(standardAutoloader);

}

/**
 * Checks if the object has this class as one of its parents
 *
 * @see https://bugs.php.net/bug.php?id=53727
 * @see https://github.com/zendframework/zf2/pull/1807
 *
 * @deprecated since zf 2.3 requires PHP >= 5.3.23
 *
 * @param  string $className
 * @param  string $type
 * @return bool
 */
PHP_METHOD(ZendFramework_Loader_AutoloaderFactory, isSubclassOf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *className_param = NULL, *type_param = NULL;
	zval *className = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &type_param);

	zephir_get_strval(className, className_param);
	zephir_get_strval(type, type_param);


	ZEPHIR_RETURN_CALL_FUNCTION("is_subclass_of", &_0, className, type);
	zephir_check_call_status();
	RETURN_MM();

}

