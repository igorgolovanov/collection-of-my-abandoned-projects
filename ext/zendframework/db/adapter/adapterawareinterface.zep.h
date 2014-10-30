
extern zend_class_entry *zendframework_db_adapter_adapterawareinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_AdapterAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_db_adapter_adapterawareinterface_setdbadapter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, adapter, ZendFramework\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_db_adapter_adapterawareinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Db_Adapter_AdapterAwareInterface, setDbAdapter, arginfo_zendframework_db_adapter_adapterawareinterface_setdbadapter)
  PHP_FE_END
};
