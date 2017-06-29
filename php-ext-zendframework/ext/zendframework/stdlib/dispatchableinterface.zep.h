
extern zend_class_entry *zendframework_stdlib_dispatchableinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_DispatchableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_dispatchableinterface_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, ZendFramework\\Stdlib\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, ZendFramework\\Stdlib\\ResponseInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_dispatchableinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Stdlib_DispatchableInterface, dispatch, arginfo_zendframework_stdlib_dispatchableinterface_dispatch)
  PHP_FE_END
};
