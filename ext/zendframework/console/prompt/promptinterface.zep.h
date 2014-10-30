
extern zend_class_entry *zendframework_console_prompt_promptinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Console_Prompt_PromptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_console_prompt_promptinterface_setconsole, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, adapter, ZendFramework\\Console\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_console_prompt_promptinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Console_Prompt_PromptInterface, show, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Console_Prompt_PromptInterface, getLastResponse, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Console_Prompt_PromptInterface, getConsole, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Console_Prompt_PromptInterface, setConsole, arginfo_zendframework_console_prompt_promptinterface_setconsole)
  PHP_FE_END
};
