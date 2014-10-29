
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


/**
 * Logic exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Exception_LogicException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib\\Exception, LogicException, zendframework, stdlib_exception_logicexception, spl_ce_LogicException, NULL, 0);

	zend_class_implements(zendframework_stdlib_exception_logicexception_ce TSRMLS_CC, 1, zendframework_stdlib_exception_exceptioninterface_ce);
	return SUCCESS;

}

