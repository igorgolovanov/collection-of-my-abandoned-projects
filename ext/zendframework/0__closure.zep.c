
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(zendframework_0__closure) {

	ZEPHIR_REGISTER_CLASS(zendframework, 0__closure, zendframework, 0__closure, zendframework_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(zendframework_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *letter = NULL, *_2 = NULL;
	zval *letters_param = NULL, *_0 = NULL, *_3 = NULL, *_4;
	zval *letters = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &letters_param);

	if (unlikely(Z_TYPE_P(letters_param) != IS_ARRAY)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'letters' must be an array") TSRMLS_CC);
		RETURN_MM_NULL();
	}

		letters = letters_param;



	Z_SET_ISREF_P(letters);
	ZEPHIR_CALL_FUNCTION(&_0, "array_shift", &_1, letters);
	Z_UNSET_ISREF_P(letters);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(letter, _2);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_strtolower(_4, letter);
	ZEPHIR_CONCAT_SV(return_value, "_", _4);
	RETURN_MM();

}

