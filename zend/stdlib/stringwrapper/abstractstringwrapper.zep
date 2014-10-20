/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\StringWrapper;

use Zend\Stdlib\Exception;
use Zend\Stdlib\StringUtils;

abstract class AbstractStringWrapper implements StringWrapperInterface
{
    /**
     * The character encoding working on
     * @var string|null
     */
    protected encoding = "UTF-8";

    /**
     * An optionally character encoding to convert to
     * @var string|null
     */
    protected convertEncoding;

    /**
     * Check if the given character encoding is supported by this wrapper
     * and the character encoding to convert to is also supported.
     *
     * @param  string      $encoding
     * @param  string|null $convertEncoding
     * @return bool
     */
    public static function isSupported(string encoding, string convertEncoding = null) -> boolean
    {
        array supportedEncodings;
        // todo: change self -> static
        let supportedEncodings = self::getSupportedEncodings();
        if !in_array(encoding->upper(), supportedEncodings) {
            return false;
        }

        if convertEncoding !== null && !in_array(convertEncoding->upper(), supportedEncodings) {
            return false;
        }
        return true;
    }

    /**
     * Set character encoding working with and convert to
     *
     * @param string      $encoding         The character encoding to work with
     * @param string|null $convertEncoding  The character encoding to convert to
     * @return StringWrapperInterface
     */
    public function setEncoding(string encoding, string convertEncoding = null) -> <StringWrapperInterface>
    {
        array supportedEncodings;
        string encodingUpper;
        // todo: change self -> static
        let supportedEncodings = self::getSupportedEncodings();
        let encodingUpper = encoding->upper();



        return this;
    }

    /**
     * Get the defined character encoding to work with
     *
     * @return string
     * @throws Exception\LogicException If no encoding was defined
     */
    public function getEncoding() -> string
    {
        return this->encoding;
    }

    /**
     * Get the defined character encoding to convert to
     *
     * @return string|null
    */
    public function getConvertEncoding() -> string
    {
        return this->convertEncoding;
    }

    /**
     * Convert a string from defined character encoding to the defined convert encoding
     *
     * @param string  $str
     * @param bool $reverse
     * @return string|false
     */
    public function convert(string str, boolean $reverse = false) -> string
    {

    }

    /**
     * Wraps a string to a given number of characters
     *
     * @param  string  $string
     * @param  int $width
     * @param  string  $break
     * @param  bool $cut
     * @return string|false
     */
    public function wordWrap(string $string, int width = 75, string $break = "", boolean cut = false) -> string
    {

    }

    /**
     * Pad a string to a certain length with another string
     *
     * @param  string  $input
     * @param  int $padLength
     * @param  string  $padString
     * @param  int $padType
     * @return string
     */
    public function strPad(string input, int padLength, string padString = " ", int padType = STR_PAD_RIGHT) -> string
    {

    }

}
