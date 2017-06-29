
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Text_Table_Exception_InvalidDecoratorException) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Text\\Table\\Exception, InvalidDecoratorException, zendframework, text_table_exception_invaliddecoratorexception, spl_ce_DomainException, NULL, 0);

	zend_class_implements(zendframework_text_table_exception_invaliddecoratorexception_ce TSRMLS_CC, 1, zendframework_text_table_exception_exceptioninterface_ce);
	return SUCCESS;

}

