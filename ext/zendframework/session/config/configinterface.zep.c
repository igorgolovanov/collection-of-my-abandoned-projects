
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
 * Standard session configuration
 */
ZEPHIR_INIT_CLASS(ZendFramework_Session_Config_ConfigInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Session\\Config, ConfigInterface, zendframework, session_config_configinterface, zendframework_session_config_configinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setOptions);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getOptions);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setOption);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getOption);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, hasOption);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, toArray);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setName);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getName);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setSavePath);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getSavePath);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setCookieLifetime);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getCookieLifetime);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setCookiePath);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getCookiePath);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setCookieDomain);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getCookieDomain);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setCookieSecure);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getCookieSecure);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setCookieHttpOnly);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getCookieHttpOnly);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setUseCookies);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getUseCookies);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, setRememberMeSeconds);

ZEPHIR_DOC_METHOD(ZendFramework_Session_Config_ConfigInterface, getRememberMeSeconds);

