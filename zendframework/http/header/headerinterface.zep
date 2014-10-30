/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Interface for HTTP Header classes.
 */
interface HeaderInterface
{
    /**
     * Factory to generate a header object from a string
     *
     * @param string $headerLine
     * @return self
     * @throws Exception\InvalidArgumentException If the header does not match RFC 2616 definition.
     * @see http://tools.ietf.org/html/rfc2616#section-4.2
     */
    public static function fromString(string headerLine) -> <HeaderInterface>;

    /**
     * Retrieve header name
     *
     * @return string
     */
    public function getFieldName() -> string;

    /**
     * Retrieve header value
     *
     * @return string
     */
    public function getFieldValue() -> string;

    /**
     * Cast to string
     *
     * Returns in form of "NAME: VALUE"
     *
     * @return string
     */
    public function toString() -> string;

}
