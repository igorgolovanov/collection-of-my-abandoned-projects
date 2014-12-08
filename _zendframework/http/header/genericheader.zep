/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Content-Location Header
 *
  */
class GenericHeader implements HeaderInterface
{
    /**
     * @var string
     */
    protected fieldName;

    /**
     * @var string
     */
    protected fieldValue;

    /**
     * Factory to generate a header object from a string
     *
     * @static
     * @param string $headerLine
     * @return GenericHeader
     */
    public static function fromString(string headerLine) -> <GenericHeader>
    {

    }

    /**
     * Splits the header line in `name` and `value` parts.
     *
     * @param string $headerLine
     * @return string[] `name` in the first index and `value` in the second.
     * @throws Exception\InvalidArgumentException If header does not match with the format ``name:value``
     */
    public static function splitHeaderLine(string headerLine) -> array
    {

    }

    /**
     * Constructor
     *
     * @param null|string $fieldName
     * @param null|string $fieldValue
     */
    public function __construct(string fieldName = null, string fieldValue = null)
    {

    }

    /**
     * Set header field name
     *
     * @param  string $fieldName
     * @return GenericHeader
     * @throws Exception\InvalidArgumentException If the name does not match with RFC 2616 format.
     */
    public function setFieldName(string fieldName) -> <GenericHeader>
    {

    }

    /**
     * Retrieve header field name
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

    /**
     * Set header field value
     *
     * @param  string $fieldValue
     * @return GenericHeader
     */
    public function setFieldValue(string fieldValue) -> <GenericHeader>
    {

    }

    /**
     * Retrieve header field value
     *
     * @return string
     */
    public function getFieldValue() -> string
    {

    }

    /**
     * Cast to string as a well formed HTTP header line
     *
     * Returns in form of "NAME: VALUE\r\n"
     *
     * @return string
     */
    public function toString() -> string
    {

    }

}
