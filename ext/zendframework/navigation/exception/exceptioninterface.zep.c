
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
/**
 * Navigation exception
 */
ZEPHIR_INIT_CLASS(ZendFramework_Navigation_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Navigation\\Exception, ExceptionInterface, zendframework, navigation_exception_exceptioninterface, NULL);

	return SUCCESS;

}

