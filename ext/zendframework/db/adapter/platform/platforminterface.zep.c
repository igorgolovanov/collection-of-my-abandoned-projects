
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Platform_PlatformInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Platform, PlatformInterface, zendframework, db_adapter_platform_platforminterface, zendframework_db_adapter_platform_platforminterface_method_entry);

	return SUCCESS;

}

/**
 * Get name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, getName);

/**
 * Get quote identifier symbol
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, getQuoteIdentifierSymbol);

/**
 * Quote identifier
 *
 * @param  string $identifier
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteIdentifier);

/**
 * Quote identifier chain
 *
 * @param string|string[] $identifierChain
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteIdentifierChain);

/**
 * Get quote value symbol
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, getQuoteValueSymbol);

/**
 * Quote value
 *
 * Will throw a notice when used in a workflow that can be considered "unsafe"
 *
 * @param  string $value
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteValue);

/**
 * Quote Trusted Value
 *
 * The ability to quote values without notices
 *
 * @param $value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteTrustedValue);

/**
 * Quote value list
 *
 * @param string|string[] $valueList
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteValueList);

/**
 * Get identifier separator
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, getIdentifierSeparator);

/**
 * Quote identifier in fragment
 *
 * @param  string $identifier
 * @param  array $additionalSafeWords
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Platform_PlatformInterface, quoteIdentifierInFragment);

