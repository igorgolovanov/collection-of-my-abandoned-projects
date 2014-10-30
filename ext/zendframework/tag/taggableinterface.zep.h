
extern zend_class_entry *zendframework_tag_taggableinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Tag_TaggableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_tag_taggableinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_tag_taggableinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_tag_taggableinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Tag_TaggableInterface, getTitle, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Tag_TaggableInterface, getWeight, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Tag_TaggableInterface, setParam, arginfo_zendframework_tag_taggableinterface_setparam)
	PHP_ABSTRACT_ME(ZendFramework_Tag_TaggableInterface, getParam, arginfo_zendframework_tag_taggableinterface_getparam)
  PHP_FE_END
};
