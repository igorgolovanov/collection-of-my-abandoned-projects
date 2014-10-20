/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Rbac;

use RecursiveIteratorIterator;

class Rbac extends AbstractIterator
{
    /**
     * flag: whether or not to create roles automatically if
     * they do not exist.
     *
     * @var bool
     */
    protected createMissingRoles = false;

    /**
     * @param  bool                     $createMissingRoles
     * @return \Zend\Permissions\Rbac\Rbac
     */
    public function setCreateMissingRoles(boolean createMissingRoles) -> <Rbac>
    {
        let this->createMissingRoles = createMissingRoles;
    }

    /**
     * @return bool
     */
    public function getCreateMissingRoles() -> boolean
    {
        return this->createMissingRoles;
    }

    /**
     * Add a child.
     *
     * @param  string|RoleInterface               $child
     * @param  array|RoleInterface|null           $parents
     * @return self
     * @throws Exception\InvalidArgumentException
     */
    public function addRole(var child, var parents = null) -> self
    {
        var parent, role;

        if typeof child == "string" {
            let child = new Role(child);
        }
        if unlikely !(child instanceof RoleInterface) {
            throw new Exception\InvalidArgumentException(
                "Child must be a string or implement Zend\Permissions\Rbac\RoleInterface"
            );
        }

        if !empty parents {
            if typeof parents != "array" {
                let parents = [parents];
            }
            for parent in parents {
                if this->createMissingRoles {
                    if !this->hasRole(parent) {
                        this->addRole(parent);
                    }
                }
                let role = <RoleInterface> this->getRole(parent);
                role->addChild(child);
            }
        }
        let this->children[] = child;

        return this;
    }

    /**
     * Is a child with $name registered?
     *
     * @param  \Zend\Permissions\Rbac\RoleInterface|string $objectOrName
     * @return bool
     */
    public function hasRole(var objectOrName) -> boolean
    {
        var e;

        try {
            this->getRole(objectOrName);
            return true;
        } catch (xception\InvalidArgumentException e) {
            return false;
        }
    }

    /**
     * Get a child.
     *
     * @param  \Zend\Permissions\Rbac\RoleInterface|string $objectOrName
     * @return RoleInterface
     * @throws Exception\InvalidArgumentException
     */
    public function getRole(var objectOrName) -> <RoleInterface>
    {
        var iterator, leaf;
        string requiredRole, name, exceptionMsg;

        if unlikely typeof objectOrName != "string" && !(objectOrName instanceof RoleInterface) {
            throw new Exception\InvalidArgumentException(
                "Expected string or implement \Zend\Permissions\Rbac\RoleInterface"
            );
        }

        if typeof objectOrName == "object" {
            let requiredRole = objectOrName->getName();
        } else {
            let requiredRole = objectOrName;
        }

        let iterator = new RecursiveIteratorIterator(this, RecursiveIteratorIterator::CHILD_FIRST);
        for leaf in iterator {
            let name = leaf->getName();
            if name == requiredRole {
                return leaf;
            }
        }

        let exceptionMsg = "No role with name \"" . requiredRole . "\" could be found";
        throw new Exception\InvalidArgumentException(exceptionMsg);
    }

    /**
     * Determines if access is granted by checking the role and child roles for permission.
     *
     * @param  RoleInterface|string             $role
     * @param  string                           $permission
     * @param  AssertionInterface|Callable|null $assert
     * @throws Exception\InvalidArgumentException
     * @return bool
     */
    public function isGranted(var role, string permission, var assert = null) -> boolean
    {
        var roleInstance;

        if !empty assert {
            if assert instanceof AssertionInterface {
                if assert->assert(this) {
                    return false;
                }
            } else {
                if is_callable(assert) {
                    if !call_user_func(assert, this) {
                        return false;
                    }
                } else {
                    throw new Exception\InvalidArgumentException(
                        "Assertions must be a Callable or an instance of Zend\Permissions\Rbac\AssertionInterface"
                    );
                }
            }
        }

        let roleInstance = <RoleInterface> this->getRole(role);

        return roleInstance->hasPermission(permission);
    }

}
