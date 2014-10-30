/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Math\BigInteger\Adapter;

interface AdapterInterface
{
    const BASE62_ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    /**
     * Create adapter-specific representation of a big integer
     *
     * @param  string $operand
     * @param  int|null $base
     * @return mixed
     */
    public function init(string operand, int base = null);

    /**
     * Add two big integers
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @return string
     */
    public function add(string leftOperand, string rightOperand) -> string;

    /**
     * Subtract two big integers
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @return string
     */
    public function sub(string leftOperand, string rightOperand) -> string;

    /**
     * Multiply two big integers
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @return string
     */
    public function mul(string leftOperand, string rightOperand) -> string;

    /**
     * Divide two big integers
     * (this method returns only int part of result)
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @return string
     */
    public function div(string leftOperand, string rightOperand) -> string;

    /**
     * Raise a big integers to another
     *
     * @param  string $operand
     * @param  string $exp
     * @return string
     */
    public function pow(string operand, string exp) -> string;

    /**
     * Get the square root of a big integer
     *
     * @param  string $operand
     * @return string
     */
    public function sqrt(string operand) -> string;

    /**
     * Get absolute value of a big integer
     *
     * @param  string $operand
     * @return string
     */
    public function abs(string operand) -> string;

    /**
     * Get modulus of a big integer
     *
     * @param  string $leftOperand
     * @param  string $modulus
     * @return string
     */
    public function mod(string leftOperand, string modulus) -> string;

    /**
     * Raise a big integer to another, reduced by a specified modulus
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @param  string $modulus
     * @return string
     */
    public function powmod(string leftOperand, string rightOperand, string modulus) -> string;

    /**
     * Compare two big integers
     * Returns < 0 if leftOperand is less than rightOperand;
     * > 0 if leftOperand is greater than rightOperand, and 0 if they are equal.
     *
     * @param  string $leftOperand
     * @param  string $rightOperand
     * @return int
     */
    public function comp(string leftOperand, string rightOperand) -> int;

    /**
     * Convert big integer into it's binary number representation
     *
     * @param  string $int
     * @param  bool $twoc
     * @return string
     */
    public function intToBin(string $int, boolean twoc = false) -> string;

    /**
     * Convert binary number into big integer
     *
     * @param  string $bytes
     * @param  bool $twoc
     * @return string
     */
    public function binToInt(string bytes, boolean twoc = false) -> string;

    /**
     * Convert a number between arbitrary bases
     *
     * @param  string $operand
     * @param  int $fromBase
     * @param  int $toBase
     * @return string
     */
    public function baseConvert(string operand, int fromBase, int toBase = 10) -> string;

}
