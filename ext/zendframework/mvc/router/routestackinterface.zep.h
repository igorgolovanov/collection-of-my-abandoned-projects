
extern zend_class_entry *zendframework_mvc_router_routestackinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Mvc_Router_RouteStackInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routestackinterface_addroute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routestackinterface_addroutes, 0, 0, 1)
	ZEND_ARG_INFO(0, routes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routestackinterface_removeroute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_mvc_router_routestackinterface_setroutes, 0, 0, 1)
	ZEND_ARG_INFO(0, routes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_mvc_router_routestackinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteStackInterface, addRoute, arginfo_zendframework_mvc_router_routestackinterface_addroute)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteStackInterface, addRoutes, arginfo_zendframework_mvc_router_routestackinterface_addroutes)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteStackInterface, removeRoute, arginfo_zendframework_mvc_router_routestackinterface_removeroute)
	PHP_ABSTRACT_ME(ZendFramework_Mvc_Router_RouteStackInterface, setRoutes, arginfo_zendframework_mvc_router_routestackinterface_setroutes)
  PHP_FE_END
};
