
extern zend_class_entry *zendframework_db_sql_preparablesqlinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_PreparableSqlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_sql_preparablesqlinterface_preparestatement, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, adapter, ZendFramework\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, statementContainer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_db_sql_preparablesqlinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Db_Sql_PreparableSqlInterface, prepareStatement, arginfo_zendframework_db_sql_preparablesqlinterface_preparestatement)
  PHP_FE_END
};
