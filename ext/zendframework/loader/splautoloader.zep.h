
extern zend_class_entry *zendframework_loader_splautoloader_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Loader_SplAutoloader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_splautoloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_splautoloader_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_splautoloader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_loader_splautoloader_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Loader_SplAutoloader, __construct, arginfo_zendframework_loader_splautoloader___construct)
	PHP_ABSTRACT_ME(ZendFramework_Loader_SplAutoloader, setOptions, arginfo_zendframework_loader_splautoloader_setoptions)
	PHP_ABSTRACT_ME(ZendFramework_Loader_SplAutoloader, autoload, arginfo_zendframework_loader_splautoloader_autoload)
	PHP_ABSTRACT_ME(ZendFramework_Loader_SplAutoloader, register, NULL)
  PHP_FE_END
};
