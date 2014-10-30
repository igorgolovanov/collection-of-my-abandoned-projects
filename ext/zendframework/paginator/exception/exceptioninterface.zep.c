
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Paginator_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Paginator\\Exception, ExceptionInterface, zendframework, paginator_exception_exceptioninterface, NULL);

	return SUCCESS;

}

