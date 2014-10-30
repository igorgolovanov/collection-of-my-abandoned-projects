
extern zend_class_entry *zendframework_inputfilter_inputfilterawareinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_InputFilter_InputFilterAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_inputfilter_inputfilterawareinterface_setinputfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, inputFilter, ZendFramework\\InputFilter\\InputFilterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_inputfilter_inputfilterawareinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_InputFilter_InputFilterAwareInterface, setInputFilter, arginfo_zendframework_inputfilter_inputfilterawareinterface_setinputfilter)
	PHP_ABSTRACT_ME(ZendFramework_InputFilter_InputFilterAwareInterface, getInputFilter, NULL)
  PHP_FE_END
};