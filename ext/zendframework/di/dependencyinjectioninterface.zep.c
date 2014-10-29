
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
ZEPHIR_INIT_CLASS(ZendFramework_Di_DependencyInjectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Di, DependencyInjectionInterface, zendframework, di_dependencyinjectioninterface, zendframework_di_dependencyinjectioninterface_method_entry);

	zend_class_implements(zendframework_di_dependencyinjectioninterface_ce TSRMLS_CC, 1, zendframework_di_locatorinterface_ce);
	return SUCCESS;

}

/**
 * Retrieve a new instance of a class
 *
 * Forces retrieval of a discrete instance of the given class, using the
 * constructor parameters provided.
 *
 * @param  mixed       $name   Class name or service alias
 * @param  array       $params Parameters to pass to the constructor
 * @return object|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_Di_DependencyInjectionInterface, newInstance);

