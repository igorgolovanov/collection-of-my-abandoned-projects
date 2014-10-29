
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
ZEPHIR_INIT_CLASS(ZendFramework_Di_ServiceLocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Di, ServiceLocatorInterface, zendframework, di_servicelocatorinterface, zendframework_di_servicelocatorinterface_method_entry);

	zend_class_implements(zendframework_di_servicelocatorinterface_ce TSRMLS_CC, 1, zendframework_di_locatorinterface_ce);
	return SUCCESS;

}

/**
 * Register a service with the locator
 *
 * @abstract
 * @param  string                  $name
 * @param  mixed                   $service
 * @return ServiceLocatorInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_ServiceLocatorInterface, set);

