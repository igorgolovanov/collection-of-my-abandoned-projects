/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * @throws Exception\InvalidArgumentException
 * @see http://tools.ietf.org/id/draft-abarth-origin-03.html#rfc.section.2
 */
class Origin implements HeaderInterface
{
    /**
     * @var string
     */
    protected value;

    public static function fromString(headerLine)
    {

    }

    /**
     * @param string|null $value
     */
    public function __construct(string value = null)
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

}
