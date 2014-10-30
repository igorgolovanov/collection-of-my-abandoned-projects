
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
ZEPHIR_INIT_CLASS(ZendFramework_Console_ColorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Console, ColorInterface, zendframework, console_colorinterface, NULL);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("NORMAL"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("RESET"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("BLACK"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("RED"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("GREEN"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("YELLOW"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("BLUE"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("MAGENTA"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("CYAN"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("WHITE"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("GRAY"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_RED"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_GREEN"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_YELLOW"), 12 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_BLUE"), 13 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_MAGENTA"), 14 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_CYAN"), 15 TSRMLS_CC);

	zend_declare_class_constant_long(zendframework_console_colorinterface_ce, SL("LIGHT_WHITE"), 16 TSRMLS_CC);

	return SUCCESS;

}

