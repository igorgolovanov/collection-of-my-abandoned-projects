
extern zend_class_entry *zendframework_view_resolver_resolverinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_View_Resolver_ResolverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_view_resolver_resolverinterface_resolve, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, renderer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_view_resolver_resolverinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_View_Resolver_ResolverInterface, resolve, arginfo_zendframework_view_resolver_resolverinterface_resolve)
  PHP_FE_END
};
