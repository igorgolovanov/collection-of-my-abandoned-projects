
extern zend_class_entry *zendframework_db_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_AdapterInterface);

ZEPHIR_INIT_FUNCS(zendframework_db_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Db_Adapter_AdapterInterface, getDriver, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Db_Adapter_AdapterInterface, getPlatform, NULL)
  PHP_FE_END
};
