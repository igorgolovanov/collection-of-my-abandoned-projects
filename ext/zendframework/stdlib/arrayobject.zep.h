
extern zend_class_entry *zendframework_stdlib_arrayobject_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_ArrayObject);

PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __construct);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __isset);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __set);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __unset);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, __get);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, append);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, asort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, count);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, exchangeArray);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getArrayCopy);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getFlags);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getIterator);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, getIteratorClass);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, ksort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, natcasesort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, natsort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetExists);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetGet);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetSet);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, offsetUnset);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, serialize);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, setFlags);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, setIteratorClass);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, uasort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, uksort);
PHP_METHOD(ZendFramework_Stdlib_ArrayObject, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, input, 1)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, iteratorClass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_append, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_exchangearray, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_setflags, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_setiteratorclass, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_uasort, 0, 0, 1)
	ZEND_ARG_INFO(0, function)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_uksort, 0, 0, 1)
	ZEND_ARG_INFO(0, function)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_stdlib_arrayobject_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_stdlib_arrayobject_method_entry) {
	PHP_ME(ZendFramework_Stdlib_ArrayObject, __construct, arginfo_zendframework_stdlib_arrayobject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, __isset, arginfo_zendframework_stdlib_arrayobject___isset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, __set, arginfo_zendframework_stdlib_arrayobject___set, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, __unset, arginfo_zendframework_stdlib_arrayobject___unset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, __get, arginfo_zendframework_stdlib_arrayobject___get, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, append, arginfo_zendframework_stdlib_arrayobject_append, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, asort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, exchangeArray, arginfo_zendframework_stdlib_arrayobject_exchangearray, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, getArrayCopy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, getFlags, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, getIteratorClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, ksort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, natcasesort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, natsort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, offsetExists, arginfo_zendframework_stdlib_arrayobject_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, offsetGet, arginfo_zendframework_stdlib_arrayobject_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, offsetSet, arginfo_zendframework_stdlib_arrayobject_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, offsetUnset, arginfo_zendframework_stdlib_arrayobject_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, setFlags, arginfo_zendframework_stdlib_arrayobject_setflags, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, setIteratorClass, arginfo_zendframework_stdlib_arrayobject_setiteratorclass, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, uasort, arginfo_zendframework_stdlib_arrayobject_uasort, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, uksort, arginfo_zendframework_stdlib_arrayobject_uksort, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Stdlib_ArrayObject, unserialize, arginfo_zendframework_stdlib_arrayobject_unserialize, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
