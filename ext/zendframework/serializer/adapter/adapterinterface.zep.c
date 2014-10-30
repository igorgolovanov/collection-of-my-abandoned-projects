
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
ZEPHIR_INIT_CLASS(ZendFramework_Serializer_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Serializer\\Adapter, AdapterInterface, zendframework, serializer_adapter_adapterinterface, zendframework_serializer_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Generates a storable representation of a value.
 *
 * @param  mixed $value Data to serialize
 * @return string
 * @throws \Zend\Serializer\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Serializer_Adapter_AdapterInterface, serialize);

/**
 * Creates a PHP value from a stored representation.
 *
 * @param  string $serialized Serialized string
 * @return mixed
 * @throws \Zend\Serializer\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Serializer_Adapter_AdapterInterface, unserialize);

