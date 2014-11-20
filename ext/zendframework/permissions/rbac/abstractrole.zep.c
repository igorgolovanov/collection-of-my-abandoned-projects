
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(ZendFramework_Permissions_Rbac_AbstractRole) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Permissions\\Rbac, AbstractRole, zendframework, permissions_rbac_abstractrole, zendframework_permissions_rbac_abstractiterator_ce, zendframework_permissions_rbac_abstractrole_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var null|RoleInterface
	 */
	zend_declare_property_null(zendframework_permissions_rbac_abstractrole_ce, SL("parent"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(zendframework_permissions_rbac_abstractrole_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(zendframework_permissions_rbac_abstractrole_ce, SL("permissions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_permissions_rbac_abstractrole_ce TSRMLS_CC, 1, zendframework_permissions_rbac_roleinterface_ce);
	return SUCCESS;

}

/**
 * Get the name of the role.
 *
 * @return string
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, getName) {


	RETURN_MEMBER(this_ptr, "name");

}

/**
 * Add permission to the role.
 *
 * @param string $name
 * @return RoleInterface
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, addPermission) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("permissions"), name, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Checks if a permission exists for this role or any child roles.
 *
 * @param  string $name
 * @return bool
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, hasPermission) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *iterator, *leaf = NULL, *_0, *_1, **_4, *_5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("permissions"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(iterator);
	object_init_ex(iterator, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, this_ptr, _1);
	zephir_check_call_status();
	zephir_is_iterable(iterator, &_3, &_2, 0, 0, "zendframework/permissions/rbac/abstractrole.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(leaf, _4);
		ZEPHIR_CALL_METHOD(&_5, leaf, "haspermission", NULL, name);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Add a child.
 *
 * @param  RoleInterface|string $child
 * @return RoleInterface
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, addChild) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *child = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &child);

	ZEPHIR_SEPARATE_PARAM(child);


	if (Z_TYPE_P(child) == IS_STRING) {
		ZEPHIR_INIT_NVAR(child);
		object_init_ex(child, zendframework_permissions_rbac_role_ce);
		ZEPHIR_CALL_METHOD(NULL, child, "__construct", NULL, child);
		zephir_check_call_status();
	}
	if (unlikely(!(zephir_instance_of_ev(child, zendframework_permissions_rbac_roleinterface_ce TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zendframework_permissions_rbac_exception_invalidargumentexception_ce, "Child must be a string or implement Zend\\Permissions\\Rbac\\RoleInterface", "zendframework/permissions/rbac/abstractrole.zep", 93);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, child, "setparent", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("children"), child TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param  RoleInterface $parent
 * @return RoleInterface
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, setParent) {

	zval *parent;

	zephir_fetch_params(0, 1, 0, &parent);



	if (!(zephir_instance_of_ev(parent, zendframework_permissions_rbac_roleinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'parent' must be an instance of 'ZendFramework\\Permissions\\Rbac\\RoleInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("parent"), parent TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @return null|RoleInterface
 */
PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, getParent) {


	RETURN_MEMBER(this_ptr, "parent");

}

PHP_METHOD(ZendFramework_Permissions_Rbac_AbstractRole, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("permissions"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("children"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

