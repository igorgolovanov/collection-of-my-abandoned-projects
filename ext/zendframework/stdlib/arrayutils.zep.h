
extern zend_class_entry *zendframework_stdlib_arrayutils_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayUtils);

PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasStringKeys);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasIntegerKeys);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, hasNumericKeys);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, isList);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, isHashTable);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, inArray);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, iteratorToArray);
PHP_METHOD(ZendFramework_Stdlib_ArrayUtils, merge);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_hasstringkeys, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_hasintegerkeys, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_hasnumerickeys, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_islist, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_ishashtable, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowEmpty)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_inarray, 0, 0, 2)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_ARRAY_INFO(0, haystack, 0)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_iteratortoarray, 0, 0, 1)
	ZEND_ARG_INFO(0, iterator)
	ZEND_ARG_INFO(0, recursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayutils_merge, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, a, 0)
	ZEND_ARG_ARRAY_INFO(0, b, 0)
	ZEND_ARG_INFO(0, preserveNumericKeys)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_arrayutils_method_entry) {
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, hasStringKeys, arginfo_zendframework_stdlib_arrayutils_hasstringkeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, hasIntegerKeys, arginfo_zendframework_stdlib_arrayutils_hasintegerkeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, hasNumericKeys, arginfo_zendframework_stdlib_arrayutils_hasnumerickeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, isList, arginfo_zendframework_stdlib_arrayutils_islist, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, isHashTable, arginfo_zendframework_stdlib_arrayutils_ishashtable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, inArray, arginfo_zendframework_stdlib_arrayutils_inarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, iteratorToArray, arginfo_zendframework_stdlib_arrayutils_iteratortoarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(ZendFramework_Stdlib_ArrayUtils, merge, arginfo_zendframework_stdlib_arrayutils_merge, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
