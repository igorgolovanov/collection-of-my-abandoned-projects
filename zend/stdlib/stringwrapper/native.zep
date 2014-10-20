/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\StringWrapper;

use Zend\Stdlib\Exception;
use Zend\Stdlib\StringUtils;

class Native extends AbstractStringWrapper implements StringWrapperInterface
{
    /**
     * The character encoding working on
     * (overwritten to change defaut encoding)
     *
     * @var string
     */
    protected encoding = "ASCII";

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
        string encodingUpper;
        array supportedEncodings;

        // todo: change self -> static
        let supportedEncodings = self::getSupportedEncodings();
        let encodingUpper = encoding->upper();

        if !in_array(encodingUpper, supportedEncodings) {
            return false;
        }

        // This adapter doesn't support to convert between encodings
        if convertEncoding !== null && encodingUpper !== convertEncoding->upper() {
            return false;
        }

        return true;
    }

    /**
     * Get a list of supported character encodings
     *
     * @return string[]
     */
    public static function getSupportedEncodings() -> array
    {
        array encodings;
        let encodings = StringUtils::getSingleByteEncodings();

        return encodings;
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
        string encodingUpper, exceptionMsg;

        // todo: change self -> static
        let supportedEncodings = self::getSupportedEncodings(); 
        let encodingUpper = encoding->upper();

        if unlikely !in_array(encodingUpper, supportedEncodings) {
            let exceptionMsg = "Wrapper doesn\'t support character encoding \"%s\"";
            let exceptionMsg = sprintf(exceptionMsg, encoding);

            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if encodingUpper !== convertEncoding->upper() {
            let this->convertEncoding = encodingUpper;
        }

        if convertEncoding !== null {
            if unlikely encodingUpper !== convertEncoding->upper() {
                throw new Exception\InvalidArgumentException(
                    "Wrapper doesn't support to convert between character encodings"
                );
            }
            let this->convertEncoding = encodingUpper;
        } else {
            let this->convertEncoding = null;
        }
        let this->encoding = encodingUpper;

        return this;
    }

    /**
     * Returns the length of the given string
     *
     * @param string $str
     * @return int|false
     */
    public function strlen(string str) -> int|boolean
    {
        var length;
        let length = strlen(str);

        return length;
    }

    /**
     * Returns the portion of string specified by the start and length parameters
     *
     * @param string   $str
     * @param int      $offset
     * @param int|null $length
     * @return string|false
     */
    public function substr(string str, int offset = 0, int length = null) -> string|boolean
    {
        var sub;
        let sub = substr(str, offset, length);

        return sub;
    }

    /**
     * Find the position of the first occurrence of a substring in a string
     *
     * @param string $haystack
     * @param string $needle
     * @param int    $offset
     * @return int|false
     */
    public function strpos(string haystack, string needle, int offset = 0) -> int|boolean
    {
        var pos;
        let pos = strpos(haystack, needle, offset);

        return pos;
    }


}
