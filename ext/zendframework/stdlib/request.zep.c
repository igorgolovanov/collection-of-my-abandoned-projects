
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


ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Request) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, Request, zendframework, stdlib_request, NULL, 0);

	return SUCCESS;

}

