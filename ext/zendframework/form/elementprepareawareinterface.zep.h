
extern zend_class_entry *zendframework_form_elementprepareawareinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Form_ElementPrepareAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_elementprepareawareinterface_prepareelement, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, form, ZendFramework\\Form\\FormInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_form_elementprepareawareinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Form_ElementPrepareAwareInterface, prepareElement, arginfo_zendframework_form_elementprepareawareinterface_prepareelement)
  PHP_FE_END
};