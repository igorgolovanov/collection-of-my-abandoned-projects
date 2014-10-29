
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
ZEPHIR_INIT_CLASS(ZendFramework_Filter_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Filter, FilterInterface, zendframework, filter_filterinterface, zendframework_filter_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the result of filtering $value
 *
 * @param  mixed $value
 * @throws Exception\RuntimeException If filtering $value is impossible
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Filter_FilterInterface, filter);

