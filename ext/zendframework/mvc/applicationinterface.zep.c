
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
ZEPHIR_INIT_CLASS(ZendFramework_Mvc_ApplicationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mvc, ApplicationInterface, zendframework, mvc_applicationinterface, zendframework_mvc_applicationinterface_method_entry);

	zend_class_implements(zendframework_mvc_applicationinterface_ce TSRMLS_CC, 1, zendframework_eventmanager_eventscapableinterface_ce);
	return SUCCESS;

}

/**
 * Get the locator object
 *
 * @return \Zend\ServiceManager\ServiceLocatorInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_ApplicationInterface, getServiceManager);

/**
 * Get the request object
 *
 * @return \Zend\Stdlib\RequestInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_ApplicationInterface, getRequest);

/**
 * Get the response object
 *
 * @return \Zend\Stdlib\ResponseInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_ApplicationInterface, getResponse);

/**
 * Run the application
 *
 * @return self
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mvc_ApplicationInterface, run);

