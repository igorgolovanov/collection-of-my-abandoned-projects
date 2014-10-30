
extern zend_class_entry *zendframework_view_renderer_rendererinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_View_Renderer_RendererInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_renderer_rendererinterface_setresolver, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resolver, ZendFramework\\View\\Resolver\\ResolverInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_renderer_rendererinterface_render, 0, 0, 1)
	ZEND_ARG_INFO(0, nameOrModel)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_view_renderer_rendererinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_View_Renderer_RendererInterface, getEngine, NULL)
	PHP_ABSTRACT_ME(ZendFramework_View_Renderer_RendererInterface, setResolver, arginfo_zendframework_view_renderer_rendererinterface_setresolver)
	PHP_ABSTRACT_ME(ZendFramework_View_Renderer_RendererInterface, render, arginfo_zendframework_view_renderer_rendererinterface_render)
  PHP_FE_END
};
