
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


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Exception thrown when SOAP PHP extension is not loaded
 */
ZEPHIR_INIT_CLASS(ZendFramework_Soap_Exception_ExtensionNotLoadedException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Soap\\Exception, ExtensionNotLoadedException, zendframework, soap_exception_extensionnotloadedexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

