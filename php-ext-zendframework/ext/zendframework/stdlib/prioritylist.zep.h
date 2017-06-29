
extern zend_class_entry *zendframework_stdlib_prioritylist_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_PriorityList);

PHP_METHOD(ZendFramework_Stdlib_PriorityList, insert);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, setPriority);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, remove);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, clear);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, get);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, sort);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, compare);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, isLIFO);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, rewind);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, current);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, key);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, next);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, valid);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, count);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, toArray);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, _returnItemPriority);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, _returnItemData);
PHP_METHOD(ZendFramework_Stdlib_PriorityList, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_setpriority, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_compare, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, item1, 0)
	ZEND_ARG_ARRAY_INFO(0, item2, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_islifo, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist__returnitempriority, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_prioritylist__returnitemdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_prioritylist_method_entry) {
	PHP_ME(ZendFramework_Stdlib_PriorityList, insert, arginfo_zendframework_stdlib_prioritylist_insert, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, setPriority, arginfo_zendframework_stdlib_prioritylist_setpriority, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, remove, arginfo_zendframework_stdlib_prioritylist_remove, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, get, arginfo_zendframework_stdlib_prioritylist_get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, sort, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Stdlib_PriorityList, compare, arginfo_zendframework_stdlib_prioritylist_compare, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Stdlib_PriorityList, isLIFO, arginfo_zendframework_stdlib_prioritylist_islifo, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, toArray, arginfo_zendframework_stdlib_prioritylist_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_PriorityList, _returnItemPriority, arginfo_zendframework_stdlib_prioritylist__returnitempriority, ZEND_ACC_PRIVATE)
	PHP_ME(ZendFramework_Stdlib_PriorityList, _returnItemData, arginfo_zendframework_stdlib_prioritylist__returnitemdata, ZEND_ACC_PRIVATE)
	PHP_ME(ZendFramework_Stdlib_PriorityList, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
