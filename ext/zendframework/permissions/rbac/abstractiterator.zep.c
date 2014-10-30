
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_AbstractIterator) {

	ZEPHIR_REGISTER_CLASS(Zend\\Permissions\\Rbac, AbstractIterator, zendframework, permissions_rbac_abstractiterator, zendframework_permissions_rbac_abstractiterator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var int
	 */
	zend_declare_property_long(zendframework_permissions_rbac_abstractiterator_ce, SL("index"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_permissions_rbac_abstractiterator_ce, SL("children"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_permissions_rbac_abstractiterator_ce TSRMLS_CC, 1, spl_ce_RecursiveIterator);
	return SUCCESS;

}

/**
 * (PHP 5 &gt;= 5.0.0)<br/>
 * Return the current element
 * @link http://php.net/manual/en/iterator.current.php
 * @return mixed Can return any type.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, current) {

	zval *index = NULL, *value, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("index"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(index, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("children"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, index, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * (PHP 5 &gt;= 5.0.0)<br/>
 * Move forward to next element
 * @link http://php.net/manual/en/iterator.next.php
 * @return void Any returned value is ignored.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, next) {


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("index") TSRMLS_CC));

}

/**
 * (PHP 5 &gt;= 5.0.0)<br/>
 * Return the key of the current element
 * @link http://php.net/manual/en/iterator.key.php
 * @return int|null scalar on success, or null on failure.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, key) {


	RETURN_MEMBER(this_ptr, "index");

}

/**
 * (PHP 5 &gt;= 5.0.0)<br/>
 * Checks if current position is valid
 * @link http://php.net/manual/en/iterator.valid.php
 * @return bool The return value will be casted to boolean and then evaluated.
 * Returns true on success or false on failure.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, valid) {

	zval *_0, *_1;
	int index;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("index"), PH_NOISY_CC);
	index = zephir_get_numberval(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("children"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset_long(_1, index));

}

/**
 * (PHP 5 &gt;= 5.0.0)<br/>
 * Rewind the Iterator to the first element
 * @link http://php.net/manual/en/iterator.rewind.php
 * @return void Any returned value is ignored.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("index"), _0 TSRMLS_CC);

}

/**
 * (PHP 5 &gt;= 5.1.0)<br/>
 * Returns if an iterator can be created fot the current entry.
 * @link http://php.net/manual/en/recursiveiterator.haschildren.php
 * @return bool true if the current entry can be iterated over, otherwise returns false.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, hasChildren) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *current = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current",  NULL);
		zephir_check_call_status();
		if (zephir_is_instance_of(current, SL("RecursiveIterator") TSRMLS_CC)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * (PHP 5 &gt;= 5.1.0)<br/>
 * Returns an iterator for the current entry.
 * @link http://php.net/manual/en/recursiveiterator.getchildren.php
 * @return RecursiveIterator An iterator for the current entry.
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, getChildren) {

	zval *index = NULL, *value, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("index"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(index, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("children"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, index, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractIterator, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("children"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

