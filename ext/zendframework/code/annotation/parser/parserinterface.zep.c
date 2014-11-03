
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Code_Annotation_Parser_ParserInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Code\\Annotation\\Parser, ParserInterface, zendframework, code_annotation_parser_parserinterface, zendframework_code_annotation_parser_parserinterface_method_entry);

	return SUCCESS;

}

/**
 * Respond to the "createAnnotation" event
 *
 * @param  EventInterface  $e
 * @return false|object
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Annotation_Parser_ParserInterface, onCreateAnnotation);

/**
 * Register an annotation this parser will accept
 *
 * @param  mixed $annotation
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Annotation_Parser_ParserInterface, registerAnnotation);

/**
 * Register multiple annotations this parser will accept
 *
 * @param  array|\Traversable $annotations
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Code_Annotation_Parser_ParserInterface, registerAnnotations);

