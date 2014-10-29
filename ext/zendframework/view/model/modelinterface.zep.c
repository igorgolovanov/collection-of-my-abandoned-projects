
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
/**
 * Interface describing a view model.
 *
 * Extends "Countable"; count() should return the number of children attached
 * to the model.
 *
 * Extends "IteratorAggregate"; should allow iterating over children.
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Model_ModelInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Model, ModelInterface, zendframework, view_model_modelinterface, zendframework_view_model_modelinterface_method_entry);

	zend_class_implements(zendframework_view_model_modelinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(zendframework_view_model_modelinterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * Set renderer option/hint
 *
 * @param  string $name
 * @param  mixed $value
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setOption);

/**
 * Set renderer options/hints en masse
 *
 * @param  array|\Traversable $options
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setOptions);

/**
 * Get renderer options/hints
 *
 * @return array|\Traversable
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, getOptions);

/**
 * Get a single view variable
 *
 * @param  string       $name
 * @param  mixed|null   $default (optional) default value if the variable is not present.
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, getVariable);

/**
 * Set view variable
 *
 * @param  string $name
 * @param  mixed $value
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setVariable);

/**
 * Set view variables en masse
 *
 * @param  array|\ArrayAccess $variables
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setVariables);

/**
 * Get view variables
 *
 * @return array|\ArrayAccess
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, getVariables);

/**
 * Set the template to be used by this model
 *
 * @param  string $template
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setTemplate);

/**
 * Get the template to be used by this model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, getTemplate);

/**
 * Add a child model
 *
 * @param  ModelInterface $child
 * @param  null|string $captureTo Optional; if specified, the "capture to" value to set on the child
 * @param  null|bool $append Optional; if specified, append to child  with the same capture
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, addChild);

/**
 * Return all children.
 *
 * Return specifies an array, but may be any iterable object.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, getChildren);

/**
 * Does the model have any children?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, hasChildren);

/**
 * Set the name of the variable to capture this model to, if it is a child model
 *
 * @param  string $capture
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setCaptureTo);

/**
 * Get the name of the variable to which to capture this model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, captureTo);

/**
 * Set flag indicating whether or not this is considered a terminal or standalone model
 *
 * @param  bool $terminate
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setTerminal);

/**
 * Is this considered a terminal or standalone model?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, terminate);

/**
 * Set flag indicating whether or not append to child  with the same capture
 *
 * @param  bool $append
 * @return ModelInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, setAppend);

/**
 * Is this append to child  with the same capture?
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Model_ModelInterface, isAppend);

