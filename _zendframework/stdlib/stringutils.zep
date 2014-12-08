/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

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
    protected static singleByteEncodings;

    /**
     * Is PCRE compiled with Unicode support?
     *
     * @var bool
     **/
    protected static hasPcreUnicodeSupport;

    protected static function _singleByteEncodings() -> array
    {
        return [
            "ASCII", "7BIT", "8BIT",
            "ISO-8859-1", "ISO-8859-2", "ISO-8859-3", "ISO-8859-4", "ISO-8859-5",
            "ISO-8859-6", "ISO-8859-7", "ISO-8859-8", "ISO-8859-9", "ISO-8859-10",
            "ISO-8859-11", "ISO-8859-13", "ISO-8859-14", "ISO-8859-15", "ISO-8859-16",
            "CP-1251", "CP-1252"
        ];
    }

    /**
     * Get registered wrapper classes
     *
     * @return string[]
     */
    public static function getRegisteredWrappers() -> array
    {
        var className, wrapperRegistry = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        }%
        if wrapperRegistry === null {
            let wrapperRegistry = [];

            if extension_loaded("intl") {
                 let wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Intl";
            }
            if extension_loaded("mbstring") {
                 let wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\MbString";
            }
            if extension_loaded("iconv") {
                 let wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Iconv";
            }

            let wrapperRegistry[] = "Zend\\Stdlib\\StringWrapper\\Native";
        }

        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        }%
        return wrapperRegistry;
    }

    /**
     * Register a string wrapper class
     *
     * @param string $wrapper
     * @return void
     */
    public static function registerWrapper(string wrapper) -> void
    {
        var className, wrapperRegistry = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        }%
        if wrapperRegistry === null {
            let wrapperRegistry = [];
        }
        if !in_array(wrapper, wrapperRegistry, true) {
            let wrapperRegistry[] = wrapper;
        }

        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        }%
    }

    /**
     * Unregister a string wrapper class
     *
     * @param string $wrapper
     * @return void
     */
    public static function unregisterWrapper(string wrapper) -> void
    {
        var index, className, wrapperRegistry = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&wrapperRegistry, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry") TSRMLS_CC);
        }%
        if wrapperRegistry === null {
            let wrapperRegistry = [];
        }
        let index = array_search(wrapper, wrapperRegistry, true);

        if index !== false {
            unset wrapperRegistry[index];
        }

        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        }%
    }

    /**
     * Reset all registered wrappers so the default wrappers will be used
     *
     * @return void
     */
    public static function resetRegisteredWrappers() -> void
    {
        var className, wrapperRegistry;

        let className = get_called_class();
        let wrapperRegistry = null;
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("wrapperRegistry"), &wrapperRegistry TSRMLS_CC);
        }%
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
        var wrappers, wrapperClass, wrapper;
        string exceptionMsg;

        let wrappers = static::getRegisteredWrappers();

        for wrapperClass in wrappers {
           // if {wrapperClass}::isSupported(encoding, convertEncoding) {
//                let wrapper = <StringWrapperInterface> new {wrapperClass}(encoding, convertEncoding);
//                wrapper->setEncoding(encoding, convertEncoding);
//todo:
//                return wrapper;
           // }
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
        var singleByteEncodings = null, className;

        let className = get_called_class();
        %{
            zephir_read_static_property(&singleByteEncodings, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("singleByteEncodings") TSRMLS_CC);
        }%
        if singleByteEncodings === null {
            let singleByteEncodings = static::_singleByteEncodings();
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("singleByteEncodings"), &singleByteEncodings TSRMLS_CC);
            }%
        }
        return singleByteEncodings;
    }

    /**
     * Check if a given encoding is a known single-byte character encoding
     *
     * @param string $encoding
     * @return bool
     */
    public static function isSingleByteEncoding(string encoding) -> boolean
    {
        var encodings;
        let encodings = static::getSingleByteEncodings();

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
        var hasPcreUnicodeSupport = null, className;

        let className = get_called_class();
        %{
            zephir_read_static_property(&hasPcreUnicodeSupport, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("hasPcreUnicodeSupport") TSRMLS_CC);
        }%
        if hasPcreUnicodeSupport === null {
            ErrorHandler::start();
            if defined("PREG_BAD_UTF8_OFFSET_ERROR") && preg_match("/\\pL/u", "a") == 1 {
                let hasPcreUnicodeSupport = true;
            } else {
                let hasPcreUnicodeSupport = false;
            }
            ErrorHandler::stop();
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("hasPcreUnicodeSupport"), &hasPcreUnicodeSupport TSRMLS_CC);
            }%
        }
        return hasPcreUnicodeSupport;
    }

}
