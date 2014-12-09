
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Exception class for Zend\Tag\Cloud\Decorator
 */
ZEPHIR_INIT_CLASS(ZendFramework_Tag_Cloud_Decorator_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Tag\\Cloud\\Decorator\\Exception, ExceptionInterface, zendframework, tag_cloud_decorator_exception_exceptioninterface, NULL);

	zend_class_implements(zendframework_tag_cloud_decorator_exception_exceptioninterface_ce TSRMLS_CC, 1, zendframework_tag_exception_exceptioninterface_ce);
	return SUCCESS;

}

