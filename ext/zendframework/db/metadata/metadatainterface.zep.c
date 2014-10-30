
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
ZEPHIR_INIT_CLASS(ZendFramework_Db_Metadata_MetadataInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Metadata, MetadataInterface, zendframework, db_metadata_metadatainterface, zendframework_db_metadata_metadatainterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getSchemas);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTableNames);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTables);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTable);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getViewNames);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getViews);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getView);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getColumnNames);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getColumns);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getColumn);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getConstraints);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getConstraint);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getConstraintKeys);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTriggerNames);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTriggers);

ZEPHIR_DOC_METHOD(ZendFramework_Db_Metadata_MetadataInterface, getTrigger);

