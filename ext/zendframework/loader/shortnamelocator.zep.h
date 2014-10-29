
extern zend_class_entry *zendframework_loader_shortnamelocator_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Loader_ShortNameLocator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_shortnamelocator_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_shortnamelocator_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_shortnamelocator_load, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_loader_shortnamelocator_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Loader_ShortNameLocator, isLoaded, arginfo_zendframework_loader_shortnamelocator_isloaded)
	PHP_ABSTRACT_ME(ZendFramework_Loader_ShortNameLocator, getClassName, arginfo_zendframework_loader_shortnamelocator_getclassname)
	PHP_ABSTRACT_ME(ZendFramework_Loader_ShortNameLocator, load, arginfo_zendframework_loader_shortnamelocator_load)
  PHP_FE_END
};
