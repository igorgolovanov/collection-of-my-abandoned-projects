
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_Ddl_Column_ColumnInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Sql\\Ddl\\Column, ColumnInterface, zendframework, db_sql_ddl_column_columninterface, zendframework_db_sql_ddl_column_columninterface_method_entry);

	zend_declare_class_constant_string(zendframework_db_sql_ddl_column_columninterface_ce, SL("TYPE_IDENTIFIER"), "identifier" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_sql_ddl_column_columninterface_ce, SL("TYPE_VALUE"), "value" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_sql_ddl_column_columninterface_ce, SL("TYPE_LITERAL"), "literal" TSRMLS_CC);

	zend_class_implements(zendframework_db_sql_ddl_column_columninterface_ce TSRMLS_CC, 1, zendframework_db_sql_expressioninterface_ce);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_Ddl_Column_ColumnInterface, getName);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_Ddl_Column_ColumnInterface, isNullable);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_Ddl_Column_ColumnInterface, getDefault);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_Ddl_Column_ColumnInterface, getOptions);

