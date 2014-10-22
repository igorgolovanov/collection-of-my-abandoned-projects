/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\StringWrapper;

use Zend\Stdlib\Exception;

class Intl extends AbstractStringWrapper
{
    /**
     * List of supported character sets (upper case)
     *
     * @var string[]
     */
    protected static encodings; // ["UTF-8"]

    /**
     * Get a list of supported character encodings
     *
     * @return string[]
     */
    public static function getSupportedEncodings() -> array
    {
        return static::encodings;
    }

    /**
     * Constructor
     *
     * @throws Exception\ExtensionNotLoadedException
     */
    public function __construct()
    {
        if unlikely !extension_loaded("intl") {
            throw new Exception\ExtensionNotLoadedException(
                "PHP extension \"intl\" is required for this wrapper"
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
        return grapheme_strlen(str);
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
        // Due fix of PHP #62759 The third argument returns an empty string if is 0 or null.
        if length {
            return grapheme_substr(str, offset, length);
        }
        return grapheme_substr(str, offset);
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
        return grapheme_strpos(haystack, needle, offset);
    }

}
