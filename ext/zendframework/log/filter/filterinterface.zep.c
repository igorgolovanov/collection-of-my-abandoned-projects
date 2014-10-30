
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
ZEPHIR_INIT_CLASS(ZendFramework_Log_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Log\\Filter, FilterInterface, zendframework, log_filter_filterinterface, zendframework_log_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns TRUE to accept the message, FALSE to block it.
 *
 * @param array $event event data
 * @return bool accepted?
 */
ZEPHIR_DOC_METHOD(ZendFramework_Log_Filter_FilterInterface, filter);

