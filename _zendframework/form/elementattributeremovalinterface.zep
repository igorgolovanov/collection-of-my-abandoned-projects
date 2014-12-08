/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

interface ElementAttributeRemovalInterface
{
    /**
     * Remove a single element attribute
     *
     * @param  string $key
     * @return ElementAttributeRemovalInterface
     */
    public function removeAttribute(string key) -> <ElementAttributeRemovalInterface>;

    /**
     * Remove many attributes at once
     *
     * @param array $keys
     * @return ElementAttributeRemovalInterface
     */
    public function removeAttributes(array! keys) -> <ElementAttributeRemovalInterface>;

    /**
     * Remove all attributes at once
     *
     * @return ElementAttributeRemovalInterface
     */
    public function clearAttributes() -> <ElementAttributeRemovalInterface>;

}
