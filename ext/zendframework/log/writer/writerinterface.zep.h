
extern zend_class_entry *zendframework_log_writer_writerinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Log_Writer_WriterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_writerinterface_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_writerinterface_setformatter, 0, 0, 1)
	ZEND_ARG_INFO(0, formatter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_writerinterface_write, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, event, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_log_writer_writerinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_WriterInterface, addFilter, arginfo_zendframework_log_writer_writerinterface_addfilter)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_WriterInterface, setFormatter, arginfo_zendframework_log_writer_writerinterface_setformatter)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_WriterInterface, write, arginfo_zendframework_log_writer_writerinterface_write)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_WriterInterface, shutdown, NULL)
  PHP_FE_END
};
