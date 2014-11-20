
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
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * ArrayObject that acts as a stack with regards to iteration
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayStack) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib, ArrayStack, zendframework, stdlib_arraystack, spl_ce_ArrayObject, zendframework_stdlib_arraystack_method_entry, 0);

	return SUCCESS;

}

/**
 * Retrieve iterator
 *
 * Retrieve an array copy of the object, reverse its order, and return an
 * ArrayIterator with that reversed array.
 *
 * @return ArrayIterator
 */
PHP_METHOD(ZendFramework_Stdlib_ArrayStack, getIterator) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *iterator, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&data, this_ptr, "getarraycopy", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "array_reverse", &_1, data);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(data, _0);
	ZEPHIR_INIT_VAR(iterator);
	object_init_ex(iterator, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, iterator, "__construct", NULL, data);
	zephir_check_call_status();
	RETURN_CCTOR(iterator);

}

