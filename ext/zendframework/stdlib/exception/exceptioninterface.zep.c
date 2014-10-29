
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Exception marker interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Exception, ExceptionInterface, zendframework, stdlib_exception_exceptioninterface, NULL);

	return SUCCESS;

}

