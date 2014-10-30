
extern zend_class_entry *zendframework_config_writer_writerinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Config_Writer_WriterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_writer_writerinterface_tofile, 0, 0, 2)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, config)
	ZEND_ARG_INFO(0, exclusiveLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_writer_writerinterface_tostring, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_config_writer_writerinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Config_Writer_WriterInterface, toFile, arginfo_zendframework_config_writer_writerinterface_tofile)
	PHP_ABSTRACT_ME(ZendFramework_Config_Writer_WriterInterface, toString, arginfo_zendframework_config_writer_writerinterface_tostring)
  PHP_FE_END
};
