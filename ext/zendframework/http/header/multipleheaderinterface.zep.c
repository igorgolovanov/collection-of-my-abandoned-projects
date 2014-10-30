
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
ZEPHIR_INIT_CLASS(ZendFramework_Http_Header_MultipleHeaderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Http\\Header, MultipleHeaderInterface, zendframework, http_header_multipleheaderinterface, zendframework_http_header_multipleheaderinterface_method_entry);

	zend_class_implements(zendframework_http_header_multipleheaderinterface_ce TSRMLS_CC, 1, zendframework_http_header_headerinterface_ce);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Http_Header_MultipleHeaderInterface, toStringMultipleHeaders);

