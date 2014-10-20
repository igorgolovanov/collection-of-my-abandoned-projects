/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

interface LocatorInterface
{
    /**
     * Retrieve a class instance
     *
     * @param  string      $name   Class name or service name
     * @param  null|array  $params Parameters to be used when instantiating a new instance of $name
     * @return object|null
     */
    public function get(string name, array! params = []) -> object;

}
