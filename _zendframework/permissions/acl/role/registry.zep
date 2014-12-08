/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Permissions\Acl\Role;

use Traversable;
use Zend\Permissions\Acl\Exception;

class Registry
{
    /**
     * Internal Role registry data storage
     *
     * @var array
     */
    protected roles = [];

    /**
     * Adds a Role having an identifier unique to the registry
     *
     * The $parents parameter may be a reference to, or the string identifier for,
     * a Role existing in the registry, or $parents may be passed as an array of
     * these - mixing string identifiers and objects is ok - to indicate the Roles
     * from which the newly added Role will directly inherit.
     *
     * In order to resolve potential ambiguities with conflicting rules inherited
     * from different parents, the most recently added parent takes precedence over
     * parents that were previously added. In other words, the first parent added
     * will have the least priority, and the last parent added will have the
     * highest priority.
     *
     * @param  RoleInterface                           $role
     * @param  RoleInterface|string|array|Traversable $parents
     * @throws Exception\InvalidArgumentException
     * @return Registry Provides a fluent interface
     */
    public function add(<RoleInterface> role, var parents = null) -> <Registry>
    {
        string exceptionMsg;
        var roleId, roleParentId, roleParents, roleInfo, parent, e, roleParent;

        let roleId = role->getRoleId();

        if unlikely !!this->has(roleId) {
            let exceptionMsg = "Role id \"" . roleId . "\" already exists in the registry";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let roleParents = [];

        if parents !== null {
            if typeof parents != "array" || !(parents instanceof Traversable) {
                let parents = [parents];
            }
            for parent in parents {
                try {
                    if parent instanceof RoleInterface {
                        let roleParentId = parent->getRoleId();
                    } else {
                        let roleParentId = parent;
                    }
                    let roleParent = <RoleInterface> this->get(roleParentId);

                } catch \Exception, e {
                    let exceptionMsg = "Parent Role id \"" . roleParentId . "\" does not exist";
                    throw new Exception\InvalidArgumentException(exceptionMsg, 0, e);
                }
                let roleParents[roleParentId] = roleParent;
                let this->roles[roleParentId]["children"][roleId] = role;
            }
        }

        let roleInfo = [
            "instance" : role,
            "parents" : roleParents,
            "children" : []
        ];

        let this->roles[roleId] = roleInfo;

        return this;
    }

    /**
     * Returns the identified Role
     *
     * The $role parameter can either be a Role or a Role identifier.
     *
     * @param  RoleInterface|string $role
     * @throws Exception\InvalidArgumentException
     * @return RoleInterface
     */
    public function get(var role) -> <RoleInterface>
    {
        string exceptionMsg;
        var instance, roleId, roles;

        if role instanceof RoleInterface {
            let roleId = role->getRoleId();
        } else {
            let roleId = role;
        }
        if unlikely !this->has(role) {
            let exceptionMsg = "Role \"" . roleId . "\" not found";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let roles = this->roles[roleId];
        let instance = <RoleInterface> roles["instance"];

        return instance;
    }

    /**
     * Returns true if and only if the Role exists in the registry
     *
     * The $role parameter can either be a Role or a Role identifier.
     *
     * @param  RoleInterface|string $role
     * @return bool
     */
    public function has(var role) -> boolean
    {
        var roleId;

        if role instanceof RoleInterface {
            let roleId = role->getRoleId();
        } else {
            let roleId = role;
        }

        return isset this->roles[roleId];
    }

    /**
     * Returns an array of an existing Role's parents
     *
     * The array keys are the identifiers of the parent Roles, and the values are
     * the parent Role instances. The parent Roles are ordered in this array by
     * ascending priority. The highest priority parent Role, last in the array,
     * corresponds with the parent Role most recently added.
     *
     * If the Role does not have any parents, then an empty array is returned.
     *
     * @param  RoleInterface|string $role
     * @return array
     */
    public function getParents(var role) -> array
    {
        var parents, info, instance, roleId;

        let instance = <RoleInterface> this->get(role);
        let roleId = instance->getRoleId();
        let info = this->roles[roleId];
        let parents = info["parents"];

        return parents;
    }

    /**
     * Returns true if and only if $role inherits from $inherit
     *
     * Both parameters may be either a Role or a Role identifier. If
     * $onlyParents is true, then $role must inherit directly from
     * $inherit in order to return true. By default, this method looks
     * through the entire inheritance DAG to determine whether $role
     * inherits from $inherit through its ancestor Roles.
     *
     * @param  RoleInterface|string  $role
     * @param  RoleInterface|string  $inherit
     * @param  bool                    $onlyParents
     * @throws Exception\InvalidArgumentException
     * @return bool
     */
    public function inherits(var role, var inherit, boolean onlyParents = false) -> boolean
    {
        var e, roleId, inheritId, parent, parentId, exceptionCode, exceptionMsg;
        boolean inherits;

        try {
            let role = <RoleInterface> this->get(role);
            let inherit = <RoleInterface> this->get(inherit);
            let roleId = role->getRoleId();
            let inheritId = inherit->getRoleId();
        } catch Exception\ExceptionInterface, e {
            let exceptionMsg = e->getMessage();
            let exceptionCode = e->getCode();
            throw new Exception\InvalidArgumentException(exceptionMsg, exceptionCode, e);
        }

        let inherits = isset this->roles[roleId]["parents"][inheritId];

        if inherits || onlyParents {
            return inherits;
        }

        for parentId, parent in this->roles[roleId]["parents"] {
            if this->inherits(parentId, inheritId) {
                return true;
            }
        }
        return false;
    }

    /**
     * Removes the Role from the registry
     *
     * The $role parameter can either be a Role or a Role identifier.
     *
     * @param  RoleInterface|string $role
     * @throws Exception\InvalidArgumentException
     * @return Registry Provides a fluent interface
     */
    public function remove(var role) -> <Registry>
    {
        var e, child, childId, info, exceptionCode, exceptionMsg, roleId;

        try {
            let role = <RoleInterface> this->get(role);
            let roleId = role->getRoleId();
        } catch Exception\ExceptionInterface, e {
            let exceptionMsg = e->getMessage();
            let exceptionCode = e->getCode();
            throw new Exception\InvalidArgumentException(exceptionMsg, exceptionCode, e);
        }

        let info = this->roles[roleId];

        for childId, child in info["children"] {
            unset this->roles[childId]["parents"][roleId];
        }

        for childId, child in info["parents"] {
            unset this->roles[childId]["children"][roleId];
        }

        unset this->roles[roleId];

        return this;
    }

    /**
     * Removes all Roles from the registry
     *
     * @return Registry Provides a fluent interface
     */
    public function removeAll() -> <Registry>
    {
        let this->roles = [];

        return this;
    }

    /**
     * Get all roles in the registry
     *
     * @return array
     */
    public function getRoles() -> array
    {
        return this->roles;
    }

}
