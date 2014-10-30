
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_Rbac) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Permissions\\Rbac, Rbac, zendframework, permissions_rbac_rbac, zendframework_permissions_rbac_abstractiterator_ce, zendframework_permissions_rbac_rbac_method_entry, 0);

	/**
	 * flag: whether or not to create roles automatically if
	 * they do not exist.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(zendframework_permissions_rbac_rbac_ce, SL("createMissingRoles"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param  bool                     $createMissingRoles
 * @return \Zend\Permissions\Rbac\Rbac
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, setCreateMissingRoles) {

	zval *createMissingRoles_param = NULL;
	zend_bool createMissingRoles;

	zephir_fetch_params(0, 1, 0, &createMissingRoles_param);

	createMissingRoles = zephir_get_boolval(createMissingRoles_param);


	zephir_update_property_this(this_ptr, SL("createMissingRoles"), createMissingRoles ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, getCreateMissingRoles) {


	RETURN_MEMBER(this_ptr, "createMissingRoles");

}

/**
 * Add a child.
 *
 * @param  string|RoleInterface               $child
 * @param  array|RoleInterface|null           $parents
 * @return Rbac
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, addRole) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_7 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *child = NULL, *parents = NULL, *parent = NULL, *role = NULL, **_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &child, &parents);

	ZEPHIR_SEPARATE_PARAM(child);
	if (!parents) {
		ZEPHIR_CPY_WRT(parents, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(parents);
	}


	if (Z_TYPE_P(child) == IS_STRING) {
		ZEPHIR_INIT_NVAR(child);
		object_init_ex(child, zendframework_permissions_rbac_role_ce);
		ZEPHIR_CALL_METHOD(NULL, child, "__construct", NULL, child);
		zephir_check_call_status();
	}
	if (unlikely(!(zephir_instance_of_ev(child, zendframework_permissions_rbac_roleinterface_ce TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_permissions_rbac_exception_invalidargumentexception_ce, "Child must be a string or implement Zend\\\\Permissions\\\\Rbac\\\\RoleInterface", "zendframework/permissions/rbac/rbac.zep", 61);
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(parents))) {
		if (Z_TYPE_P(parents) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(parents);
			array_init_size(parents, 2);
			zephir_array_fast_append(parents, parents);
		}
		zephir_is_iterable(parents, &_1, &_0, 0, 0, "zendframework/permissions/rbac/rbac.zep", 77);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(parent, _2);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("createMissingRoles"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				ZEPHIR_CALL_METHOD(&_4, this_ptr, "hasrole", &_5, parent);
				zephir_check_call_status();
				if (!(zephir_is_true(_4))) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "addrole", &_6, parent);
					zephir_check_call_status();
				}
			}
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "getrole", &_7, parent);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(role, _4);
			ZEPHIR_CALL_METHOD(NULL, role, "addchild", NULL, child);
			zephir_check_call_status();
		}
	}
	zephir_update_property_array_append(this_ptr, SL("children"), child TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Is a child with $name registered?
 *
 * @param  \Zend\Permissions\Rbac\RoleInterface|string $objectOrName
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, hasRole) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *objectOrName, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objectOrName);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "getrole", NULL, objectOrName);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM_BOOL(1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CPY_WRT(_0, EG(exception));
		if (zephir_is_instance_of(_0, SL("Exception\\InvalidArgumentException") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get a child.
 *
 * @param  \Zend\Permissions\Rbac\RoleInterface|string $objectOrName
 * @return RoleInterface
 * @throws Exception\InvalidArgumentException
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, getRole) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *exceptionMsg = NULL;
	zval *objectOrName, *iterator, *leaf = NULL, *requiredRole = NULL, *name = NULL, *_1, **_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objectOrName);



	_0 = Z_TYPE_P(objectOrName) != IS_STRING;
	if (_0) {
		_0 = !(zephir_instance_of_ev(objectOrName, zendframework_permissions_rbac_roleinterface_ce TSRMLS_CC));
	}
	if (unlikely(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_permissions_rbac_exception_invalidargumentexception_ce, "Expected string or implement Zend\\\\Permissions\\\\Rbac\\\\RoleInterface", "zendframework/permissions/rbac/rbac.zep", 115);
		return;
	}
	if (Z_TYPE_P(objectOrName) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&requiredRole, objectOrName, "getname",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(requiredRole, objectOrName);
	}
	ZEPHIR_INIT_VAR(iterator);
	object_init_ex(iterator, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, this_ptr, _1);
	zephir_check_call_status();
	zephir_is_iterable(iterator, &_3, &_2, 0, 0, "zendframework/permissions/rbac/rbac.zep", 128);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(leaf, _4);
		ZEPHIR_CALL_METHOD(&name, leaf, "getname",  NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(name, requiredRole)) {
			RETURN_CCTOR(leaf);
		}
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVS(_5, "No role with name \"", requiredRole, "\" could be found");
	zephir_get_strval(exceptionMsg, _5);
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, zendframework_permissions_rbac_exception_invalidargumentexception_ce);
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, exceptionMsg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_6, "zendframework/permissions/rbac/rbac.zep", 129 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Determines if access is granted by checking the role and child roles for permission.
 *
 * @param  RoleInterface|string             $role
 * @param  string                           $permission
 * @param  AssertionInterface|Callable|null $assert
 * @throws Exception\InvalidArgumentException
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_Rbac, isGranted) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *permission = NULL;
	zval *role, *permission_param = NULL, *assert = NULL, *roleInstance = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &role, &permission_param, &assert);

	zephir_get_strval(permission, permission_param);
	if (!assert) {
		assert = ZEPHIR_GLOBAL(global_null);
	}


	if (!(ZEPHIR_IS_EMPTY(assert))) {
		if (zephir_instance_of_ev(assert, zendframework_permissions_rbac_assertioninterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0, assert, "assert", NULL, this_ptr);
			zephir_check_call_status();
			if (zephir_is_true(_0)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			if (unlikely(!zephir_is_callable(assert TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_permissions_rbac_exception_invalidargumentexception_ce, "Assertions must be a Callable or an instance of Zend\\\\Permissions\\\\Rbac\\\\AssertionInterface", "zendframework/permissions/rbac/rbac.zep", 154);
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_0, "call_user_func", &_1, assert, this_ptr);
			zephir_check_call_status();
			if (!(zephir_is_true(_0))) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrole", NULL, role);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(roleInstance, _0);
	ZEPHIR_RETURN_CALL_METHOD(roleInstance, "haspermission", NULL, permission);
	zephir_check_call_status();
	RETURN_MM();

}

