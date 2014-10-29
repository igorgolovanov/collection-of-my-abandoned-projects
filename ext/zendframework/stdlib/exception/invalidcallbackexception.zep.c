
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
 * Invalid callback exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Exception_InvalidCallbackException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib\\Exception, InvalidCallbackException, zendframework, stdlib_exception_invalidcallbackexception, zendframework_stdlib_exception_domainexception_ce, NULL, 0);

	zend_class_implements(zendframework_stdlib_exception_invalidcallbackexception_ce TSRMLS_CC, 1, zendframework_stdlib_exception_exceptioninterface_ce);
	return SUCCESS;

}

