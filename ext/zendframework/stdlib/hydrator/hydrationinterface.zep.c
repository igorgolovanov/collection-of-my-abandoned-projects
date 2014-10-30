
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
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_HydrationInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator, HydrationInterface, zendframework, stdlib_hydrator_hydrationinterface, zendframework_stdlib_hydrator_hydrationinterface_method_entry);

	return SUCCESS;

}

/**
 * Hydrate $object with the provided $data.
 *
 * @param  array $data
 * @param  object $object
 * @return object
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_Hydrator_HydrationInterface, hydrate);

