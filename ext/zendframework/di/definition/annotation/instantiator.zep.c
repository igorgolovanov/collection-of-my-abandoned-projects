
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
/**
* Annotation for instantiator
*/
ZEPHIR_INIT_CLASS(ZendFramework_Di_Definition_Annotation_Instantiator) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di\\Definition\\Annotation, Instantiator, zendframework, di_definition_annotation_instantiator, zendframework_di_definition_annotation_instantiator_method_entry, 0);

	/**
	 * @var mixed
	 */
	zend_declare_property_null(zendframework_di_definition_annotation_instantiator_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(zendframework_di_definition_annotation_instantiator_ce TSRMLS_CC, 1, zendframework_code_annotation_annotationinterface_ce);
	return SUCCESS;

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(ZendFramework_Di_Definition_Annotation_Instantiator, initialize) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("content"), content TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

