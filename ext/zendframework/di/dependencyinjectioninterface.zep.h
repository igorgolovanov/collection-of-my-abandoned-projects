
extern zend_class_entry *zendframework_di_dependencyinjectioninterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Di_DependencyInjectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_di_dependencyinjectioninterface_newinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_di_dependencyinjectioninterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Di_DependencyInjectionInterface, newInstance, arginfo_zendframework_di_dependencyinjectioninterface_newinstance)
  PHP_FE_END
};
