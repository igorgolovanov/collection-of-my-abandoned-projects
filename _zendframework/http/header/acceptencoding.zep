/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Accept Encoding Header
 *
 * @see        http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.3
 */
class AcceptEncoding extends AbstractAccept
{
    protected regexAddType = "#^([a-zA-Z0-9+-]+|\*)$#";

    /**
     * Get field name
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

    /**
     * Cast to string
     *
     * @return string
     */
    public function toString() -> string
    {

    }

    /**
     * Add an encoding, with the given priority
     *
     * @param  string $type
     * @param  int|float $priority
     * @return Accept
     */
    public function addEncoding(string type, var priority = 1) -> <Accept>
    {

    }

    /**
     * Does the header have the requested encoding?
     *
     * @param  string $type
     * @return bool
     */
    public function hasEncoding(string type) -> boolean
    {

    }

    /**
     * Parse the keys contained in the header line
     *
     * @param string $fieldValuePart
     * @return \Zend\Http\Header\Accept\FieldValuePart\EncodingFieldValuePart
     * @see \Zend\Http\Header\AbstractAccept::parseFieldValuePart()
     */
    protected function parseFieldValuePart(string fieldValuePart) -> <Accept\FieldValuePart\EncodingFieldValuePart>
    {

    }

}
