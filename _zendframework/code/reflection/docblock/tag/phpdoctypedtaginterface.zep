/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Code\Reflection\DocBlock\Tag;

interface PhpDocTypedTagInterface
{
    /**
     * Return all types supported by the tag definition
     *
     * @return string[]
     */
    public function getTypes() -> array;

}
