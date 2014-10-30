
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
ZEPHIR_INIT_CLASS(ZendFramework_Code_Reflection_DocBlock_Tag_TagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Reflection\\DocBlock\\Tag, TagInterface, zendframework, code_reflection_docblock_tag_taginterface, zendframework_code_reflection_docblock_tag_taginterface_method_entry);

	zend_class_implements(zendframework_code_reflection_docblock_tag_taginterface_ce TSRMLS_CC, 1, zendframework_code_generic_prototype_prototypeinterface_ce);
	return SUCCESS;

}

/**
 * @param  string $content
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Reflection_DocBlock_Tag_TagInterface, initialize);

