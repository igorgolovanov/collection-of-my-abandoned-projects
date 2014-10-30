
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
ZEPHIR_INIT_CLASS(ZendFramework_Authentication_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Authentication\\Adapter, AdapterInterface, zendframework, authentication_adapter_adapterinterface, zendframework_authentication_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Performs an authentication attempt
 *
 * @return \Zend\Authentication\Result
 * @throws \Zend\Authentication\Adapter\Exception\ExceptionInterface If authentication cannot be performed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Authentication_Adapter_AdapterInterface, authenticate);

