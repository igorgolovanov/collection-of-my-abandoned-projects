
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Acl_Role_Registry) {

	ZEPHIR_REGISTER_CLASS(Zend\\Permissions\\Acl\\Role, Registry, zendframework, permissions_acl_role_registry, zendframework_permissions_acl_role_registry_method_entry, 0);

	/**
	 * Internal Role registry data storage
	 *
	 * @var array
	 */
	zend_declare_property_null(zendframework_permissions_acl_role_registry_ce, SL("roles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a Role having an identifier unique to the registry
 *
 * The $parents parameter may be a reference to, or the string identifier for,
 * a Role existing in the registry, or $parents may be passed as an array of
 * these - mixing string identifiers and objects is ok - to indicate the Roles
 * from which the newly added Role will directly inherit.
 *
 * In order to resolve potential ambiguities with conflicting rules inherited
 * from different parents, the most recently added parent takes precedence over
 * parents that were previously added. In other words, the first parent added
 * will have the least priority, and the last parent added will have the
 * highest priority.
 *
 * @param  RoleInterface                           $role
 * @param  RoleInterface|string|array|Traversable $parents
 * @throws Exception\InvalidArgumentException
 * @return Registry Provides a fluent interface
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, add) {

	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	HashTable *_5;
	HashPosition _4;
	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *role, *parents = NULL, *roleId = NULL, *roleParentId = NULL, *roleParents, *roleInfo, *parent = NULL, *e = NULL, *roleParent = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_6, *_7 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &parents);

	if (!parents) {
		ZEPHIR_CPY_WRT(parents, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(parents);
	}


	if (!(zephir_instance_of_ev(role, zendframework_permissions_acl_role_roleinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'role' must be an instance of 'ZendFramework\\\\Permissions\\\\Acl\\\\Role\\\\RoleInterface'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&roleId, role, "getroleid",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, roleId);
	zephir_check_call_status();
	if (unlikely(!!zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role id \"", roleId, "\" already exists in the registry");
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_permissions_acl_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/permissions/acl/role/registry.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(roleParents);
	array_init(roleParents);
	if (Z_TYPE_P(parents) != IS_NULL) {
		_3 = Z_TYPE_P(parents) != IS_ARRAY;
		if (!(_3)) {
			_3 = !(zephir_is_instance_of(parents, SL("Traversable") TSRMLS_CC));
		}
		if (_3) {
			ZEPHIR_INIT_NVAR(parents);
			array_init_size(parents, 2);
			zephir_array_fast_append(parents, parents);
		}
		zephir_is_iterable(parents, &_5, &_4, 0, 0, "zendframework/permissions/acl/role/registry.zep", 77);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(parent, _6);

			/* try_start_1: */

				if (zephir_instance_of_ev(parent, zendframework_permissions_acl_role_roleinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&roleParentId, parent, "getroleid",  NULL);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					ZEPHIR_CPY_WRT(roleParentId, parent);
				}
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "get", &_8, roleParentId);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(roleParent, _7);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_CPY_WRT(e, EG(exception));
				if (zephir_is_instance_of(e, SL("Exception") TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVS(_1, "Parent Role id \"", roleParentId, "\" does not exist");
					zephir_get_strval(exceptionMsg, _1);
					ZEPHIR_INIT_LNVAR(_2);
					object_init_ex(_2, zendframework_permissions_acl_exception_invalidargumentexception_ce);
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_LONG(_9, 0);
					ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_10, exceptionMsg, _9, e);
					zephir_check_call_status();
					zephir_throw_exception_debug(_2, "zendframework/permissions/acl/role/registry.zep", 72 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_update_zval(&roleParents, roleParentId, &roleParent, PH_COPY | PH_SEPARATE);
			zephir_update_property_array_multi(this_ptr, SL("roles"), &role TSRMLS_CC, SL("zsz"), 4, roleParentId, SL("children"), roleId);
		}
	}
	ZEPHIR_INIT_VAR(roleInfo);
	array_init_size(roleInfo, 4);
	zephir_array_update_string(&roleInfo, SL("instance"), &role, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&roleInfo, SL("parents"), &roleParents, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_9);
	array_init(_9);
	zephir_array_update_string(&roleInfo, SL("children"), &_9, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("roles"), roleId, roleInfo TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the identified Role
 *
 * The $role parameter can either be a Role or a Role identifier.
 *
 * @param  RoleInterface|string $role
 * @throws Exception\InvalidArgumentException
 * @return RoleInterface
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptionMsg = NULL;
	zval *role, *instance = NULL, *roleId = NULL, *roles = NULL, *_0 = NULL, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &role);



	if (zephir_instance_of_ev(role, zendframework_permissions_acl_role_roleinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&roleId, role, "getroleid",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(roleId, role);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, role);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role \"", roleId, "\" not found");
		zephir_get_strval(exceptionMsg, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zendframework_permissions_acl_exception_invalidargumentexception_ce);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, exceptionMsg);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "zendframework/permissions/acl/role/registry.zep", 111 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, roleId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 113 TSRMLS_CC);
	ZEPHIR_CPY_WRT(roles, _4);
	zephir_array_fetch_string(&_4, roles, SL("instance"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 114 TSRMLS_CC);
	ZEPHIR_CPY_WRT(instance, _4);
	RETURN_CCTOR(instance);

}

/**
 * Returns true if and only if the Role exists in the registry
 *
 * The $role parameter can either be a Role or a Role identifier.
 *
 * @param  RoleInterface|string $role
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *role, *roleId = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &role);



	if (zephir_instance_of_ev(role, zendframework_permissions_acl_role_roleinterface_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&roleId, role, "getroleid",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(roleId, role);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, roleId));

}

/**
 * Returns an array of an existing Role's parents
 *
 * The array keys are the identifiers of the parent Roles, and the values are
 * the parent Role instances. The parent Roles are ordered in this array by
 * ascending priority. The highest priority parent Role, last in the array,
 * corresponds with the parent Role most recently added.
 *
 * If the Role does not have any parents, then an empty array is returned.
 *
 * @param  RoleInterface|string $role
 * @return array
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, getParents) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *role, *parents, *info, *instance = NULL, *roleId = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &role);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, role);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(instance, _0);
	ZEPHIR_CALL_METHOD(&roleId, instance, "getroleid",  NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_fetch(&info, _1, roleId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 159 TSRMLS_CC);
	zephir_array_fetch_string(&parents, info, SL("parents"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 160 TSRMLS_CC);
	RETURN_CTOR(parents);

}

/**
 * Returns true if and only if $role inherits from $inherit
 *
 * Both parameters may be either a Role or a Role identifier. If
 * $onlyParents is true, then $role must inherit directly from
 * $inherit in order to return true. By default, this method looks
 * through the entire inheritance DAG to determine whether $role
 * inherits from $inherit through its ancestor Roles.
 *
 * @param  RoleInterface|string  $role
 * @param  RoleInterface|string  $inherit
 * @param  bool                    $onlyParents
 * @throws Exception\InvalidArgumentException
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, inherits) {

	zephir_fcall_cache_entry *_12 = NULL;
	HashTable *_10;
	HashPosition _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool onlyParents, inherits, _5;
	zval *role = NULL, *inherit = NULL, *onlyParents_param = NULL, *e = NULL, *roleId = NULL, *inheritId = NULL, *parent = NULL, *parentId = NULL, *exceptionCode = NULL, *exceptionMsg = NULL, *_0 = NULL, *_1, *_2, *_3, *_4, *_6, *_7, *_8, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &role, &inherit, &onlyParents_param);

	ZEPHIR_SEPARATE_PARAM(role);
	ZEPHIR_SEPARATE_PARAM(inherit);
	if (!onlyParents_param) {
		onlyParents = 0;
	} else {
		onlyParents = zephir_get_boolval(onlyParents_param);
	}



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, role);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(role, _0);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, inherit);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(inherit, _0);
		ZEPHIR_CALL_METHOD(&roleId, role, "getroleid",  NULL);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&inheritId, inherit, "getroleid",  NULL);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_is_instance_of(e, SL("Exception\\ExceptionInterface") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&exceptionMsg, e, "getmessage",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&exceptionCode, e, "getcode",  NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, zendframework_permissions_acl_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg, exceptionCode, e);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "zendframework/permissions/acl/role/registry.zep", 193 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, roleId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 196 TSRMLS_CC);
	zephir_array_fetch_string(&_4, _3, SL("parents"), PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 196 TSRMLS_CC);
	inherits = zephir_array_isset(_4, inheritId);
	_5 = inherits;
	if (!(_5)) {
		_5 = onlyParents;
	}
	if (_5) {
		RETURN_MM_BOOL(inherits);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_fetch(&_7, _6, roleId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 202 TSRMLS_CC);
	zephir_array_fetch_string(&_8, _7, SL("parents"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 202 TSRMLS_CC);
	zephir_is_iterable(_8, &_10, &_9, 0, 0, "zendframework/permissions/acl/role/registry.zep", 207);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(parentId, _10, _9);
		ZEPHIR_GET_HVALUE(parent, _11);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "inherits", &_12, parentId, inheritId);
		zephir_check_call_status();
		if (zephir_is_true(_0)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Removes the Role from the registry
 *
 * The $role parameter can either be a Role or a Role identifier.
 *
 * @param  RoleInterface|string $role
 * @throws Exception\InvalidArgumentException
 * @return Registry Provides a fluent interface
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, remove) {

	HashTable *_5, *_11;
	HashPosition _4, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *role = NULL, *e = NULL, *child = NULL, *childId = NULL, *info, *exceptionCode = NULL, *exceptionMsg = NULL, *roleId = NULL, *_0 = NULL, *_1, *_2, *_3, **_6, *_7, *_8, *_9, **_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &role);

	ZEPHIR_SEPARATE_PARAM(role);



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, role);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(role, _0);
		ZEPHIR_CALL_METHOD(&roleId, role, "getroleid",  NULL);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_is_instance_of(e, SL("Exception\\ExceptionInterface") TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&exceptionMsg, e, "getmessage",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&exceptionCode, e, "getcode",  NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, zendframework_permissions_acl_exception_invalidargumentexception_ce);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, exceptionMsg, exceptionCode, e);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "zendframework/permissions/acl/role/registry.zep", 229 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_fetch(&info, _2, roleId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 232 TSRMLS_CC);
	zephir_array_fetch_string(&_3, info, SL("children"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 234 TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "zendframework/permissions/acl/role/registry.zep", 238);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(childId, _5, _4);
		ZEPHIR_GET_HVALUE(child, _6);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
		zephir_array_fetch(&_8, _7, childId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 235 TSRMLS_CC);
		zephir_array_fetch_string(&_9, _8, SL("parents"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 235 TSRMLS_CC);
		zephir_array_unset(&_9, roleId, PH_SEPARATE);
	}
	zephir_array_fetch_string(&_8, info, SL("parents"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 238 TSRMLS_CC);
	zephir_is_iterable(_8, &_11, &_10, 0, 0, "zendframework/permissions/acl/role/registry.zep", 242);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HMKEY(childId, _11, _10);
		ZEPHIR_GET_HVALUE(child, _12);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
		zephir_array_fetch(&_9, _7, childId, PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 239 TSRMLS_CC);
		zephir_array_fetch_string(&_13, _9, SL("children"), PH_NOISY | PH_READONLY, "zendframework/permissions/acl/role/registry.zep", 239 TSRMLS_CC);
		zephir_array_unset(&_13, roleId, PH_SEPARATE);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("roles"), PH_NOISY_CC);
	zephir_array_unset(&_7, roleId, PH_SEPARATE);
	RETURN_THIS();

}

/**
 * Removes all Roles from the registry
 *
 * @return Registry Provides a fluent interface
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, removeAll) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("roles"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get all roles in the registry
 *
 * @return array
 */
PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, getRoles) {


	RETURN_MEMBER(this_ptr, "roles");

}

PHP_METHOD(ZendFramework_Permissions_Acl_Role_Registry, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("roles"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

