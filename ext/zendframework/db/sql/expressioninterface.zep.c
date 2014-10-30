
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_ExpressionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Sql, ExpressionInterface, zendframework, db_sql_expressioninterface, zendframework_db_sql_expressioninterface_method_entry);

	zend_declare_class_constant_string(zendframework_db_sql_expressioninterface_ce, SL("TYPE_IDENTIFIER"), "identifier" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_sql_expressioninterface_ce, SL("TYPE_VALUE"), "value" TSRMLS_CC);

	zend_declare_class_constant_string(zendframework_db_sql_expressioninterface_ce, SL("TYPE_LITERAL"), "literal" TSRMLS_CC);

	return SUCCESS;

}

/**
 * @abstract
 *
 * @return array of array|string should return an array in the format:
 *
 * array (
 *    // a sprintf formatted string
 *    string $specification,
 *
 *    // the values for the above sprintf formatted string
 *    array $values,
 *
 *    // an array of equal length of the $values array, with either TYPE_IDENTIFIER or TYPE_VALUE for each value
 *    array $types,
 * )
 *
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Sql_ExpressionInterface, getExpressionData);

