
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
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Storage_Message_MessageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Storage\\Message, MessageInterface, zendframework, mail_storage_message_messageinterface, zendframework_mail_storage_message_messageinterface_method_entry);

	return SUCCESS;

}

/**
 * return toplines as found after headers
 *
 * @return string toplines
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Message_MessageInterface, getTopLines);

/**
 * check if flag is set
 *
 * @param mixed $flag a flag name, use constants defined in Zend\Mail\Storage
 * @return bool true if set, otherwise false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Message_MessageInterface, hasFlag);

/**
 * get all set flags
 *
 * @return array array with flags, key and value are the same for easy lookup
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Message_MessageInterface, getFlags);

