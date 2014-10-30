
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_File_Exception_BadMethodCallException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\File\\Exception, BadMethodCallException, zendframework, file_exception_badmethodcallexception, spl_ce_BadMethodCallException, NULL, 0);

	zend_class_implements(zendframework_file_exception_badmethodcallexception_ce TSRMLS_CC, 1, zendframework_file_exception_exceptioninterface_ce);
	return SUCCESS;

}

