/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Permissions\Acl\Assertion;

use Zend\Permissions\Acl\Role\RoleInterface;
use Zend\Permissions\Acl\Resource\ResourceInterface;
use Zend\Permissions\Acl\AclInterface;

interface AssertionInterface
{
    /**
     * Returns true if and only if the assertion conditions are met
     *
     * This method is passed the ACL, Role, Resource, and privilege to which the authorization query applies. If the
     * $role, $resource, or $privilege parameters are null, it means that the query applies to all Roles, Resources, or
     * privileges, respectively.
     *
     * @param  AclInterface         $acl
     * @param  RoleInterface        $role
     * @param  ResourceInterface    $resource
     * @param  string               $privilege
     * @return bool
     */
    public function assert(<AclInterface> acl, <RoleInterface> role = null, <ResourceInterface> $resource = null, string privilege = null) -> boolean;

}
