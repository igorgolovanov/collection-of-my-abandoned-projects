
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
 * Exception class for Zend\ProgressBar\Adapter
 */
ZEPHIR_INIT_CLASS(ZendFramework_ProgressBar_Adapter_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ProgressBar\\Adapter\\Exception, ExceptionInterface, zendframework, progressbar_adapter_exception_exceptioninterface, NULL);

	zend_class_implements(zendframework_progressbar_adapter_exception_exceptioninterface_ce TSRMLS_CC, 1, zendframework_progressbar_exception_exceptioninterface_ce);
	return SUCCESS;

}

