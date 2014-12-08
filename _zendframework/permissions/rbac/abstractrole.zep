/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Permissions\Rbac;

use RecursiveIteratorIterator;

abstract class AbstractRole extends AbstractIterator implements RoleInterface
{
    /**
     * @var null|RoleInterface
     */
    protected parent;

    /**
     * @var string
     */
    protected name;

    /**
     * @var array
     */
    protected permissions = [];

    /**
     * Get the name of the role.
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Add permission to the role.
     *
     * @param string $name
     * @return RoleInterface
     */
    public function addPermission(string name) -> <RoleInterface>
    {
        let this->permissions[name] = true;

        return this;
    }

    /**
     * Checks if a permission exists for this role or any child roles.
     *
     * @param  string $name
     * @return bool
     */
    public function hasPermission(string name) -> boolean
    {
        var iterator, leaf;

        if isset this->permissions[name] {
            return true;
        }

        let iterator = new RecursiveIteratorIterator(this, RecursiveIteratorIterator::CHILD_FIRST);

        for leaf in iterator {
            if leaf->hasPermission(name) {
                return true;
            }
        }
        return false;
    }

    /**
     * Add a child.
     *
     * @param  RoleInterface|string $child
     * @return RoleInterface
     */
    public function addChild(var child) -> <RoleInterface>
    {
        if typeof child == "string" {
            let child = new Role(child);
        }

        if unlikely !(child instanceof RoleInterface) {
            throw new Exception\InvalidArgumentException(
                "Child must be a string or implement Zend\\Permissions\\Rbac\\RoleInterface"
            );
        }

        child->setParent(this);
        let this->children[] = child;

        return this;
    }

    /**
     * @param  RoleInterface $parent
     * @return RoleInterface
     */
    public function setParent(<RoleInterface> parent) -> <RoleInterface>
    {
        let this->parent = parent;

        return this;
    }

    /**
     * @return null|RoleInterface
     */
    public function getParent() -> <RoleInterface>|null
    {
        return this->parent;
    }

}
