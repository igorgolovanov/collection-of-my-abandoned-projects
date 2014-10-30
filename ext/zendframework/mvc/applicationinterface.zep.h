
extern zend_class_entry *zendframework_mvc_applicationinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mvc_ApplicationInterface);

ZEPHIR_INIT_FUNCS(zendframework_mvc_applicationinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Mvc_ApplicationInterface, getServiceManager, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_ApplicationInterface, getRequest, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_ApplicationInterface, getResponse, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_ApplicationInterface, run, NULL)
  PHP_FE_END
};
