
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
ZEPHIR_INIT_CLASS(ZendFramework_Code_Annotation_AnnotationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Annotation, AnnotationInterface, zendframework, code_annotation_annotationinterface, zendframework_code_annotation_annotationinterface_method_entry);

	return SUCCESS;

}

/**
 * Initialize
 *
 * @param  string $content
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Annotation_AnnotationInterface, initialize);

