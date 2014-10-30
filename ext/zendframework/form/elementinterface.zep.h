
extern zend_class_entry *zendframework_form_elementinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Form_ElementInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_hasattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, arrayOrTraversable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementinterface_setmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_form_elementinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setName, arginfo_zendframework_form_elementinterface_setname)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getName, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setOptions, arginfo_zendframework_form_elementinterface_setoptions)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setOption, arginfo_zendframework_form_elementinterface_setoption)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getOption, arginfo_zendframework_form_elementinterface_getoption)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setAttribute, arginfo_zendframework_form_elementinterface_setattribute)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getAttribute, arginfo_zendframework_form_elementinterface_getattribute)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, hasAttribute, arginfo_zendframework_form_elementinterface_hasattribute)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setAttributes, arginfo_zendframework_form_elementinterface_setattributes)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setValue, arginfo_zendframework_form_elementinterface_setvalue)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getValue, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setLabel, arginfo_zendframework_form_elementinterface_setlabel)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getLabel, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, setMessages, arginfo_zendframework_form_elementinterface_setmessages)
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementInterface, getMessages, NULL)
  PHP_FE_END
};
