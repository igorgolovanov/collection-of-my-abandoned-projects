/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use Reflector;

interface ReflectionInterface extends Reflector
{
    /**
     * @return string
     */
    public function toString() -> string;

}
