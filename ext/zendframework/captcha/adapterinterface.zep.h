
extern zend_class_entry *zendframework_captcha_adapterinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Captcha_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_captcha_adapterinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_captcha_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Captcha_AdapterInterface, generate, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Captcha_AdapterInterface, setName, arginfo_zendframework_captcha_adapterinterface_setname)
	PHP_ABSTRACT_ME(ZendFramework_Captcha_AdapterInterface, getName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Captcha_AdapterInterface, getHelperName, NULL)
  PHP_FE_END
};
