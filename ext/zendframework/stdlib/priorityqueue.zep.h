
extern zend_class_entry *zendframework_stdlib_priorityqueue_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_PriorityQueue);

PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, insert);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, remove);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, isEmpty);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, count);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, top);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, extract);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, getIterator);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, serialize);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, unserialize);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toArray);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toDataArray);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, toPriorityArray);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, setInternalQueueClass);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, contains);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, hasPriority);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, getQueue);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, __clone);
PHP_METHOD(ZendFramework_Stdlib_PriorityQueue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_insert, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, datum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_todataarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_topriorityarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_setinternalqueueclass, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, datum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_priorityqueue_haspriority, 0, 0, 1)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_priorityqueue_method_entry) {
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, insert, arginfo_zendframework_stdlib_priorityqueue_insert, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, remove, arginfo_zendframework_stdlib_priorityqueue_remove, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, top, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, extract, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, unserialize, arginfo_zendframework_stdlib_priorityqueue_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, toArray, arginfo_zendframework_stdlib_priorityqueue_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, toDataArray, arginfo_zendframework_stdlib_priorityqueue_todataarray, ZEND_ACC_PRIVATE)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, toPriorityArray, arginfo_zendframework_stdlib_priorityqueue_topriorityarray, ZEND_ACC_PRIVATE)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, setInternalQueueClass, arginfo_zendframework_stdlib_priorityqueue_setinternalqueueclass, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, contains, arginfo_zendframework_stdlib_priorityqueue_contains, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, hasPriority, arginfo_zendframework_stdlib_priorityqueue_haspriority, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, getQueue, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityQueue, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
