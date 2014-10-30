/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Ldap\Node\Schema\AttributeType;

/**
 * This class provides a contract for schema attribute-types.
 */
interface AttributeTypeInterface
{
    /**
     * Gets the attribute name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Gets the attribute OID
     *
     * @return string
     */
    public function getOid() -> string;

    /**
     * Gets the attribute syntax
     *
     * @return string
     */
    public function getSyntax() -> string;

    /**
     * Gets the attribute maximum length
     *
     * @return int|null
     */
    public function getMaxLength() -> int;

    /**
     * Returns if the attribute is single-valued.
     *
     * @return bool
     */
    public function isSingleValued() -> boolean;

    /**
     * Gets the attribute description
     *
     * @return string
     */
    public function getDescription() -> string;

}
