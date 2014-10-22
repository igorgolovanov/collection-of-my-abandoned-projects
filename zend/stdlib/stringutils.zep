/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

use Zend\Stdlib\StringWrapper\StringWrapperInterface;

/**
 * Utility class for handling strings of different character encodings
 * using available PHP extensions.
 *
 * Declared abstract, as we have no need for instantiation.
 */
abstract class StringUtils
{
    /**
     * Ordered list of registered string wrapper instances
     *
     * @var StringWrapperInterface[]
     */
    protected static wrapperRegistry;

    /**
     * A list of known single-byte character encodings (upper-case)
     *
     * @var string[]
     */
    protected static singleByteEncodings = [
        'ASCII', '7BIT', '8BIT',
        'ISO-8859-1', 'ISO-8859-2', 'ISO-8859-3', 'ISO-8859-4', 'ISO-8859-5',
        'ISO-8859-6', 'ISO-8859-7', 'ISO-8859-8', 'ISO-8859-9', 'ISO-8859-10',
        'ISO-8859-11', 'ISO-8859-13', 'ISO-8859-14', 'ISO-8859-15', 'ISO-8859-16',
        'CP-1251', 'CP-1252',
    ]; 

    /**
     * Is PCRE compiled with Unicode support?
     *
     * @var bool
     **/
    protected static hasPcreUnicodeSupport;

    /**
     * Get registered wrapper classes
     *
     * @return string[]
     */
    public static function getRegisteredWrappers() -> array
    {
        // todo: change self -> static

        if static::wrapperRegistry === null {
            let static::wrapperRegistry = [];

            if extension_loaded("intl") {
                 let static::wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Intl";
            }
            if extension_loaded("mbstring") {
                 let static::wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\MbString";
            }
            if extension_loaded("iconv") {
                 let static::wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Iconv";
            }

            let static::wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Native";
        }
        return static::wrapperRegistry;
    }

    /**
     * Register a string wrapper class
     *
     * @param string $wrapper
     * @return void
     */
    public static function registerWrapper(string wrapper) -> void
    {
        if !in_array(wrapper, static::wrapperRegistry, true) {
            let static::wrapperRegistry[] = wrapper;
        }
    }

    /**
     * Unregister a string wrapper class
     *
     * @param string $wrapper
     * @return void
     */
    public static function unregisterWrapper(string wrapper) -> void
    {
        var index;
        let index = array_search(wrapper, static::wrapperRegistry, true);

        if index !== false {
            unset static::wrapperRegistry[index];
        }
    }

    /**
     * Reset all registered wrappers so the default wrappers will be used
     *
     * @return void
     */
    public static function resetRegisteredWrappers() -> void
    {
        let static::wrapperRegistry = null;
    }

    /**
     * Get the first string wrapper supporting the given character encoding
     * and supports to convert into the given convert encoding.
     *
     * @param string      $encoding        Character encoding to support
     * @param string|null $convertEncoding OPTIONAL character encoding to convert in
     * @return StringWrapperInterface
     * @throws Exception\RuntimeException If no wrapper supports given character encodings
     */
    public static function getWrapper(string encoding = "UTF-8", string convertEncoding = null) -> <StringWrapperInterface>
    {
        array wrapers;
        string wrapperClass, exceptionMsg;
        var wrapper;

        let wrapers = static::getRegisteredWrappers();

        for wrapperClass in wrapers {
            if {wrapperClass}::isSupported(encoding, convertEncoding) {
                let wrapper = <StringWrapperInterface> new {wrapperClass}(encoding, convertEncoding);
                wrapper->setEncoding(encoding, convertEncoding);

                return wrapper;
            }
        }

        let exceptionMsg = "No wrapper found supporting \"" . encoding . "\"";
        if convertEncoding !== null {
            let exceptionMsg = exceptionMsg . " and \"" . convertEncoding . "\"";
        }
        throw new Exception\RuntimeException(exceptionMsg);
    }

    /**
     * Get a list of all known single-byte character encodings
     *
     * @return string[]
     */
    public static function getSingleByteEncodings() -> array
    {
        return static::singleByteEncodings;
    }

    /**
     * Check if a given encoding is a known single-byte character encoding
     *
     * @param string $encoding
     * @return bool
     */
    public static function isSingleByteEncoding(string encoding) -> boolean
    {
        array encodings;

        let encodings = static::singleByteEncodings

        return in_array(encoding->upper(), encodings);
    }

    /**
     * Check if a given string is valid UTF-8 encoded
     *
     * @param string $str
     * @return bool
     */
    public static function isValidUtf8(var str) -> boolean
    {
        if typeof str == "string" {
            if str === "" || preg_match("/^./su", str) == 1 {
                return true;
            }
        }
        return false;
    }

    /**
     * Is PCRE compiled with Unicode support?
     *
     * @return bool
     */
    public static function hasPcreUnicodeSupport() -> boolean
    {
        if static::hasPcreUnicodeSupport === null {
            ErrorHandler::start();
            if defined("PREG_BAD_UTF8_OFFSET_ERROR") && preg_match("/\pL/u", "a") == 1 {
                let static::hasPcreUnicodeSupport = true;
            } else {
                let static::hasPcreUnicodeSupport = false;
            }
            ErrorHandler::end();
        }
        return static::hasPcreUnicodeSupport;
    }

}
