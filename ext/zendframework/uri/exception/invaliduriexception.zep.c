
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
/**
 * Exceptions for Zend\Uri
 */
ZEPHIR_INIT_CLASS(ZendFramework_Uri_Exception_InvalidUriException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Uri\\Exception, InvalidUriException, zendframework, uri_exception_invaliduriexception, zendframework_uri_exception_invalidargumentexception_ce, NULL, 0);

	return SUCCESS;

}

