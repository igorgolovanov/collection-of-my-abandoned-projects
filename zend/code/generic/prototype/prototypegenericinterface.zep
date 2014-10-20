/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generic\Prototype;

interface PrototypeGenericInterface extends PrototypeInterface
{
    /**
     * @param string $name
     */
    public function setName(string name) -> self;

}
