
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
 * Interface for Zend\Text\Table decorators
 */
ZEPHIR_INIT_CLASS(ZendFramework_Text_Table_Decorator_DecoratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Text\\Table\\Decorator, DecoratorInterface, zendframework, text_table_decorator_decoratorinterface, zendframework_text_table_decorator_decoratorinterface_method_entry);

	return SUCCESS;

}

/**
 * Get a single character for the top left corner
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getTopLeft);

/**
 * Get a single character for the top right corner
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getTopRight);

/**
 * Get a single character for the bottom left corner
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getBottomLeft);

/**
 * Get a single character for the bottom right corner
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getBottomRight);

/**
 * Get a single character for a vertical line
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getVertical);

/**
 * Get a single character for a horizontal line
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getHorizontal);

/**
 * Get a single character for a crossing line
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getCross);

/**
 * Get a single character for a vertical divider right
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getVerticalRight);

/**
 * Get a single character for a vertical divider left
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getVerticalLeft);

/**
 * Get a single character for a horizontal divider down
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getHorizontalDown);

/**
 * Get a single character for a horizontal divider up
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Text_Table_Decorator_DecoratorInterface, getHorizontalUp);

