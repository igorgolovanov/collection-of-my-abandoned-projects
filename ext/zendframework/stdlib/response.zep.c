
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


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Stdlib, Response, zendframework, stdlib_response, zendframework_stdlib_message_ce, NULL, 0);

	zend_class_implements(zendframework_stdlib_response_ce TSRMLS_CC, 1, zendframework_stdlib_messageinterface_ce);
	zend_class_implements(zendframework_stdlib_response_ce TSRMLS_CC, 1, zendframework_stdlib_responseinterface_ce);
	return SUCCESS;

}

