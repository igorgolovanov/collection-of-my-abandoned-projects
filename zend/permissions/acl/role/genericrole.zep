/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Acl\Role;

class GenericRole implements RoleInterface
{
    /**
     * Unique id of Role
     *
     * @var string
     */
    protected roleId;

    /**
     * Sets the Role identifier
     *
     * @param string $roleId
     */
    public function __construct(string roleId)
    {
        let this->roleId = roleId;
    }

    /**
     * Defined by RoleInterface; returns the Role identifier
     *
     * @return string
     */
    public function getRoleId() -> string
    {
        return this->roleId;
    }

    /**
     * Defined by RoleInterface; returns the Role identifier
     * Proxies to getRoleId()
     *
     * @return string
     */
    public function __toString() -> string
    {
        string id;
        
        let id = this->getRoleId();

        return id;
    }

}
