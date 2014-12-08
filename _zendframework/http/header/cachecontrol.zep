/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * @throws Exception\InvalidArgumentException
 * @see http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.9
 */
class CacheControl implements HeaderInterface
{
    /** @var string */
    protected value;

    /**
     * Array of Cache-Control directives
     *
     * @var array
     */
    protected directives = [];

    /**
     * Creates a CacheControl object from a headerLine
     *
     * @param string $headerLine
     * @throws Exception\InvalidArgumentException
     * @return CacheControl
     */
    public static function fromString(string headerLine) -> <CacheControl>
    {

    }

    /**
     * Required from HeaderDescription interface
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

    /**
     * Checks if the internal directives array is empty
     *
     * @return bool
     */
    public function isEmpty() -> boolean
    {

    }

    /**
     * Add a directive
     * For directives like 'max-age=60', $value = '60'
     * For directives like 'private', use the default $value = true
     *
     * @param string $key
     * @param string|bool $value
     * @return CacheControl - provides the fluent interface
     */
    public function addDirective(string key, var value = true) -> <CacheControl>
    {

    }

    /**
     * Check the internal directives array for a directive
     *
     * @param string $key
     * @return bool
     */
    public function hasDirective(string key) -> boolean
    {

    }

    /**
     * Fetch the value of a directive from the internal directive array
     *
     * @param string $key
     * @return string|null
     */
    public function getDirective(string key) -> string|null
    {

    }

    /**
     * Remove a directive
     *
     * @param string $key
     * @return CacheControl - provides the fluent interface
     */
    public function removeDirective(string key) -> <CacheControl>
    {

    }

    /**
     * Assembles the directives into a comma-delimited string
     *
     * @return string
     */
    public function getFieldValue() -> string
    {

    }

    /**
     * Returns a string representation of the HTTP Cache-Control header
     *
     * @return string
     */
    public function toString() -> string
    {

    }

    /**
     * Internal function for parsing the value part of a
     * HTTP Cache-Control header
     *
     * @param string $value
     * @throws Exception\InvalidArgumentException
     * @return array
     */
    protected static function parseValue(string value) -> array
    {

    }

    /**
     * Internal function used by parseValue to match tokens
     *
     * @param array $tokens
     * @param string $string
     * @param string $lastMatch
     * @return int
     */
    protected static function match(array tokens, string $string, string lastMatch) -> int
    {

    }

}
