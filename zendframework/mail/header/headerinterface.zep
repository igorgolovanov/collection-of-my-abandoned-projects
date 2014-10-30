/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Header;

interface HeaderInterface
{
    const FORMAT_ENCODED = true;
    const FORMAT_RAW = false;

    /**
     * Factory to generate a header object from a string
     *
     * @param string $headerLine
     * @return self
     * @throws Exception\InvalidArgumentException If the header does not match with RFC 2822 definition.
     * @see http://tools.ietf.org/html/rfc2822#section-2.2
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
     * @param  bool $format Return the value in Mime::Encoded or in Raw format
     * @return string
     */
    public function getFieldValue(boolean format = Zend\Mail\Header\HeaderInterface::FORMAT_RAW) -> string;

    /**
     * Set header encoding
     *
     * @param  string $encoding
     * @return self
     */
    public function setEncoding(string encoding) -> <HeaderInterface>;

    /**
     * Get header encoding
     *
     * @return string
     */
    public function getEncoding() -> string;

    /**
     * Cast to string
     *
     * Returns in form of "NAME: VALUE"
     *
     * @return string
     */
    public function toString() -> string;

}
