
extern zend_class_entry *zendframework_view_helper_helperinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_View_Helper_HelperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_helper_helperinterface_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, ZendFramework\\View\\Renderer\\RendererInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_view_helper_helperinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_View_Helper_HelperInterface, setView, arginfo_zendframework_view_helper_helperinterface_setview)
	PHP_ABSTRACT_ME(ZendFramework_View_Helper_HelperInterface, getView, NULL)
  PHP_FE_END
};
