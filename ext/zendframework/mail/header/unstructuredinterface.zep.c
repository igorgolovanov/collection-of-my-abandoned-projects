
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
 * Marker interface for unstructured headers.
 */
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Header_UnstructuredInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Header, UnstructuredInterface, zendframework, mail_header_unstructuredinterface, NULL);

	zend_declare_class_constant_bool(zendframework_mail_header_unstructuredinterface_ce, SL("FORMAT_ENCODED"), 1 TSRMLS_CC);

	zend_declare_class_constant_bool(zendframework_mail_header_unstructuredinterface_ce, SL("FORMAT_RAW"), 0 TSRMLS_CC);

	zend_class_implements(zendframework_mail_header_unstructuredinterface_ce TSRMLS_CC, 1, zendframework_mail_header_headerinterface_ce);
	return SUCCESS;

}

