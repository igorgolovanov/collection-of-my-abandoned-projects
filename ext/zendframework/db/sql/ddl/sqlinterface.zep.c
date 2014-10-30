
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_Ddl_SqlInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Sql\\Ddl, SqlInterface, zendframework, db_sql_ddl_sqlinterface, NULL);

	zend_class_implements(zendframework_db_sql_ddl_sqlinterface_ce TSRMLS_CC, 1, zendframework_db_sql_sqlinterface_ce);
	return SUCCESS;

}

