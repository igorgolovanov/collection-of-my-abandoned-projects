/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * If-Unmodified-Since Header
 *
 * @link       http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.28
 */
class IfUnmodifiedSince extends AbstractDate
{
    const DATE_RFC1123 = 0;

    const DATE_RFC1036 = 1;

    const DATE_ANSIC = 2;

    /**
     * Get header name
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

}
