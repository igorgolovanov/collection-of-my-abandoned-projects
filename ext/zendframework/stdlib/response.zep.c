
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Response) {

	ZEPHIR_REGISTER_CLASS(Zend\\Stdlib, Response, zendframework, stdlib_response, zendframework_stdlib_response_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(ZendFramework_Stdlib_Response, test) {

	zval *r;

	zephir_fetch_params(0, 1, 0, &r);



	if (!(zephir_is_instance_of(r, SL("Zend\\Stdlib\\Request") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'r' must be an instance of 'Zend\\\\Stdlib\\\\Request'", "", 0);
		return;
	}

}

