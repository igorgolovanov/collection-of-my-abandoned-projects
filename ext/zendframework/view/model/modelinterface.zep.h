
extern zend_class_entry *zendframework_view_model_modelinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_View_Model_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_getvariable, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setvariable, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setvariables, 0, 0, 1)
	ZEND_ARG_INFO(0, variables)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_settemplate, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_addchild, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, child, ZendFramework\\View\\Model\\ModelInterface, 0)
	ZEND_ARG_INFO(0, captureTo)
	ZEND_ARG_INFO(0, append)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setcaptureto, 0, 0, 1)
	ZEND_ARG_INFO(0, capture)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setterminal, 0, 0, 1)
	ZEND_ARG_INFO(0, terminate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_model_modelinterface_setappend, 0, 0, 1)
	ZEND_ARG_INFO(0, append)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_view_model_modelinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setOption, arginfo_zendframework_view_model_modelinterface_setoption)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setOptions, arginfo_zendframework_view_model_modelinterface_setoptions)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, getVariable, arginfo_zendframework_view_model_modelinterface_getvariable)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setVariable, arginfo_zendframework_view_model_modelinterface_setvariable)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setVariables, arginfo_zendframework_view_model_modelinterface_setvariables)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, getVariables, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setTemplate, arginfo_zendframework_view_model_modelinterface_settemplate)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, getTemplate, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, addChild, arginfo_zendframework_view_model_modelinterface_addchild)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, getChildren, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, hasChildren, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setCaptureTo, arginfo_zendframework_view_model_modelinterface_setcaptureto)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, captureTo, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setTerminal, arginfo_zendframework_view_model_modelinterface_setterminal)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, terminate, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, setAppend, arginfo_zendframework_view_model_modelinterface_setappend)
	PHP_ABSTRACT_ME(ZendFramework_View_Model_ModelInterface, isAppend, NULL)
  PHP_FE_END
};
