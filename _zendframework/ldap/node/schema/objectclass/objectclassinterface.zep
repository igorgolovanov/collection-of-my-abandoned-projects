/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Ldap\Node\Schema\ObjectClass;

/**
 * This class provides a contract for schema objectClasses.
 */
interface ObjectClassInterface
{
    /**
     * Gets the objectClass name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Gets the objectClass OID
     *
     * @return string
     */
    public function getOid() -> string;

    /**
     * Gets the attributes that this objectClass must contain
     *
     * @return array
     */
    public function getMustContain() -> array;

    /**
     * Gets the attributes that this objectClass may contain
     *
     * @return array
     */
    public function getMayContain() -> array;

    /**
     * Gets the objectClass description
     *
     * @return string
     */
    public function getDescription() -> string;

    /**
     * Gets the objectClass type
     *
     * @return int
     */
    public function getType() -> int;

    /**
     * Returns the parent objectClasses of this class.
     * This includes structural, abstract and auxiliary objectClasses
     *
     * @return array
     */
    public function getParentClasses() -> array;

}
