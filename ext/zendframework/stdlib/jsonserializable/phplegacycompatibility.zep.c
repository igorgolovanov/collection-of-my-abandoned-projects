
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
 * Interface compatible with the built-in JsonSerializable interface
 *
 * JsonSerializable was introduced in PHP 5.4.0.
 *
 * @see http://php.net/manual/class.jsonserializable.php
 */
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_JsonSerializable_PhpLegacyCompatibility) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\JsonSerializable, PhpLegacyCompatibility, zendframework, stdlib_jsonserializable_phplegacycompatibility, zendframework_stdlib_jsonserializable_phplegacycompatibility_method_entry);

	return SUCCESS;

}

/**
 * Returns data which can be serialized by json_encode().
 *
 * @return mixed
 * @see    http://php.net/manual/jsonserializable.jsonserialize.php
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_JsonSerializable_PhpLegacyCompatibility, jsonSerialize);

