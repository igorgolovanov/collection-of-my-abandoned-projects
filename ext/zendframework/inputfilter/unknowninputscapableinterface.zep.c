
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
/**
 * Implementors of this interface may report on the existence of unknown input,
 * as well as retrieve all unknown values.
 */
ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_UnknownInputsCapableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\InputFilter, UnknownInputsCapableInterface, zendframework, inputfilter_unknowninputscapableinterface, zendframework_inputfilter_unknowninputscapableinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_UnknownInputsCapableInterface, hasUnknown);

ZEPHIR_DOC_METHOD(ZendFramework_InputFilter_UnknownInputsCapableInterface, getUnknown);

