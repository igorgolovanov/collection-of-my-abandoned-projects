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
        
        let supportedEncodings = static::getSupportedEncodings();
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
        string encodingUpper, exceptionMsg, convertEncodingUpper;

        let supportedEncodings = static::getSupportedEncodings();
        let encodingUpper = encoding->upper();

        if unlikely !in_array(encodingUpper, supportedEncodings) {
            let exceptionMsg = "Wrapper doesn\'t support character encoding \"" . encoding . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if convertEncoding !== null {
            let convertEncodingUpper = convertEncoding->upper();
            if unlikely !in_array(convertEncodingUpper, supportedEncodings) {
                let exceptionMsg = "Wrapper doesn\'t support character encoding \"" . convertEncoding . "\"";
                throw new Exception\InvalidArgumentException(exceptionMsg);
            }
            let this->convertEncoding = convertEncodingUpper;
        } else {
            let this->convertEncoding = null;
        }
        let this->encoding = encodingUpper;

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
    public function getConvertEncoding() -> string|null
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
    public function convert(string str, boolean $reverse = false) -> string|boolean
    {
        string encoding, convertEncoding, from, to, exceptionMsg;

        let encoding = this->getEncoding();
        let convertEncoding = $this->getConvertEncoding();

        if unlikely convertEncoding === null {
            throw new Exception\LogicException("No convert encoding defined");
        }

        if encoding === convertEncoding {
            return str;
        }

        if $reverse {
            let from = convertEncoding;
            let to = encoding;
        } else {
            let from = encoding;
            let to = convertEncoding;
        }

        let exceptionMsg = "Converting from \"" . from . "\" to \"" . to . "\" isn't supported by this string wrapper";
        throw new Exception\RuntimeException(exceptionMsg);
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
    public function wordWrap(string $string, int width = 75, string $break = "\n", boolean cut = false) -> string|boolean
    {
        string encoding, ch, possibleBreak, substr;
        int stringWidth, breakWidth, lastSpace = 0, lastStart = 0, current = 0;
        var result;

        if $string === "" {
            return "";
        }

        if unlikely $break === "" {
            throw new Exception\InvalidArgumentException("Break string cannot be empty");
        }

        if unlikely width === 0 && cut {
            throw new Exception\InvalidArgumentException("Cannot force cut when width is zero");
        }

        let encoding = this->getEncoding();
        if StringUtils::isSingleByteEncoding(encoding) {
            return wordwrap($string, width, $break, cut);
        }

        let stringWidth = this->strlen($string);
        let breakWidth = this->strlen($break);

        while current < stringWidth {
            let current++;
            let ch = this->substr($string, current, 1);
            let possibleBreak = ch;

            if breakWidth != 1 {
                let possibleBreak = this->substr($string, current, breakWidth);
            }

            if possibleBreak === $break {
                let substr = this->substr($string, lastStart, current - lastStart + breakWidth);
                let result = result . substr;
                let current = current + breakWidth - 1;
                let lastStart = current + 1;
                let lastSpace = lastStart;
                continue;
            }

            if ch == "" {
                if current - lastStart >= width {
                    let substr = this->substr($string, lastStart, current - lastStart);
                    let result = result . substr . $break;
                    let lastStart = current + 1;
                }
                let lastSpace = current;
                continue;
            }

            if (current - lastStart >= width) && cut && (lastStart >= lastSpace) {
                let substr = this->substr($string, lastStart, current - lastStart);
                let result = result . substr . $break;
                let lastStart = current;
                let lastSpace = lastStart;
                continue
            }

            if (current - lastStart >= width) && (lastStart < lastSpace) {
                let substr = this->substr($string, lastStart, lastSpace - lastStart);
                let result = result . substr . $break;
                let lastSpace++;
                let lastStart = lastSpace;
                continue
            }
        }

        if lastStart !== current {
            let substr = this->substr($string, lastStart, current - lastStart);
            let result = result . substr;
        }

        return result;
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
        string encoding, lastString, lastStringLeft, lastStringRight, result;
        int lengthOfPadding, padStringLength, repeatCount, repeatCountLeft, 
            repeatCountRight, lastStringLength, lastStringLeftLength,
            lastStringRightLength;

        let encoding = this->getEncoding();
        if StringUtils::isSingleByteEncoding(encoding) {
            return str_pad(input, padLength, padString, padType);
        }

        let lengthOfPadding = padLength - this->strlen(input);
        if lengthOfPadding <= 0 {
            return input;
        }

        let padStringLength = this->strlen(padString);
        if padStringLength === 0 {
            return input;
        }

        let repeatCount = floor(lengthOfPadding / padStringLength);

        if padType === STR_PAD_BOTH {
            let repeatCountLeft = (repeatCount - (repeatCount % 2)) / 2;
            let repeatCountRight = repeatCountLeft;

            let lastStringLength = lengthOfPadding - 2 * repeatCountLeft * padStringLength;
            let lastStringLeftLength = floor(lastStringLength / 2);
            let lastStringRightLength = lastStringLeftLength + lastStringLength % 2;

            let lastStringLeft = this->substr(padString, 0, lastStringLeftLength);
            let lastStringRight = this->substr(padString, 0, lastStringRightLength);

            let result = str_repeat(padString, repeatCountLeft);
            let result = result . lastStringLeft . input;
            let result = result . str_repeat(padString, repeatCountRight);
            let result = result . lastStringRight;

            return result;
        }

        let lastString = this->substr(padString, 0, lengthOfPadding % padStringLength);

        if padType === STR_PAD_LEFT {
            let result = str_repeat(padString, repeatCount);
            let result = result . lastString . input

            return result;
        }

        let result = str_repeat(padString, repeatCount);
        let result = input . result . lastString;

        return result;
    }

}
