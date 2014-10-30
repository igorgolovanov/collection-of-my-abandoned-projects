
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
/**
 * Polyfill for JsonSerializable
 *
 * JsonSerializable was introduced in PHP 5.4.0.
 *
 * @see http://php.net/manual/class.jsonserializable.php
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_JsonSerializable) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, JsonSerializable, zendframework, stdlib_jsonserializable, NULL);

	return SUCCESS;

}

