
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
 * XML generator adapter interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_XmlRpc_Generator_GeneratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\XmlRpc\\Generator, GeneratorInterface, zendframework, xmlrpc_generator_generatorinterface, zendframework_xmlrpc_generator_generatorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, getEncoding);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, setEncoding);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, openElement);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, closeElement);

/**
 * Return XML as a string
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, saveXml);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, stripDeclaration);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, flush);

ZEPHIR_DOC_METHOD(ZendFramework_XmlRpc_Generator_GeneratorInterface, __toString);

