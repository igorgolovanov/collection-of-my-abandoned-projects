
extern zend_class_entry *zendframework_db_metadata_metadatainterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Db_Metadata_MetadataInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettablenames, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, includeViews)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettables, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, includeViews)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getviewnames, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getcolumnnames, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getcolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getcolumn, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getconstraints, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getconstraint, 0, 0, 2)
	ZEND_ARG_INFO(0, constraintName)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_getconstraintkeys, 0, 0, 2)
	ZEND_ARG_INFO(0, constraint)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettriggernames, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettriggers, 0, 0, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_metadata_metadatainterface_gettrigger, 0, 0, 1)
	ZEND_ARG_INFO(0, triggerName)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_db_metadata_metadatainterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getSchemas, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTableNames, arginfo_zendframework_db_metadata_metadatainterface_gettablenames)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTables, arginfo_zendframework_db_metadata_metadatainterface_gettables)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTable, arginfo_zendframework_db_metadata_metadatainterface_gettable)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getViewNames, arginfo_zendframework_db_metadata_metadatainterface_getviewnames)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getViews, arginfo_zendframework_db_metadata_metadatainterface_getviews)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getView, arginfo_zendframework_db_metadata_metadatainterface_getview)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getColumnNames, arginfo_zendframework_db_metadata_metadatainterface_getcolumnnames)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getColumns, arginfo_zendframework_db_metadata_metadatainterface_getcolumns)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getColumn, arginfo_zendframework_db_metadata_metadatainterface_getcolumn)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getConstraints, arginfo_zendframework_db_metadata_metadatainterface_getconstraints)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getConstraint, arginfo_zendframework_db_metadata_metadatainterface_getconstraint)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getConstraintKeys, arginfo_zendframework_db_metadata_metadatainterface_getconstraintkeys)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTriggerNames, arginfo_zendframework_db_metadata_metadatainterface_gettriggernames)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTriggers, arginfo_zendframework_db_metadata_metadatainterface_gettriggers)
	PHP_ABSTRACT_ME(ZendFramework_Db_Metadata_MetadataInterface, getTrigger, arginfo_zendframework_db_metadata_metadatainterface_gettrigger)
  PHP_FE_END
};
