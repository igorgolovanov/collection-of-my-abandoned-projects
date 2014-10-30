
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
 * Deprecated by https://github.com/zendframework/zf2/pull/5636
 *
 * @deprecated
 */
ZEPHIR_INIT_CLASS(ZendFramework_Form_FieldsetPrepareAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Form, FieldsetPrepareAwareInterface, zendframework, form_fieldsetprepareawareinterface, zendframework_form_fieldsetprepareawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Prepare the fieldset element (called while this fieldset is added to another one)
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Form_FieldsetPrepareAwareInterface, prepareFieldset);

