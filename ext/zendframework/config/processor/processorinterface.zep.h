
extern zend_class_entry *zendframework_config_processor_processorinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Config_Processor_ProcessorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_processor_processorinterface_process, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_config_processor_processorinterface_processvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_config_processor_processorinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Config_Processor_ProcessorInterface, process, arginfo_zendframework_config_processor_processorinterface_process)
	PHP_ABSTRACT_ME(ZendFramework_Config_Processor_ProcessorInterface, processValue, arginfo_zendframework_config_processor_processorinterface_processvalue)
  PHP_FE_END
};