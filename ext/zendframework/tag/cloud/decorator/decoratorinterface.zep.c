
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
/**
 * Interface for decorators
 */
ZEPHIR_INIT_CLASS(ZendFramework_Tag_Cloud_Decorator_DecoratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Tag\\Cloud\\Decorator, DecoratorInterface, zendframework, tag_cloud_decorator_decoratorinterface, zendframework_tag_cloud_decorator_decoratorinterface_method_entry);

	return SUCCESS;

}

/**
 * Constructor
 *
 * Allow passing options to the constructor.
 *
 * @param  mixed $options
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_Cloud_Decorator_DecoratorInterface, __construct);

/**
 * Render a list of tags
 *
 * @param  mixed $tags
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_Cloud_Decorator_DecoratorInterface, render);

