/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Rbac;

interface RoleInterface extends \RecursiveIterator, \Traversable, \Iterator
{
    /**
     * Get the name of the role.
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Add permission to the role.
     *
     * @param $name
     * @return RoleInterface
     */
    public function addPermission(string name) -> <RoleInterface>;

    /**
     * Checks if a permission exists for this role or any child roles.
     *
     * @param  string $name
     * @return bool
     */
    public function hasPermission(string name) -> boolean;

    /**
     * Add a child.
     *
     * @param  RoleInterface|string $child
     * @return RoleInterface
     */
    public function addChild(var child) -> <RoleInterface>;

    /**
     * @param  RoleInterface $parent
     * @return RoleInterface
     */
    public function setParent(<RoleInterface> parent) -> <RoleInterface>;

    /**
     * @return null|RoleInterface
     */
    public function getParent() -> <RoleInterface>;

}
