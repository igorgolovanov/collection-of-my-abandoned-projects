
extern zend_class_entry *zendframework_eventmanager_filter_filteriterator_ce;

ZEPHIR_INIT_CLASS(ZendFramework_EventManager_Filter_FilterIterator);

PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, contains);
PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, remove);
PHP_METHOD(ZendFramework_EventManager_Filter_FilterIterator, next);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filter_filteriterator_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, datum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filter_filteriterator_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, datum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_eventmanager_filter_filteriterator_next, 0, 0, 0)
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_OBJ_INFO(0, chain, ZendFramework\\EventManager\\Filter\\FilterIterator, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_eventmanager_filter_filteriterator_method_entry) {
	PHP_ME(ZendFramework_EventManager_Filter_FilterIterator, contains, arginfo_zendframework_eventmanager_filter_filteriterator_contains, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Filter_FilterIterator, remove, arginfo_zendframework_eventmanager_filter_filteriterator_remove, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_EventManager_Filter_FilterIterator, next, arginfo_zendframework_eventmanager_filter_filteriterator_next, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
