/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Header;

interface StructuredInterface extends HeaderInterface
{
    const FORMAT_ENCODED = true;

    const FORMAT_RAW = false;

    /**
     * Return the delimiter at which a header line should be wrapped
     *
     * @return string
     */
    public function getDelimiter() -> string;

}
