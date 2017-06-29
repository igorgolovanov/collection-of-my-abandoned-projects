
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
 * Feed exceptions
 *
 * Interface to represent exceptions that occur during Feed operations.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Feed_Writer_Exception_ExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Feed\\Writer\\Exception, ExceptionInterface, zendframework, feed_writer_exception_exceptioninterface, NULL);

	return SUCCESS;

}

