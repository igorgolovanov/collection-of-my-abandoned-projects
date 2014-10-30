
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_StatementContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter, StatementContainerInterface, zendframework, db_adapter_statementcontainerinterface, zendframework_db_adapter_statementcontainerinterface_method_entry);

	return SUCCESS;

}

/**
 * Set sql
 *
 * @param $sql
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_StatementContainerInterface, setSql);

/**
 * Get sql
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_StatementContainerInterface, getSql);

/**
 * Set parameter container
 *
 * @param ParameterContainer $parameterContainer
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_StatementContainerInterface, setParameterContainer);

/**
 * Get parameter container
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_StatementContainerInterface, getParameterContainer);

