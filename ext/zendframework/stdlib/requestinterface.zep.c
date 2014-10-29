
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_RequestInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, RequestInterface, zendframework, stdlib_requestinterface, NULL);

	zend_class_implements(zendframework_stdlib_requestinterface_ce TSRMLS_CC, 1, zendframework_stdlib_messageinterface_ce);
	return SUCCESS;

}

