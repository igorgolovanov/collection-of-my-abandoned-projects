
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
 * Marker interface for exceptions found in this component
 */
ZEPHIR_INIT_CLASS(ZendFramework_File_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\File\\Exception, ExceptionInterface, zendframework, file_exception_exceptioninterface, NULL);

	return SUCCESS;

}

