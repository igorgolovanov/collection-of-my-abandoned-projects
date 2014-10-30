
extern zend_class_entry *zendframework_mvc_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routeinterface_factory, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routeinterface_match, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, ZendFramework\\Stdlib\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routeinterface_assemble, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_mvc_router_routeinterface_method_entry) {
	ZEND_FENTRY(factory, NULL, arginfo_zendframework_mvc_router_routeinterface_factory, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteInterface, match, arginfo_zendframework_mvc_router_routeinterface_match)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteInterface, assemble, arginfo_zendframework_mvc_router_routeinterface_assemble)
  PHP_FE_END
};
