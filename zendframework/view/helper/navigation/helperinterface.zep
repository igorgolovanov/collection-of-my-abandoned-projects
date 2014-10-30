/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\View\Helper\Navigation;

use Zend\View\Helper\HelperInterface as ViewHelperInterface;
use Zend\Permissions\Acl\AclInterface;

/**
 * Interface for navigational helpers
 */
interface HelperInterface extends ViewHelperInterface
{
    /**
     * Magic overload: Should proxy to {@link render()}.
     *
     * @return string
     */
    public function __toString() -> string;

    /**
     * Renders helper
     *
     * @param  string|Navigation\AbstractContainer $container [optional] container to render.
     *                                         Default is null, which indicates
     *                                         that the helper should render
     *                                         the container returned by {@link
     *                                         getContainer()}.
     * @return string helper output
     * @throws \Zend\View\Exception\ExceptionInterface
     */
    public function render(var container = null) -> string;

    /**
     * Sets ACL to use when iterating pages
     *
     * @param  Acl\AclInterface $acl [optional] ACL instance
     * @return HelperInterface
     */
    public function setAcl(acl = null) -> <HelperInterface>;

    /**
     * Returns ACL or null if it isn't set using {@link setAcl()} or
     * {@link setDefaultAcl()}
     *
     * @return Acl\AclInterface|null
     */
    public function getAcl();

    /**
     * Checks if the helper has an ACL instance
     *
     * @return bool
     */
    public function hasAcl() -> boolean;

    /**
     * Sets navigation container the helper should operate on by default
     *
     * @param  string|Navigation\AbstractContainer $container [optional] container to operate
     *                                         on. Default is null, which
     *                                         indicates that the container
     *                                         should be reset.
     * @return HelperInterface
     */
    public function setContainer(string container = null) -> <HelperInterface>;

    /**
     * Returns the navigation container the helper operates on by default
     *
     * @return Navigation\AbstractContainer  navigation container
     */
    public function getContainer();

    /**
     * Checks if the helper has a container
     *
     * @return bool
     */
    public function hasContainer() -> boolean;

    /**
     * Render invisible items?
     *
     * @param  bool $renderInvisible [optional] boolean flag
     * @return HelperInterface
     */
    public function setRenderInvisible(boolean renderInvisible = true) -> <HelperInterface>;

    /**
     * Return renderInvisible flag
     *
     * @return bool
     */
    public function getRenderInvisible() -> boolean;

    /**
     * Sets ACL role to use when iterating pages
     *
     * @param  mixed $role [optional] role to set.  Expects a string, an
     *                     instance of type {@link Acl\Role}, or null. Default
     *                     is null.
     * @throws \Zend\View\Exception\ExceptionInterface if $role is invalid
     * @return HelperInterface
     */
    public function setRole(role = null) -> <HelperInterface>;

    /**
     * Returns ACL role to use when iterating pages, or null if it isn't set
     *
     * @return string|Acl\Role\RoleInterface|null
     */
    public function getRole() -> string;

    /**
     * Checks if the helper has an ACL role
     *
     * @return bool
     */
    public function hasRole() -> boolean;

    /**
     * Sets whether ACL should be used
     *
     * @param  bool $useAcl [optional] whether ACL should be used. Default is true.
     * @return HelperInterface
     */
    public function setUseAcl(boolean useAcl = true) -> <HelperInterface>;

    /**
     * Returns whether ACL should be used
     *
     * @return bool
     */
    public function getUseAcl() -> boolean;

}
