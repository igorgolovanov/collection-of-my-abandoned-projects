
extern zend_class_entry *zendframework_form_fieldsetinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Form_FieldsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, elementOrFieldset)
	ZEND_ARG_ARRAY_INFO(0, flags, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, elementOrFieldset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, elementOrFieldset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, elementOrFieldset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_setpriority, 0, 0, 2)
	ZEND_ARG_INFO(0, elementOrFieldset)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_populatevalues, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_setobject, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_allowobjectbinding, 0, 0, 1)
	ZEND_ARG_INFO(0, object)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_sethydrator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, hydrator, ZendFramework\\Stdlib\\Hydrator\\HydratorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_form_fieldsetinterface_bindvalues, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_form_fieldsetinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, add, arginfo_zendframework_form_fieldsetinterface_add)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, has, arginfo_zendframework_form_fieldsetinterface_has)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, get, arginfo_zendframework_form_fieldsetinterface_get)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, remove, arginfo_zendframework_form_fieldsetinterface_remove)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, setPriority, arginfo_zendframework_form_fieldsetinterface_setpriority)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, getElements, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, getFieldsets, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, populateValues, arginfo_zendframework_form_fieldsetinterface_populatevalues)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, setObject, arginfo_zendframework_form_fieldsetinterface_setobject)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, getObject, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, allowObjectBinding, arginfo_zendframework_form_fieldsetinterface_allowobjectbinding)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, setHydrator, arginfo_zendframework_form_fieldsetinterface_sethydrator)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, getHydrator, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, bindValues, arginfo_zendframework_form_fieldsetinterface_bindvalues)
	PHP_ABSTRACT_ME(ZendFramework_Form_FieldsetInterface, allowValueBinding, NULL)
  PHP_FE_END
};
