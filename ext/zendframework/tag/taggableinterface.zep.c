
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
ZEPHIR_INIT_CLASS(ZendFramework_Tag_TaggableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Tag, TaggableInterface, zendframework, tag_taggableinterface, zendframework_tag_taggableinterface_method_entry);

	return SUCCESS;

}

/**
 * Get the title of the tag
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_TaggableInterface, getTitle);

/**
 * Get the weight of the tag
 *
 * @return float
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_TaggableInterface, getWeight);

/**
 * Set a parameter
 *
 * @param string $name
 * @param string $value
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_TaggableInterface, setParam);

/**
 * Get a parameter
 *
 * @param  string $name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Tag_TaggableInterface, getParam);

