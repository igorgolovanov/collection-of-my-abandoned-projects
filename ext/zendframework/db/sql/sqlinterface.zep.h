
extern zend_class_entry *zendframework_db_sql_sqlinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Db_Sql_SqlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_sql_sqlinterface_getsqlstring, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, adapterPlatform, ZendFramework\\Db\\Adapter\\Platform\\PlatformInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_db_sql_sqlinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Db_Sql_SqlInterface, getSqlString, arginfo_zendframework_db_sql_sqlinterface_getsqlstring)
  PHP_FE_END
};
