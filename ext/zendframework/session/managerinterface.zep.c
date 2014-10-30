
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
/**
 * Session manager interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Session_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session, ManagerInterface, zendframework, session_managerinterface, zendframework_session_managerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setConfig);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getConfig);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setStorage);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getStorage);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setSaveHandler);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getSaveHandler);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, sessionExists);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, start);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, destroy);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, writeClose);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setName);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getName);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setId);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getId);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, regenerateId);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, rememberMe);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, forgetMe);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, expireSessionCookie);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, setValidatorChain);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, getValidatorChain);

ZEPHIR_DOC_METHOD(ZendFramework_Session_ManagerInterface, isValid);

