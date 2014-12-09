
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
ZEPHIR_INIT_CLASS(ZendFramework_Uri_Exception_InvalidUriPartException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Uri\\Exception, InvalidUriPartException, zendframework, uri_exception_invaliduripartexception, zendframework_uri_exception_invalidargumentexception_ce, NULL, 0);

	/**
	 * Part-specific error codes
	 *
	 * @var int
	 */
	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_SCHEME"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_USER"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_PASSWORD"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_USERINFO"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_HOSTNAME"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_PORT"), 16 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_AUTHORITY"), 30 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_PATH"), 32 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_QUERY"), 64 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_uri_exception_invaliduripartexception_ce, SL("INVALID_FRAGMENT"), 128 TSRMLS_CC);

	return SUCCESS;

}

