/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

use Traversable;

/**
 * Utility class for testing and manipulation of PHP arrays.
 *
 * Declared abstract, as we have no need for instantiation.
 */
abstract class ArrayUtils
{
    /**
     * Test whether an array contains one or more string keys
     *
     * @param  mixed $value
     * @param  bool  $allowEmpty    Should an empty array() return true
     * @return bool
     */
    public static function hasStringKeys(value, boolean allowEmpty = false) -> boolean
    {
        array keys, filtered;

        if typeof value != "array" {
            return false;
        }

        if !value {
            return allowEmpty;
        }

        let keys = array_keys(value);
        let filtered = array_filter(keys, "is_string");

        if count(filtered) > 0 {
            return true;
        }
        return false;
    }

    /**
     * Test whether an array contains one or more integer keys
     *
     * @param  mixed $value
     * @param  bool  $allowEmpty    Should an empty array() return true
     * @return bool
     */
    public static function hasIntegerKeys(value, boolean allowEmpty = false) -> boolean
    {
        array keys, filtered;

        if typeof value != "array" {
            return false;
        }

        if !value {
            return allowEmpty;
        }

        let keys = array_keys(value);
        let filtered = array_filter(keys, "is_int");

        if count(filtered) > 0 {
            return true;
        }
        return false;
    }

    /**
     * Test whether an array contains one or more numeric keys.
     *
     * A numeric key can be one of the following:
     * - an integer 1,
     * - a string with a number '20'
     * - a string with negative number: '-1000'
     * - a float: 2.2120, -78.150999
     * - a string with float:  '4000.99999', '-10.10'
     *
     * @param  mixed $value
     * @param  bool  $allowEmpty    Should an empty array() return true
     * @return bool
     */
    public static function hasNumericKeys(value, boolean allowEmpty = false) -> boolean
    {
        array keys, filtered;

        if typeof value != "array" {
            return false;
        }

        if !value {
            return allowEmpty;
        }

        let keys = array_keys(value);
        let filtered = array_filter(keys, "is_numeric");

        if count(filtered) > 0 {
            return true;
        }
        return false;
    }

    /**
     * Test whether an array is a list
     *
     * A list is a collection of values assigned to continuous integer keys
     * starting at 0 and ending at count() - 1.
     *
     * For example:
     * <code>
     * $list = array('a', 'b', 'c', 'd');
     * $list = array(
     *     0 => 'foo',
     *     1 => 'bar',
     *     2 => array('foo' => 'baz'),
     * );
     * </code>
     *
     * @param  mixed $value
     * @param  bool  $allowEmpty    Is an empty list a valid list?
     * @return bool
     */
    public static function isList(value, boolean allowEmpty = false) -> boolean
    {
        array values;

        if typeof value != "array" {
            return false;
        }

        if !value {
            return allowEmpty;
        }
        let values = array_values(value);

        return values === value;
    }

    /**
     * Test whether an array is a hash table.
     *
     * An array is a hash table if:
     *
     * 1. Contains one or more non-integer keys, or
     * 2. Integer keys are non-continuous or misaligned (not starting with 0)
     *
     * For example:
     * <code>
     * $hash = array(
     *     'foo' => 15,
     *     'bar' => false,
     * );
     * $hash = array(
     *     1995  => 'Birth of PHP',
     *     2009  => 'PHP 5.3.0',
     *     2012  => 'PHP 5.4.0',
     * );
     * $hash = array(
     *     'formElement,
     *     'options' => array( 'debug' => true ),
     * );
     * </code>
     *
     * @param  mixed $value
     * @param  bool  $allowEmpty    Is an empty array() a valid hash table?
     * @return bool
     */
    public static function isHashTable(value, boolean allowEmpty = false) -> boolean
    {
        array values;

        if typeof value != "array" {
            return false;
        }

        if !value {
            return allowEmpty;
        }
        let values = array_values(value);

        return values !== value;
    }

    /**
     * Checks if a value exists in an array.
     *
     * Due to "foo" == 0 === TRUE with in_array when strict = false, an option
     * has been added to prevent this. When $strict = 0/false, the most secure
     * non-strict check is implemented. if $strict = -1, the default in_array
     * non-strict behaviour is used.
     *
     * @param mixed $needle
     * @param array $haystack
     * @param int|bool $strict
     * @return bool
     */
    public static function inArray(needle, array! haystack, var strict = false) -> boolean
    {
        string type;
        var h, i;

        if strict {
            let type = typeof needle;
            if type == "int" || type == "float" {
                let needle = strval(needle);
            }
            if type == "string" {
                for h, i in haystack {
                    if typeof h == "int" || typeof h == "float" {
                        let haystack[i] = strval(h);
                    }
                }
            }
        }

        return in_array(needle, haystack, strict);
    }

    /**
     * Convert an iterator to an array.
     *
     * Converts an iterator to an array. The $recursive flag, on by default,
     * hints whether or not you want to do so recursively.
     *
     * @param  array|Traversable  $iterator     The array or Traversable object to convert
     * @param  bool               $recursive    Recursively check all nested structures
     * @throws Exception\InvalidArgumentException if $iterator is not an array or a Traversable object
     * @return array
     */
    public static function iteratorToArray(var iterator, boolean recursive = true) -> array
    {
        // todo: change self -> static
        string exceptionMsg;
        array data;
        var key, value;

        if unlikely (typeof iterator != "array" && !iterator instanceof Traversable) {
            let exceptionMsg = __METHOD__ + " expects an array or Traversable object";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if !recursive {
            if typeof iterator != "array" {
                let data = iterator_to_array(iterator);
                return data;
            }
            return iterator;
        }

        if method_exists(iterator, "toArray") {
            let data = iterator->toArray();
            return data;
        }

        let data = [];
        for value, key in iterator {
            if is_scalar(value) {
                let data[key] = value;
                continue;
            }
            if typeof value == "array" || value instanceof Traversable {
                let data[key] = self::iteratorToArray(value, recursive);
                continue;
            }
            let data[key] = value;
        }
        return data;
    }

    /**
     * Merge two arrays together.
     *
     * If an integer key exists in both arrays and preserveNumericKeys is false, the value
     * from the second array will be appended to the first array. If both values are arrays, they
     * are merged together, else the value of the second array overwrites the one of the first array.
     *
     * @param  array $a
     * @param  array $b
     * @param  bool  $preserveNumericKeys
     * @return array
     */
    public static function merge(array! a, array! b, boolean preserveNumericKeys = false) -> array
    {
        // todo: change self -> static
        var key, value, av;

        for value, key in b {
            if isset a[key] {
                if typeof value == "int" && !preserveNumericKeys {
                    let a[] = value;
                    continue;
                } 
                if typeof value == "array" {
                    let av = a[key];
                    if typeof av == "array" {
                        let a[key] = self::merge(av, value, preserveNumericKeys);
                        continue;
                    }
                }
            }
            let a[key] = value;
        }
        return a;
    }
}
