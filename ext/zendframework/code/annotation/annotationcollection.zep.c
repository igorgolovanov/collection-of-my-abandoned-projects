
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_array.h"
#include "kernel/iterator.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Code_Annotation_AnnotationCollection) {

	ZEPHIR_REGISTER_CLASS_EX(Zend\\Code\\Annotation, AnnotationCollection, zendframework, code_annotation_annotationcollection, spl_ce_ArrayObject, zendframework_code_annotation_annotationcollection_method_entry, 0);

	return SUCCESS;

}

/**
 * Checks if the collection has annotations for a class
 *
 * @param  string $class
 * @return bool
 */
PHP_METHOD(ZendFramework_Code_Annotation_AnnotationCollection, hasAnnotation) {

	zend_object_iterator *_0;
	zval *class_param = NULL, *annotation = NULL, *className = NULL;
	zval *class = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &class_param);

	zephir_get_strval(class, class_param);


	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		annotation = *tmp;
		}
		ZEPHIR_INIT_NVAR(className);
		zephir_get_class(className, annotation, 0 TSRMLS_CC);
		if (ZEPHIR_IS_EQUAL(className, class)) {
			RETURN_MM_BOOL(1);
		}
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

