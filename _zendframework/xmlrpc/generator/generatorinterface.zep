/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\XmlRpc\Generator;

// todo: types

/**
 * XML generator adapter interface
 */
interface GeneratorInterface
{
    public function getEncoding();

    public function setEncoding(encoding);

    public function openElement(name, value = null);

    public function closeElement(name);

    /**
     * Return XML as a string
     *
     * @return string
     */
    public function saveXml() -> string;

    public function stripDeclaration(xml);

    public function flush();

    public function __toString();

}
