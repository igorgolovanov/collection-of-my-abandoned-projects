
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
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Address_AddressInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Address, AddressInterface, zendframework, mail_address_addressinterface, zendframework_mail_address_addressinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Mail_Address_AddressInterface, getEmail);

ZEPHIR_DOC_METHOD(ZendFramework_Mail_Address_AddressInterface, getName);

ZEPHIR_DOC_METHOD(ZendFramework_Mail_Address_AddressInterface, toString);

