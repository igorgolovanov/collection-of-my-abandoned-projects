/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\StringWrapper;

interface StringWrapperInterface
{
    /**
     * Check if the given character encoding is supported by this wrapper
     * and the character encoding to convert to is also supported.
     *
     * @param string      $encoding
     * @param string|null $convertEncoding
     */
    public static function isSupported(string encoding, string convertEncoding = null);

    /**
     * Get a list of supported character encodings
     *
     * @return string[]
     */
    public static function getSupportedEncodings() -> array;

    /**
     * Set character encoding working with and convert to
     *
     * @param string      $encoding         The character encoding to work with
     * @param string|null $convertEncoding  The character encoding to convert to
     * @return StringWrapperInterface
     */
    public function setEncoding(string encoding, string convertEncoding = null) -> <StringWrapperInterface>;

    /**
     * Get the defined character encoding to work with (upper case)
     *
     * @return string
     */
    public function getEncoding() -> string;

    /**
     * Get the defined character encoding to convert to (upper case)
     *
     * @return string|null
     */
    public function getConvertEncoding() -> string;

    /**
     * Returns the length of the given string
     *
     * @param string $str
     * @return int|false
     */
    public function strlen(string str) -> int;

    /**
     * Returns the portion of string specified by the start and length parameters
     *
     * @param string   $str
     * @param int      $offset
     * @param int|null $length
     * @return string|false
     */
    public function substr(string str, int offset = 0, int length = null) -> string;

    /**
     * Find the position of the first occurrence of a substring in a string
     *
     * @param string $haystack
     * @param string $needle
     * @param int    $offset
     * @return int|false
     */
    public function strpos(string haystack, string needle, int offset = 0) -> int;

    /**
     * Convert a string from defined encoding to the defined convert encoding
     *
     * @param string  $str
     * @param bool $reverse
     * @return string|false
     */
    public function convert(string str, boolean $reverse = false) -> string;

    /**
     * Wraps a string to a given number of characters
     *
     * @param  string  $str
     * @param  int $width
     * @param  string  $break
     * @param  bool $cut
     * @return string
     */
    public function wordWrap(string str, int width = 75, string $break = "\n", boolean cut = false) -> string;

    /**
     * Pad a string to a certain length with another string
     *
     * @param  string  $input
     * @param  int $padLength
     * @param  string  $padString
     * @param  int $padType
     * @return string
     */
    public function strPad(string input, int padLength, string padString = " ", int padType = STR_PAD_RIGHT) -> string;

}
