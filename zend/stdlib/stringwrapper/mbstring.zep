/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\StringWrapper;

use Zend\Stdlib\Exception;

class MbString extends AbstractStringWrapper
{
    /**
     * List of supported character sets (upper case)
     *
     * @var null|string[]
     * @link http://php.net/manual/mbstring.supported-encodings.php
     */
    protected static encodings;

    /**
     * Get a list of supported character encodings
     *
     * @return string[]
     */
    public static function getSupportedEncodings() -> array
    {
        array encodings;
        var indexIso885916;

        // todo: change self -> static
        if static::encodings === null {
            let encodings = mb_list_encodings();
            let encodings = array_map("strtoupper", encodings);
            let static::encodings = encodings;

            // FIXME: Converting € (UTF-8) to ISO-8859-16 gives a wrong result
            let indexIso885916 = array_search("ISO-8859-16", encodings, true);
            if indexIso885916 !== false {
                unset static::encodings[indexIso885916];
            }
        }

        return static::encodings;
    }

    /**
     * Constructor
     *
     * @throws Exception\ExtensionNotLoadedException
     */
    public function __construct()
    {
        if unlikely !extension_loaded("mbstring") {
            throw new Exception\ExtensionNotLoadedException(
                "PHP extension \"mbstring\" is required for this wrapper"
            );
        }
    }

    /**
     * Returns the length of the given string
     *
     * @param string $str
     * @return int|false
     */
    public function strlen(string str) -> int
    {
        string encoding;
        let encoding = this->getEncoding();

        return mb_strlen(str, encoding);
    }

    /**
     * Returns the portion of string specified by the start and length parameters
     *
     * @param string   $str
     * @param int      $offset
     * @param int|null $length
     * @return string|false
     */
    public function substr(string str, int offset = 0, int length = null) -> string
    {
        string encoding;
        let encoding = this->getEncoding();

        return mb_substr(str, offset, length, encoding);
    }

    /**
     * Find the position of the first occurrence of a substring in a string
     *
     * @param string $haystack
     * @param string $needle
     * @param int    $offset
     * @return int|false
     */
    public function strpos(string haystack, string needle, int offset = 0) -> int
    {
        string encoding;
        let encoding = this->getEncoding();

        return mb_strpos(haystack, needle, offset, encoding);
    }

    /**
     * Convert a string from defined encoding to the defined convert encoding
     *
     * @param string  $str
     * @param bool $reverse
     * @return string|false
     */
    public function convert(string str, boolean $reverse = false) -> string
    {
        string encoding, convertEncoding, fromEncoding, toEncoding;

        let encoding = this->getEncoding();
        let convertEncoding = this->getConvertEncoding();

        if unlikely empty convertEncoding {
            throw new Exception\LogicException(
                "No convert encoding defined"
            );
        }

        if encoding === convertEncoding {
            return str;
        }

        if $reverse {
            let fromEncoding = convertEncoding;
            let toEncoding = encoding;
        } else {
            let fromEncoding = encoding;
            let toEncoding = convertEncoding;
        }

        let str = mb_convert_encoding(str, toEncoding, fromEncoding);
        return str;
    }

}
