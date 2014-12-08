/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Permissions\Rbac;

interface AssertionInterface
{
    /**
     * Assertion method - must return a boolean.
     *
     * @param  Rbac    $rbac
     * @return bool
     */
    public function assert(rbac) -> boolean; // todo: <Rbac>

}
