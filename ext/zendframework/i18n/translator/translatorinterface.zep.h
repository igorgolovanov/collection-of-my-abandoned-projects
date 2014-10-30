
extern zend_class_entry *zendframework_i18n_translator_translatorinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_I18n_Translator_TranslatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_i18n_translator_translatorinterface_translate, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, textDomain)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_i18n_translator_translatorinterface_translateplural, 0, 0, 3)
	ZEND_ARG_INFO(0, singular)
	ZEND_ARG_INFO(0, plural)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, textDomain)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_i18n_translator_translatorinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_I18n_Translator_TranslatorInterface, translate, arginfo_zendframework_i18n_translator_translatorinterface_translate)
	PHP_ABSTRACT_ME(ZendFramework_I18n_Translator_TranslatorInterface, translatePlural, arginfo_zendframework_i18n_translator_translatorinterface_translateplural)
  PHP_FE_END
};
