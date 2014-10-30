
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(ZendFramework_Di_Di) {

	ZEPHIR_REGISTER_CLASS(Zend\\Di, Di, zendframework, di_di, NULL, 0);

	/**
	 * Resolve method policy
	 *
	 * EAGER: explore type preference or go through
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("RESOLVE_EAGER"), 1 TSRMLS_CC);

	/**
	 * Resolve method policy
	 *
	 * STRICT: explore type preference or throw exception
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("RESOLVE_STRICT"), 2 TSRMLS_CC);

	/**
	 * use only specified parameters
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_OPTIONAL"), 0 TSRMLS_CC);

	/**
	 * resolve mode RESOLVE_EAGER
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_AWARE"), 1 TSRMLS_CC);

	/**
	 * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_CONSTRUCTOR"), 3 TSRMLS_CC);

	/**
	 * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_INSTANTIATOR"), 3 TSRMLS_CC);

	/**
	 * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_REQUIRED"), 3 TSRMLS_CC);

	/**
	 * resolve mode RESOLVE_EAGER
	 */
	zend_declare_class_constant_long(zendframework_di_di_ce, SL("METHOD_IS_EAGER"), 1 TSRMLS_CC);

	return SUCCESS;

}

