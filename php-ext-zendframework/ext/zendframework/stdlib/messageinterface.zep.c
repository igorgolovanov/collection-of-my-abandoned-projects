
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_MessageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, MessageInterface, zendframework, stdlib_messageinterface, zendframework_stdlib_messageinterface_method_entry);

	return SUCCESS;

}

/**
 * Set metadata
 *
 * @param  string|int|array|\Traversable $spec
 * @param  mixed $value
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_MessageInterface, setMetadata);

/**
 * Get metadata
 *
 * @param  null|string|int $key
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_MessageInterface, getMetadata);

/**
 * Set content
 *
 * @param  mixed $content
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_MessageInterface, setContent);

/**
 * Get content
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_MessageInterface, getContent);

