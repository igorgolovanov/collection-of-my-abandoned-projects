
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Code_Reflection_DocBlock_Tag_PhpDocTypedTagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Reflection\\DocBlock\\Tag, PhpDocTypedTagInterface, zendframework, code_reflection_docblock_tag_phpdoctypedtaginterface, zendframework_code_reflection_docblock_tag_phpdoctypedtaginterface_method_entry);

	return SUCCESS;

}

/**
 * Return all types supported by the tag definition
 *
 * @return string[]
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Reflection_DocBlock_Tag_PhpDocTypedTagInterface, getTypes);

