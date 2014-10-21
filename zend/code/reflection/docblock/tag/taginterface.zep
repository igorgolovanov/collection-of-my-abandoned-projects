/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

use Zend\Code\Generic\Prototype\PrototypeInterface;

interface TagInterface extends PrototypeInterface
{
    /**
     * @param  string $content
     * @return void
     */
    public function initialize(string content) -> void;
}