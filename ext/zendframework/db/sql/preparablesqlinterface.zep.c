
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_PreparableSqlInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Sql, PreparableSqlInterface, zendframework, db_sql_preparablesqlinterface, zendframework_db_sql_preparablesqlinterface_method_entry);

	return SUCCESS;

}

/**
 * @param AdapterInterface $adapter
 * @param StatementContainerInterface $statementContainer
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_PreparableSqlInterface, prepareStatement);

