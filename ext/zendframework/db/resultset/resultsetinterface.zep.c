
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_ResultSet_ResultSetInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\ResultSet, ResultSetInterface, zendframework, db_resultset_resultsetinterface, zendframework_db_resultset_resultsetinterface_method_entry);

	zend_class_implements(zendframework_db_resultset_resultsetinterface_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Can be anything traversable|array
 * @abstract
 * @param $dataSource
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_ResultSet_ResultSetInterface, initialize);

/**
 * Field terminology is more correct as information coming back
 * from the database might be a column, and/or the result of an
 * operation or intersection of some data
 * @abstract
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_ResultSet_ResultSetInterface, getFieldCount);

