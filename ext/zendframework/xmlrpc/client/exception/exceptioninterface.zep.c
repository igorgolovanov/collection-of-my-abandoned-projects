
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Base class for all Zend\XmlRpc\Client\* exceptions
 */
ZEPHIR_INIT_CLASS(ZendFramework_XmlRpc_Client_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\XmlRpc\\Client\\Exception, ExceptionInterface, zendframework, xmlrpc_client_exception_exceptioninterface, NULL);

	zend_class_implements(zendframework_xmlrpc_client_exception_exceptioninterface_ce TSRMLS_CC, 1, zendframework_xmlrpc_exception_exceptioninterface_ce);
	return SUCCESS;

}

