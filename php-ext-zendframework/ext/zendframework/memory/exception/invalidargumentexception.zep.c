
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


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Exception for Zend\Memory component.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Memory_Exception_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Memory\\Exception, InvalidArgumentException, zendframework, memory_exception_invalidargumentexception, spl_ce_InvalidArgumentException, NULL, 0);

	zend_class_implements(zendframework_memory_exception_invalidargumentexception_ce TSRMLS_CC, 1, zendframework_memory_exception_exceptioninterface_ce);
	return SUCCESS;

}

