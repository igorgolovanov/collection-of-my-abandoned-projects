/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Address;

interface AddressInterface
{
    public function getEmail() -> string;

    public function getName() -> string;

    public function toString() -> string;

}
