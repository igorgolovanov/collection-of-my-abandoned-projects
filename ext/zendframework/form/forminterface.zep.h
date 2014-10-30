
extern zend_class_entry *zendframework_form_forminterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Form_FormInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_forminterface_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_forminterface_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_forminterface_setbindonvalidate, 0, 0, 1)
	ZEND_ARG_INFO(0, bindOnValidateFlag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_forminterface_setinputfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, inputFilter, ZendFramework\\InputFilter\\InputFilterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_forminterface_getdata, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_form_forminterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, setData, arginfo_zendframework_form_forminterface_setdata)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, bind, arginfo_zendframework_form_forminterface_bind)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, setBindOnValidate, arginfo_zendframework_form_forminterface_setbindonvalidate)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, setInputFilter, arginfo_zendframework_form_forminterface_setinputfilter)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, getInputFilter, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, isValid, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, getData, arginfo_zendframework_form_forminterface_getdata)
	PHP_ABSTRACT_ME(ZendFramework_Form_FormInterface, setValidationGroup, NULL)
  PHP_FE_END
};
