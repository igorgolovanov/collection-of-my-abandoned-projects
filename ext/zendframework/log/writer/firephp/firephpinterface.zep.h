
extern zend_class_entry *zendframework_log_writer_firephp_firephpinterface_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Log_Writer_FirePhp_FirePhpInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_firephp_firephpinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_firephp_firephpinterface_warn, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_firephp_firephpinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_firephp_firephpinterface_trace, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_log_writer_firephp_firephpinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_log_writer_firephp_firephpinterface_method_entry) {
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, getEnabled, NULL)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, error, arginfo_zendframework_log_writer_firephp_firephpinterface_error)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, warn, arginfo_zendframework_log_writer_firephp_firephpinterface_warn)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, info, arginfo_zendframework_log_writer_firephp_firephpinterface_info)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, trace, arginfo_zendframework_log_writer_firephp_firephpinterface_trace)
	PHP_ABSTRACT_ME(ZendFramework_Log_Writer_FirePhp_FirePhpInterface, log, arginfo_zendframework_log_writer_firephp_firephpinterface_log)
  PHP_FE_END
};