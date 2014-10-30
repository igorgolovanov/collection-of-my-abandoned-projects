
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Math_BigInteger_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Math\\BigInteger\\Adapter, AdapterInterface, zendframework, math_biginteger_adapter_adapterinterface, zendframework_math_biginteger_adapter_adapterinterface_method_entry);

	zend_declare_class_constant_string(zendframework_math_biginteger_adapter_adapterinterface_ce, SL("BASE62_ALPHABET"), "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Create adapter-specific representation of a big integer
 *
 * @param  string $operand
 * @param  int|null $base
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, init);

/**
 * Add two big integers
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, add);

/**
 * Subtract two big integers
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, sub);

/**
 * Multiply two big integers
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, mul);

/**
 * Divide two big integers
 * (this method returns only int part of result)
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, div);

/**
 * Raise a big integers to another
 *
 * @param  string $operand
 * @param  string $exp
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, pow);

/**
 * Get the square root of a big integer
 *
 * @param  string $operand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, sqrt);

/**
 * Get absolute value of a big integer
 *
 * @param  string $operand
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, abs);

/**
 * Get modulus of a big integer
 *
 * @param  string $leftOperand
 * @param  string $modulus
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, mod);

/**
 * Raise a big integer to another, reduced by a specified modulus
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @param  string $modulus
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, powmod);

/**
 * Compare two big integers
 * Returns < 0 if leftOperand is less than rightOperand;
 * > 0 if leftOperand is greater than rightOperand, and 0 if they are equal.
 *
 * @param  string $leftOperand
 * @param  string $rightOperand
 * @return int
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, comp);

/**
 * Convert big integer into it's binary number representation
 *
 * @param  string $int
 * @param  bool $twoc
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, intToBin);

/**
 * Convert binary number into big integer
 *
 * @param  string $bytes
 * @param  bool $twoc
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, binToInt);

/**
 * Convert a number between arbitrary bases
 *
 * @param  string $operand
 * @param  int $fromBase
 * @param  int $toBase
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_Math_BigInteger_Adapter_AdapterInterface, baseConvert);

