/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * @see http://www.ietf.org/rfc/rfc2109.txt
 * @see http://www.w3.org/Protocols/rfc2109/rfc2109
 */
class Cookie extends \ArrayObject implements HeaderInterface
{
    const STD_PROP_LIST = 1;

    const ARRAY_AS_PROPS = 2;

    protected encodeValue = true;

    public static function fromSetCookieArray(array! setCookies)
    {

    }

    public static function fromString(headerLine)
    {

    }

    public function __construct(array! $array = [])
    {

    }

    public function setEncodeValue(encodeValue)
    {

    }

    public function getEncodeValue()
    {

    }

    public function getFieldName()
    {

    }

    public function getFieldValue()
    {

    }

    public function toString()
    {

    }

    /**
     * Get the cookie as a string, suitable for sending as a "Cookie" header in an
     * HTTP request
     *
     * @return string
     */
    public function __toString() -> string
    {

    }

}
